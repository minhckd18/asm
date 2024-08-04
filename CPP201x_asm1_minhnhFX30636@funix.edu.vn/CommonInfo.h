#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Setting.h"
#include "Utils.h"

class CommonInfo : public Setting {

public:
	CommonInfo();
	CommonInfo(string name, string key, string email, int odo, int service);
	~CommonInfo() = default;

	// override
	void inputSettings() override;
	void displaySettings() const override;

	// getters
	string getOwnerName();
	string getPersonalKey();
	string getEmail();
	int getODO();
	int getServiceRemind();

	// setters
	void set_owner_name(string data);
	void set_personal_key(string data);
	void set_email(string data);
	void set_ODO(int data);
	void set_service_remind(int data);

	string parseData();
	void display_common_info();

private:
	string owner_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};

#endif // COMMON_H
