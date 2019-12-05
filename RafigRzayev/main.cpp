#include <cmath>
#include <iostream>

// Function prototypes
void intro_text();
void get_input(int &, const char);
void calculate_result(const int &, const int &, const int &);
void quit_check(bool &);

const int INPUT_MIN_VAL{-20724},INPUT_MAX_VAL{20724};   // Range for a, b, c input
const int D_COEF{4};    // Coefficient in discriminant formula
const double X_COEF{2}; // Coefficient in x formula

int main() {
  intro_text();
  bool CONTINUE_SOLVER = true;
  int a{0}, b{0}, c{0};
  // main loop
  while (CONTINUE_SOLVER) {
    get_input(a, 'A');
    get_input(b, 'B');
    get_input(c, 'C');
    calculate_result(a, b, c);
    quit_check(CONTINUE_SOLVER);
  }
}

// Program start text
void intro_text() {
  std::cout << "*****************************************************************************" << std::endl;
  std::cout << "\n\t\t\tQuadratic Equation Solver\t\t\t\n" << std::endl;
  std::cout << "Quadratic equation has the form: ax2 + bx + c = 0" << std::endl;
  std::cout << "You will need to provide a, b, and c coefficients to solve the "
               "equation.\n"
            << std::endl;
}

// Get input from user until it is within the range
void get_input(int &coefficient, const char coef_name) {
  while (true) {
    std::cout << "Enter coefficient " << coef_name << " in range[" << INPUT_MIN_VAL << ", " << INPUT_MAX_VAL << "]:";
    std::cin >> coefficient;
    if (coefficient >= INPUT_MIN_VAL && coefficient <= INPUT_MAX_VAL) {
      break; // break if input is within range, else keep asking for correct input
    }
    std::cout << "Out of range, please try again" << std::endl;
  }
}

// Calculate D and x values
void calculate_result(const int &a, const int &b, const int &c) {
  int D{b * b - D_COEF * a * c};
  std::cout << "D = " << D << std::endl;
  if (D < 0 || (D == 0 && a == 0 && c != 0)) {
    std::cout << "There is no solution" << std::endl;
  } else if (D == 0 && a == 0 && c == 0) {
    std::cout << "Equation is true for all x" << std::endl;
  } else if (D > 0 && a == 0) {
    double x{static_cast<double>(-c) / b};
    std::cout << "x = " << x << std::endl;
  } else {
    double x1{(-b - sqrt(D)) / (X_COEF * a)};
    double x2{(-b + sqrt(D)) / (X_COEF * a)};
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
  }
}

// Prompt user until "Y" / "N" is entered correctly to exit/continue solver
void quit_check(bool &bool_var) {
  char temp;
  while (true) {
    std::cout << "Would you like to continue? (Y/N)";
    std::cin >> temp;
    if (temp == 'Y' || temp == 'y') {
      bool_var = true;
      break;
    } else if (temp == 'n' || temp == 'N') {
      bool_var = false;
      std::cout << "GOODBYE" << std::endl;
      break;
    } else {
      std::cout << "Unknown command, please try again..." << std::endl;
    }
  }
}
