#include "tokenizer.hpp"
#include "../tokens.hpp"
#include <optional>
#include <map>
#include <ctype.h>
#include <string>
#include <variant>
#include <vector>

namespace tokenizer
{
    std::variant<TokenizerResult, TokenizerErrorReturn> Tokenizer::tokenize(const std::string & input_str) const
    {
        std::vector<Token> toks;

        unsigned long input_start_idx = 0;

        // while there are still characters left to tokenize
        while (input_start_idx < input_str.length())
        {
            std::optional<Token> possible_match = this->try_match_longest_token(input_str, input_start_idx);

            if (!possible_match.has_value())
            {
                return std::variant<TokenizerResult, TokenizerErrorReturn>(
                    TokenizerErrorReturn("Could not process input text")
                );
            }

            input_start_idx += possible_match->get_contents().length();
            
            toks.push_back(*possible_match);
        }

        // end of input
        toks.push_back(Token(TokenType::END_OF_INPUT, ""));

        // don't return whitespace tokens
        std::vector<Token> without_whitespace;

        for (Token tok : toks)
        {
            if (tok.get_type() != TokenType::WHITESPACE)
            {
                without_whitespace.push_back(tok);
            }
        }

        return std::variant<TokenizerResult, TokenizerErrorReturn>(
            TokenizerResult(without_whitespace)
        );
    }

    Tokenizer::Tokenizer()
    {
        this->simple_tok_strings = {
            { TokenType::SEMICOLON_CH, ";" },
            { TokenType::MINUS_CH, "-" },
            { TokenType::PLUS_CH, "+" },
            { TokenType::DIVIDE_CH, "/" },
            { TokenType::ASTERISK_CH, "*" },
            { TokenType::EQUALS_CH, "=" },
            { TokenType::PERIOD_CH, "." },
            { TokenType::OPEN_PAREN_CH, "(" },
            { TokenType::CLOSE_PAREN_CH, ")" },
            { TokenType::OPEN_BRACE_CH, "{" },
            { TokenType::CLOSE_BRACE_CH, "}" },
        };
    }

    std::optional<Token> Tokenizer::try_match_longest_simple_token(const std::string & input_str, unsigned long input_start_idx) const
    {
        unsigned long chars_remaining = input_str.length() - input_start_idx;

        std::optional<Token> result_tok;

        for (std::pair<TokenType, std::string> tok_strings_pair : this->simple_tok_strings)
        {
            auto tok_string_len = tok_strings_pair.second.length();
            if (tok_string_len > chars_remaining)
            {
                continue;
            }

            bool is_match = input_str.compare(input_start_idx, tok_string_len, tok_strings_pair.second) == 0;

            if (is_match)
            {
                // if this is the first match found, or if this match is longer than the previous match
                if (!result_tok.has_value() || result_tok->get_contents().length() < tok_string_len)
                {
                    TokenType tok_type = tok_strings_pair.first;
                    std::string tok_contents = tok_strings_pair.second;
                    
                    result_tok = Token(tok_type, tok_contents);
                }
            }
        }
        
        return result_tok;
    }

    std::optional<Token> match_longest_identifier(const std::string & input_str, unsigned long input_start_idx)
    {
        // if the first character isn't an alpha character, return
        if (!isalpha(input_str[input_start_idx]))
        {
            return std::optional<Token>();
        }

        unsigned long identifier_length = 1;

        while (
            input_start_idx + identifier_length < input_str.length() &&
            isalnum(input_str[input_start_idx + identifier_length])
        ) {
            identifier_length++;
        }

        return Token(TokenType::IDENTIFIER, input_str.substr(input_start_idx, identifier_length));
    }

    std::optional<Token> match_longest_whitespace(const std::string & input_str, unsigned long input_start_idx)
    {
        // if the first character isn't whitespace
        if (!isspace(input_str[input_start_idx]))
        {
            return std::optional<Token>();
        }

        unsigned long identifier_length = 1;

        while (
            input_start_idx + identifier_length < input_str.length() &&
            isspace(input_str[input_start_idx + identifier_length])
        ) {
            identifier_length++;
        }

        return Token(TokenType::WHITESPACE, input_str.substr(input_start_idx, identifier_length));
    }

    std::optional<Token> match_longest_number(const std::string & input_str, unsigned long input_start_idx)
    {
        // // if the first character isn't a digit or a period
        if (
            !isdigit(input_str[input_start_idx]) &&
            input_str[input_start_idx] != '.'
        )
        {
            return std::optional<Token>();
        }

        unsigned long digits_before_period = 0;
        unsigned long digits_after_period = 0;
        bool seen_period = false;

        for (unsigned long idx = input_start_idx; idx < input_str.length(); idx++)
        {
            if (input_str[idx] == '.')
            {
                // only one period can exist in one number
                if (seen_period) break;

                seen_period = true;
            }
            else if (isdigit(input_str[idx]))
            {
                if (seen_period)
                {
                    digits_after_period++;
                }
                else
                {
                    digits_before_period++;
                }
            }
            // if this character is neither a digit nor a period, the number is over
            else
            {
                break;
            }
        }

        // if this "number" consists only of a single period, it is not a number
        if (digits_before_period == 0 && digits_after_period == 0)
        {
            return std::optional<Token>();
        }

        unsigned long identifier_length = digits_before_period + digits_after_period + (seen_period ? 1 : 0);

        return Token(TokenType::NUMBER, input_str.substr(input_start_idx, identifier_length));
    }

    std::optional<Token> Tokenizer::try_match_longest_token(const std::string & input_str, unsigned long input_start_idx) const
    {
        std::optional<Token> result_tok;
        
        std::optional<Token> matches[] = {
            this->try_match_longest_simple_token(input_str, input_start_idx),
            match_longest_identifier(input_str, input_start_idx),
            match_longest_whitespace(input_str, input_start_idx),
            match_longest_number(input_str, input_start_idx),
        };

        for (unsigned int i = 0; i < sizeof(matches)/sizeof(matches[0]); i++)
        {
            // if this item in the array is a match, and either it is the first match, or it is longer than the match currently stored in result_tok
            if (
                matches[i].has_value() &&
                (
                    !result_tok.has_value() ||
                    matches[i]->get_contents().length() > result_tok->get_contents().length()
                )
            ) {
                result_tok = matches[i];
            }
        }
        
        return result_tok;
    }
}