#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void printInvalidInputErrorMessage(string message) {
	cin.clear();
	cin.ignore(256, '\n');

	cout << "==============================================================" << endl
		<< message << endl
		<< "==============================================================" << endl;
}

void printAlgorithmInfo(string info) {
	cout << info << endl;
}

void fizzBuzz() {
	string output = "";

	for (int i{ 1 }; i <= 20; i++) {
		output.append("For " + to_string(i) + " we print: ");

		if (i % 3 == 0 && i % 5 == 0) {
			output.append("fizzbuzz\n");
		}
		else if (i % 3 == 0) {
			output.append("fizz\n");
		}
		else if (i % 5 == 0) {
			output.append("buzz\n");
		}
		else {
			output.append(to_string(i) + "\n");
		}
	}
	cout << output;
}

void pyramid() {
	const int height = 10;
	const double midpoint = floor((2 * height - 1) / 2);

	string pyramid = "";

	for (int row{ 0 }; row < 10; row++) {
		string pyramid_building_block_row = "";

		for (int column{ 0 }; column < 2 * height - 1; column++) {
			if (midpoint - row <= column && midpoint + row >= column) {
				pyramid_building_block_row.append("#");
			}
			else {
				pyramid_building_block_row.append(" ");
			}
		}

		pyramid.append(pyramid_building_block_row + "\n");
	}

	cout << pyramid;
}

void printAlgorithmNameBanner(string algorithm_name) {
	cout << "===============================" << algorithm_name << "===============================" << endl;
}

void printAlgorithmChoices(vector<string> algorithm_names) {
	for (int i{ 1 }, j{ 0 }; j < algorithm_names.size(); i++, j++) {
		cout << i << ". " << algorithm_names.at(j) << endl;
	}

	cout << "0. to exit application" << endl;
}

int main()
{
	vector<string> algorithm_names{ "FIZZBUZZ", "PYRAMID" };

	bool exiting_application = false;

	char input{ '0' };

	while (exiting_application == false) {
		cout << "Please select an algorithm you would like to start." << endl;

		printAlgorithmChoices(algorithm_names);

		cin >> input;

		switch (input)
		{
		case '1':
			printAlgorithmNameBanner(algorithm_names.at(0));
			printAlgorithmInfo(
				"This algorithm prints the numbers from 1 to 20.\n"
				"But for multiples of three prints 'fizz' instead of the number.\n"
				"For the multiples of five prints 'buzz'.\n"
				"For numbers which are multiples of both three and five prints 'fizzbuzz'.\n"
				"--- Example ---\n"
			);
			fizzBuzz();
			printAlgorithmNameBanner(algorithm_names.at(0));
			break;
		case '2':
			printAlgorithmNameBanner(algorithm_names.at(1));
			printAlgorithmInfo(
				"This algorithm prints a pyramid with 10 rows.\n--- Example ---\n"
			);
			pyramid();
			printAlgorithmNameBanner(algorithm_names.at(1));
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
