#include "operator_extensions.hpp"

namespace parse_nodes::operator_extensions
{
    ExpressionOperatorExtension ExpressionOperatorExtension::parse_tokens(
        const std::vector<Token> & toks, unsigned long start_idx)
    {
        // toks
    }
    
    ExpressionOperatorExtension::ExpressionOperatorExtension(std::variant<> contained_op_extension, unsigned long token_count)
    : _contained_op_extension(contained_op_extension),
    _token_count(token_count)
    {
    }

    unsigned long ExpressionOperatorExtension::token_count() const
    {
        return _token_count;
    }
    
}
