#include <iostream>
#include <math.hpp>

bool Math::Interval::Contains(double Num) {
    return 
        (this->ClosedLeft ? 
            (this->Min < Num) : 
            (this->Min <= Num)) && 
        (this->ClosedRight ? 
            (this->Max > Num) : 
            (this->Max >= Num));
}