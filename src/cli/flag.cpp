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

  if(argument.has_value()) {
    if(!argument_validator.value().validate(argument.value().c_str())) {
      if(argument_type == ARGUMENT_REQUIRED)
        throw std::format("Invalid argument {} for flag {}", argument.value(), id);
      else if(argument_type == ARGUMENT_OPTIONAL)
        move_argument = false;
    }
  } else if(argument_type == ARGUMENT_REQUIRED)
    throw std::format("Missing argument for flag {}", id);
  else if(argument_type == ARGUMENT_OPTIONAL)
    move_argument = false;

  if(move_argument)
    this->argument = std::move(std::optional<std::string>(argument.value()));
  else
    this->argument = std::nullopt;

  set = true;
}
