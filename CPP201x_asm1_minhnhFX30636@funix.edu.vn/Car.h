#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

#include "Setting.h"
#include "CommonInfo.h"

class Car
{
public:
	Car();
	~Car();

	// getters
	CommonInfo* get_common_info();
	Setting* get_display();
	Setting* get_sound();
	Setting* get_general();

	// setters
	void set_common_info(CommonInfo*);
	void set_display(Setting*);
	void set_sound(Setting*);
	void set_general(Setting*);

private:
	CommonInfo* common_info;

	Setting* display;
	//Setting* sound;
	//Setting* general;
};

#endif // CAR_H
