#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <utility>

class Command {
public:
  std::string name;

  constexpr Command(std::string&& name):
    name(std::move(name)) {}
};

#endif // COMMAND_HPP
