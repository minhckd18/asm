#include <iostream>
//#include "CommonInfo.h"
#include "Display.h"
#include "Car.h"

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
void display_common_info_dummy();
void displaySettings_dummy();

string message = ""; // Error message to display

int main(int argc, int* argv[])
{
	// Testing
	cars[0] = new Car;
	cars[0]->set_common_info(new CommonInfo("Minh", "123456ab", "minh@com", 100, 2000));
	cars[0]->set_display(new Display(10, 20, 30));
	cars[1] = new Car;
	cars[1]->set_common_info(new CommonInfo("Dung", "654321ab", "dung@com", 100, 2000));
	//cars[1].set_display(displays[1]);
	carsCnt = 2;

	int selection_1 = 0;
	// End testing


	do
	{
		screen_1_display();
		cin >> selection_1;
		screen_1_handler(selection_1);
	} while (selection_1 != 0);

	// End program
	system("cls");
	cout << "TURNING OFF PROGRAM ...\nGOOD BYE!" << endl;

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
			cin >> selection_2;
			screen_2_handler(selection_2);
		} while (selection_2 != 0);
		break;
	case 2:
		do
		{
			screen_3_display();
			cin >> selection_3;
			screen_3_handler(selection_3);
		} while (selection_3 != 0);
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
	if (selection_2 != 0)
	{
		// Input display setting
		system("cls");
		string tmp_name;
		string tmp_key;
		string tmp_email;
		string tmp_odo;
		string tmp_service_remind;
		bool isExisted = false;
		int i = 0;

		// Get personal key
		cout << "---INPUT DISPLAY SETTING---" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Owner name: ";
		getline(cin, tmp_name);
		cout << "Email: ";
		getline(cin, tmp_email);
		cout << "Please input personal key: ";
		getline(cin, tmp_key);
		cout << "ODO: ";
		getline(cin, tmp_odo);
		cout << "Service remind: ";
		getline(cin, tmp_service_remind);

		// Check if existed
		for (i = 0; i < carsCnt; ++i)
		{
			if (cars[i]->get_common_info()->getPersonalKey() == tmp_key)
			{
				isExisted = true;
				break;
			}
		}

		Car* target_car; // Pointer to the car that will be modified
		CommonInfo* target_common_info;
		Setting* target_display;
		Setting* target_sound;
		Setting* target_general;

		if (isExisted)
		{
			cout << "\t-> This car is already existed, data will be overwritten." << endl;
			target_car = cars[i]; // Car to be modified is already existed
			target_common_info = target_car->get_common_info();
		}
		else
		{
			cout << "\t-> This is a new car, data will be appended to your database" << endl;
			cars[carsCnt] = new Car;
			target_car = cars[carsCnt];
			target_car->set_common_info(new CommonInfo);
			target_common_info = target_car->get_common_info();
			carsCnt++;
		}

		target_common_info->setOwnerName(tmp_name);
		target_common_info->setPersonalKey(tmp_key);
		target_common_info->setEmail(tmp_email);
		target_common_info->setODO(stoi(tmp_odo));
		target_common_info->setServiceRemind(stoi(tmp_service_remind));

		target_display = target_car->get_display();
		//target_sound = target_car->get_sound();
		//target_general = target_car->get_general();

		switch (selection_2)
		{
		case 1:
		{
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
				cars[i]->get_common_info()->display_common_info();
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