#include <cmath>
#include <iostream>

// Program start text
void intro_text() {
  std::cout <<
      R"(
*****************************************************************************
                          Quadratic Equation Solver                                                    
Quadratic equation has the form: ax2 + bx + c = 0                            
You will need to provide a, b, and c coefficients to solve the equation.      

)";
}

// Get input from the user until it is within the range
int get_input(const char coef_name) {
  const int INPUT_MIN_VAL{-20724}, INPUT_MAX_VAL{20724}; // Range for a, b, c input
  while (true) {
    int coefficient{};
    std::cout << "Enter coefficient " << coef_name << " in range[" << INPUT_MIN_VAL << ", " << INPUT_MAX_VAL << "]:";
    std::cin >> coefficient;
    if (coefficient >= INPUT_MIN_VAL && coefficient <= INPUT_MAX_VAL) {
      return coefficient; // return if input is within the range, else keep asking for correct input
    }
    std::cout << "Out of range, please try again" << std::endl;
  }
}

// Calculate D and x values
void calculate_result(const int a, const int b, const int c) {
  const int D_COEF{4};
  auto D{b * b - D_COEF * a * c};
  std::cout << "D = " << D << std::endl;

  if (D < 0 || (D == 0 && a == 0 && c != 0)) {
    std::cout << "There is no solution" << std::endl;
    return;
  }
  if (D == 0 && a == 0 && c == 0) {
    std::cout << "Equation is true for all x" << std::endl;
    return;
  }
  if (D > 0 && a == 0) {
    auto x{static_cast<double>(-c) / b};
    std::cout << "x = " << x << std::endl;
    return;
  }
  const int X_COEF{2};
  auto x1{(-b - sqrt(D)) / (X_COEF * a)};
  auto x2{(-b + sqrt(D)) / (X_COEF * a)};
  std::cout << "x1 = " << x1 << std::endl;
  std::cout << "x2 = " << x2 << std::endl;
}

// Prompt user until "Y" / "N" is entered correctly to exit/continue solver
bool quit_check() {
  while (true) {
    char quit_input;
    std::cout << "Would you like to continue? (Y/N)";
    std::cin >> quit_input;
    switch (quit_input) {
    case 'Y':
    case 'y':
      return false;
    case 'n':
    case 'N':
      std::cout << "Goodbye" << std::endl;
      return true;
    default:
      std::cout << "Unknown command, please try again..." << std::endl;
    }
  }
}

int main() {
  intro_text();
  bool quit_solver = false;
  while (!quit_solver) {
    int a{get_input('A')};
    int b{get_input('B')};
    int c{get_input('C')};
    calculate_result(a, b, c);
    quit_solver = quit_check();
  }
}
