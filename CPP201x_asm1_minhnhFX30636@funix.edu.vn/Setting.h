#ifndef SETTING_H
#define SETTING_H

#include <iostream>
#include <iomanip>
#include <string>

#include "CommonInfo.h"

class Setting {
public:
	virtual void inputSettings() = 0;
	virtual void displaySettings() const = 0;
};

#endif // SETTING_H