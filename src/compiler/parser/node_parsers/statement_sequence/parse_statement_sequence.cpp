#include <vector>

#include "../../../tokens/tokens.hpp"
#include "parse_statement_sequence.hpp"
#include "../statement/parse_statement.hpp"
#include "../../../syntax_tree/statements/statements.hpp"

namespace parser
{
    parser::ParseResult<syntax_tree::statement_sequence::StatementSequence> parse_statement_sequence(
        const std::vector<Token> & toks,
        unsigned long start_idx,
        TokenType end_token)
    {
        unsigned long consumed = 0;
        std::vector<syntax_tree::statements::StatementContainer> statement_containers;

        while (toks[start_idx + consumed].get_type() != end_token)
        {
            auto statement_parse_result = parser::statement::parse_statement(toks, start_idx + consumed);
            
            consumed += statement_parse_result.token_count();
            statement_containers.push_back(statement_parse_result.parsed_val());
        }

        return parser::ParseResult<syntax_tree::statement_sequence::StatementSequence>(
            syntax_tree::statement_sequence::StatementSequence(statement_containers),
            consumed
        );
    }
}
