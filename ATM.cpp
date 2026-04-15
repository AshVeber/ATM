#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

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
int loadPin(string log) {
    ifstream file(log + "_pin.txt");
    int pin;

    if(file >> pin) {
        return pin;
    }
    return -1;
}
string login() {
    cout << "Enter your username: " << endl;
    string log;
    cin >> log;

    int pin = loadPin(log);

    if(pin == -1) {
        cout << "You do not have account in AV ATM" << endl;
        cout << "Let's create one!" << endl;

        while(true) {
            string newPin;
            cout << "Enter new PIN: " << endl;
            cin >> newPin;
            if(isNumber(newPin)) {
                ofstream file(log + "_pin.txt");
                file << newPin;
                cout << "Account created!" << endl;
                pin = stoi(newPin);
                break;
            }
            else {
                cout << "The PIN must have numbers." << endl;
                continue;
            }
        }
        
    }
    return log;
}
void saveHistory(vector<string>& history, string log) {
    ofstream file(log + "_history.txt");
    for(string h : history) {
        file << h << endl;
    }
}
void saveBalance(int balance, string log) {
    ofstream file(log + "_balance.txt");
    file << balance;
}
int loadBalance(string log) {
    ifstream file(log + "_balance.txt");
    int balance;

    if(file >> balance) {
        return balance;
    }
    return 1000;
}
int PinCode(int pincode) {
    int guess = 0;
    while(true) {
        cout << "Enter the PIN-code" << endl;
        cout << ">> ";
        string pin;
        cin >> pin;

        if(isNumber(pin)) {
            if(stoi(pin) == pincode) {
                cout << "Correct" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            else {
                cout << "Incorrect PIN-code." << endl;
                guess += 1;
                
                if(guess == 3) {
                    cout << "Ur card was blocked." << endl;
                    return 0;
                }else {
                    cout << "U have " << 3 - guess << " attempts." << endl;
                    continue;
                }
            }
        }
        else {
            cout << "ERROR." << endl;
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
void Balance(int balance, vector<string>& history, string log) {
    cout << "Ur balance is: $" << balance << "\n";
    history.push_back(" Checked the balance");
    saveHistory(history, log);
    this_thread::sleep_for(chrono::seconds(1));
}
void Topup(int& balance, vector<string>& history, string log) {
    string sum;

    while(true) {
        cout << "Enter the sum: ";
        cin >> sum;
        if(isNumber(sum)) {
            int ssum = stoi(sum);

            if(ssum <= 30000 && ssum > 0) {
                balance += ssum;
                history.push_back(" Topped up: $" + sum);
                saveHistory(history, log);
                saveBalance(balance, log);
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            else {
                cout << "ERROR." << endl;
                continue;
            }
        }
        else {
            cout << "ERROR." << endl;
            continue;
        }

    }
}
void Withdraw(int& balance, vector<string>& history, string log) {
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
                saveHistory(history, log);
                saveBalance(balance, log);
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            else {
                cout << "ERROR." << endl;
                continue;
            }
        }
        else {
            cout << "ERROR." << endl;
            continue;
        }
        
    }  
}
vector<string> loadHistory(string log) {
    vector<string> history;
    ifstream file(log + "_history.txt");
    string line;

    while(getline(file, line)) {
        history.push_back(line);
    }
    return history;
}
void History(vector<string>& history) {
    cout << "Here is ur history of operations" << endl;
    cout << "===================================" << endl;
    for(string his : history) {
        cout << his << "\n";
    }
    cout << "===================================" << endl;
    this_thread::sleep_for(chrono::seconds(3));
}


int main() {
    cout << "==============" << endl;
    cout << "    ATM\n'AV' company" << "\n";
    cout << "==============" << endl;

    string log = login();
    int pincode = loadPin(log);
    
    if(!PinCode(pincode)) {
        return 0;
    }
    else {
        string input;
        int balance = loadBalance(log);
        vector<string> history = loadHistory(log);

        while(true) {
            Menu();

            cout << ">> ";
            cin >> input;

            if(isNumber(input)) {
                int iinput = stoi(input);
                
                if(iinput == 1) {
                    Balance(balance, history, log);
                }
                else if(iinput == 2) {
                    cout << "The limit of transfer is to $30000" << endl;
                    Topup(balance, history, log);
                    
                }
                else if(iinput == 3) {
                    cout << "The limit of transfer is to $500 per transision" << endl;
                    Withdraw(balance, history, log);
                }
                else if(iinput == 4) {
                    History(history);
                }
                else if(iinput == 5) {
                    cout << "Goodbye!" << endl;
                    break;
                }else {
                    cout << "Incorrect input." << endl;
                    continue;
                }
            }
            else {
                cout << "ERROR." << endl;
                continue;
            }
            
        }
    }
    return 0;
}
