#include "pch.h"
#include "Player.h"
#include <iostream>

int Player::m_AmountOfPlayers{};

Player::Player(const std::string& name)
	: m_Name{name}
	, m_Score{}
{
	std::cout << m_Name << ": constructor is executing\n";
	++m_AmountOfPlayers;
}

Player::~Player()
{
	std::cout << m_Name << ": destructor is executed\n";
	--m_AmountOfPlayers;
}

void Player::ShowMessage() const
{
	std::string message{ GenerateMessage() };
	std::cout << message << '\n';
}

void Player::SetScore(int newScore)
{ 
	if (newScore >= 0)
	{
		m_Score = newScore;
	}
}

std::string Player::GenerateMessage() const
{
	std::string message{ "I am " + m_Name + " and my score is: " + std::to_string(m_Score) };
	return message;
}

int Player::GetAmountOfPlayers()
{
	return m_AmountOfPlayers;
}