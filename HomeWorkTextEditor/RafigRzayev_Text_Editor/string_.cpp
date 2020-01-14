#include "string_.hpp"

//  ************** User-defined constructor ************** 
String::String(bool EMPTY) {
  if (EMPTY) {
    string_ = new char{'\0'};
    return;
  }
  string_ = new char[MAX_LENGTH_ + 1]{'\0'};
}

//  ************** Copy constructor ************** 
String::String(const String &RIGHT_STRING) : String() {
  copy(RIGHT_STRING.string_, string_);
  length_ = RIGHT_STRING.length_;
}

//  ************** Copy assignment ************** 
void String::operator=(const String &RIGHT_STRING) {
  copy(RIGHT_STRING.string_, string_);
  length_ = RIGHT_STRING.length_;
}

//  ************** Destructor ************** 
String::~String() { delete[] string_; }

//  ************** Get length_  ************** 
size_t String::get_length() const { return length_; }

//  ************** Check emptiness ************** 
bool String::is_empty() const { return *string_ == '\0'; }

//  ************** Clear whole string ************** 
void String::clear() { erase(0, length_); }

//  ************** Insert string into string ************** 
bool String::insert(const String &STRING, const size_t INSERT_LOCATION) {
  return insert(STRING.string_, INSERT_LOCATION);
}

//  ************** Insert text into string ************** 
bool String::insert(const char *TEXT, const size_t INSERT_LOCATION) {
  // Exception 1
  if (TEXT == nullptr) {
    std::cout << "insert() - Exception: nullptr passed as argument\n";
    return false;
  }
  const size_t TEXT_LENGTH = get_length(TEXT);
  // Exception 2
  if (INSERT_LOCATION > length_) {
    std::cout << "insert() - Exception: Location exceeds current string size\n";
    return false;
  }
  // Exception 3
  if (TEXT_LENGTH + length_ > MAX_LENGTH_) {
    std::cout << "insert() - Exception: Adding text will result in overflow\n";
    return false;
  }
  // Special case of first time addition
  if (is_empty()) {
    copy(TEXT, string_);
    length_ = TEXT_LENGTH;
    return true;
  }
  // Create a copy of string
  char *string_copy = new char[length_];
  copy(string_, string_copy);
  // Shift string to create space for new text
  copy(string_copy + INSERT_LOCATION, string_ + INSERT_LOCATION + TEXT_LENGTH);
  delete[] string_copy;
  // Insert values
  copy(TEXT, string_ + INSERT_LOCATION, false);
  length_ += TEXT_LENGTH;
  return true;
}

//  ************** Delete substring ************** 
bool String::erase(const size_t START, const size_t COUNT) {
  if (COUNT == 0) {
    std::cout << "erase() - Exception: Count is 0\n";
    return false;
  }
  if (START + COUNT > length_) {
    std::cout << "erase() - Exception: Selection exceeds current string size\n";
    return false;
  }
  copy(string_ + START + COUNT, string_ + START);
  length_ -= COUNT;
  return true;
}

//  ************** Get substring ************** 
String String::get_substring(const size_t START, const size_t COUNT) const {
  String empty{true};
  // Exception 1
  if (COUNT == 0) {
    std::cout << "get_substring() - Exception: Count is 0\n";
    return empty;
  }
  // Exception 2
  if (START + COUNT > length_) {
    std::cout << "get_substring() - Exception: Selection exceeds current "
                 "string size\n";
    return empty;
  }
  String temp;
  char *sub_string = new char[COUNT + 1];
  for (size_t i{0}; i < COUNT; ++i) {
    sub_string[i] = string_[START + i];
  }
  sub_string[COUNT] = '\0';
  temp.insert(sub_string, 0);
  delete[] sub_string;
  return temp;
}

//  ************** Print string ************** 
std::ostream &operator<<(std::ostream &output, String &s) {
  output << s.string_;
  return output;
}

//  ************** Calculate text length ************** 
size_t String::get_length(const char *TEXT) const {
  if (TEXT == nullptr) {
    return 0;
  }
  const char *it = TEXT;
  size_t length{0};
  while (*it++ != '\0') {
    ++length;
  }
  return length;
}

//   ************** Copy values from source to destination ************** 
void String::copy(const char *SRC, char *dst, const bool INSERT_NULL) {
  if (SRC == nullptr || dst == nullptr) {
    return;
  }
  const size_t SRC_LENGTH = get_length(SRC);
  const char *const end = SRC + SRC_LENGTH;
  const char *begin = SRC;
  while (begin != end) {
    *dst++ = *begin++;
  }
  if (INSERT_NULL) {
    *dst = '\0';
  }
}