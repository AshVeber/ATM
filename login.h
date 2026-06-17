#pragma once

#include <iostream>
#include <fstream>
#include "settings.h"

inline int loadPin(std::string log) {
    std::ifstream file(log + "_pin.txt");
    int pin;

    if(file >> pin) {
        return pin;
    }
    return -1;
}
inline std::string login() {
    std::cout << "Enter your username: " << std::endl;
    std::string log;
    std::cin >> log;

    int pin = loadPin(log);

    if(pin == -1) {
        std::cout << "You do not have account in AV ATM" << std::endl;
        std::cout << "Let's create one!" << std::endl;

        while(true) {
            std::string newPin;
            std::cout << "Enter new PIN: " << std::endl;
            std::cin >> newPin;
            if(isNumber(newPin)) {
                std::ofstream file(log + "_pin.txt");
                file << newPin;
                std::cout << "Account created!" << std::endl;
                pin = stoi(newPin);
                break;
            }
            else {
                std::cout << "The PIN must have numbers." << std::endl;
                continue;
            }
        }
        
    }
    return log;
}