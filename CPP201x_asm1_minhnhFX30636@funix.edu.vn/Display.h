#ifndef DISPLAY_H
#define DISPLAY_H

#include "Setting.h"
#include <iostream>
#include <string>

class Display : public Setting{

public:
	Display();
	Display(int light, int screen_light, int taplo_light);
	~Display() = default;

	// override Setting
	void inputSettings() override;
	void displaySettings() const override;

	// getters
	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();

	// setters
	void set_light_level(int data);
	void set_screen_light_level(int data);
	void set_taplo_light_level(int data);
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};

#endif // DISPLAY_H

