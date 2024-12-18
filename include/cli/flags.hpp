#ifndef FLAGS_HPP
#define FLAGS_HPP

class Flags;

#if defined(FLAGS_DEF) || defined(ALL_DEF)

#define FLAG_DEF
#include <cli/flag.hpp>

#include <unordered_map>

class Flags {
public:
  std::unordered_map<char, Flag> flags;

  Flags(std::unordered_map<char, Flag>&& flags);
  void parse(int argc, char* argv[]);

private:
  std::string get_option_string(void) const;
  std::vector<option> get_options(void) const;
};

#endif // defined(FLAGS_DEF) || defined(ALL_DEF)

#endif // FLAGS_HPP
