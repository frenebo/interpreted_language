#include <vector>
#include <string>
#include <iostream>

#include "parser/parse_nodes/node_parse_exception.hpp"
#include "operator_suffixes.hpp"
#include "tokens.hpp"
#include "parser/parse_nodes/expressions/simple_expressions/simple_expressions.hpp"

namespace parse_nodes::operator_suffixes
{
    AdditionOperatorSuffix AdditionOperatorSuffix::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        if (toks.size() <= start_idx)
        {
            throw NodeParseException("Expected plus sign, got end of input");
        }

        TokenType start_tok_type = toks[start_idx].get_type();

        if (start_tok_type != TokenType::PLUS_CH)
        {
            throw NodeParseException("Expected plus sign, got " + token_type_to_string(start_tok_type));
        }

        long consumed_count = 1; // one for plus sign

        try
        {
            parse_nodes::simple_expressions::SimpleExpNode simple_exp_node = 
                parse_nodes::simple_expressions::SimpleExpNode::parse_tokens(toks, start_idx + consumed_count);
            
            consumed_count += simple_exp_node.token_count();
            
            return AdditionOperatorSuffix(
                simple_exp_node,
                consumed_count
            );
        }
        catch (const NodeParseException & ex)
        {
            throw NodeParseException(std::string(ex.what()));
        }
    }

    std::vector<TokenType> AdditionOperatorSuffix::possible_first_token_types()
    {
        std::vector<TokenType> possible_types;

        possible_types.push_back(TokenType::PLUS_CH);

        return possible_types;
    }

    AdditionOperatorSuffix::AdditionOperatorSuffix(
        parse_nodes::simple_expressions::SimpleExpNode simple_exp_node,
        unsigned long token_count)
    : _simple_exp_node(simple_exp_node),
    _token_count(token_count)
    {
    }

    parse_nodes::simple_expressions::SimpleExpNode AdditionOperatorSuffix::simple_exp_node() const
    {
        return _simple_exp_node;
    }

    unsigned long AdditionOperatorSuffix::token_count() const
    {
        return _token_count;
    }

    void AdditionOperatorSuffix::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "Addition Operator Suffix:\n";

        _simple_exp_node.print_node(indentation_level + 1);
    }
}