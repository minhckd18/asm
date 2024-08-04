#include "Sound.h"

Sound::Sound(): media_level(0), call_level(0), navi_level(0), notification_level(0) {}

void Sound::inputSettings()
{
	cout << "Media volumn level: ";
	cin >> media_level;
	cout << "Call volumn level: ";
	cin >> call_level;
	cout << "Navigation volumn level: ";
	cin >> navi_level;
	cout << "Notification volumn level: ";
	cin >> notification_level;
}

void Sound::displaySettings() const
{
	cout << left << setw(20) << this->media_level
		<< left << setw(20) << this->call_level
		<< left << setw(20) << this->navi_level
		<< left << setw(20) << this->notification_level;
}

int Sound::get_media_level(){
	return this->media_level;
}

int Sound::get_call_level(){
	return this->call_level;
}

int Sound::get_navi_level(){
	return this->navi_level;
}

int Sound::get_notification_level(){
	return this->notification_level;
}

void Sound::set_media_level(int data){
	this->media_level = data;
}

void Sound::set_call_level(int data){
	this->call_level = data;
}

void Sound::set_navi_level(int data){
	this->navi_level = data;
}

void Sound::set_notification_level(int data){
	this->notification_level = data;
}

