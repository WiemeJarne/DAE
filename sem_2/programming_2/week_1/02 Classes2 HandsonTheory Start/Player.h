#pragma once
#include <string>
class Player
{
public:
	Player(const std::string& name);
	~Player();
	void ShowMessage() const;
	void SetScore(int newScore);
	static int GetAmountOfPlayers();
private:
	std::string GenerateMessage() const;
	const std::string m_Name;
	int m_Score;
	static int m_AmountOfPlayers;
};
