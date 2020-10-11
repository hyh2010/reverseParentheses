#include "reverseParentheses.h"

#include <utility>
#include <string>
#include <stack>

#include "OutputStrategyInterface.hpp"
#include "topDownParser.hpp"

class ReverseParenthesesStrategy : public OutputStrategyInterface
{
public:
    virtual ~ReverseParenthesesStrategy() = default;
    ReverseParenthesesStrategy():
    _outputString(),
    _bufferStack(),
    _reverse(false)
    {
    }

    ReverseParenthesesStrategy(const ReverseParenthesesStrategy &) = default;
    ReverseParenthesesStrategy & operator = (const ReverseParenthesesStrategy &) = default;
    ReverseParenthesesStrategy(ReverseParenthesesStrategy &&) = default;
    ReverseParenthesesStrategy & operator = (ReverseParenthesesStrategy &&) = default;

    std::string outputString() const { return _outputString; }

    virtual void left_parenthesis() override
    {
        push_output_string();
        _reverse = !_reverse;
    }
    virtual void right_parenthesis() override
    {
        _reverse = !_reverse;
        pop_output_string();
    }
    virtual void character(const char c) override
    {
        write_to_outputString(std::string(1, c));
    }

private:
    void push_output_string()
    {
        _bufferStack.push(_outputString);
        _outputString.clear();
    }

    void pop_output_string()
    {
        std::string tempBuffer = std::move(_outputString);
        _outputString = _bufferStack.top();
        write_to_outputString(tempBuffer);
        _bufferStack.pop();
    }

    void write_to_outputString (const std::string & buffer)
    {
        // prepend to output string in reverse mode, append in forward mode
        if (_reverse)
        {
            _outputString = buffer + _outputString;
        }
        else
        {
            _outputString += buffer;
        }
    }

    std::string _outputString;
    std::stack<std::string> _bufferStack;
    bool _reverse;
};

std::string
reverseParentheses(const std::string & s)
{
    ReverseParenthesesStrategy strategy;
    
    auto it = s.begin();

    try
    { 
        topDownParser(strategy, it, s.end());
    }
    catch (const syntaxErrorExcpetion &)
    {
        print_syntax_error(it, s);
        return std::string();
    }

    return strategy.outputString();
}

