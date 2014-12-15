#ifndef _Menu_h
#define _Menu_h

#include <Wire.h>

#include <RTClib.h>
#include <LiquidCrystal\LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

#include "Arduino.h"


class Menu
{
private:

#ifndef I2C


	LiquidCrystal *lcd;

#endif
#ifdef I2C

	LiquidCrystal_I2C *lcd;





#endif
	RTC_DS1307 *rtc;

	char lO[17];
	char lB[17];
	char rO[17];
	char rB[17];
	char cB[17];
	char cO[17];

	int _lcdLength;
	int _lcdHeight;

	bool _useRTC;

public:
#ifdef I2C
	void initI2C(){
		this->lcd->init();
		this->lcd->backlight();
		if (_useRTC){
			Wire.begin();
			this->rtc->begin();
		}
	}
	Menu(LiquidCrystal_I2C *scherm, RTC_DS1307 *realTimeClock, int lcdLength, int lcdHeight){
		_lcdLength = lcdLength;
		_lcdHeight = lcdHeight;
		this->lcd = scherm;
		this->rtc = realTimeClock;
		_useRTC = true;
	};

	Menu(LiquidCrystal_I2C *lcd, int lcdLength, int lcdHeight){
		_lcdLength = lcdLength;
		_lcdHeight = lcdHeight;
		initI2C();
	};


#else
	Menu(LiquidCrystal *lcd, int lcdLength, int lcdHeight){
		this->lcd = lcd;
		_lcdLength = lcdLength;
		_lcdHeight = lcdHeight;
		this->lcd->begin(_lcdLength, _lcdHeight);
	};

	Menu(LiquidCrystal *lcd, RTC_DS1307 *rtc, int lcdLength, int lcdHeight){
		this->lcd = lcd;
		this->rtc = rtc;
		Wire.begin();
		this->rtc->begin();
		_lcdLength = lcdLength;
		_lcdHeight = lcdHeight;
		this->lcd->begin(_lcdLength, _lcdHeight);
	}
#endif

	void off();

	void all(char lB[], char rB[], char lO[], char rO[]){
		linksBoven(lB);
		rechtsBoven(rB);
		linksOnder(lO);
		rechtsOnder(rO);
	};

	void linksBoven(char s[]){
		strcpy(lB, s);
		if (strlen(lB) > 0)	{
			this->lcd->setCursor(0, 0);
			this->lcd->print(lB);
		}

	}
	void linksOnder(char s[]){
		strcpy(lO, s);

		if (strlen(lO) > 0)	{
			this->lcd->setCursor(0, 1);
			this->lcd->print(lO);
		}

	}
	void rechtsBoven(char s[]){

		strcpy(rB, s);
		int rBlength = strlen(rB);


		this->lcd->setCursor(16 - rBlength - 1, 0);

		if (rBlength > 0)	{
			this->lcd->print(" ");
			this->lcd->print(rB);
		}
	}

	void rechtsOnder(char s[]){

		strcpy(rO, s);
		int rOlength = strlen(rO);


		this->lcd->setCursor(16 - rOlength-1, 1);

		if (rOlength > 0)	{
			this->lcd->print(" ");
			this->lcd->print(rO);
		}

	}
	void centerBoven(char s[]){
		strcpy(cB, s);
		int cbLength = strlen(cB);
		int col = 0; int row = 0;
		int positie = floor((_lcdLength - cbLength) / 2);
		this->lcd->setCursor(col, row);
		for (int i = 0; i < positie; i++)	{
			this->lcd->print(" ");
		}
		this->lcd->setCursor(positie, 0);
		this->lcd->print(s);
		for (int i = positie + cbLength; i <= 16; i++) this->lcd->print(" ");
	}


	void centerOnder(char s[]){

		int lBLength = strlen(lB);
		int lOLength = strlen(lO);
		int rBLength = strlen(rB);
		int rOLength = strlen(rO);

			this->lcd->clear();

			if (lBLength > 0)	{
				this->lcd->setCursor(0, 0);
				this->lcd->print(lB);
			}

			if (rBLength > 0)	{
				int pos = _lcdLength - rBLength - 1;
				this->lcd->setCursor(pos, 0);
				this->lcd->print(" ");
				this->lcd->print(rB);
			}

			if (lOLength > 0)	{
				this->lcd->setCursor(0, 1);
				this->lcd->print(lO);
			}
			if (rOLength > 0)	{
				int pos = _lcdLength - rOLength - 1;
				this->lcd->setCursor(pos, 1);
				this->lcd->print(" ");
				this->lcd->print(rO);
			}
		
	}


#pragma region huidige tijd printen
	void timeLinksBoven(){
		linksBoven(getTimeString());
	}
	void timeRechtsBoven(){
		rechtsBoven(getTimeString());
	}
	void timeLinksOnder(){
		linksOnder(getTimeString());
	}
	void timeRechtsOnder(){
		rechtsOnder(getTimeString());
	}
#pragma endregion


	//NOK
#pragma region custom tijd printen
	void timeLinksBoven(DateTime time){
		linksBoven(getTimeString(time));
	}


	void timeRechtsBoven(DateTime time){
		rechtsBoven(getTimeString(time));
	}


	void timeLinksOnder(DateTime time){
		linksOnder(getTimeString(time));
	}


	void timeRechtsOnder(DateTime time){
		rechtsOnder(getTimeString(time));
	}
#pragma endregion


	//NOK
#pragma region huidige datum printen

	void dateLinksBoven(){
		linksBoven(getDateString());
	}

	void dateRechtsBoven(){
		rechtsBoven(getDateString());
	}


	void dateLinksOnder(){
		linksOnder(getDateString());
	}


	void dateRechtsOnder(){
		rechtsOnder(getDateString());
	}
#pragma endregion


	//NOK
#pragma region custom datum printen
	void dateLinksBoven(DateTime date){
		linksBoven(getDateString(date));
	}

	void dateRechtsBoven(DateTime date){
		rechtsBoven(getDateString(date));
	}


	void dateLinksOnder(DateTime date){
		linksOnder(getDateString(date));
	}


	void dateRechtsOnder(DateTime date){

		rechtsOnder(getDateString(date));
	}
#pragma endregion


	void printAll();


	char* timeToString(int hours, int minutes, int seconds);
	char* getTimeString();
	char* getTimeString(DateTime time);
	char* getDateString();
	char* getDateString(DateTime date);

private:
	void clear(){
		this->lcd->clear();

	}


};
#endif
