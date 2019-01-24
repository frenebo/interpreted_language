#include <vector>
#include <iostream>
#include <optional>

#include "operator_suffixes.hpp"
#include "tokens.hpp"
#include "parser/parse_nodes/node_parse_exception.hpp"

namespace parse_nodes::operator_suffixes
{    
    OperatorSuffix OperatorSuffix::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        std::optional<AdditionOperatorSuffix> parsed_addition_op;

        unsigned long longest_match = 0;

        try
        {
            parsed_addition_op = AdditionOperatorSuffix::parse_tokens(toks, start_idx);

            if (parsed_addition_op->token_count() > longest_match)
            {
                longest_match = parsed_addition_op->token_count();
            }
        }
        catch (const NodeParseException & ex)
        {
            // do nothing
        }

        if (parsed_addition_op.has_value() && parsed_addition_op->token_count() >= longest_match)
        {
            return OperatorSuffix(
                std::variant<AdditionOperatorSuffix>(*parsed_addition_op),
                longest_match
            );
        }
        else
        {
            // @TODO show the error from the closest suffix?
            
            throw NodeParseException("Expected operator suffix");
        }
    }
    
    OperatorSuffix::OperatorSuffix(
        std::variant<AdditionOperatorSuffix> contained_op_extension,
        unsigned long token_count)
    : _contained_op_extension(contained_op_extension),
    _token_count(token_count)
    {
    }

    std::variant<AdditionOperatorSuffix> OperatorSuffix::contained_op_extension() const
    {
        return _contained_op_extension;
    }

    void OperatorSuffix::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "Operator Suffix:\n";

        if (std::holds_alternative<AdditionOperatorSuffix>(_contained_op_extension))
        {
            std::get<AdditionOperatorSuffix>(_contained_op_extension).print_node(indentation_level + 1);
        }
    }

    unsigned long OperatorSuffix::token_count() const
    {
        return _token_count;
    }
}