#include <iostream>
 #include <cstring>

 int main(int argc, char* argv[]) {
   std::cout << "This program reverses string that user inputs" << std::endl;

   if (argc != 2) {
     std::cout << "Wrong number of parameters" << std::endl;
     std::cout << "Usage: ./reverse <string>" << std::endl;
     return 0;
   }

   const size_t kMaxLength = 100;
   const size_t kLength = strlen(argv[1]);

   if (kLength > kMaxLength) {
     std::cout << "Error! Input string should be less than " << kMaxLength << " characters" << std::endl;
     return 0;
   }

   char reversed[kMaxLength + 1]{};    // string should contain termination zero (+1 byte)

   // Reverse the string
   // Reduce number of iterations by copying 2 chars at a time (from start and end)
   for (size_t i = 0; i <= kLength / 2; i++) {
     *(reversed + i) = *(argv[1] + kLength - i - 1);
     *(reversed + kLength - i - 1) = *(argv[1] + i);
   }

   std::cout << "Initial string:  " << argv[1] << std::endl;
   std::cout << "Reversed string: " << reversed << std::endl;

   return 0;
 }
