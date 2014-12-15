#include "Menu.h"
//LiquidCrystal lcd1(22, 23, 24, 25, 26, 27);
/*
Menu::Menu(LiquidCrystal *lcd, int lcdLength, int lcdHeight){
this->lcd = lcd;
_lcdLength = lcdLength;
_lcdHeight = lcdHeight;
this->lcd->begin(_lcdLength, _lcdHeight);
}

Menu::Menu(LiquidCrystal *lcd, RTC_DS1307 *rtc, int lcdLength, int lcdHeight){
this->lcd = lcd;
this->rtc = rtc;
Wire.begin();
this->rtc->begin();
_lcdLength = lcdLength;
_lcdHeight = lcdHeight;
this->lcd->begin(_lcdLength, _lcdHeight);
}

Menu::Menu(LiquidCrystal_I2C *lcd, RTC_DS1307, int lcdLength, int lcdHeight){
Serial.println("test");
Serial.println("test");
this->lcd = lcd;
this->rtc = rtc;
Wire.begin();
this->rtc->begin();
_lcdLength = lcdLength;
_lcdHeight = lcdHeight;
this->lcd->init();
this->lcd->noBacklight();
}

*/
#pragma region update text



#pragma region "huidige tijd printen"
//code is placed in header
#pragma endregion

#pragma region custom tijd printen
//code in header
#pragma endregion

#pragma region huidige datum printen
//code in header
#pragma endregion

#pragma region custom datum printen
//code in header
#pragma endregion

char* Menu::timeToString(int hours, int minutes, int seconds){ //positie: lB,lO,rB,rO
	char tijd[8];
	char h[2];
	char m[2];
	char s[2];

	itoa(hours, h, 10);
	itoa(minutes, m, 10);
	itoa(seconds, s, 10);

	if (hours < 10) strcpy(tijd, "0");

	strcat(tijd, h);
	strcat(tijd, ":");

	if (minutes < 10) strcat(tijd, "0");
	strcat(tijd, m);
	strcat(tijd, ":");
	if (seconds < 10) strcat(tijd, "0");
	strcat(tijd, s);
	strcat(tijd, ":");

	return tijd;
}

char* Menu::getTimeString(){
	DateTime now = this->rtc->now();

	char tijd[5];
	char h[2];
	char m[2];

	int hours = now.hour();
	int minutes = now.minute();

	itoa(hours, h, 10);
	itoa(minutes, m, 10);

	if (hours < 10) {
		strcat(tijd, "0");
	}
	strcat(tijd, h);
	if (minutes < 10) {
		strcat(tijd, "0");
	}
	strcat(tijd, ":");
	strcat(tijd, h);
	Serial.println(tijd);
	return tijd;
}
char*  Menu::getTimeString(DateTime time){

	char tijd[5];
	char h[2];
	char m[2];

	int hours = time.hour();
	int minutes = time.minute();

	itoa(hours, h, 10);
	itoa(minutes, m, 10);

	if (hours < 10) {
		strcat(tijd, "0");
	}
	strcat(tijd, h);
	if (minutes < 10) {
		strcat(tijd, "0");
	}
	strcat(tijd, ":");
	strcat(tijd, h);
	return tijd;
}


char*  Menu::getDateString(){
	DateTime now = this->rtc->now();
	char dag[2];
	char maand[2];
	char jaar[2];
	char datum[8];

	int d = now.day();
	int m = now.month();
	int y = now.year() - 2000;

	itoa(d, dag, 10);
	itoa(m, maand, 10);
	itoa(y, jaar, 10);

	strcat(datum, dag);
	strcat(datum, "/");
	strcat(datum, maand);
	strcat(datum, "/");
	strcat(datum, jaar);
	return datum;
}
char*  Menu::getDateString(DateTime date){
	char dag[2];
	char maand[2];
	char jaar[2];
	char datum[8];

	int d = date.day();
	int m = date.month();
	int y = date.year() - 2000;

	itoa(d, dag, 10);
	itoa(m, maand, 10);
	itoa(y, jaar, 10);

	strcat(datum, dag);
	strcat(datum, "/");
	strcat(datum, maand);
	strcat(datum, "/");
	strcat(datum, jaar);
	return datum;
}
