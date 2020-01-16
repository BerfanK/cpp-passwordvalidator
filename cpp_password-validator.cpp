#include <iostream>
#include <string>
#include <stdlib.h>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
using namespace std;

class PasswordValidator {

public:

	void success(string password) {

		system("cls");
		cout << YELLOW << "### Password Validator ###" << endl;
		cout << GREEN << "SUCCESS! " << MAGENTA << password << RESET << " is secure!";

	}

	void retry(string message) {

		string password;

		system("cls");
		cout << YELLOW << "### Password Validator ###" << endl;
		cout << RED << "ERROR! " << RESET << message << endl;
		cout << MAGENTA << "Please set your password: " << RESET;
		cin >> password;

		checkPassword(password);

	}

	void checkPassword(string password) {

		bool valid = false;

		while (valid == false) {
			if (password.length() >= 5) {
				if (password.length() <= 10) {
					if (password.find('0') != string::npos ||
						password.find('1') != string::npos ||
						password.find('2') != string::npos ||
						password.find('3') != string::npos ||
						password.find('4') != string::npos ||
						password.find('5') != string::npos ||
						password.find('6') != string::npos ||
						password.find('7') != string::npos ||
						password.find('8') != string::npos ||
						password.find('9') != string::npos) {
						if (password.find('&') != string::npos ||
							password.find('+') != string::npos ||
							password.find('@') != string::npos ||
							password.find('#') != string::npos ||
							password.find('$') != string::npos ||
							password.find('%') != string::npos) {

							success(password);
							valid = true;

						}
						else {
							retry("Password must contain: &, +, @, $, # or %");
						}
					}
					else {
						retry("Password must contain atleast one number.");

					}

				}
				else {
					retry("Password can't have more than 10 characters.");
				}

			}
			else {
				retry("Password must atleast contain 5 characters.");
			}
		}

	}


	void user_message() {

		string password;

		system("cls");
		cout << YELLOW << "### Password Validator ###" << endl;
		cout << MAGENTA << "Please set your password: " << RESET;
		cin >> password;

		checkPassword(password);

	}

};

int main() {
	PasswordValidator password;
	password.user_message();
	return 0;
}