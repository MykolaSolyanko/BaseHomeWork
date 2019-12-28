#include <iostream>

struct Buffer
{
    const static size_t BUFFER_LENGTH = 10;
    char text[BUFFER_LENGTH]{};
    char copy_buffer[BUFFER_LENGTH]{};
    size_t cursor_index{get_length(text)};
    size_t selection_start{}, selection_end{};

    // show contents of the buffer and cursor location
    void show()
    {
        std::cout << "----------------------------\n";
        std::cout << "Buffer: " << text << std::endl;
        std::cout << "Cursor: " << cursor_index << std::endl;
        std::cout << "Copied text: " << copy_buffer << std::endl;
    }

    // returns length of text by finding null terminator
    size_t get_length(char array[])
    {
        for (size_t i{0}; i < BUFFER_LENGTH; ++i)
        {
            if (array[i] == '\0')
            {
                return i;
            }
        }
        std::cout << "get_length() - Unable to find null terminator" << std::endl;
        return BUFFER_LENGTH;
    }

    // move cursor to the left
    void move_left()
    {
        std::cout << "----------------------------\n";
        std::cout << "move left ";
        size_t num;
        std::cin >> num;
        if (num > cursor_index)
        {
            std::cout << "Moved to 0. Can't go further" << std::endl;
            cursor_index = 0;
            return;
        }
        cursor_index -= num;
    }

    // move cursor to the right
    void move_right()
    {
        std::cout << "----------------------------\n";
        std::cout << "move right ";
        size_t num;
        std::cin >> num;
        const size_t text_length{get_length(text)};
        if (num + cursor_index > text_length)
        {
            std::cout << "Moved to end. Can't go further" << std::endl;
            cursor_index = text_length;
            return;
        }
        cursor_index += num;
    }

    // select text from buffer
    void select()
    {
        std::cout << "----------------------------\n";
        std::cout << "select ";
        size_t start{}, count{};
        std::cin >> start >> count;
        if (count == 0)
        {
            std::cout << "Couldn't select anything" << std::endl;
            return;
        }
        if (start + count > get_length(text))
        {
            std::cout << "Selection larger than text. Try again" << std::endl;
            return;
        }
        selection_start = start;
        selection_end = start + count;
        std::cout << "Selection: ";
        for (size_t i{selection_start}; i < selection_end; ++i)
        {
            std::cout << text[i];
        }
        std::cout << std::endl;
    }

    // copy selected text
    void copy()
    {
        std::cout << "----------------------------\n";
        if (selection_start == selection_end)
        {
            std::cout << "Nothing to copy. Make selection first" << std::endl;
            return;
        }
        int j{};
        for (size_t i{selection_start}; i < selection_end; ++i)
        {
            copy_buffer[j++] = text[i];
        }
        copy_buffer[j] = '\0';
        std::cout << "\"" << copy_buffer << "\" was copied succesfully" << std::endl;
    }

    // type text into buffer
    void print()
    {
        std::cout << "----------------------------\n";
        std::cout << "print ";
        char temp[BUFFER_LENGTH];
        std::cin >> temp;
        const size_t temp_length = get_length(temp);
        const size_t text_length = get_length(text);
        // entered text + buffer text should not exceed buffer size
        if (text_length + temp_length >= BUFFER_LENGTH)
        {
            std::cout << "Can't print. Bufer will overflow" << std::endl;
            return;
        }
        // shift text to right and create space for user input
        for (int i = text_length; i >= (int)cursor_index; --i)
        {
            text[i + temp_length] = text[i];
        }
        // copy values from user input to buffer
        for (size_t i{0}; i < temp_length; ++i)
        {
            text[cursor_index + i] = temp[i];
        }
        // increment cursor by size of user input
        cursor_index += temp_length;
    }

