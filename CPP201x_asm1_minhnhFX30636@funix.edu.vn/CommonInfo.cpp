#include "CommonInfo.h"

CommonInfo::CommonInfo() : owner_name(""), personal_key(""), email(""), odo(0), service_remind(0) {}

CommonInfo::CommonInfo(string name, string key, string email, int odo, int service)
{
	this->setOwnerName(name);
	this->setPersonalKey(key);
	this->setEmail(email);
	this->setODO(odo);
	this->setServiceRemind(service);
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
void CommonInfo::setOwnerName(string data)
{
	this->owner_name = data;
}

void CommonInfo::setPersonalKey(string data)
{
	this->personal_key = data;
}

void CommonInfo::setEmail(string data)
{
	this->email = data;
}

void CommonInfo::setODO(int data)
{
	this->odo = data;
}

void CommonInfo::setServiceRemind(int data)
{
	this->service_remind = data;
}

string CommonInfo::parseData()
{
	std::stringstream ss;
	ss << this->owner_name << " " << this->personal_key << " " << this->email << " " << this->odo << " " << this->service_remind;
	return ss.str();
}

void CommonInfo::display_common_info()
{
	cout << left << setw(20) << this->owner_name
		<< left << setw(20) << this->email
		<< left << setw(20) << this->personal_key
		<< left << setw(20) << this->odo
		<< left << setw(20) << this->service_remind;
}