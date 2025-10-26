#include <iostream>
#include <string>

using namespace std;

struct Account
{
private:
	string username;
	string email;
	string password;
	string emailLogIn;
	string passwordLogIn;
	int balance = 0;
	bool isLogIn = false;
public:
	void signUp()
	{
		if (!isLogIn) {
			cout << "Please enter your E-Mail to create an account" << endl;
			cout << "Enter your E-Mail: ";
			cin >> email;
			cout << "Please enter the desired password" << endl;
			cout << "Enter the password: ";
			cin >> password;
			cout << "Please enter the desired username" << endl;
			cout << "Enter the username: ";
			cin >> username;
			isLogIn = true;
		}
		else {
			cout << "Oops, an account for this user already exists. Use the Log In option instead" << endl;
		}
	}

	void showInfo()
	{
		if (isLogIn) {
			cout << "User Information" << endl;
			cout << "Username: " << username << endl;
			cout << "E-Mail: " << email << endl;
			cout << "Current balance: " << balance << endl;
		}
		else {
			cout << "Error, could not display information because user is not logged in" << endl;
		}
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
			else if (isupper(passwordCheck[i])) {
				lettersUpper++;
			}
			else if (islower(passwordCheck[i])) {
				lettersLower++;
			}
			else if (!isalnum(passwordCheck[i]) && !isspace(passwordCheck[i])) {
				symbols++;
			}
			else if (isdigit(passwordCheck[i])) {
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
		while (true) {
			if (!isLogIn) {
				cout << "Please enter your E-Mail: " << endl;
				cin >> emailLogIn;
				if (emailLogIn == email) {
					cout << "Please enter your password: " << endl;
					cin >> passwordLogIn;
					if (passwordLogIn == password) {
						cout << "Log in succesfull! Welcome " << username << endl;
						isLogIn = true;
						break;
					}
					else {
						cout << "Oops, the password you entered is incorrect" << endl;
					}
				}
				else {
					cout << "Oops, the email you entered is incorrect" << endl;
				}
			}
			else {
				cout << "Oops, you are already logged in" << endl;
			}
		}
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