#ifndef PARSER_RESULT_H
#define PARSER_RESULT_H

namespace parser
{
    template <class T>
    class ParseResult
    {
        T _parsed_val;
        unsigned long _token_count;
    public:
        ParseResult(T parsed_val, unsigned long token_count)
        : _parsed_val(parsed_val),
        _token_count(token_count)
        {
        }
        
        T parsed_val() const
        {
            return _parsed_val;
        }
        
        unsigned long token_count() const
        {
            return _token_count;
        }
    };
}

#endif
