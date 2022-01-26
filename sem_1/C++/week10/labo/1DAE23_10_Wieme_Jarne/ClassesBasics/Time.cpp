#include "pch.h"
#include "Time.h"

Time::Time(float seconds)
	:m_Seconds{seconds}
{
	//no code
}

Time::Time(float minutes, float seconds)
	:m_Seconds{60*minutes + seconds}
{
	//no code
}

Time::Time(float hours, float minutes, float seconds)
	: m_Seconds{ 3600 * hours + 60 * minutes + seconds }
{
	//no code
}

void Time::AddHours(float hours)
{
	m_Seconds += 3600 * hours;
}

void Time::AddMinutes(float minutes)
{
	m_Seconds += 60 * minutes;
}

void Time::AddSeconds(float seconds)
{
	m_Seconds += seconds;
}

int Time::GetHours()
{
	return int(m_Seconds / 3600);
}

int Time::GetMinutes()
{
	return  int((m_Seconds - GetHours() * 3600) / 60);
}

int Time::GetSeconds()
{
	return m_Seconds - GetHours() * 3600 - GetMinutes() * 60;
}

void Time::Print()
{
	std::cout << GetHours() << ':' << GetMinutes() << ':' << GetSeconds() << '\n';
}