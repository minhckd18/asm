#include "Display.h"

Display::Display() : light_level(0), screen_light_level(0), taplo_light_level(0) {}

Display::Display(int light, int screen_light, int taplo_light)
{
	this->set_light_level(light);
	this->set_screen_light_level(screen_light);
	this->set_taplo_light_level(taplo_light);
}

int Display::get_light_level()
{
	return this->light_level;
}

int Display::get_screen_light_level()
{
	return this->screen_light_level;
}

int Display::get_taplo_light_level() 
{
	return this->taplo_light_level;
}

void Display::set_light_level(int data)
{
	this->light_level = data;
}

void Display::set_screen_light_level(int data)
{
	this->screen_light_level = data;
}

void Display::set_taplo_light_level(int data)
{
	this->taplo_light_level = data;
}

void Display::inputSettings()
{
	int light, screen_light, taplo_light;
	std::cout << "Light level: ";
	std::cin >> light;
	this->set_light_level(light);
	std::cout << "Screen light level: ";
	std::cin >> screen_light;
	this->set_screen_light_level(screen_light);
	std::cout << "Taplo light level: ";
	std::cin >> taplo_light;
	this->set_taplo_light_level(taplo_light);
}

void Display::displaySettings() const
{
	cout << left << setw(20) << this->light_level
		<< left << setw(20) << this->screen_light_level
		<< left << setw(20) << this->taplo_light_level;
}