#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "node_parsers/parse_result.hpp"
#include "../tokens/tokens.hpp"
#include "../syntax_tree/statement_sequence/statement_sequence.hpp"

namespace parser
{
    class Parser
    {
    public:
        Parser();
        ParseResult<syntax_tree::statement_sequence::StatementSequence> parse_tokens(const std::vector<Token> & toks) const;
    };
}

#endif
