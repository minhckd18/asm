#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class CommonInfo{
public:
	CommonInfo();
	CommonInfo(string name, string key, string email, int odo, int service);
	~CommonInfo() = default;

	// getters
	string getOwnerName();
	string getPersonalKey();
	string getEmail();
	int getODO();
	int getServiceRemind();
	
	// setters
	void setOwnerName(string data);
	void setPersonalKey(string data);
	void setEmail(string data);
	void setODO(int data);
	void setServiceRemind(int data);
	
	string parseData();
	void display_common_info();
	
private:
	string owner_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};

#endif // COMMON_H_
