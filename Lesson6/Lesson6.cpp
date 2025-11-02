#include <iostream>
#include <string>
#include <vector>

using namespace std;

// push_back(value) -  додати в кінці колекції
// pop_back() - прибрати з кінця
// size() - повертає розмір колекції
// empty() - повертає чи порожня колекція
// clear() - очищає всі елементи
// at(index) - безпечний доступ за індексом 
// operator[index] - доступ за індексом без перевірки

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
			while (true) {
				cout << "Please enter your E-Mail to create an account" << endl;
				cout << "Enter your E-Mail: ";
				cin >> email;
				if (!isValidEmail(email)) {
					cout << "The email you entered is invalid, you will be returned to start of the Sign Up process";
					continue;
				}
				cout << "Please enter the desired password" << endl;
				cout << "Enter the password: ";
				cin >> password;
				if (!isValidPassword(password)) {
					cout << "The password you entered is invalid, you will be returned to start of the Sign Up process";
					continue;
				}
				cout << "Please enter the desired username" << endl;
				cout << "Enter the username: ";
				cin >> username;
				isLogIn = true;
				break;
			}
			menuUi();
		}
		else {
			cout << "Oops, an account for this user already exists. Use the Log In option instead" << endl;
			menuUi();
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
		// 0. Не більше однієї собачки`+
		// 1. only one '@'+
		// 2. После '@' буква + один символ '.' + мінімум два символа после+
		// 3. NO whitespaces+
		// 4. Мінімум один символ перед '@'+

		int atCount = 0;
		int atPlacement = 0;
		int dotPlacement = 0;

		for (int i = 0; i < emailCheck.length(); i++)
		{
		    if(emailCheck[i] == '@')
		    {
		        atPlacement = i;
		        atCount++;
		        if(atCount > 1)
		        {
		            return false;
		        }
		    }
		    if(emailCheck[i] == '.')
		    {
		        dotPlacement = i;
		    }
		    if (isspace(emailCheck[i])) {
				cout << "False space check";
				return false;
			}
	    }

	    if(dotPlacement < atPlacement)
	    {
	        return false;
	    }
	    else if((dotPlacement - atPlacement) > 1 && (emailCheck.length() - dotPlacement) > 2 && atPlacement > 0)
	    {
            return true;
	    }
	    // example@mail.com
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

		for (int i = 0; i < passwordCheck.length(); i++) {
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
			if (!isalnum(passwordCheck[i])) {
				symbols++;
			}
			if (isdigit(passwordCheck[i])) {
				numbers++;
			}
		}
		cout << "Upper Letters: " << lettersUpper << " Lower Letters: " << lettersLower << " Symbols: " << symbols << " Numbers: " << numbers << endl;

		if (lettersUpper >= 2 && lettersLower >= 2 && numbers >= 2 && symbols >= 1) {
			cout << "True" << endl;
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
						menuUi();
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
				menuUi();
			}
		}
	}

	void buySkyrim()
	{
		if (isLogIn) {
			cout << "Skytom";
		}
	}

	void menuUi(){
		while (true) {
			int userChoice = 0;
			if (!isLogIn) {
				cout << "Welcome, you're not logged in" << endl;
				cout << "1. Log In" << endl;
				cout << "2. Sign Up" << endl;
				cout << "To choose an option enter its number: ";
				cin >> userChoice;
				switch (userChoice) {
				case 1: logIn(); break;
				case 2: signUp(); break;
				default: cout << "The option you entered doen't exist" << endl;
				}
			}
			else {
				cout << "Welcome, " << username << endl;
				cout << "1. Show your info" << endl;
				cout << "2. Buy Skyrim" << endl;
				cout << "3. Log In" << endl;
				cout << "4. Sign Up" << endl;
				cout << "To choose an option enter its number: ";
				cin >> userChoice;
				switch (userChoice) {
				case 1: showInfo(); break;
				case 2: buySkyrim(); break;
				case 3: isLogIn = false; logIn(); break;
				case 4: isLogIn = false; signUp(); break;
				default: cout << "The option you entered doen't exist" << endl;
				}
			}
		}
	}
};

int main()
{
	vector<Account> accounts;
	Account user1;
	user1.signUp();
	accounts.push_back(user1);
	/*user1.isValidPassword("c3K1u=£1sZ{m");
	cout << user1.isValidEmail("example@mail.com") << endl;*/
	return 0;
}