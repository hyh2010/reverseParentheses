#ifndef TOPDOWNPARSER_HPP
#define TOPDOWNPARSER_HPP
#include <string>
#include <exception>
#include "OutputStrategyInterface.hpp"
class syntaxErrorExcpetion : public std::exception { };
void topDownParser (OutputStrategyInterface & outputStrategy, std::string::const_iterator & it, const std::string::const_iterator & end);
void print_syntax_error(const std::string::const_iterator & it, const std::string & s);
#endif
