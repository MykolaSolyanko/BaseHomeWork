#include <iostream>

 int main(int argc, char *argv[]) {
   std::cout << "This progtam checks char array and outputs digit from it" << std::endl;

   const size_t kMaxArrayLen = 100;
   char array[kMaxArrayLen]{};

   std::cout << "Enter string (max " << kMaxArrayLen << " elements): ";
   std::cin >> array;

   std::cout << "Digits in array: ";
   bool isNumFound = false;
   char *ptr = array;

   while (*ptr != '\0') {
     if (*ptr >= '0' && *ptr <= '9') {
       if (!isNumFound) {
         isNumFound = true;
         std::cout << '[';
       }
       std::cout << *ptr << ", ";
     }
     ++ptr;
   }
   if (isNumFound) {
     std::cout << "\b\b]";
   } else {
     std::cout << "none";
   }

   std::cout << std::endl;

   return 0;
 }
