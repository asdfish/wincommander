#ifndef FLAG_PARSER_HPP
#define FLAG_PARSER_HPP

#include <cli/argument/parser/base.hpp>

#include <getopt.h>

class FlagParser : public ArgumentParserBase {
public:
  std::string documentation;
  std::string id;

  FlagParser(
    std::string&& input_documentation,
    std::string&& input_id,
    ArgumentType argument_type,
    std::optional<ArgumentValidator>&& argument_validator = std::nullopt
  );

  void parse(std::optional<std::string>&& argument = std::nullopt);
  constexpr std::optional<char> get_option_string_end(void) const {
    switch(argument_type) {
      case ARGUMENT_OPTIONAL:
      case ARGUMENT_REQUIRED:
        return std::optional<char>(':');
      case ARGUMENT_NONE:
      default:
        return std::nullopt;
    }
  }
  constexpr option get_option(void) const {
    return option { id.c_str(), argument_type, nullptr, 0 };
  }
};

#endif // FLAG_PARSER_HPP
