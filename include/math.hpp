#pragma once

#include <array>
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
        void Print(bool Color = true);

        bool Contains(double Num);
        bool Contains(Interval& Intv);
        bool Intersects(Interval& Intv);
        bool Disjoined(Interval& Intv);
        bool Adjacent(Interval& Intv);

        Interval Union(Interval& Intv);
        Interval Intersection(Interval& Intv);
        Interval Gap(Interval& Intv);
        std::array<Math::Interval, 2> Difference(Interval& Intv);
    };

    struct Collection {
        
    };

    const Interval realInterval    = Interval(-INF, INF);
    const Interval integerInterval = Interval(-INF, INF, false, false, true);
    const Interval wholeInterval   = Interval(0, INF, false, false, true);
    const Interval naturalInterval = Interval(1, INF, false, false, true);
}
