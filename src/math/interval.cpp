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

bool Math::Interval::Intersects(Interval& Intv) {
    return
        !(this->ClosedRight ?
            (this->Max < Intv.Min) :
            (this->Max <= Intv.Min)) &&
        !(this->ClosedLeft ?
            (this->Min > Intv.Max) :
            (this->Min >= Intv.Max));
}

bool Math::Interval::Disjoined(Interval& Intv) {
    return
        (this->ClosedRight ?
            (this->Max < Intv.Min) :
            (this->Max <= Intv.Min)) ||
        (this->ClosedLeft ?
            (this->Min > Intv.Max) :
            (this->Min >= Intv.Max));
}

bool Math::Interval::Adjacent(Interval& Intv) {
    return
        (this->Max == Intv.Min &&
            !(this->ClosedRight && Intv.ClosedLeft)) ||
        (this->Min == Intv.Max &&
            !(this->ClosedLeft && Intv.ClosedRight));
}

Math::Interval Math::Interval::Union(Interval& Intv) {
    return 
        Interval(
            (this->Min < Intv.Min ? this->Min : Intv.Min), 
            (this->Max > Intv.Max ? this->Max : Intv.Max),
            (this->Min < Intv.Min ? this->ClosedLeft : Intv.ClosedLeft),
            (this->Max > Intv.Max ? this->ClosedRight : Intv.ClosedRight)
        );
}

Math::Interval Math::Interval::Intersection(Interval& Intv) {
    if ((this->Min > Intv.Max) || (Intv.Min > this->Max) ||
        (this->Min == Intv.Max && !(this->ClosedLeft && Intv.ClosedRight)) ||
        (Intv.Min == this->Max && !(Intv.ClosedLeft && this->ClosedRight)))
            return Interval(0, 0);

    return Interval(
        (this->Min > Intv.Min ? this->Min : Intv.Min), 
        (this->Max < Intv.Max ? this->Max : Intv.Max),
        (this->Min > Intv.Min ? this->ClosedLeft : Intv.ClosedLeft),
        (this->Max < Intv.Max ? this->ClosedRight : Intv.ClosedRight)
    );
}

Math::Interval Math::Interval::Gap(Interval& Intv) {
    if (this->Max < Intv.Min)
        return Interval(
            this->Max,
            Intv.Min,
            !this->ClosedRight,
            !Intv.ClosedLeft
        );

    if (Intv.Max < this->Min)
        return Interval(
            Intv.Max,
            this->Min,
            !Intv.ClosedRight,
            !this->ClosedLeft
        );

    return Interval(0, 0);
}

std::array<Math::Interval, 2> Math::Interval::Difference(Interval& Intv) {
    return
        (this->Max <= Intv.Min || (this->Max == Intv.Min && !(this->ClosedRight && Intv.ClosedLeft))) ?
            std::array<Interval, 2>{ *this, Interval(0, 0, false, false) } :

        (Intv.Min <= this->Min && Intv.Max >= this->Max) ?
            std::array<Interval, 2>{ Interval(0, 0, false, false), Interval(0, 0, false, false) } :

        std::array<Interval, 2>{
            (this->Min < Intv.Min || (this->Min == Intv.Min && this->ClosedLeft && !Intv.ClosedLeft)) ?
                Interval(this->Min, Intv.Min, this->ClosedLeft, !Intv.ClosedLeft) :
                Interval(0, 0, false, false),

            (this->Max > Intv.Max || (this->Max == Intv.Max && this->ClosedRight && !Intv.ClosedRight)) ?
                Interval(Intv.Max, this->Max, !Intv.ClosedRight, this->ClosedRight) :
                Interval(0, 0, false, false)
        };
}


void Math::Interval::Print(bool Color) {
    if (Color)
        std::cout << "\x1b[0m" << (this->ClosedLeft ? "[" : "(") << "\x1b[96m" <<
            this->Min << "\x1b[0m, \x1b[96m" <<
            this->Max << "\x1b[0m" << (this->ClosedRight ? "]" : ")") << "\n";
    else
        std::cout << (this->ClosedLeft ? "[" : "(") <<
            this->Min << ", " <<
            this->Max << (this->ClosedRight ? "]" : ")") << "\n";
}