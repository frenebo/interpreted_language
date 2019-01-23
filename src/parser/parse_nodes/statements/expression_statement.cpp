#include "statement_nodes.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"
#include "parser/parse_nodes/expressions/expression_nodes.hpp"
#include <vector>
#include <iostream>
#include <optional>
#include "tokens.hpp"

namespace parse_nodes::statement_nodes
{
    ExpressionStatementNode ExpressionStatementNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        std::optional<parse_nodes::expressions::ExpressionNode> exp_node;
        
        try
        {
            exp_node = parse_nodes::expressions::ExpressionNode::parse_tokens(toks, start_idx);
        }
        catch (const NodeParseException & ex)
        {
            throw NodeParseException(std::string(ex.what()));
        }

        if (toks.size() <= start_idx + exp_node->token_count())
        {
            throw NodeParseException("Expected semicolon, reached end of input");
        }

        TokenType next_tok_type = toks[start_idx + exp_node->token_count()].get_type();

        if (next_tok_type != TokenType::SEMICOLON_CH)
        {
            throw NodeParseException(
                "Expected " + token_type_to_string(TokenType::SEMICOLON_CH) +
                ", got " + token_type_to_string(next_tok_type)
            );
        }

        return ExpressionStatementNode(*exp_node, exp_node->token_count() + 1);
    }

    ExpressionStatementNode::ExpressionStatementNode(
        parse_nodes::expressions::ExpressionNode exp_node,
        unsigned long token_count)
    : _exp_node(exp_node),
    _token_count(token_count)
    {
    }

    unsigned long ExpressionStatementNode::token_count()
    {
        return this->_token_count;
    }

    void ExpressionStatementNode::print_node(int indentation_level)
    {
        std::cout << std::string(indentation_level, ' ') << "Expression statement: \n";

        this->_exp_node.print_node(indentation_level + 1);
    }
}