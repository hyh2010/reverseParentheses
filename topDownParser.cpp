#include "topDownParser.hpp"

#include <iostream>
#include <string>
#include <exception>

static const syntaxErrorExcpetion syntaxError;

static void 
E (OutputStrategyInterface & outputStrategy, std::string::const_iterator & it, const std::string::const_iterator & end);

static bool inline
is_valid_character(const char c)
{
    return c != '(' && c != ')';
}

static bool inline
in_first_F(const std::string::const_iterator & it, const std::string::const_iterator & end)
{
    return it != end && (*it == '(' || is_valid_character(*it));
}

static void
F (OutputStrategyInterface & outputStrategy, std::string::const_iterator & it, const std::string::const_iterator & end)
{
    if (*it == '(')
    {   // F->(E)
        outputStrategy.left_parenthesis();
        ++it; // consume the '(' token
        E (outputStrategy, it, end);
        if (*it == ')')
        {
            outputStrategy.right_parenthesis();
            ++it; // consume the ')' token
        }
        else
        {
            throw syntaxError;
        }
    }
    else
    {   // F->character
        outputStrategy.character(*it);
        ++it; // consume the character
    }
}

static void
E_prime (OutputStrategyInterface & outputStrategy, std::string::const_iterator & it, const std::string::const_iterator & end)
{
    while (in_first_F(it, end))
    {   // E' -> FE'
        F (outputStrategy, it, end);
    }

    // E' -> epislon
}

static void
E (OutputStrategyInterface & outputStrategy, std::string::const_iterator & it, const std::string::const_iterator & end)
{
    if (in_first_F(it, end))
    {   // E -> FE'
        F (outputStrategy, it, end);
        E_prime (outputStrategy, it, end);
    }
    else
    {
        throw syntaxError;
    }
}

void
topDownParser (OutputStrategyInterface & outputStrategy, std::string::const_iterator & it, const std::string::const_iterator & end)
{
    // S -> E
    E(outputStrategy, it, end);

    if (it != end)
    {
        throw syntaxError;
    }
}

void
print_syntax_error(const std::string::const_iterator & it, const std::string & s)
{
    using namespace std;
    cout << s << endl;
    const size_t position = it - s.begin();
    cout << std::string(position, ' ' ) << "|" << endl;
    cout << "syntax error at position " << position << endl;
}
