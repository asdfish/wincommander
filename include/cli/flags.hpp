#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <getopt.h>

#include <vector>
#include <string>
#include <unordered_map>

class Flag;

class Flags {
public:
  std::unordered_map<char, Flag> flags;

  Flags(std::unordered_map<char, Flag>&& flags);
  void parse(int argc, char* argv[]);
  void print_documentation(size_t padding) const;

private:
  std::string get_option_string(void) const;
  std::vector<option> get_options(void) const;
};

#endif // FLAGS_HPP
