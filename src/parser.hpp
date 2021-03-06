#ifndef PARSER_HPP_
#define PARSER_HPP_


#include <string>
#include <iostream>
#include <vector>
#include <utility>

#include "token.hpp"
#include "binary_expr_tree.hpp"
#include "error.hpp"
#include "utilities.hpp"


// Parses basic math operations for a calculator application.
// The grammar is given by:
// <expr>             ::=  <value> | <value> <binary-operator> <expr> <EOL>
// <value>            ::= <integer> | <double> | <unary-operator> <value>
// <EOL>              ::= "\n"
// <unary-operator>   ::= "-"
// <binary-operator>  ::= "+" | "-" | "*" | "/" | "^"
// <integer>          ::= <digit> | <digit> <integer>
// <double>           ::= <integer> "." <integer>
// <digit>            ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
class parser {

  public:

    typedef std::string::const_iterator SIT;

    parser() {}

    parser(const bool _debug) : m_debug(_debug) {}

    ~parser() {}

    // Parse and tokenize an expression and construct and return a binary
    // expression tree.
    binary_expr_tree parse(const std::string& _expression);

    // Starting from the beginning of a value (digit or decimal point) parse the
    // entire integer or floating point number. Return a token containing the
    // new number
    const token
    parse_value(const std::string& _expression, SIT& _sit)
    const;

    // Returns true if the character pointed to by _sit is a digit or a decimal
    // point signalling the beginning of a floating point number.
    const bool is_value(const SIT& _sit) const;

  private:

    std::vector<token> m_tokens;

    bool m_debug{false};
};


#endif
