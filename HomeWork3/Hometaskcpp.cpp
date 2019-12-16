#include <iostream>

 void print_array(unsigned int * const parray, const size_t size) {
   std::cout << '[';
   for (size_t i = 0; i < size; i++){
     std::cout << *(parray + i);
     if (i != (size - 1)) {
       std::cout << ", ";
     }
   }
   std::cout << ']' << std::endl;
 }

 void insert_element (unsigned int * const parray, const size_t size, const unsigned int element) {
   size_t largerElementPos{};

   // Iterate all array and find position where larger elements start
   size_t i{};
   while ( (*(parray + i) < element) && 
           (*(parray + i) != 0) && 
           (i < size) ) {
     ++i;
     largerElementPos = i;
   }

   // Move all larger elements to the right
   for (size_t i = size-1; i > largerElementPos; i--) {
     if (i > 0) {
       *(parray + i) = *(parray + i - 1);
     }
   }

   *(parray + largerElementPos) = element;
 }

 int main(int argc, char **argv) {
   const size_t kArraySize = 20;
   unsigned int array[kArraySize]{};

   std::cout << "This program inserts elements in array" << std::endl;

   // print_array();

   for (size_t i = 0; i < kArraySize; i++) {
     unsigned int element;
     do {
       std::cout << "Insert element (" << i << "), greater than 0: ";
       std::cin >> element;
     } while (element == 0);

     insert_element(array, kArraySize, element);

     print_array(array, kArraySize);  
   }

   return 0;
 }