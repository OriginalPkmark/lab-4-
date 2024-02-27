#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class definition for BankUser
class BankUser {
private:
    string accountNumber; // Private member variable to store account number

public:
    string first_name, last_name; // Public member variables for first name and last name
    float balance; // Public member variable for balance
    double amount; // Public member variable for amount

    // Default constructor
    BankUser() {} // default object

    // Parameterized constructor
    BankUser(const string& firstName, const string& lastName, float bal, double amt, const string& accountNum) {
        first_name = firstName;
        last_name = lastName;
        balance = bal;
        amount = amt;
        accountNumber = accountNum;
    }

    // Setter method for account number
    void setAccountNumber(const string& accountNum) {
        accountNumber = accountNum;
    }

    // Getter method for first name
    string getFirstName() const {
        return first_name;
    }

    // Getter method for last name
    string getLastName() const {
        return last_name;
    }

    // Getter method for account number
    string getAccountNumber() const {
        return accountNumber;
    }

    // Method to verify if input account number matches user's account number
    bool verifyAccountNumber(const string& inputAccountNum) const {
        return inputAccountNum == accountNumber;
    }

    // Getter method for balance
    float getBalance() const {
        return balance;
    }

    // Getter method for amount
    double getAmount() const {
        return amount;
    }
};

// Main function
int main() {
    // Vector to store BankUser objects
    vector<BankUser> users;

    // Adding two users to the vector
    users.push_back(BankUser("JohnO", "BOY", 1000.0f, 500.0, "8889"));
    users.push_back(BankUser("Alice", "potato", 2000.0f, 1000.0, "7778"));

    string inputAccountNum;
    cout << "(totally not 8889 or 7778)" << endl;
    cout << "Enter account number to access account: ";
    cin >> inputAccountNum;

    bool accessGranted = false;
    // Loop through users to check for matching account number
    for (const auto& user : users) {
        if (user.verifyAccountNumber(inputAccountNum)) {
            cout << "Welcome, " << user.getFirstName() << " " << user.getLastName() << "! Access granted." << endl;
            cout << "Account amount: " << user.getAmount() << ", Account balance: " << user.getBalance() << endl;
            accessGranted = true;
            break;
        }
    }

    // Display message if access is denied
    if (!accessGranted) {
        cout << "Access denied. Incorrect account number." << endl;
    }

    return 0;
}
