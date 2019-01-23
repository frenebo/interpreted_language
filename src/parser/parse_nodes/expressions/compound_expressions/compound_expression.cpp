#include "compound_expression.hpp"
// #include "../simple_expressions/simple"

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

    // CompoundExpNode CompoundExpNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    // {

    // }
}