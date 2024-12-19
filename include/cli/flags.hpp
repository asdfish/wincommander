#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <getopt.h>

#include <std/vector.hpp>
#include <std/string.hpp>
#include <std/unordered_map.hpp>

class FlagParser;

class Flags {
public:
  std::unordered_map<char, FlagParser> flags;

  Flags(std::unordered_map<char, FlagParser>&& flags);
  void parse(int argc, char* argv[]);
  void print_documentation(size_t padding) const;

private:
  std::string get_option_string(void) const;
  std::vector<option> get_options(void) const;
};

#endif // FLAGS_HPP
