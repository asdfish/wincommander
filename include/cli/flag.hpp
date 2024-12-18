#ifndef FLAG_HPP
#define FLAG_HPP

class Flag;
enum FlagArgumentType {
  ARGUMENT_NONE     = 0,
  ARGUMENT_REQUIRED = 1,
  ARGUMENT_OPTIONAL = 2,
};

#if defined(FLAG_DEF) || defined(ALL_DEF)

#define ARGUMENT_VALIDATOR_DEF
#include <argument_validator.hpp>

#include <getopt.h>

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
    std::optional<ArgumentValidator>&& input_argument_validator
  );
  void parse(std::optional<std::string>&& argument = std::nullopt);
  constexpr option to_option(void) const {
    return option { id.c_str(), argument_type, nullptr, 0 };
  }
};

#endif // defined(FLAG_DEF) || defined(ALL_DEF)

#endif
