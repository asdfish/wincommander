#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <cli/argument/parser/base.hpp>

class CommandParser : public ArgumentParserBase {
public:
  std::string name;

  CommandParser(
    std::string&& input_name,
    ArgumentType input_argument_type,
    std::optional<ArgumentValidator>&& input_argument_validator
  );
  void parse(int argc, const char* argv[]);
};

#endif // COMMAND_PARSER_HPP
