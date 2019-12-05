/**
 * Home Work #1. ITEA C++ Basic Courses.
 *
 * This program calcuates roots of quadratic equation.
 *
 * Author:  Andrii Samozvon
 * Date:    04 Dec 2019
 */

#include <cmath>
#include <iostream>
#include <limits>

const int kTwo = 2;
const int kFour = 4;

int main(int argc, char **argv) {
  float fA, fB, fC;
  float fX1, fX2;

  std::cout << "This program solves quadratic equation" << std::endl;
  std::cout << "General view of the equation: a*x^2 + b*x + c = 0" << std::endl;

  // Ask user to enter coefitients of the equation
  // Continue until we get valid input (only numerical)
  std::cout << "Enter a: ";
  while (!(std::cin >> fA)) {
    std::cout << "Error! Please, enter a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  std::cout << "Enter b: ";
  while (!(std::cin >> fB)) {
    std::cout << "Error! Please, enter a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  std::cout << "Enter c: ";
  while (!(std::cin >> fC)) {
    std::cout << "Error! Please, enter a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  // Print out user's equiation
  std::cout << "Your equation: " << fA << "*x^2 + " << fB << "*x + " << fC
            << " = 0" << std::endl;

  // Calculate discriminant
  float fD = (fB * fB) - (static_cast<float>(kFour) * fA * fC);

  // Try to find valid roots
  if (fD < 0.0) {
    std::cout << "Equation has no real roots." << std::endl;
  } else if (fA == 0.0) {
    std::cout << "Equation is not quadratic." << std::endl;
  } else {
    std::cout << "Equation has 2 roots: ";
    fX1 = (-fB + sqrtf(fD)) / (static_cast<float>(kTwo) * fA);
    fX2 = (-fB - sqrtf(fD)) / (static_cast<float>(kTwo) * fA);
    std::cout << fX1 << ", " << fX2 << std::endl;
  }

  return 0;
}
