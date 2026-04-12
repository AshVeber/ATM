#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

using namespace std;

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

int main() {
    printSlow("==============");
    cout << "    ATM\n'AV' company" << "\n";
    printSlow("==============\n");

    string pincode = "4268";
    int guess = 0;
    string pin;

    while(true) {
        printSlow("Enter the PIN-code");
        cout << ">> ";
        cin >> pin;

        if(isNumber(pin)) {
            if(pin == pincode) {
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
    

     
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<string> amts = {"Balance", "Top up", "Withdraw funds", "Check the history", "Exit"};

    

    string input;
    int balance = 1000;
    int wf = 0;
    vector<string> history;

    while(true) {
        for(size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ". " << amts[i] << "\n";
        }

        cout << ">> ";
        cin >> input;

        if(isNumber(input)) {
            if(stoi(input) == 1) {
                cout << "Ur balance is: $" << balance << "\n";
                history.push_back(" Checked the balance");
                this_thread::sleep_for(chrono::seconds(1));
            }
            else if(stoi(input) == 2) {
                printSlow("The limit of transfer is to $30000");
                while(true) {
                    cout << "Enter the sum: ";
                    string sum;
                    cin >> sum;
                    if(isNumber(sum)) {
                        if(stoi(sum) <= 30000 && stoi(sum) > 0) {
                            balance = balance + stoi(sum);
                            history.push_back(" Topped up: $" + sum);
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
            else if(stoi(input) == 3) {
                string sum0;
                printSlow("The limit of transfer is to $500 per transision");
                while(true) {
                    cout << "Enter amount: ";
                    cin >> sum0;
                    if(isNumber(sum0)) {
                        if(stoi(sum0) <= balance && stoi(sum0) > 0 && stoi(sum0) < 500) {
                            balance = balance - stoi(sum0);
                            history.push_back(" Withdraw funds: $" + sum0);
                            break;
                            this_thread::sleep_for(chrono::seconds(1));
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
            else if(stoi(input) == 4) {
                history.push_back(" Checked the history of operations");
                printSlow("Here is ur history of operations");
                cout << "===================================" << endl;
                for(string his : history) {
                    cout << his << "\n";
                }
                cout << "===================================" << endl;
                this_thread::sleep_for(chrono::seconds(5));
            }
            else if(stoi(input) == 5) {
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

    return 0;
}
