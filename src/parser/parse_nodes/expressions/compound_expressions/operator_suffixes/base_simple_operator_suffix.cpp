#include <vector>
#include <string>
#include <iostream>

#include "parser/parse_nodes/node_parse_exception.hpp"
#include "operator_suffixes.hpp"
#include "tokens.hpp"
#include "parser/parse_nodes/expressions/simple_expressions/simple_expressions.hpp"

namespace parse_nodes::operator_suffixes
{
    BaseSimpleOperatorSuffix::SimpleOperatorParseResult BaseSimpleOperatorSuffix::parse_simple_op(
        TokenType op_token,
        const std::vector<Token> & toks,
        unsigned long start_idx)
    {

        TokenType start_tok_type = toks[start_idx].get_type();

        if (start_tok_type != op_token)
        {
            throw NodeParseException(
                "Expected " + token_type_to_string(op_token) + ", got " + token_type_to_string(start_tok_type)
            );
        }

        long consumed_count = 1; // one for plus sign

        parse_nodes::simple_expressions::SimpleExpNode simple_exp_node = 
            parse_nodes::simple_expressions::SimpleExpNode::parse_tokens(toks, start_idx + consumed_count);
        
        consumed_count += simple_exp_node.token_count();
        
        return BaseSimpleOperatorSuffix::SimpleOperatorParseResult(
            simple_exp_node,
            consumed_count
        );
    }

    BaseSimpleOperatorSuffix::BaseSimpleOperatorSuffix(
        std::string op_name,
        parse_nodes::simple_expressions::SimpleExpNode simple_exp_node,
        unsigned long token_count)
    : _op_name(op_name),
    _simple_exp_node(simple_exp_node),
    _token_count(token_count)
    {
    }

    parse_nodes::simple_expressions::SimpleExpNode BaseSimpleOperatorSuffix::simple_exp_node() const
    {
        return _simple_exp_node;
    }

    unsigned long BaseSimpleOperatorSuffix::token_count() const
    {
        return _token_count;
    }

    void BaseSimpleOperatorSuffix::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << _op_name << ":\n";

        _simple_exp_node.print_node(indentation_level + 1);
    }
}