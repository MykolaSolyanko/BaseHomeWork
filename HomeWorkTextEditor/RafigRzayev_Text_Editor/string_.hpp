#pragma once

#include <iostream>

class String {
public:
  // User-defined constructor
  String(bool EMPTY = false);
  // Copy constructor
  String(const String &RIGHT_STRING);
  // Copy assignment
  void operator=(const String &RIGHT_STRING);
  // Destructor
  ~String();
  // Get length_
  size_t get_length() const;
  // Check emptiness
  bool is_empty() const;
  // Clear whole string
  void clear();
  // Insert string into string
  bool insert(const String &STRING, const size_t INSERT_LOCATION);
  // Insert text into string
  bool insert(const char *TEXT, const size_t INSERT_LOCATION);
  // Delete substring
  bool erase(const size_t START, const size_t COUNT);
  // Get substring
  String get_substring(const size_t START, const size_t COUNT) const;
  // Print string
  friend std::ostream &operator<<(std::ostream &, String &);

private:
  // Calculate text length
  size_t get_length(const char *TEXT) const;
  // Copy values from source to destination
  void copy(const char *SRC, char *dst, const bool INSERT_NULL = true);

  const size_t MAX_LENGTH_{20};
  size_t length_{0};
  char *string_{nullptr};
};