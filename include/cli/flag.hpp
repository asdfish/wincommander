#ifndef FLAG_HPP
#define FLAG_HPP

class Flag;
enum FlagArgumentType {
  ARGUMENT_NONE     = 0,
  ARGUMENT_REQUIRED = 1,
  ARGUMENT_OPTIONAL = 2,
};

#ifdef FLAG_DEF

#define ARGUMENT_VALIDATOR_DEF
#include <argument_validator.hpp>

#include <getopt.h>

#include <format>
#include <string>
#include <optional>

class Flag {
public:
  FlagArgumentType argument_type;
  std::string documentation;
  std::string id;

  std::optional<ArgumentValidator> argument_validator;

  bool set;
  std::optional<std::string> argument;

  Flag(
    FlagArgumentType input_argument_type,
    std::string&& input_documentation,
    std::string&& input_id,
    std::optional<ArgumentValidator>&& input_argument_validator = std::nullopt
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

#endif // FLAG_DEF

#endif
