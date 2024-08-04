#ifndef SOUND_H
#define SOUND_H

#include "Setting.h"
#include <iostream>
#include <string>

class Sound : public Setting {
public:
	Sound();
	~Sound() = default;

	// override Setting
	void inputSettings() override;
	void displaySettings() const override;

	// getters
	int get_media_level();
	int get_call_level();
	int get_navi_level();
	int get_notification_level();

	// setters
	void set_media_level(int data);
	void set_call_level(int data);
	void set_navi_level(int data);
	void set_notification_level(int data);

private:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
};
#endif // SOUND_H

