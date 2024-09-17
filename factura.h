#pragma once
#include <iostream>
#include"Cinema.h"
#include"ClassMovie.h"
#include"sala.h"
#include"horario.h"

class Invoice {
private:
	int ID;
	int card;
public:
	Invoice();
	~Invoice();
	void setID(int ID_);
	void setCard(int card_);
	int getID();
	int getCard();
	void voucher(Schedules vectorSchedule[],Movie vectorMovie[], Rooms vectorRooms[], int roomSeleted,int scheduleSelected, int code_);
};