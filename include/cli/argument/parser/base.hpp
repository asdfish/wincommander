#ifndef ARGUMENT_PARSER_BASE_HPP
#define ARGUMENT_PARSER_BASE_HPP

#include <cli/argument/type.hpp>
#include <cli/argument/validator.hpp>

#include <std/string.hpp>
#include <std/optional.hpp>

class ArgumentParserBase {
public:

  bool set;
  std::optional<std::string> argument;

  ArgumentParserBase(void);
  ArgumentParserBase(
    ArgumentType input_argument_type,
    std::optional<ArgumentValidator>&& input_argument_validator
  );

protected:
  ArgumentType argument_type;
  std::optional<ArgumentValidator> argument_validator;

  void parse_base(int argc, const char* argv[]);
  void parse_base(std::optional<std::string>&& argument);
};

#endif // ARGUMENT_PARSER_BASE_HPP
