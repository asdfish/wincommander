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
};

#endif // defined(FLAGS_DEF) || defined(ALL_DEF)

#endif // FLAGS_HPP
