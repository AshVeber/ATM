#pragma once
#include <iostream>
#include <cctype>
#include <fstream>

inline bool isNumber(const std::string& s) {
    if(s.empty()) {
        return false;
    }
    for(char const &c : s) {
        if(!(isdigit(c))) {
            return false;
        }
    }
    return true;
}
inline int loadPin(std::string log) {
    std::ifstream file(log + "_pin.txt");
    int pin;

    if(file >> pin) {
        return pin;
    }
    return -1;
}