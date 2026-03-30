#include <iostream>
#include <math.hpp>

int Math::Collection::Size() {
    return this->Elements.size();
}

void Math::Collection::Print(bool Color) {
    if (Color) {
        std::cout << "{";
        for (auto& E : this->Elements)
            std::cout << "\x1b[96m" << E << "\x1b[0m, ";
        std::cout << "}\n";
    } else {
        std::cout << "{";
        for (auto& E : this->Elements)
            std::cout << E << ", ";
        std::cout << "}\n";
    }
}

void Math::Collection::Set(std::unordered_set<double> Dat) {
    this->Elements = Dat;
};

void Math::Collection::Add(double Num) {
    this->Elements.insert(Num);
};

bool Math::Collection::Contains(double Num) {
    if (this->Elements.find(Num) != this->Elements.end())
        return true;
    return false;
}

bool Math::Collection::Contains(Collection& Coll) {
    for (double E : Coll.Elements)
        if (!this->Contains(E)) return false;
    return true;
}
