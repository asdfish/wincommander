#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <cli/argument_validator.hpp>

#include <std/string.hpp>

class Command {
public:
  std::string name;
  ArgumentValidator argument_validator;

  Command(
    std::string&& input_name,
    ArgumentValidator&& input_argument_validator
  );
};

#endif // COMMAND_HPP
