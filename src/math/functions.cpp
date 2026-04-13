#include <math.hpp>

double Math::abs(double Num) {
    return Num < 0 ? -Num : Num;
}

double Math::exp(double Num) {
    double Term = 1.0;
    double Sum = 1.0;

    for (int i = 1; i < 100; i++) {
        Term *= Num / i;
        Sum += Term;

        if (Term < 1e-15 && Term > -1e-15) break;
    }

    return Sum;
}
