#define FLAG_DEF
#include <cli/flag.hpp>

#include <format>
#include <utility>

Flag::Flag(
  FlagArgumentType input_argument_type,
  std::string&& input_documentation,
  std::string&& input_id,
  std::optional<ArgumentValidator>&& input_argument_validator
):
  argument_type(input_argument_type),
  documentation(std::move(input_documentation)),
  id(std::move(input_id)),
  argument_validator(std::move(input_argument_validator)),
  set(false) {}

void Flag::parse(std::optional<std::string>&& argument) {
  bool move_argument = true;
  #define FAIL(ERROR) \
    if(argument_type == ARGUMENT_REQUIRED) \
      throw ERROR; \
    else if(argument_type == ARGUMENT_OPTIONAL) \
      move_argument = false;

  if(argument_type != ARGUMENT_NONE) {
    if(argument.has_value()) {
      if(argument_validator.has_value()) {
        if(!argument_validator.value().validate(argument.value().c_str())) {
          FAIL(std::format("Invalid argument {} for flag {}", argument.value(), id))
        }
      } else FAIL(std::format("Missing argument parser for flag {}", id))
    } else FAIL(std::format("Missing argument for flag {}", id))
  }

  if(move_argument && argument.has_value())
    this->argument = std::optional<std::string>(std::move(argument.value()));
  else
    this->argument = std::nullopt;

  set = true;
}
