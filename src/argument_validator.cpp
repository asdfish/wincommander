#include <argument_validator.hpp>

#include <utility>

ArgumentValidator::ArgumentValidator(void):
  validator(VALIDATOR_ANY) {}
ArgumentValidator::ArgumentValidator(std::string&& input_name):
  validator(VALIDATOR_NAME),
  name(std::move(input_name)) {}
ArgumentValidator::ArgumentValidator(std::vector<std::string>&& input_options):
  validator(VALIDATOR_OPTIONS),
  options(std::move(input_options)) {}
ArgumentValidator::ArgumentValidator(std::regex&& input_regex):
  validator(VALIDATOR_REGEX),
  regex(std::move(input_regex)) {}
bool ArgumentValidator::validate(const char* argument) {
  return (get_validator())(argument);
}

std::function<bool(const char*)> ArgumentValidator::get_validator(void) const {
  switch(validator) {
    case VALIDATOR_NAME:
      return [&] (const char* argument) {
        return name == argument;
      };
    case VALIDATOR_OPTIONS:
      return [&] (const char* argument) {
        for(const std::string& option : options)
        if(argument == option)
          return true;
        return false;
      };
    case VALIDATOR_REGEX:
      return [&] (const char* argument) {
        return std::regex_match(argument, regex);
      };
    case VALIDATOR_ANY:
    default:
      return [] (const char*) {
        return true;
      };
  }
}
