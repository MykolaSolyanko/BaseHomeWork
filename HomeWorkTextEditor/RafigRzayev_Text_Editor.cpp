#include <functional>
#include <iostream>

/******************************************** STRING CLASS ********************************************/

class String {
public:
  // DEFAULT CONSTRUCTOR
  String() {
    string = new char[MAX_LENGTH + 1];
    *string = '\0';
  }
  // COPY CONSTRUCTOR
  String(const String &RIGHT_STRING) : String() {
    update(RIGHT_STRING.string, string, true);
  }
  // COPY ASSIGNMENT
  void operator=(const String &RIGHT_STRING) {
    update(RIGHT_STRING.string, string, true);
  }
  // DESTRUCTOR
  ~String() { delete[] string; }
  // GET LENGTH OF THE STRING
  size_t get_length() const { return get_length(string); }
  // CHECK FOR EMPTINESS
  bool is_empty() const { return *string == '\0'; }
  // CLEAR WHOLE STRING
  void clear() { erase(0, get_length()); }
  // INSERT STRING INTO STRING
  bool insert(const String &TEMP, const size_t INSERT_LOCATION) {
    return insert(TEMP.string, INSERT_LOCATION);
  }
  // INSERT TEXT INTO STRING
  bool insert(const char *, const size_t);
  // ERASE SUBSTRING
  bool erase(const size_t, const size_t);
  // GET SUBSTIRNG
  String get_substring(const size_t, const size_t) const;
  // Overload std::cout
  friend std::ostream &operator<<(std::ostream &, String &);

private:
  size_t get_length(const char *) const;
  void update(const char *, char *, const bool);
  const size_t MAX_LENGTH = 20;
  char *string = nullptr;
};

// CALCULATE TEXT LENGTH
size_t String::get_length(const char *TEXT) const {
  if (TEXT == nullptr) {
    return 0;
  }
  char *it = const_cast<char *>(TEXT);
  size_t length{0};
  while (*it++ != '\0') {
    ++length;
  }
  return length;
}

// COPY VALUES FROM SRC. TO DEST.
void String::update(const char *SRC, char *dst, const bool INSERT_NULL = true) {
  if (SRC == nullptr || dst == nullptr) {
    return;
  }
  const size_t SRC_LENGTH = get_length(SRC);
  for (size_t i{0}; i < SRC_LENGTH; ++i) {
    *(dst + i) = *(SRC + i);
  }
  if (INSERT_NULL) {
    *(dst + SRC_LENGTH) = '\0';
  }
}

// INSERT TEXT INTO STRING
bool String::insert(const char *TEXT, const size_t INSERT_LOCATION) {
  // Exception 1
  if (TEXT == nullptr) {
    std::cout << "insert() - Exception: nullptr passed as argument\n";
    return false;
  }
  const size_t TEXT_LENGTH = get_length(TEXT);
  const size_t STRING_LENGTH = get_length();
  // Exception 2
  if (INSERT_LOCATION > STRING_LENGTH) {
    std::cout << "insert() - Exception: Location exceeds current string size\n";
    return false;
  }
  // Exception 3
  if (TEXT_LENGTH + STRING_LENGTH > MAX_LENGTH) {
    std::cout << "insert() - Exception: Adding text will result in overflow\n";
    return false;
  }
  // Special case of first time addition
  if (is_empty()) {
    update(TEXT, string);
    return true;
  }
  // Create a copy of string
  char *string_copy = new char[STRING_LENGTH];
  update(string, string_copy);
  // Shift string to create space for new text
  update(string_copy + INSERT_LOCATION, string + INSERT_LOCATION + TEXT_LENGTH);
  delete[] string_copy;
  // Insert values
  update(TEXT, string + INSERT_LOCATION, false);
  return true;
}

// DELETE SUBSTRING
bool String::erase(const size_t START, const size_t COUNT) {
  if (COUNT == 0) {
    std::cout << "erase() - Exception: Count is 0\n";
    return false;
  }
  const size_t STRING_LENGTH = get_length();
  if (START + COUNT > STRING_LENGTH) {
    std::cout << "erase() - Exception: Selection exceeds current string size\n";
    return false;
  }
  update(string + START + COUNT, string + START);
  return true;
}

// GET SUBSTRING
String String::get_substring(const size_t START, const size_t COUNT) const {
  String temp;
  // Exception 1
  if (COUNT == 0) {
    std::cout << "get_substring() - Exception: Count is 0\n";
    return temp;
  }
  const size_t STRING_LENGTH = get_length();
  // Exception 2
  if (START + COUNT > STRING_LENGTH) {
    std::cout << "get_substring() - Exception: Selection exceeds current "
                 "string size\n";
    return temp;
  }
  char *sub_string = new char[COUNT + 1];
  for (size_t i{0}; i < COUNT; ++i) {
    sub_string[i] = string[START + i];
  }
  sub_string[COUNT] = '\0';
  temp.insert(sub_string, 0);
  delete[] sub_string;
  return temp;
}

std::ostream &operator<<(std::ostream &output, String &s) {
  output << s.string;
  return output;
}

/******************************************** TEXT EDITOR FUNCTIONS ******************************************/

size_t calculate_length(const char *TEXT) {
  if (TEXT == nullptr) {
    return 0;
  }
  char *it = const_cast<char *>(TEXT);
  size_t length{0};
  while (*it++ != '\0') {
    ++length;
  }
  return length;
}

