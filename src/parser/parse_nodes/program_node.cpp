#include "node_parse_exception.hpp"
#include "parse_nodes.hpp"
#include <vector>
#include "tokens.hpp"
#include <optional>
#include <iostream>
#include <string>
#include "statements/statement_nodes.hpp"

namespace parse_nodes
{
    ProgramNode ProgramNode::parse_tokens(const std::vector<Token> & toks, unsigned long start_idx)
    {
        std::vector<statement_nodes::StatementNode> statement_nodes;

        long tokens_consumed = 0;

        while (toks[start_idx + tokens_consumed].get_type() != TokenType::END_OF_INPUT)
        {
            try 
            {
                statement_nodes::StatementNode statement_node =
                    statement_nodes::StatementNode::parse_tokens(toks, start_idx + tokens_consumed);

                tokens_consumed += statement_node.token_count();
                statement_nodes.push_back(statement_node);
            }
            catch (const NodeParseException & ex)
            {
                throw NodeParseException(std::string(ex.what()));
            }
        }
        
        return ProgramNode(statement_nodes, tokens_consumed);
    }
    
    ProgramNode::ProgramNode(std::vector<statement_nodes::StatementNode> statement_nodes, unsigned long token_count)
    {
        this->_statement_nodes = statement_nodes;
        this->_token_count = token_count;
    }

    const std::vector<statement_nodes::StatementNode> & ProgramNode::statement_nodes()
    {
        return this->_statement_nodes;
    }

    unsigned long ProgramNode::token_count()
    {
        return this->_token_count;
    }

    void ProgramNode::print_node(unsigned int indentation_level)
    {
        std::cout << std::string(indentation_level, ' ') << "Program Node:\n";

        for (statement_nodes::StatementNode expression_node : this->_statement_nodes)
        {
            expression_node.print_node(indentation_level + 1);
        }
    }
}