    // paste copied text into buffer. same code as print but without user input.
    void paste()
    {
        std::cout << "----------------------------\n";
        const size_t copy_length = get_length(copy_buffer);
        if (copy_length == 0)
        {
            std::cout << "Nothing to paste. Copy or Cut before pasting" << std::endl;
            return;
        }
        const size_t text_length = get_length(text);
        // copied text + buffer text should not exceed buffer size
        if (text_length + copy_length >= BUFFER_LENGTH)
        {
            std::cout << "Can't paste. Not enough space" << std::endl;
            return;
        }
        // shift text to right and create space for copied text
        for (int i = text_length; i >= (int)cursor_index; --i)
        {
            text[i + copy_length] = text[i];
        }
        // copy values from copy_buffer to buffer
        for (size_t i{0}; i < copy_length; ++i)
        {
            text[cursor_index + i] = copy_buffer[i];
        }
        // update cursor location
        cursor_index += copy_length;
        // reset copy buffer
        std::cout << copy_buffer << " has been pasted successfully " << std::endl;
        copy_buffer[0] = '\0';
        // reset selection
        selection_start = 0;
        selection_end = 0;
    }

    // deletes selected content from the string
    void delete_selection()
    {
        std::cout << "----------------------------\n";
        if (selection_start == selection_end)
        {
            std::cout << "Nothing to delete. Make selection first" << std::endl;
            return;
        }
        const size_t shift = selection_end - selection_start;
        const int text_length = static_cast<int>(get_length(text));
        for (int i = selection_end; i <= text_length; ++i)
        {
            text[i - shift] = text[i];
        }
        std::cout << "Selected text has been deleted" << std::endl;
        // update cursor location and reset selection
        if (cursor_index < selection_start)
        {
            selection_start = 0;
            selection_end = 0;
            return;
        }
        if (cursor_index >= selection_start && cursor_index < selection_end)
        {
            cursor_index = selection_start - 1;
            selection_start = 0;
            selection_end = 0;
            return;
        }
        if (cursor_index >= selection_end)
        {
            cursor_index -= shift;
            selection_start = 0;
            selection_end = 0;
            return;
        }
    }
    void cut()
    {
        if (selection_start == selection_end)
        {
            std::cout << "----------------------------\n";
            std::cout << "Nothing to cut. Make selection first" << std::endl;
            return;
        }
        copy();
        delete_selection();
    }
};

enum COMMANDS
{
    QUIT,
    SHOW,
    PRINT,
    MOVE_LEFT,
    MOVE_RIGHT,
    SELECT,
    COPY,
    PASTE,
    DELETE,
    CUT,
    DEFAULT,
};

void menu_text()
{
    std::cout << "----------------------------\n";
    std::cout << SHOW << " - show \t" << COPY << " - copy\n";
    std::cout << PRINT << " - print \t" << PASTE << " - paste\n";
    std::cout << MOVE_LEFT << " - move left \t" << DELETE << " - delete\n";
    std::cout << MOVE_RIGHT << " - move right \t" << CUT << " - cut\n";
    std::cout << SELECT << " - select \t" << QUIT << " - quit\n";
    std::cout << "Enter your command: ";
}

int main()
{
    Buffer buffer;
    while (true)
    {
        menu_text();
        size_t user_input;
        std::cin >> user_input;
        switch (user_input)
        {
        case QUIT:
            std::cout << "----------------------------\n";
            std::cout << "Quitting" << std::endl;
            return 0;
        case SHOW:
            buffer.show();
            break;
        case PRINT:
            buffer.print();
            break;
        case MOVE_LEFT:
            buffer.move_left();
            break;
        case MOVE_RIGHT:
            buffer.move_right();
            break;
        case SELECT:
            buffer.select();
            break;
        case COPY:
            buffer.copy();
            break;
        case PASTE:
            buffer.paste();
            break;
        case DELETE:
            buffer.delete_selection();
            break;
        case CUT:
            buffer.cut();
            break;
        default:
            std::cout << "----------------------------\n";
            std::cout << "Unknown command, please try again." << std::endl;
        }
    }
    return 0;
}
