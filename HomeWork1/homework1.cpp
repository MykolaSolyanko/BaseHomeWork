#include <iostream>
#include <cmath>

int main()
{
    std::cout << "This is an example of a program for calculating square roots with the following data:"<<std::endl;
        std::cout << "a=2\n" << "b=8\n" << "c=4\n";
        int ka = 2;
        int kb = 8;
        int kc = 4;
        int kd = kb * kb - 4 * ka * kc;
        double kx1 = (-kb + sqrt(kd)) / (2 * ka);
        double kx2 = (-kb - sqrt(kd)) / (2 * ka);
            std::cout << "First root=" << kx1 << std::endl;
        std::cout << "Second root=" << kx2 << std::endl;
    std::cout << "This program calculates the roots of a quadratic equation of type:\n" <<"a*x^2+b*x+c \n"<< std::endl;
    int a;
    int b;
    int c;
    std::cout << "Enter a" << std::endl;
    std::cin >> a;
    while (a == 0||a>255||a<-255) {
        std::cout << "Not correct number \n"<<"Enter a"<<std::endl;
        std::cin >> a;
    }
    std::cout <<"Enter b"<<std::endl;
    std::cin >> b;
    std::cout << "Enter c" << std::endl;
    std::cin >> c;
    int d;
    d = b * b - 4 * a * c;
    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
            std::cout << "First root \n"<< x1<<std::endl ;
            double x2 = (-b - sqrt(d)) / (2 * a);
            std::cout << "Second root \n"<<x2;
    }
    return 0;
}
