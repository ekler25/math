#include <iostream>
#include <math.hpp>

Math::Interval A = Math::Interval(0, 10, false, false);
Math::Interval B = Math::Interval(3, 13, false, false);
Math::Interval C = Math::Interval(-Math::INF, Math::INF, false, false);

int main() {
    std::cout << A.Contains(B) << "\n";
    A.Print();
    B.Print();
    C.Print();
}
