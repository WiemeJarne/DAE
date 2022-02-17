// 07Classes1HandsonTheory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Player.h"
#include <vector>

void Function(Player* pPlayer); 

int main()
{
    std::cout << "Hello World!\n";

	std::cout << "Amount of players is:" << Player::GetAmountOfPlayers() << '\n';

	// object is on the heap, the pointer is on the stack!!
	Player* pHeapPlayer{ new Player{ "Mr Heap" } };
	pHeapPlayer->SetScore(20);

	std::cout << "Amount of players is:" << Player::GetAmountOfPlayers() << '\n';

	Player* pHeapPlayer2{ new Player{ "Mr Heap2" } };

	std::cout << "Amount of players is:" << Player::GetAmountOfPlayers() << '\n';

	pHeapPlayer->ShowMessage();

	Function(pHeapPlayer);

	delete pHeapPlayer2;
	pHeapPlayer2 = nullptr;
	delete pHeapPlayer;
	pHeapPlayer = nullptr;

	std::cout << "Amount of players is:" << Player::GetAmountOfPlayers() << '\n';

	Function(pHeapPlayer);
	
	std::vector<Player*> playerPtrs;

	for (int index{}; index < 100; ++index)
	{
		playerPtrs.push_back( new Player{ std::string("Player nummer ") + std::to_string(index + 1) } );
	}

	std::cout << "Amount of players is:" << Player::GetAmountOfPlayers() << '\n';

	for (int index{}; index < 100; ++index)
	{
		playerPtrs[index]->ShowMessage();
	}

	for (int index{}; index < 100; ++index)
	{
		delete playerPtrs[index];
		std::cout << "Amount of players is: " << Player::GetAmountOfPlayers() << '\n';
	}

	playerPtrs.clear();
}

void Function(Player* pPlayer)
{
	if (pPlayer != nullptr)
	{
		pPlayer->SetScore(42);
		pPlayer->ShowMessage();
	}
}