#include <iostream>
#include <string>

#include "compound_expression.hpp"
#include "../simple_expressions/simple_expressions.hpp"
#include "../../node_parse_exception.hpp"

namespace parse_nodes::compound_expression
{
    CompoundExpNode::CompoundExpNode(
        parse_nodes::simple_expressions::SimpleExpNode first_exp_node,
        std::vector<parse_nodes::operator_suffixes::OperatorSuffixContainer> operator_suffixes,
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

    const std::vector<parse_nodes::operator_suffixes::OperatorSuffixContainer> & CompoundExpNode::operator_suffixes() const
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

        for (parse_nodes::operator_suffixes::OperatorSuffixContainer op_suffix : _operator_suffixes)
        {
            op_suffix.print_node(indentation_level + 1);
        }
    }

    CompoundExpNode CompoundExpNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        parse_nodes::simple_expressions::SimpleExpNode first_node =
            parse_nodes::simple_expressions::SimpleExpNode::parse_tokens(toks, start_idx);

        unsigned long consumed_count = 1;
        
        std::vector<parse_nodes::operator_suffixes::OperatorSuffixContainer> operator_suffixes;

        while (true)
        {
            std::optional<parse_nodes::operator_suffixes::OperatorSuffixContainer> try_parse_suffix =
                parse_nodes::operator_suffixes::OperatorSuffixContainer::try_parse_suffix(toks, start_idx + consumed_count);

            if (!try_parse_suffix.has_value())
            {
                break;
            }
            
            operator_suffixes.push_back(*try_parse_suffix);
            consumed_count += try_parse_suffix->token_count();
        }

        return CompoundExpNode(
            first_node,
            operator_suffixes,
            consumed_count
        );

    }
}