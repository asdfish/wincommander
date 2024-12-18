#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command;

#ifdef COMMAND_DEF

#include <string>
#include <utility>

class Command {
public:
  std::string name;

  constexpr Command(std::string&& name):
    name(std::move(name));
};

#endif // COMMAND_DEF

#endif // COMMAND_HPP
