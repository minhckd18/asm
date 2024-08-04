#include "CommonInfo.h"

CommonInfo::CommonInfo() : owner_name(""), personal_key(""), email(""), odo(0), service_remind(0) {}

CommonInfo::CommonInfo(string name, string key, string email, int odo, int service)
{
	this->set_owner_name(name);
	this->set_personal_key(key);
	this->set_email(email);
	this->set_ODO(odo);
	this->set_service_remind(service);
}

// getters
string CommonInfo::getOwnerName()
{
	return this->owner_name;
}

string CommonInfo::getPersonalKey()
{
	return this->personal_key;
}

string CommonInfo::getEmail()
{
	return this->email;
}

int CommonInfo::getODO()
{
	return this->odo;
}

int CommonInfo::getServiceRemind()
{
	return this->service_remind;
}

// setters
void CommonInfo::set_owner_name(string data)
{
	this->owner_name = data;
}

void CommonInfo::set_personal_key(string data)
{
	this->personal_key = data;
}

void CommonInfo::set_email(string data)
{
	this->email = data;
}

void CommonInfo::set_ODO(int data)
{
	this->odo = data;
}

void CommonInfo::set_service_remind(int data)
{
	this->service_remind = data;
}

string CommonInfo::parseData()
{
	std::stringstream ss;
	ss << this->owner_name << " " << this->personal_key << " " << this->email << " " << this->odo << " " << this->service_remind;
	return ss.str();
}

void CommonInfo::displaySettings() const
{
	cout << left << setw(20) << this->owner_name
		<< left << setw(20) << this->email
		<< left << setw(20) << this->personal_key
		<< left << setw(20) << this->odo
		<< left << setw(20) << this->service_remind;
}

void CommonInfo::inputSettings()
{
	string owner_name, personal_key, email;
	int odo, service_remind;
	std::cout << "Owner name: ";
	getline(cin, owner_name);
	this->set_owner_name(owner_name);
	std::cout << "Email: ";
	getline(cin, email);
	this->set_email(email);
	std::cout << "Personal key: ";
	getline(cin, personal_key);
	this->set_personal_key(personal_key);
	std::cout << "ODO: ";
	readInt(cin, odo, 999999);
	this->set_ODO(odo);
	std::cout << "Service remind (km): ";
	readInt(cin, service_remind, 20000);
	this->set_service_remind(service_remind);
}