#include <iostream>
//#include "CommonInfo.h"
#include "Display.h"
#include "Car.h"
#include "Utils.h"

namespace MH_1
{
	const int SELECTION_MIN = 0;
	const int SELECTION_MAX = 2;
}

namespace MH_2
{
	const int SELECTION_MIN = 0;
	const int SELECTION_MAX = 3;
}

namespace MH_3
{
	const int SELECTION_MIN = 0;
	const int SELECTION_MAX = 4;
}

using namespace std;

CommonInfo** infos = new CommonInfo * [100];
Setting** displays = new Setting * [100];
Car** cars = new Car * [100];
int carsCnt, displaysCnt, infosCnt;

void screen_1_display();
void screen_1_handler(int);
void screen_2_display();
void screen_2_handler(int);
void screen_3_display();
void screen_3_handler(int);

void input_common_info(Car* car);

void display_common_info_dummy();
void displaySettings_dummy();

string message = ""; // Error message to display

int main(int argc, int* argv[])
{
	// Testing
	cars[0] = new Car;
	cars[0]->set_common_info(new CommonInfo("Minh", "12345678", "minh@com", 100, 2000));
	cars[0]->set_display(new Display(10, 20, 30));
	cars[1] = new Car;
	cars[1]->set_common_info(new CommonInfo("Dung", "12345679", "dung@com", 100, 2000));
	//cars[1].set_display(displays[1]);
	carsCnt = 2;

	int selection_1 = 0;
	// End testing


	do
	{
		screen_1_display();
		readInt(cin, selection_1, MH_1::SELECTION_MAX);

		if (selection_1 != 0)
		{
			screen_1_handler(selection_1);
		}
		else
		{
			break;
		}
	} while (true);

	// End program
	system("cls");
	cout << "Turning off program..." << endl;
	cout << "Clearing memory..." << endl;

	// Delete cars memory
	for (int i = 0; i < 100; i++) {
		if (cars[i] != nullptr) {
			delete cars[i];
		}
	}
	delete[] cars;
	// Avoid dangling pointer
	cars = nullptr;

	cout << "GOOD BYE!" << endl;

	return 0;
}

void screen_1_display()
{
	system("cls");
	cout << " --- SELECT MENU --- " << endl;
	cout << "1. Input setting information" << endl;
	cout << "2. Print setting information" << endl;
	cout << "0. Exit" << endl;
	cout << "Your selection: ";
}

void screen_1_handler(int selection_1)
{
	int selection_2 = 0, selection_3 = 0;

	switch (selection_1)
	{
	case 1:
		do
		{
			screen_2_display();
			readInt(cin, selection_2, MH_2::SELECTION_MAX);

			if (selection_2 != 0)
			{
				screen_2_handler(selection_2);
			}
			else
			{
				break;
			}
		} while (true);
		break;
	case 2:
		do
		{
			screen_3_display();
			readInt(cin, selection_3, MH_3::SELECTION_MAX);

			if (selection_3 != 0)
			{
				screen_3_handler(selection_3);
			}
			else
			{
				break;
			}
		} while (true);
		break;
	case 0:
		// Do nothing, end the program
		break;
	default:
		// Nothing to do
		break;
	}
}

void screen_2_display()
{
	system("cls");
	cout << " --- SELECT MENU --- " << endl;
	cout << "1. Display setting" << endl;
	cout << "2. Sound setting" << endl;
	cout << "3. General setting" << endl;
	cout << "0. Return" << endl;
	cout << "Your selection: ";
}

void screen_2_handler(int selection_2)
{
	// Input display setting
	system("cls");
	cout << "---INPUT DISPLAY SETTING---" << endl;

	Car* target_car;
	input_common_info(target_car);

	switch (selection_2)
	{
	case 1:
	{
		Setting* target_display = target_car->get_display();
		// Input display setting		
		if (target_display != nullptr)
		{
			// Existed display setting -> overwrite
			target_display->inputSettings();
		}
		else
		{
			// New display setting -> allocate
			target_car->set_display(new Display);
			target_display = target_car->get_display();
			target_display->inputSettings();
		}
		break;
	}
	case 2:
		// something here
		break;
	case 3:
		// something here
		break;
	case 0:
		// Do nothing, return to screen 1
		break;
	default:
		// Nothing to do
		break;
	}
}

void screen_3_display()
{
	system("cls");
	cout << " --- SELECT MENU --- " << endl;
	cout << "1. Print Display setting information" << endl;
	cout << "2. Print Sound setting information" << endl;
	cout << "3. Print General setting information" << endl;
	cout << "4. Print all setting information" << endl;
	cout << "0. Return" << endl;
	cout << "Your selection: ";
}

void screen_3_handler(int selection_3)
{
	switch (selection_3)
	{
	case 1:
		// display setting
		system("cls");
		cout << "---DISPLAY SETTING---" << endl;
		cout << left << setw(20) << "Owner name"
			<< left << setw(20) << "Email"
			<< left << setw(20) << "Personal key"
			<< left << setw(20) << "ODO number"
			<< left << setw(20) << "Remind service"
			<< left << setw(20) << "Light level"
			<< left << setw(20) << "Screen light level"
			<< left << setw(20) << "Taplo light level" << endl;
		// cout << person1.parseData() << endl;
		for (int i = 0; i < carsCnt; ++i)
		{
			if (cars[i]->get_common_info() != nullptr)
				cars[i]->get_common_info()->displaySettings();
			else
				display_common_info_dummy();

			if (cars[i]->get_display() != nullptr)
				cars[i]->get_display()->displaySettings();
			else
				displaySettings_dummy();
			cout << endl;
		}
		system("pause");
		break;
	case 2:
		// something here
		break;
	case 3:
		// something here
		break;
	case 4:
		// something here
		break;
	case 0:
		// Do nothing, return to screen 1
		break;
	default:
		// Nothing to do
		break;
	}
}

void display_common_info_dummy()
{
	cout << left << setw(20) << ""
		<< left << setw(20) << ""
		<< left << setw(20) << ""
		<< left << setw(20) << ""
		<< left << setw(20) << "";
}

void displaySettings_dummy()
{
	cout << left << setw(20) << ""
		<< left << setw(20) << ""
		<< left << setw(20) << "";
}

void input_common_info(Car* target_car)
{
	// Create a temp car obj
	Car* tmp_car = new Car;

	// allocate memory for temp car common info
	tmp_car->set_common_info(new CommonInfo);

	// read input for temp common info
	tmp_car->get_common_info()->inputSettings();

	// check if existed in database based on id
	bool isExisted = false;
	int i = 0;
	for (i = 0; i < carsCnt; ++i)
	{
		if (cars[i]->get_common_info()->getPersonalKey() == tmp_car->get_common_info()->getPersonalKey())
		{
			isExisted = true;
			break;
		}
	}

	if (isExisted)
	{
		// if yes:
		// - overwrite common info into that existed car
		cout << "\t-> This car is already existed, data will be overwritten." << endl;
		target_car = cars[i]; // Car to be modified is already existed
		*(target_car->get_common_info()) = *(tmp_car->get_common_info());
		
		// - delete temp car memory
		delete tmp_car;
	}
	else
	{
		// if no, create new slot and point to the temp car obj
		cout << "\t-> This is a new car, data will be appended to your database" << endl;
		cars[carsCnt] = tmp_car;
		target_car = cars[carsCnt];
		carsCnt++;
	}
}