#define FLAGS_DEF
#include <cli/flags.hpp>

#include <utility>

Flags::Flags(std::unordered_map<char, Flag>&& input_flags):
  flags(std::move(input_flags)) {}
