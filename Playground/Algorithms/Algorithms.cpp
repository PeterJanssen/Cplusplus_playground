#include <iostream>
#include <vector>
#include <algorithm>
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

void printChoiceInfo(string info) {
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

void vowelCounter() {
	string strings_to_count_vowels_in = "LEt's coUnt the AmoUnt of vowels in this string!";
	transform(strings_to_count_vowels_in.begin(),
		strings_to_count_vowels_in.end(),
		strings_to_count_vowels_in.begin(),
		tolower);

	int vowel_count{ 0 };

	const vector<char> vowels{ 'a', 'e','i','o','u' };

	for (char string_to_count_vowel : strings_to_count_vowels_in) {
		for (char vowel : vowels) {
			if (string_to_count_vowel == vowel) {
				vowel_count++;
			}
		}
	}

	cout << "The amount of vowels contained in the sentence #" << strings_to_count_vowels_in << "#: " << vowel_count << endl;
}

void reverseArray() {
	vector<string> string_array{ "This is the first sentence!", "Second sentence.","Third sentence." };
	vector<string> reversed_string_array{};

	for (int i = string_array.size() - 1; i >= 0; i--) {
		reversed_string_array.push_back(string_array[i]);
	}

	string original_string = "";
	string reversed_string = "";

	for (int i = 0; i < reversed_string_array.size(); i++) {
		original_string.append("\"" + string_array[i] + "\", ");
		reversed_string.append("\"" + reversed_string_array[i] + "\", ");
	}

	cout << "Original: [ " << original_string << " ]" << endl;
	cout << "Reversed: [ " << reversed_string << " ]" << endl;
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
	vector<string> algorithm_names{ "FIZZBUZZ", "PYRAMID","VOWEL_COUNTER", "REVERSE_ARRAY" };

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
			printChoiceInfo(
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
			printChoiceInfo(
				"This algorithm prints a pyramid with 10 rows.\n--- Example ---\n"
			);
			pyramid();
			printAlgorithmNameBanner(algorithm_names.at(1));
			break;
		case '3':
			printAlgorithmNameBanner(algorithm_names.at(2));
			printChoiceInfo(
				"This algorithm returns the number of vowels ('a', 'e', 'i', 'o', 'u') used in a #string#.\n--- Example ---\n"
			);
			vowelCounter();
			printAlgorithmNameBanner(algorithm_names.at(2));
			break;
			break;
		case '4':
			printAlgorithmNameBanner(algorithm_names.at(3));
			printChoiceInfo(
				"This algorithm returns a reversed array.\n--- Example ---\n"
			);
			reverseArray();
			printAlgorithmNameBanner(algorithm_names.at(3));
			break;
		case '0':
			printChoiceInfo("Exiting application. Goodbye!");
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
