#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;
void saveHistory(vector<string>& history) {
    ofstream file("history.txt");
    for(string h : history) {
        file << h << endl;
    }
}
void printSlow(const string& text) {
    for(char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
}
bool isNumber(const string& s) {
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
void saveBalance(int balance) {
    ofstream file("balance.txt");
    file << balance;
}
int loadBalance() {
    ifstream file("balance.txt");
    int balance;

    if(file >> balance) {
        return balance;
    }
    return 1000;
}
int PinCode(int pincode) {
    int guess = 0;
    while(true) {
        printSlow("Enter the PIN-code");
        cout << ">> ";
        string pin;
        cin >> pin;

        if(isNumber(pin)) {
            if(stoi(pin) == pincode) {
                printSlow("Correct");
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            else {
                printSlow("Incorrect PIN-code.");
                guess += 1;
                
                if(guess == 3) {
                    printSlow("Ur card was blocked.");
                    return 0;
                }else {
                    cout << "U have " << 3 - guess << " attempts." << endl;
                    continue;
                }
            }
        }
        else {
            printSlow("ERROR.");
            continue;
        }
        
    }
    return 1;
}
void Menu() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<string> amts = {"Balance", "Top up", "Withdraw funds", "Check the history", "Exit"};
    
    for(size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ". " << amts[i] << "\n";
        }
}
void Balance(int balance, vector<string>& history) {
    cout << "Ur balance is: $" << balance << "\n";
    history.push_back(" Checked the balance");
    saveHistory(history);
    this_thread::sleep_for(chrono::seconds(1));
}
void Topup(int& balance, vector<string>& history) {
    string sum;

    while(true) {
        cout << "Enter the sum: ";
        cin >> sum;
        if(isNumber(sum)) {
            int ssum = stoi(sum);

            if(ssum <= 30000 && ssum > 0) {
                balance += ssum;
                history.push_back(" Topped up: $" + sum);
                saveHistory(history);
                saveBalance(balance);
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            else {
                printSlow("ERROR.");
                continue;
            }
        }
        else {
            printSlow("ERROR.");
            continue;
        }

    }
}
void Withdraw(int& balance, vector<string>& history) {
    string sum0;
    while(true) {
        cout << "Enter amount: ";
        cin >> sum0;
        if(isNumber(sum0)) {
            int sum00 = stoi(sum0);
            const int limit = 500;
            if(sum00 <= balance && sum00 > 0 && sum00 < limit) {
                balance -= sum00;
                history.push_back(" Withdraw funds: $" + sum0);
                saveHistory(history);
                saveBalance(balance);
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            else {
                printSlow("ERROR.");
                continue;
            }
        }
        else {
            printSlow("ERROR.");
            continue;
        }
        
    }  
}
void History(vector<string>& history) {
    printSlow("Here is ur history of operations");
    cout << "===================================" << endl;
    for(string his : history) {
        cout << his << "\n";
    }
    cout << "===================================" << endl;
    this_thread::sleep_for(chrono::seconds(5));
}
vector<string> loadHistory() {
    vector<string> history;
    ifstream file("history.txt");
    string line;

    while(getline(file, line)) {
        history.push_back(line);
    }
    return history;
}

int main() {
    printSlow("==============");
    cout << "    ATM\n'AV' company" << "\n";
    printSlow("==============\n");

    int pincode = 4268;
    
    if(!PinCode(pincode)) {
        return 0;
    }
    else {
        string input;
        int balance = loadBalance();
        vector<string> history = loadHistory();

        while(true) {
            Menu();

            cout << ">> ";
            cin >> input;

            if(isNumber(input)) {
                int iinput = stoi(input);
                
                if(iinput == 1) {
                    Balance(balance, history);
                }
                else if(iinput == 2) {
                    printSlow("The limit of transfer is to $30000");
                    Topup(balance, history);
                    
                }
                else if(iinput == 3) {
                    printSlow("The limit of transfer is to $500 per transision");
                    Withdraw(balance, history);
                }
                else if(iinput == 4) {
                    History(history);
                }
                else if(iinput == 5) {
                    printSlow("Goodbye!");
                    break;
                }else {
                    printSlow("Incorrect input.");
                    continue;
                }
            }
            else {
                printSlow("ERROR.");
                continue;
            }
            
        }
    }

    return 0;
}
        }
    }

    return 0;
}
