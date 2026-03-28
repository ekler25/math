#include <iostream>
#include <math.hpp>

int Math::Interval::Size() {
    return this->Max - this->Min;
}

bool Math::Interval::Contains(double Num) {
    return 
        (this->ClosedLeft ? 
            (this->Min < Num) : 
            (this->Min <= Num)) && 
        (this->ClosedRight ? 
            (this->Max > Num) : 
            (this->Max >= Num));
}

bool Math::Interval::Contains(Interval& Intv) {
    return 
        (Intv.ClosedLeft ? 
            (Intv.Min >= this->Min) : 
            (Intv.Min > this->Min)) && 
        (Intv.ClosedRight ? 
            (Intv.Max <= this->Max) : 
            (Intv.Max < this->Max));
}

void Math::Interval::Print(bool Color) {
    if (Color)
        std::cout << "\x1b[0m(\x1b[96m" <<
            this->Min << "\x1b[0m, \x1b[96m" <<
            this->Max << "\x1b[0m)\n";
    else
        std::cout << "(" <<
            this->Min << ", " <<
            this->Max << ")\n";
}
