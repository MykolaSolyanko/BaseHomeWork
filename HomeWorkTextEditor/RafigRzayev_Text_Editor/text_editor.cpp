#include "text_editor.hpp"

//  ******* Show Text Editor Data *******
void display(TextEditor &Editor) {
  std::cout << Editor.buffer << std::endl;
  std::cout << "cursor: " << Editor.cursor << std::endl;
  std::cout << "selection start: " << Editor.selection_start;
  std::cout << " selection count: " << Editor.selection_count << std::endl;
}

//  ******* Ask user to type a text into Text Editor *******
void type(TextEditor &Editor) {
  std::cout << "type ";
  const size_t INPUT_SIZE = 100;
  char user_input[INPUT_SIZE];
  std::cin >> user_input;
  clear_istream();
  if (Editor.buffer.insert(user_input, Editor.cursor)) {
    Editor.cursor += calculate_length(user_input);
  }
}

//  ******* Ask user to move cursor to the left *******
void move_left(TextEditor &Editor) {
  std::cout << "move left ";
  size_t user_input;
  std::cin >> user_input;
  clear_istream();
  Editor.selection_count = 0;
  Editor.selection_start = 0;
  if (user_input > Editor.cursor) {
    Editor.cursor = 0;
    std::cout << "Moved to left end\n";
    return;
  }
  Editor.cursor -= user_input;
  std::cout << "Moved left\n";
}

//  ******* Ask user to move cursor to the right *******
void move_right(TextEditor &Editor) {
  std::cout << "move right ";
  size_t user_input;
  std::cin >> user_input;
  clear_istream();
  const size_t BUFFER_LENGTH = Editor.buffer.get_length();
  Editor.selection_count = 0;
  Editor.selection_start = 0;
  if (user_input + Editor.cursor > BUFFER_LENGTH) {
    Editor.cursor = BUFFER_LENGTH;
    std::cout << "Moved to right end\n";
    return;
  }
  Editor.cursor += user_input;
  std::cout << "Moved right\n";
}

//  ******* Ask user to make a selection *******
void select_(TextEditor &Editor) {
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

//  ******* Copy the selection *******
void copy(TextEditor &Editor) {
  if (Editor.selection_count == 0) {
    std::cout << "Need to select first\n";
    return;
  }
  Editor.copy_buffer = Editor.buffer.get_substring(Editor.selection_start,
                                                   Editor.selection_count);
  if (Editor.copy_buffer.is_empty()) {
    std::cout << "Unable to copy. Try again\n";
    return;
  }
  std::cout << Editor.copy_buffer << " has been copied\n";
}

//  ******* Paste the copied text *******
void paste(TextEditor &Editor) {
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

//  ******* Cut the selection *******
void cut(TextEditor &Editor) {
  if (Editor.selection_count == 0) {
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

//  ******* Calculate text length *******
size_t calculate_length(const char *TEXT) {
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

//  ******* Clear std::cin *******
void clear_istream() {
  std::cin.clear();
  std::cin.ignore();
}