// Currency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int dollar_cents{};
	const int dollar_value{ 100 };
	const int quarter_value{ 25 };
	const int dimes_value{ 10 };
	const int nickles_value{ 5 };
	cout << "===============================DOLLARS===============================";
	cout << "\nEnter an amount in dollar cents: ";

	cin >> dollar_cents;

	int balance = dollar_cents;

	int dollars = balance / dollar_value;
	balance = dollar_cents % dollar_value;

	int quarters = balance / quarter_value;
	balance %= quarter_value;

	int dimes = balance / dimes_value;
	balance %= dimes_value;

	int nickles = balance / nickles_value;
	balance %= nickles_value;

	int pennies = balance;

	cout << "You can provide change for this change as follows: "
		<< "\ndollars: " << dollars << "\nquarters: " << quarters << "\ndimes: " << dimes << "\nnickles: " << nickles
		<< "\npennies: " << pennies;

	cout << "\n===============================EUROS===============================\n";

	int euro_cents{};
	const int one_euro_value{ 100 };
	const int fifty_cent_value{ 50 };
	const int twenty_cent_value{ 20 };
	const int ten_cent_value{ 10 };
	const int five_cent_value{ 5 };
	const int two_cent_value{ 2 };

	cout << "Enter an amount in euro cents: ";

	cin >> euro_cents;

	balance = euro_cents;

	int one_euros = balance / one_euro_value;
	balance = euro_cents % one_euro_value;

	int fifty_cents = balance / fifty_cent_value;
	balance %= fifty_cent_value;

	int twenty_five_cents = balance / twenty_cent_value;
	balance %= twenty_cent_value;

	int ten_cents = balance / ten_cent_value;
	balance %= ten_cent_value;

	int five_cents = balance / five_cent_value;
	balance %= five_cent_value;

	int two_cents = balance / two_cent_value;
	balance %= two_cent_value;

	int one_cents = balance;

	cout << "You can provide change for this change as follows: "
		<< "\none euro's: " << one_euros << "\nfifty cents: " << fifty_cents
		<< "\ntwenty cents: " << twenty_five_cents << "\nten cents: " << ten_cents << "\nfive cents: " << five_cents
		<< "\ntwo cents: " << two_cents << "\none cents: " << one_cents;

	cout << endl;
	return 0;
}
