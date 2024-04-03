#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;
    double sodu;

public:
    User(string username, string password, double sodu) {
        this->username = username;
        this->password = password;
        this->sodu = sodu;
    }

    string getUsername() {
        return username;
    }

    bool checkPassword(string inputPassword) {
        return password == inputPassword;
    }

    bool checkUserName(string inputUserName) {
        return username == inputUserName;
    }

    double getSodu() {
        return sodu;
    }

    void deductSodu(double amount) {
        sodu -= amount;
    }

    bool changePassword() {
        string oldPassword;
        string newPassword;
        cout << "Enter old password: ";
        cin >> oldPassword;
        if (checkPassword(oldPassword)) {
            cout << "Enter new password: ";
            cin >> newPassword;
            password = newPassword;
            cout << "Password changed successfully." << endl;
            return true; // Password changed successfully
        } else {
            cout << "Incorrect old password. Please try again." << endl;
            return false;
        }
    }
    void displayBalance() {
    int totalMinutes = sodu * 60; 
    int hours = totalMinutes / 60; 
    int minutes = totalMinutes % 60; 
    cout << "Remaining account balance: " << hours << " hours and " << minutes << " minutes" << endl;
}
    void addBalance(double minutes) {
        double amount = minutes / 8.6; 
        if (amount > 50) {
            double discount = amount * 0.15; 
            amount -= discount; 
        }
        sodu += amount;
        cout << "Extra balance added successfully." << endl;
    }

    static User registerUser() {
        string username, password;
        double minutes, sodu;

        cout << "Register Account: " << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter initial balance in minutes: ";
        cin >> minutes;
        sodu = minutes / 8.6;
        if (sodu > 50) {
            sodu -= (minutes / 8.6) * 0.15;
        }
        return User(username, password, sodu);
    }

    bool login() {
        string inputUserName;
        string inputPassword;
        cout << "Login Account: " << endl;
        cout << "Enter your username: ";
        cin >> inputUserName;
        cout << "Enter your password: ";
        cin >> inputPassword;
        return checkUserName(inputUserName) && checkPassword(inputPassword);
    }
};

int main() {
    User user1("default_user", "password", 0.0);
    int choice;
    double extraBalance;

    do {
        cout << "-----Menu CGT NET-----" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Change Password" << endl;
        cout << "4. Show Balance" << endl;
        cout << "5. Add Balance" << endl;
        cout << "6. Exit" << endl;
        cout << "-----Welcome-----" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                user1 = User::registerUser();
                break;
            case 2:
                if (user1.login()) {
                    cout << "Login successful. Welcome, " << user1.getUsername() << "!" << endl;
                } else {
                    cout << "Login failed. Invalid username or password." << endl;
                }
                break;
            case 3:
                user1.changePassword();
                break;
            case 4:
                user1.displayBalance();
                break;
            case 5:
                cout << "Enter extra balance to add: ";
                cin >> extraBalance;
                user1.addBalance(extraBalance);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}

