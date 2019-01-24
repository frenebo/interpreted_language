#include <vector>
#include <iostream>
#include <optional>
#include <algorithm>

#include "operator_suffixes.hpp"
#include "../../../../../tokens.hpp"
#include "../../../node_parse_exception.hpp"

namespace parse_nodes::operator_suffixes
{    
    std::optional<OperatorSuffixContainer> OperatorSuffixContainer::try_parse_suffix(const std::vector<Token> & toks, unsigned long start_idx)
    {
        TokenType first_tok_type = toks[start_idx].get_type();

        // if the next token appears to lead to an addition operation
        if (first_tok_type == AdditionOperatorSuffix::possible_first_token_type())
        {
            AdditionOperatorSuffix parsed_addition_op = AdditionOperatorSuffix::parse_tokens(toks, start_idx);
            
            return OperatorSuffixContainer(
                std::variant<
                    AdditionOperatorSuffix,
                    AssignmentOperatorSuffix
                >(parsed_addition_op),
                parsed_addition_op.token_count()
            );
        }
        else if (first_tok_type == AssignmentOperatorSuffix::possible_first_token_type())
        {
            AssignmentOperatorSuffix parsed_assignment_op = AssignmentOperatorSuffix::parse_tokens(toks, start_idx);

            return OperatorSuffixContainer(
                std::variant<
                    AdditionOperatorSuffix,
                    AssignmentOperatorSuffix
                >(parsed_assignment_op),
                parsed_assignment_op.token_count()
            );
        }
        else
        {
            return std::optional<OperatorSuffixContainer>();
        }
    }
    
    OperatorSuffixContainer::OperatorSuffixContainer(
        std::variant<
            AdditionOperatorSuffix,
            AssignmentOperatorSuffix
        > contained_op_extension,
        unsigned long token_count)
    : _contained_op_extension(contained_op_extension),
    _token_count(token_count)
    {
    }

    std::variant<
        AdditionOperatorSuffix,
        AssignmentOperatorSuffix
    > OperatorSuffixContainer::contained_op_extension() const
    {
        return _contained_op_extension;
    }

    void OperatorSuffixContainer::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "Operator Suffix Container:\n";

        if (std::holds_alternative<AdditionOperatorSuffix>(_contained_op_extension))
        {
            std::get<AdditionOperatorSuffix>(_contained_op_extension).print_node(indentation_level + 1);
        }
        else if (std::holds_alternative<AssignmentOperatorSuffix>(_contained_op_extension))
        {
            std::get<AssignmentOperatorSuffix>(_contained_op_extension).print_node(indentation_level + 1);
        }
    }

    unsigned long OperatorSuffixContainer::token_count() const
    {
        return _token_count;
    }
}