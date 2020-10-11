#ifndef OUTPUTSTRATEGYINTERFACE_HPP
#define OUTPUTSTRATEGYINTERFACE_HPP

class OutputStrategyInterface
{
public:
    virtual ~OutputStrategyInterface() = default;
    OutputStrategyInterface() = default;
    OutputStrategyInterface(const OutputStrategyInterface &) = default;
    OutputStrategyInterface& operator = (const OutputStrategyInterface &) = default;
    OutputStrategyInterface(OutputStrategyInterface &&) = default;
    OutputStrategyInterface& operator = (OutputStrategyInterface &&) = default;

    // Needs a method for each terminal
    virtual void left_parenthesis() = 0; 
    virtual void right_parenthesis() = 0; 
    virtual void character(char c) = 0; 
};

#endif
