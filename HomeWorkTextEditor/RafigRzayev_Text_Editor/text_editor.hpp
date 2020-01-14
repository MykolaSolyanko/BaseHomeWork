#pragma once

#include "string_.hpp"

struct TextEditor {
  String buffer{};
  String copy_buffer{};
  size_t cursor{0};
  size_t selection_start{0};
  size_t selection_count{0};
};

// Show Text Editor Data
void display(TextEditor &Editor);
// Ask user to type a text into Text Editor
void type(TextEditor &Editor);
// Ask user to move cursor to the left
void move_left(TextEditor &Editor);
// Ask user to move cursor to the right
void move_right(TextEditor &Editor);
// Ask user to make a selection
void select_(TextEditor &Editor);
// Copy the selection
void copy(TextEditor &Editor);
// Paste the copied text
void paste(TextEditor &Editor);
// Cut the selection
void cut(TextEditor &Editor);
// Calculate text length
size_t calculate_length(const char *TEXT);
// Clear std::cin
void clear_istream();