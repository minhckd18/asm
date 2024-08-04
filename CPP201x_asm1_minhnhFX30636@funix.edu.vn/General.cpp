#include "General.h"
#include "CommonInfo.h"

General::General() : timeZone(""), language("") {}

void General::inputSettings(){
	// Your code
}

void General::displaySettings(){
	// Your code
}

string General::get_language(){
	return this->language;
}

string General::get_timeZone(){
	return this->timeZone;
}

void General::set_timeZone(string data){
	this->timeZone = data;
}

void General::set_language(string data){
	this->language = data;
}
