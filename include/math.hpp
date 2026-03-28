#pragma once

#include <limits>

namespace Math {
    static constexpr double PI   = 3.141592653589793;
    static constexpr double TAU  = PI * 2;
    static constexpr double SQR2 = 1.772453850905516;
    static constexpr double E    = 2.718281828459045;
    static constexpr double INF = std::numeric_limits<double>::infinity();

    struct Interval {
        double Min;
        double Max;
        bool   ClosedLeft;
        bool   ClosedRight;
        bool   Whole;

        Interval(double Mn, double Mx, bool ClL = false, bool ClR = false, bool Wh = false) 
            : Min(Mn), Max(Mx), ClosedLeft(ClL), ClosedRight(ClR), Whole(Wh) {};

        int  Size();
        bool Contains(double Num);
        bool Contains(Interval& Intv);
        void Print(bool Color = true);
    };

    const Interval realInterval    = Interval(-INF, INF);
    const Interval integerInterval = Interval(-INF, INF, false, false, false);
    const Interval wholeInterval   = Interval(0, INF, false, false, true);
    const Interval naturalInterval = Interval(1, INF, false, false, true);
}
