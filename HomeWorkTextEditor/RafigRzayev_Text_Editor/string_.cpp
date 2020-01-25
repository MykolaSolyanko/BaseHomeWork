#include "string_.hpp"

//  ************** User-defined constructor 1 ************** 
String::String(const size_t SIZE) {
  if(SIZE > MAX_LENGTH_) {
    std::cout << "Exception: Size is larger than MAX_LENGTH_\n";
    return;
  }
  init("", SIZE);
}

//  ************** User-defined constructor 2 ************** 
String::String(const char *TEXT) {
  // Empty text case
  if(TEXT == nullptr) {
    std::cout << "Exception: Input text is nullptr\n";
    return;
  }
  const size_t TEXT_LENGTH = get_length(TEXT);
  // Overflow case
  if(TEXT_LENGTH > MAX_LENGTH_) {
    std::cout << "Exception: Text length is larger than MAX_LENGTH_\n";
    return;
  }
  init(TEXT, TEXT_LENGTH);
}

//  ************** Copy constructor ************** 
String::String(const String &RHS) {
  // Empty RHS string case
  if(RHS.is_empty()) {
    return;
  }
  init(RHS.string_, RHS.length_);
}

//  ************** Copy assignment ************** 
String& String::operator=(const String &RHS) {
  // Self-assignment case
  if(this == &RHS) {
    return *this;
  }
  this->clear();
  // Empty RHS string case
  if(RHS.is_empty()) {
    return *this;
  }
  init(RHS.string_, RHS.length_);
  return *this;
}

//  ************** Destructor ************** 
String::~String() { delete[] string_; }

//  ************** Get length_  ************** 
size_t String::get_length() const { return length_; }

//  ************** Check emptiness ************** 
bool String::is_empty() const { return length_ == 0; }

//  ************** Clear whole string ************** 
void String::clear() {
  delete [] string_;
  string_ = nullptr;
  length_ = 0;
}

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
    init(TEXT, TEXT_LENGTH);
    return true;
  }
  // Create a new string with increased memory and original content
  length_ += TEXT_LENGTH;
  char *new_string = new char[length_ + 1];
  copy(string_, new_string);
  // Insert TEXT values
  copy(TEXT, new_string + INSERT_LOCATION);
  // Insert erased values
  copy(string_ + INSERT_LOCATION, new_string + INSERT_LOCATION + TEXT_LENGTH);
  // Update string_ with new string and delete old data
  delete[] string_;
  string_ = new_string;
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
  // Copy values after START + COUNT to values after START
  copy(string_ + START + COUNT, string_ + START);
  // Create new string with less memory and new contents
  length_ -= COUNT;
  char *new_string = new char[length_ + 1];
  copy(string_, new_string);
  // Update string_ with new string and delete old data
  delete [] string_;
  string_ = new_string;
  return true;
}

//  ************** Get substring ************** 
String String::get_substring(const size_t START, const size_t COUNT) const {
  String empty;
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
  String temp(COUNT);
  for (size_t i{0}; i < COUNT; ++i) {
    temp.string_[i] = string_[START + i];
  }
  temp.string_[COUNT] = '\0';
  return temp;
}

//  ************** Print string ************** 
std::ostream &operator<<(std::ostream &output, String &s) {
  if(s.is_empty()) {
    return output;
  }
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
void String::copy(const char *SRC, char *dst) {
  if (SRC == nullptr || dst == nullptr) {
    return;
  }
  const size_t SRC_LENGTH = get_length(SRC);
  const char *const end = SRC + SRC_LENGTH;
  const char *begin = SRC;
  while (begin != end) {
    *dst++ = *begin++;
  }
  *dst = '\0';
}


void String::init(const char *TEXT, const size_t TEXT_LENGTH) {
  length_ = TEXT_LENGTH;
  string_ = new char[length_ + 1];
  copy(TEXT, string_);
}