#include <iostream>
#include <algorithm>
#include <numeric>
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
    if (Elements.empty()) return false;
    if (this->Elements.find(Num) != this->Elements.end())
        return true;
    return false;
}

bool Math::Collection::Contains(Collection& Coll) {
    if (Elements.empty()) return false;
    for (double E : Coll.Elements)
        if (!this->Contains(E)) return false;
    return true;
}

double Math::Collection::Max() {
    if (Elements.empty()) return 0;
    return *std::max_element(this->Elements.begin(), this->Elements.end());
}

double Math::Collection::Min() {
    if (Elements.empty()) return 0;
    return *std::min_element(this->Elements.begin(), this->Elements.end());
}

double Math::Collection::Sum() {
    if (Elements.empty()) return 0;
    return std::accumulate(Elements.begin(), Elements.end(), 0.0);
}

double Math::Collection::Avg() {
    if (Elements.empty()) return 0;
    return this->Sum() / this->Size();
}
