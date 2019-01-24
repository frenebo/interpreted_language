#include <iostream>
#include <string>

#include "compound_expression.hpp"
#include "parser/parse_nodes/expressions/simple_expressions/simple_expressions.hpp"
#include "parser/parse_nodes/node_parse_exception.hpp"

namespace parse_nodes::compound_expression
{
    CompoundExpNode::CompoundExpNode(
        parse_nodes::simple_expressions::SimpleExpNode first_exp_node,
        std::vector<parse_nodes::operator_suffixes::OperatorSuffix> operator_suffixes,
        unsigned long token_count)
    : _first_exp_node(first_exp_node),
    _operator_suffixes(operator_suffixes),
    _token_count(token_count)
    {
    }

    parse_nodes::simple_expressions::SimpleExpNode CompoundExpNode::first_exp_node() const
    {
        return _first_exp_node;
    }

    const std::vector<parse_nodes::operator_suffixes::OperatorSuffix> & CompoundExpNode::operator_suffixes() const
    {
        return _operator_suffixes;
    }

    unsigned long CompoundExpNode::token_count() const
    {
        return _token_count;
    }

    void CompoundExpNode::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "Compound Expression Node:\n";

        _first_exp_node.print_node(indentation_level + 1);

        if (_operator_suffixes.size() != 0)
            std::cout << std::string(indentation_level, ' ') << "Suffixes:\n";

        for (parse_nodes::operator_suffixes::OperatorSuffix op_suffix : _operator_suffixes)
        {
            op_suffix.print_node(indentation_level + 1);
        }
    }

    CompoundExpNode CompoundExpNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        parse_nodes::simple_expressions::SimpleExpNode first_node =
            parse_nodes::simple_expressions::SimpleExpNode::parse_tokens(toks, start_idx);

        unsigned long consumed_count = 1;
        
        std::vector<parse_nodes::operator_suffixes::OperatorSuffix> operator_suffixes;

        try
        {
            while (true)
            {
                parse_nodes::operator_suffixes::OperatorSuffix suffix =
                    parse_nodes::operator_suffixes::OperatorSuffix::parse_tokens(toks, start_idx + consumed_count);
                
                operator_suffixes.push_back(suffix);
                consumed_count += suffix.token_count();
            }
        }
        catch (const NodeParseException & ex)
        {
            // do nothing - this just keeps adding suffixes until the suffix parser throws
        }

        return CompoundExpNode(
            first_node,
            operator_suffixes,
            consumed_count
        );

    }
}