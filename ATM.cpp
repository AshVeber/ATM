#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

void printSlow(const string& text) {
    for(char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
}

int main() {
    printSlow("==============");
    cout << "    ATM\n'AV' company" << "\n";
    printSlow("==============\n");

    int pincode = 4268;
    int guess = 0;

    while(true) {
        cout << "Enter ur PIN-code: ";
        int pin;
        cin >> pin;

        if(pin == pincode) {
            break;
        }else {
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
    

     
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<string> amts = {"Balance", "Top up", "Withdraw funds", "Check the history", "Exit"};

    for(size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ". " << amts[i] << "\n";
    }

    int input;
    int balance = 1000;
    int tu = 0;
    int wf = 0;
    vector<string> history;

    while(true) {
        cout << ">> ";
        cin >> input;

        if(input == 1) {
            cout << "Ur balance is: $" << balance << "\n";
            history.push_back("Checked the balance");
        }
        else if(input == 2) {
            cout << "Enter the sum: ";
            int sum;
            cin >> sum;
            balance = balance + sum;
            history.push_back("Topped up the sum");
        }
        else if(input == 3) {
            int sum0;
            while(true) {
                cout << "Enter the fund: ";
                cin >> sum0;
                if(sum0 <= balance) {
                    balance = balance - sum0;
                    history.push_back("Withdrawed funds");
                    break;
                }else {
                    printSlow("U can not go into the minus\n");
                    continue;
                }
            }  
        }
        else if(input == 4) {
            history.push_back("Checked the history of operations");
            printSlow("Here is ur history of operations");
            for(string his : history) {
                cout << his << "\n";
            }
        }
        else if(input == 5) {
            printSlow("Goodbye!");
            break;
        }else {
            printSlow("Incorrect input.");
            continue;
        }
    }

    return 0;
}
