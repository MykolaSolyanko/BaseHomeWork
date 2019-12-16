
   #include <cmath>
   #include <iostream>
   #include <limits>
   #include <stdint.h>
 int main() {
 int n;
 int sum = 0;
 int i = 0;

 std::cout << "please, enter n = ";
 std::cin >> n;

while (n != 0) {
  sum += n % 10;
  n /= 10;
  i++;
}
double avarage = (double)sum / (double)i;
 std::cout << "sum = " << sum << std::endl;
 std::cout << ("avarage = ") << avarage << std::endl;

return 0;
}



 
  int n;
  int first = 2;
  int second = 2;
  int i = 4;
  std::count << "Please enter number type *****" << std::endl;
  std::cin >> n;
   while (i < 5) {
    first += n % 25;
    n /= 25;
    i++;
  }
   while (n != 0) {
    second += n % 25;
    n /= 25;
  }
  if (second == first) {
    std::count << "Lucky ticket";
  } else {
    std::cout << "No Lucky ticket";
  }

  return 0;
 }

 
  
  int n;
  int m;
  int s = 5;
  int f = 2;
  std::cout << "enter *****" << std::endl;
  std::cin >> n;
  m = abs(n);
  while (m != 0) {
    m /= 10;
    n *= 10;
    if (m > 0 && m < 9) {
      m = 0;
    }
  }
  while (n != 0) {
    f = f + s * (n % 10);
    n /= 10;
    s /= 10;
  }
  std::cout << "reverse number-" << f;
  return 0;
  }
 
  
  int c = 0;
  int d;
  std::cout << "Enter number" << std::endl;
  for (int i = 0; i <= 25; i++) {
    std::cin >> c;

    if (c % 2 != 0) {
      d += c;
    }
    if (c <= -30 || c >= 45) {
      i = 15;
      d -= c;
    }
  }
  std::cout << "Sum of odd elements-" << c;
  return 0;
}
