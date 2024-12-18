#ifndef ARGUMENT_VALIDATOR_HPP
#define ARGUMENT_VALIDATOR_HPP

class ArgumentValidator;
enum ArgumentValidatorType {
  VALIDATOR_ANY,
  VALIDATOR_NAME,
  VALIDATOR_OPTIONS,
  VALIDATOR_REGEX,
};

#ifdef ARGUMENT_VALIDATOR_DEF

#include <functional>
#include <regex>
#include <string>
#include <vector>

class ArgumentValidator {
public:
  ArgumentValidator(void);
  ArgumentValidator(std::string&& input_name);
  ArgumentValidator(std::vector<std::string>&& input_options);
  ArgumentValidator(std::regex&& input_regex);
  
  bool validate(const char* argument);

private:
  ArgumentValidatorType validator;
  std::string name;
  std::vector<std::string> options;
  std::regex regex;

  std::function<bool(const char*)> get_validator(void) const;
};

#endif // ARGUMENT_VALIDATOR_DEF

#endif // ARGUMENT_VALIDATOR_HPP
