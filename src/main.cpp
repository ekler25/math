#include <iostream>
#include <math.hpp>

Math::Interval A = Math::Interval(0, 10, false, false);

int main() {
    std::cout << A.Contains(-5) << "\n";
    std::cout << A.Contains(0) << "\n";
    std::cout << A.Contains(5) << "\n";
    std::cout << A.Contains(10) << "\n";
    std::cout << A.Contains(20) << "\n";
}