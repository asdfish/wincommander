#include <cli/command.hpp>

#include <std/utility.hpp>

Command::Command(
  std::string&& input_name,
  ArgumentValidator&& input_argument_validator
):
  name(std::move(input_name)),
  argument_validator(std::move(input_argument_validator)) {}
