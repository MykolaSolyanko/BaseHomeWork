# Homework -2 
 
 Домашнее задание №2

 Вичесление средних арифметических вычеслений

  #include <cmath>
  #include <stdint.h>
  #include <limits>

     Задание №1
    void _and_arith_mean() {
    uint10_t number, digits{0};
   std::cout << "Введите число [" << std::numeric_limits<uint10_t>::min() << ".." << std::numeric_limits<uint10_t>::max() << "]: ";
   std::cin >> number;
   uint20_t sum{0};
   do {
     ++digits;
     sum += (number % 10);
     number /= 10;
   } while (number);
   float arith_mean = (float)sum / digits;
   std::cout << "Sum of digits: " << sum << std::endl;
   std::cout << "Арифметическое значение " << arith_mean << std::endl;
 }

 Задание №2
   void  happy_ticket () {
    int ticket;
    do {
     std::cout << "Ввести номер билета от [100000..999999]: ";
     std::cin >> билет;
     } while (билет < 100000|| билет > 999999);
     const int left_sum  =  (ticket / 100000)    + ((ticket / 10000) % 10) + ((ticket / 1000) % 10);
   const int right_sum = ((ticket / 100) % 10) + ((ticket / 10) % 10)    +  (ticket % 10);
   if (left_sum == right_sum) {
     std::cout << "Вы вииграли счастливий билет  :)" << std::endl;
   } else {
     std::cout << "Your have a regular ticket! :(" << std::endl;
   }
 Задание №3
 void reverse_numbers() {
   std::cout << "Enter number in range ["
             << std::numeric_limits<int16_t>::min() << ".."
             << std::numeric_limits<int16_t>::max() << "]: ";
   int16_t number;
   std::cin >> number;
   int32_t reverse_number{0};
   do {
     reverse_number *= 10;
     reverse_number += number % 10;
     number /= 10;
   } while (number != 0);
   std::cout << reverse_number << std::endl;
 }

 Задание №4
 void sum_of_even() {
   size_t amount;
   do {
     std::cout << "Введите число от [1..50]: ";
     std::cin >> amount;
   } while (amount == 0 || amount > 50);

   int sum;
   for (size_t i = 1; i <= amount; i++) {
     int number;
     do {
       std::cout << i << ": ";
       std::cin >> number;
     } while (number < -60 || number > 90);
     if (number%2) {
       sum += number;
     }
   }
   std::cout << "Сумма четных чисел: " << sum << std::endl;
 }



   
 
