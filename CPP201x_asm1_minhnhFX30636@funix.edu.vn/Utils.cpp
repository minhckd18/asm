#include "Utils.h"

using namespace std;

void readInt(istream& is, int& num, const int& max, const int& min)
{
	string input;

	while (true)
	{
		is.clear();

		// Check and remove if there's anything left in buffer
		if (is.rdbuf()->in_avail() > 0)
		{
			is.ignore(INT_MAX, '\n');
		}
		getline(is, input);

		// Trim leading and trailing whitespace
		input.erase(0, input.find_first_not_of(" \t"));
		input.erase(input.find_last_not_of(" \t") + 1);

		if (regex_match(input, regex("[0-9]{1,}")))
		{
			num = stoi(input);

			if (num < min || num > max)
			{
				cerr << "Please input a number from " << min << " to " << max << endl;
				cout << "Please try again: ";
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			cerr << "Please input a positive integer" << endl;
			cout << "Please try again: ";
			continue;
		}
	}
}