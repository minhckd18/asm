#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>

#include "CommonInfo.h"

using namespace std;

class Setting {
public:
	virtual void inputSettings() = 0;
	virtual void displaySettings() const = 0;
};

#endif // SETTING_H

