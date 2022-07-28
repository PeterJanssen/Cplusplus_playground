#include <iostream>
#include <vector>
using namespace std;

void centsToCurrencyConverter(vector<int> values, vector<string> currency_value_names) {
	int cents{ 0 };

	cout << "Enter an amount: ";

	cin >> cents;

	int balance = cents;
	cout << "You can provide change for this change as follows:" << endl;

	for (int i = 0; i < values.size(); i++)
	{
		int currency = balance / values[i];
		balance %= values[i];
		cout << currency_value_names[i] << ": " << currency << endl;
	}
}

void printCurrencyNameBanner(string currency_name) {
	cout << "===============================" << currency_name << "===============================" << endl;
}


int main()
{
	vector<int> dollar_values = { 10000,5000,2000,1000,100,25,10,5,1 };
	vector <string> dollar_values_names = {
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
	vector <string> euro_values_names = {
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

	bool exiting_application = false;

	char input{ '0' };

	while (exiting_application == false) {
		cout << "Please select a currency you would like to convert." << endl;
		cout << "1. dollars" << endl;;
		cout << "2. euro's" << endl;
		cout << "0. to exit application" << endl;
		cin >> input;

		switch (input)
		{
		case '1':
			printCurrencyNameBanner("DOLLAR");
			centsToCurrencyConverter(dollar_values, dollar_values_names);
			printCurrencyNameBanner("DOLLAR");
			break;
		case '2':
			printCurrencyNameBanner("EURO'S");
			centsToCurrencyConverter(euro_values, euro_values_names);
			printCurrencyNameBanner("EURO'S");
			break;
		case '0':
			cout << "Exiting application." << endl;
			exiting_application = true;
			break;
		default:
			cout << "==============================================================" << endl;
			cout << "Please provide a valid input." << endl;
			cout << "==============================================================" << endl;
			break;
		}
	}

	cout << endl;
	return 0;
}
