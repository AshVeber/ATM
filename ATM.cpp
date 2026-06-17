#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "settings.h"

std::string login() {
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

void saveHistory(std::vector<std::string>& history, std::string log) {
    std::ofstream file(log + "_history.txt");
    for(std::string h : history) {
        file << h << std::endl;
    }
}
void saveBalance(int balance, std::string log) {
    std::ofstream file(log + "_balance.txt");
    file << balance;
}
int loadBalance(std::string log) {
    std::ifstream file(log + "_balance.txt");
    int balance;

    if(file >> balance) {
        return balance;
    }
    return 1000;
}
int PinCode(int pincode) {
    int guess = 0;
    while(true) {
        std::cout << "Enter the PIN-code" << std::endl;
        std::cout << ">> ";
        std::string pin;
        std::cin >> pin;

        if(isNumber(pin)) {
            if(stoi(pin) == pincode) {
                std::cout << "Correct" << std::endl;
                break;
            }
            else {
                std::cout << "Incorrect PIN-code." << std::endl;
                guess += 1;
                
                if(guess == 3) {
                    std::cout << "Ur card was blocked." << std::endl;
                    return 0;
                }else {
                    std::cout << "U have " << 3 - guess << " attempts." << std::endl;
                    continue;
                }
            }
        }
        else {
            std::cout << "ERROR." << std::endl;
            continue;
        }
        
    }
    return 1;
}
void Menu() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<std::string> amts = {"Balance", "Top up", "Withdraw funds", "Check the history", "Exit"};
    
    for(size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << ". " << amts[i] << "\n";
        }
}
void Balance(int balance, std::vector<std::string>& history, std::string log) {
    std::cout << "Ur balance is: $" << balance << "\n";
    history.push_back(" Checked the balance");
    saveHistory(history, log);
}
void Topup(int& balance, std::vector<std::string>& history, std::string log) {
    std::string sum;

    while(true) {
        std::cout << "Enter the sum: ";
        std::cin >> sum;
        if(isNumber(sum)) {
            int ssum = stoi(sum);

            if(ssum <= 30000 && ssum > 0) {
                balance += ssum;
                history.push_back(" Topped up: $" + sum);
                saveHistory(history, log);
                saveBalance(balance, log);
                break;
            }
            else {
                std::cout << "ERROR." << std::endl;
                continue;
            }
        }
        else {
            std::cout << "ERROR." << std::endl;
            continue;
        }

    }
}
void Withdraw(int& balance, std::vector<std::string>& history, std::string log) {
    std::string sum0;
    while(true) {
        std::cout << "Enter amount: ";
        std::cin >> sum0;
        if(isNumber(sum0)) {
            int sum00 = stoi(sum0);
            const int limit = 500;
            if(sum00 <= balance && sum00 > 0 && sum00 < limit) {
                balance -= sum00;
                history.push_back(" Withdraw funds: $" + sum0);
                saveHistory(history, log);
                saveBalance(balance, log);
                break;
            }
            else {
                std::cout << "ERROR." << std::endl;
                continue;
            }
        }
        else {
            std::cout << "ERROR." << std::endl;
            continue;
        }
        
    }  
}
std::vector<std::string> loadHistory(std::string log) {
    std::vector<std::string> history;
    std::ifstream file(log + "_history.txt");
    std::string line;

    while(getline(file, line)) {
        history.push_back(line);
    }
    return history;
}
void History(std::vector<std::string>& history) {
    std::cout << "Here is ur history of operations" << std::endl;
    std::cout << "===================================" << std::endl;
    for(std::string his : history) {
        std::cout << his << "\n";
    }
    std::cout << "===================================" << std::endl;
}


int main() {
    std::cout << "==============\n    ATM\n'AV' company\n==============" << std::endl;
    std::string log = login();
    int pincode = loadPin(log);
    
    if(!PinCode(pincode)) {
        return 0;
    }
    else {
        std::string input;
        int balance = loadBalance(log);
        std::vector<std::string> history = loadHistory(log);

        while(true) {
            Menu();

            std::cout << ">> ";
            std::cin >> input;

            if(isNumber(input)) {
                int iinput = stoi(input);
                
                if(iinput == 1) {
                    Balance(balance, history, log);
                }
                else if(iinput == 2) {
                    std::cout << "The limit of transfer is to $30000" << std::endl;
                    Topup(balance, history, log);
                    
                }
                else if(iinput == 3) {
                    std::cout << "The limit of transfer is to $500 per transision" << std::endl;
                    Withdraw(balance, history, log);
                }
                else if(iinput == 4) {
                    History(history);
                }
                else if(iinput == 5) {
                    std::cout << "Goodbye!" << std::endl;
                    break;
                }else {
                    std::cout << "Incorrect input." << std::endl;
                    continue;
                }
            }
            else {
                std::cout << "ERROR." << std::endl;
                continue;
            }
            
        }
    }
    return 0;
}
