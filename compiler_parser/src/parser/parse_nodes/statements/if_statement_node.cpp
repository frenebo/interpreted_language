#include <string>
#include <iostream>
#include <vector>

#include "tokens.hpp"
#include "statement_nodes.hpp"
#include "parser/parse_nodes/node_parse_exception.hpp"
#include "parser/parse_nodes/parse_nodes.hpp"

namespace parse_nodes::statement_nodes
{
    IfStatementNode::IfStatementNode(
        parse_nodes::compound_expression::CompoundExpNode if_condition,
        parse_nodes::StatementSequenceNode if_body,
        unsigned long token_count)
    : _if_condition(if_condition),
    _if_body(new parse_nodes::StatementSequenceNode(if_body)),
    _token_count(token_count)
    {
    }

    IfStatementNode::IfStatementNode(const IfStatementNode & old_node) noexcept
    : _if_condition(old_node.if_condition()),
    _if_body(new parse_nodes::StatementSequenceNode(old_node.if_body())),
    _token_count(old_node.token_count())
    {
    }

    IfStatementNode::~IfStatementNode() noexcept
    {
        delete _if_body;
    }

    // @QUESTION @TODO should this copy or assign???
    IfStatementNode& IfStatementNode::operator=(const IfStatementNode & other) noexcept
    {
        delete this->_if_body; // necessary???
        this->_if_condition = other.if_condition();
        this->_if_body = new parse_nodes::StatementSequenceNode(other.if_body());
        this->_token_count = other.token_count();

        return *this;
    }

    parse_nodes::compound_expression::CompoundExpNode IfStatementNode::if_condition() const
    {
        return _if_condition;
    }

    parse_nodes::StatementSequenceNode IfStatementNode::if_body() const
    {
        return *_if_body;
    }

    unsigned long IfStatementNode::token_count() const
    {
        return _token_count;
    }

    void IfStatementNode::print_node(unsigned int indentation_level) const
    {
        std::cout << std::string(indentation_level, ' ') << "If Statement Node\n";
    }

    bool IfStatementNode::look_ahead(TokenType next_token_type)
    {
        return next_token_type == TokenType::IF_KEYWORD;
    }

    IfStatementNode IfStatementNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        // first token should be the if keyword
        TokenType expect_if_keyword = toks[start_idx].get_type();
        
        if (expect_if_keyword != TokenType::IF_KEYWORD)
        {
            throw NodeParseException(
                "Expected " + token_type_to_string(TokenType::IF_KEYWORD) +
                ", got " + token_type_to_string(expect_if_keyword)
            );
        }

        TokenType expect_open_parenthesis = toks[start_idx + 1].get_type();
        if (expect_open_parenthesis != TokenType::OPEN_PAREN_CH)
        {
            throw NodeParseException(
                "Expected " + token_type_to_string(TokenType::OPEN_PAREN_CH) +
                " after if keyword, got " + token_type_to_string(expect_open_parenthesis)
            );
        }

        // if token and open parenthesis token
        unsigned long consumed = 2;

        parse_nodes::compound_expression::CompoundExpNode if_condition =
            parse_nodes::compound_expression::CompoundExpNode::parse_tokens(toks, start_idx + consumed);
        
        consumed += if_condition.token_count();

        // should be close parenthesis
        TokenType expect_close_parenthesis = toks[start_idx + consumed].get_type();
        if (expect_close_parenthesis != TokenType::CLOSE_PAREN_CH)
        {
            throw NodeParseException(
                "Expected " + token_type_to_string(TokenType::CLOSE_PAREN_CH) +
                ", got " + token_type_to_string(expect_close_parenthesis)
            );
        }

        // for close parenthesis
        consumed++;

        // should be open brace
        TokenType expect_open_brace_type = toks[start_idx + consumed].get_type();
        if (expect_open_brace_type != TokenType::OPEN_BRACE_CH)
        {
            throw NodeParseException(
                "Expected " + token_type_to_string(TokenType::OPEN_BRACE_CH) +
                " after if statement condition, got " + token_type_to_string(expect_open_brace_type)
            );
        }

        // for open brace
        consumed++;

        parse_nodes::StatementSequenceNode if_body =
            parse_nodes::StatementSequenceNode::parse_tokens(toks, start_idx + consumed, TokenType::CLOSE_BRACE_CH);
        
        consumed += if_body.token_count();

        // should be close brace
        TokenType expect_close_brace_type = toks[start_idx + consumed].get_type();
        if (expect_close_brace_type != TokenType::CLOSE_BRACE_CH)
        {
            throw NodeParseException(
                "Expected " + token_type_to_string(TokenType::CLOSE_BRACE_CH) +
                " after if statement body, got " + token_type_to_string(expect_close_brace_type)
            );
        }

        // for close brace
        consumed++;

        return IfStatementNode(
            if_condition,
            if_body,
            consumed
        );
    }
}
