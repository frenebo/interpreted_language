#include <vector>
#include <iostream>
#include <optional>
#include <algorithm>

#include "operator_suffixes.hpp"
#include "tokens.hpp"
#include "parser/parse_nodes/node_parse_exception.hpp"

namespace parse_nodes::operator_suffixes
{    
    std::optional<OperatorSuffix> OperatorSuffix::try_parse_suffix(const std::vector<Token> & toks, unsigned long start_idx)
    {
        TokenType first_tok_type = toks[start_idx].get_type();
        
        std::vector<TokenType> add_first_tok_types = AdditionOperatorSuffix::possible_first_token_types();

        if (std::find(add_first_tok_types.begin(), add_first_tok_types.end(), first_tok_type) != add_first_tok_types.end())
        {
            AdditionOperatorSuffix parsed_addition_op = AdditionOperatorSuffix::parse_tokens(toks, start_idx);
            
            return OperatorSuffix(
                std::variant<AdditionOperatorSuffix>(parsed_addition_op),
                parsed_addition_op.token_count()
            );
        }
        else
        {
            return std::optional<OperatorSuffix>();
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