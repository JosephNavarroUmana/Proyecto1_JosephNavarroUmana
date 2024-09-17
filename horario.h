#pragma once
#include<iostream>
using namespace std;

class Schedules
{
private:
	string date;
	string firstTime;
	string secondTime;
public:
	Schedules();
	Schedules(string date_, string firstTime_, string secondTime_);
	string getFirstTime();
	void toString();
	~Schedules();
	bool isLessThan30MinutesRemaining();
};