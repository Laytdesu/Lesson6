/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

// Створити структуру, в котрій
    // Змінні: нікнейм, пошта, пароль, баланс, bool isLogIn
    // Функції: signIn, showInfo, bool isValidEmail/Password, LogIn,buySkirym, 
#include <iostream>
#include <string>

using namespace std;

struct Account {
private:
    string username;
    string email;
    string password;
    int balance = 0;
    bool isLogIn = false;
public:
    void signUp()
    {
        cout << "Please enter your credentials to create and account" << endl;
        cout << "Enter your E-Mail: ";
        cin >> email;
    }

    void showInfo()
    {
        cout << "User Information";
    }

    bool isValidEmail(string emailCheck)
    {
        return false;
    }

    bool isValidPassword(string passwordCheck)
    {

        // valid: 
         // 1. 8-64 size
         // 2. Мінімум: 2 великих літери, 2 малі літери, 2 цифри, символ
         // 3. не повинно бути пробілів
        int lettersUpper = 0;
        int lettersLower = 0;
        int symbols = 0;
        int numbers = 0;

        if (passwordCheck.length() < 8 || passwordCheck.length() > 64) {
            cout << "Length of password is invalid" << endl;
            cout << "False length";
            return false;
        }

        for (int i = 0; i < password.length(); i++) {
            if (isspace(passwordCheck[i])) {
                cout << "False space check";
                return false;
            }
            if (isupper(passwordCheck[i])) {
                lettersUpper++;
            }
            if (islower(passwordCheck[i])) {
                lettersLower++;
            }
            if (!isalnum(passwordCheck[i]) && !isspace(passwordCheck[i])) {
                symbols++;
            }
            if (isdigit(passwordCheck[i])) {
                numbers++;
            }
        }
        cout << "Upper Letters: " << lettersUpper << " Lower Letters: " << lettersLower << " Symbols: " << symbols << " Numbers: " << numbers << endl;

        if (lettersUpper >= 2 && lettersLower >= 2 && numbers >= 2 && symbols >= 1) {
            cout << "True";
            return true;
        }
        else {
            cout << "False last check";
            return false;
        }
    }

    void logIn()
    {
        cout << "Lalala";
    }

    void buySkyrim()
    {
        cout << "Skytom";
    }
};

int main()
{

    Account user1;
    user1.signUp();
    user1.isValidPassword("c3K1u=£1sZ{m");
    return 0;
}