void clear_istream() {
  std::cin.clear();
  std::cin.ignore();
}

struct TextEditor {
  String buffer;
  String copy_buffer;
  size_t cursor = 0;
  size_t selection_start = 0;
  size_t selection_count = 0;
};

// Show Text Editor Data
void display(TextEditor &Editor) {
  std::cout << "--------------------\n";
  std::cout << Editor.buffer << std::endl;
  std::cout << "cursor: " << Editor.cursor << std::endl;
  std::cout << "selection start: " << Editor.selection_start;
  std::cout << " selection count: " << Editor.selection_count << std::endl;
}

// Ask user to type a text into Text Editor
void type(TextEditor &Editor) {
  std::cout << "--------------------\n";
  std::cout << "type ";
  const size_t INPUT_SIZE = 100;
  char user_input[INPUT_SIZE];
  std::cin >> user_input;
  clear_istream();
  if (Editor.buffer.insert(user_input, Editor.cursor)) {
    Editor.cursor += calculate_length(user_input);
  }
}

// Ask user to move cursor to the left
void move_left(TextEditor &Editor) {
  std::cout << "--------------------\n";
  std::cout << "move left ";
  size_t user_input;
  std::cin >> user_input;
  clear_istream();
  if (user_input > Editor.cursor) {
    Editor.cursor = 0;
    std::cout << "Moved to left end\n";
    return;
  }
  Editor.cursor -= user_input;
  std::cout << "Moved left\n";
}

// Ask user to move cursor to the right
void move_right(TextEditor &Editor) {
  std::cout << "--------------------\n";
  std::cout << "move right ";
  size_t user_input;
  std::cin >> user_input;
  clear_istream();
  const size_t BUFFER_LENGTH = Editor.buffer.get_length();
  if (user_input + Editor.cursor > BUFFER_LENGTH) {
    Editor.cursor = BUFFER_LENGTH;
    std::cout << "Moved to right end\n";
    return;
  }
  Editor.cursor += user_input;
  std::cout << "Moved right\n";
}

// Ask user to make a selection
void select_(TextEditor &Editor) {
  std::cout << "--------------------\n";
  std::cout << "select ";
  size_t start{}, count{};
  std::cin >> start >> count;
  clear_istream();
  const size_t BUFFER_LENGTH = Editor.buffer.get_length();
  if (start + count > BUFFER_LENGTH || count == 0) {
    std::cout << "Invalid selection\n";
    return;
  }
  Editor.selection_start = start;
  Editor.selection_count = count;
  std::cout << "Selection successfull\n";
}

// Copy the selection
void copy(TextEditor &Editor) {
  std::cout << "--------------------\n";
  if (Editor.selection_count == 0) {
    std::cout << "Need to select first\n";
    return;
  }
  Editor.copy_buffer = Editor.buffer.get_substring(Editor.selection_start,
                                                   Editor.selection_count);
  std::cout << Editor.copy_buffer << " has been copied\n";
}

// Paste the copied text
void paste(TextEditor &Editor) {
  std::cout << "--------------------\n";
  if (Editor.copy_buffer.is_empty()) {
    std::cout << "Need to copy first\n";
    return;
  }

  if (Editor.buffer.insert(Editor.copy_buffer, Editor.cursor)) {
    Editor.cursor += Editor.copy_buffer.get_length();
    Editor.copy_buffer.clear();
    Editor.selection_count = 0;
    Editor.selection_start = 0;
    std::cout << "Paste succesfull\n";
  }
}

// Cut the selection
void cut(TextEditor &Editor) {
  if (Editor.selection_count == 0) {
    std::cout << "--------------------\n";
    std::cout << "Need to select first\n";
    return;
  }
  copy(Editor);
  if (Editor.copy_buffer.is_empty()) {
    return;
  }

  size_t &start = Editor.selection_start;
  size_t &count = Editor.selection_count;
  size_t &cursor = Editor.cursor;

  if (Editor.buffer.erase(start, count)) {
    if (cursor > start) {
      cursor = (cursor <= start + count ? start : cursor - count);
    }
    count = start = 0;
    std::cout << "Cut successful\n";
  }
}

enum OPTIONS {
  QUIT,
  TYPE,
  DISPLAY,
  MOVE_LEFT,
  MOVE_RIGHT,
  SELECT,
  COPY,
  CUT,
  PASTE
};

std::function<void(TextEditor &)> user_commands[PASTE]{
    type, display, move_left, move_right, select_, copy, cut, paste};

void menu() {
  std::cout << "--------------------\n";
  std::cout << TYPE << " - TYPE\n";
  std::cout << DISPLAY << " - DISPLAY\n";
  std::cout << MOVE_LEFT << " - MOVE LEFT\n";
  std::cout << MOVE_RIGHT << " - MOVE RIGHT\n";
  std::cout << SELECT << " - SELECT\n";
  std::cout << COPY << " - COPY\n";
  std::cout << CUT << " - CUT\n";
  std::cout << PASTE << " - PASTE\n";
  std::cout << QUIT << " - QUIT\n";
  std::cout << "Command: ";
}

int main() {
  TextEditor Editor;
  while (true) {
    menu();
    size_t user_input;
    std::cin >> user_input;
    clear_istream();
    if (user_input == QUIT) {
      std::cout << "Quitting\n";
      return 0;
    }
    if (user_input > PASTE) {
      std::cout << "Unknown command\n";
      continue;
    }
    user_commands[user_input - 1](Editor);
  }
  return 0;
}