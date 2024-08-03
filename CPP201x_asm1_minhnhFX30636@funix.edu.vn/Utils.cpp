#include "Utils.h"

using namespace std;

void readInt(istream& is, unsigned int& num)
{
    while (1)
    {
        if (!(is >> num))
        {
            cout << "Please input a positive integer" << endl;
            continue;
        }
        else
        {
            break;
        }
    }
}
