#include "Car.h"

Car::Car()
{
	this->set_common_info(nullptr);
	this->set_display(nullptr);
	//set_sound(nullptr);
	//set_general(nullptr);
}

Car::~Car()
{
	delete common_info;
	delete display;
	//delete sound;
	//delete general;
}

CommonInfo* Car::get_common_info() { return this->common_info; }
Setting* Car::get_display() { return this->display; }
//Setting* Car::get_sound() { return this->sound; }
//Setting* Car::get_general() { return this->general; }

// setters
void Car::set_common_info(CommonInfo* data) { this->common_info = data; }
void Car::set_display(Setting* data) { this->display = data; }
//void Car::set_sound(Setting* data) { this->sound = data; }
//void Car::set_general(Setting* data) { this->general = data; }