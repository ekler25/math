#pragma once

namespace Math {
    struct Interval {
        double Min;
        double Max;
        bool ClosedLeft = false;
        bool ClosedRight = false;

        Interval(double Mn, double Mx, bool ClL = false, bool ClR = false) 
            : Min(Mn), Max(Mx), ClosedLeft(ClL), ClosedRight(ClR) {};
        bool Contains(double Num);
    };
}