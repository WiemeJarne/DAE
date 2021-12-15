#pragma once
#include <iostream>

class Time
{
public:
	//constructors
	Time(float seconds);
	Time(float minutes, float seconds);
	Time(float hours, float minutes, float seconds);

	//public member functions
	void Print();
	void AddSeconds(float seconds);
	void AddMinutes(float minutes);
	void AddHours(float hours);

private:
	//private datamembers
	float m_Seconds;

	//private member functions
	int GetSeconds();
	int GetMinutes();
	int GetHours();
};

