#include <iostream>
 #include <cstring>

 int main(int argc, char *argv[]) {

   std::cout << "This program transforms string to upper case" << std::endl;

   const size_t kMaxLength = 100;
   char inputString[kMaxLength]{}, outputString[kMaxLength]{};

   std::cout << "Enter a string (max " << kMaxLength << " symbols): ";
   std::cin >> inputString;

   size_t length = strlen(inputString);

   if (length > kMaxLength) {
     std::cout << "Error! Too long string. Exiting." << std::endl;
     return 0;
   }

   std::cout << "Input string:  " << inputString << std::endl;

   const char kDiff = 'A'-'a';

   for (size_t i = 0; i < length; i++) {
     outputString[i] = inputString[i];
     if (inputString[i] >= 'a' && inputString[i] <= 'z') {
       outputString[i] += kDiff;
     }
   }

   std::cout << "Output string: " << outputString << std::endl;

   return 0;
 }
