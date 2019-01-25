#ifndef STATEMENT_SEQUENCE_H
#define STATEMENT_SEQUENCE_H

#include <vector>

#include "../statements/statements.hpp"

namespace syntax_tree::statement_sequence
{
    class StatementSequence
    {
    private:
        std::vector<syntax_tree::statements::StatementContainer> _statements;
    public:
        StatementSequence(std::vector<syntax_tree::statements::StatementContainer> statements)
        : _statements(statements)
        {
        }

        const std::vector<syntax_tree::statements::StatementContainer> & statements() const
        {
            return _statements;
        }
    };
}

#endif
