#ifndef OPERATOR_EXTENSIONS_H
#define OPERATOR_EXTENSIONS_H

#include <vector>
#include <variant>

#include "tokens.hpp"

namespace parse_nodes::operator_suffixes{
    class OperatorSuffix
    {
    private:
        std::variant<> _contained_op_extension;
        unsigned long _token_count;
        OperatorSuffix(std::variant<> contained_op_extension, unsigned long token_count);
    public:
        unsigned long token_count() const;
        static OperatorSuffix parse_tokens(const std::vector<Token> & toks, unsigned long start_idx);
        std::variant<> contained_op_extension() const;
    };
}


#endif
