#include <iostream>
#include <math.hpp>

Math::Collection A;
Math::Collection B;
Math::Collection C;

int main() {
    A.Set({0, 10, 55, 30, 1});
    B.Set({10, 55, 1});
    C.Set({5, 7});
    A.Print();
    std::cout << A.Min() << "\n";
    std::cout << A.Max() << "\n";
    std::cout << A.Avg() << "\n";
    std::cout << A.Sum() << "\n";
}
