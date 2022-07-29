#include <iostream>
#include <vector>
using namespace std;

void printInvalidInputErrorMessage(string message) {
	cin.clear();
	cin.ignore(256, '\n');

	cout << "==============================================================" << endl
		<< message << endl
		<< "==============================================================" << endl;
}

void centsToCurrencyConverter(vector<int> values, vector<string> currency_value_names) {
	int cents{ 0 };

	cout << "Enter an amount in cents: ";

	cin >> cents;

	while (cents <= 0 || cin.fail()) {
		printInvalidInputErrorMessage("Please enter a number above 0");
		cout << "Enter an amount in cents: ";
		cin >> cents;
	}

	int balance = cents;
	int currency{ 0 };

	cout << "You can provide change for " << balance << " as follows : " << endl;

	for (int i{ 0 }; i < values.size(); i++)
	{
		currency = balance / values.at(i);
		cents = balance;
		balance %= values.at(i);
		if (currency > 0) {
			cout << cents - balance << "\tconverted to\t" << currency << "*\t" << currency_value_names.at(i) << endl;
		}
	}
}

void printCurrencyNameBanner(string currency_name) {
	cout << "===============================" << currency_name << "===============================" << endl;
}

void printCurrencyChoices(vector<string> currency_names) {
	for (int i{ 1 }, j{ 0 }; j < currency_names.size(); i++, j++) {
		cout << i << ". " << currency_names.at(j) << endl;
	}

	cout << "0. to exit application" << endl;
}

int main()
{
	vector<int> dollar_values = { 10000,5000,2000,1000,100,25,10,5,1 };
	vector<string> dollar_values_names = {
		"hundred dollars",
		"fifty dollars",
		"twenty dollars",
		"ten dollars",
		"one dollars",
		"quarters",
		"dimes",
		"nickles",
		"pennies"
	};

	vector<int> euro_values = { 50000,20000,10000,5000,2000,1000,500,100,50,20,10,5,2,1 };
	vector<string> euro_values_names = {
		"five hundred euro's",
		"two hundred euro's",
		"one hundred euro's",
		"fifty euro's",
		"twenty euro's",
		"ten euro's",
		"five euro's",
		"one euro's",
		"fifty cents",
		"twenty cents",
		"ten cents",
		"five cents",
		"two cents",
		"one cents"
	};

	vector<string> currency_names{ "DOLLAR","EURO" };

	bool exiting_application = false;

	char input{ '0' };

	while (exiting_application == false) {
		cout << "Please select a currency you would like to convert." << endl;

		printCurrencyChoices(currency_names);

		cin >> input;

		switch (input)
		{
		case '1':
			printCurrencyNameBanner(currency_names.at(0));
			centsToCurrencyConverter(dollar_values, dollar_values_names);
			printCurrencyNameBanner(currency_names.at(0));
			break;
		case '2':
			printCurrencyNameBanner(currency_names.at(1));
			centsToCurrencyConverter(euro_values, euro_values_names);
			printCurrencyNameBanner(currency_names.at(1));
			break;
		case '0':
			cout << "Exiting application." << endl;
			exiting_application = true;
			break;
		default:
			printInvalidInputErrorMessage("Please provide a valid input.");
			break;
		}
	}

	cout << endl;
	return 0;
}
