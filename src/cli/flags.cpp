#define FLAGS_DEF
#include <cli/flags.hpp>

#include <utility>

Flags::Flags(std::unordered_map<char, Flag>&& input_flags):
  flags(std::move(input_flags)) {}
void Flags::parse(int argc, char* argv[]) {
  std::string option_string = get_option_string();
  std::vector<option> options = get_options();

  int option_character = -1;
  int option_index = 0;
  while((option_character = getopt_long(argc, argv, option_string.c_str(), options.data(), &option_index)) != -1)
    if(flags.contains(option_character)) {
      if(optarg)
        flags.at(option_character).parse(std::string(optarg));
      else
        flags.at(option_character).parse();
    }
}

std::string Flags::get_option_string(void) const {
  std::string output;
  output.reserve(flags.size() * 2);

  for(const auto& flag : flags) {
    output += flag.first;
    std::optional<char> end = flag.second.get_option_string_end();
    if(end.has_value())
      output += end.value();
  }

  return output;
}
std::vector<option> Flags::get_options(void) const {
  std::vector<option> output;
  output.reserve(flags.size() + 1);

  for(const auto& flag : flags) {
    output.push_back(flag.second.get_option());
    output.back().val = flag.first;
  }

  return output;
}