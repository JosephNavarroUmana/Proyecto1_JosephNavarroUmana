#pragma once
#include<iostream>
using namespace std;

class Movie
{
private:
	string name;
	int year;
	int duration;
	string country;
	string review;
public:
	Movie();
	Movie(string name_, int year_, int duration_, string country_, string review_);
	~Movie();
	string getName();
	void setName(string name_);
	void toString();
};