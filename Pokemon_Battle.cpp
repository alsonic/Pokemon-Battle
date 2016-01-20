// ConsoleApplication122.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//**********************************************Pokemon Utility********************************************************

const int POTION_STR = 50;
const int MAX_HEALTH = 100;
const int MAX_POTION = 2;
const int CRITICAL_HIT = 3;
const int CRITICAL_HIT_FACTOR = 5;
const int RECOVER_FACTOR = 10;
const int DEMOBILIZE_FACTOR = 3;
const int MISS_FACTOR = 5;

//**********************************************Pokemon Abstract Class*************************************************
class Pokemon
{
public:
	Pokemon(int health = MAX_HEALTH, bool conscious = true);
	virtual void Greet() const = 0;
	void Potion();
	void DisplayHealth() const;
	
	virtual void move1(Pokemon& opponent);
	virtual void move2(Pokemon& opponent);
	virtual void move3(Pokemon& opponent);
	virtual void move4(Pokemon& opponent);

	int m_Health;
	bool m_Conscious;
};

Pokemon::Pokemon(int health, bool conscious) : m_Health(health), m_Conscious(conscious)
{

}

void Pokemon::Potion()
{
	m_Health += POTION_STR;
	if (m_Health > MAX_HEALTH)
		m_Health = MAX_HEALTH;
}

void Pokemon::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

void Pokemon::move1(Pokemon& opponent)
{

}

void Pokemon::move2(Pokemon& opponent)
{

}

void Pokemon::move3(Pokemon& opponent)
{

}

void Pokemon::move4(Pokemon& opponent)
{

}

//************************************************Pikachu Class*********************************************************

const int ELECTRIC_SHOCK_STR = 5;
const int ELECTRIC_WAVE_STR = 10;
const int THUNDER_SHOCK_STR = 15;
const int THUNDER_STR = 20;

class Pikachu : public Pokemon
{
public:
	virtual void Greet() const;
	virtual void move1(Pokemon& opponent);
	virtual void move2(Pokemon& opponent);
	virtual void move3(Pokemon& opponent);
	virtual void move4(Pokemon& opponent);
};

void Pikachu::Greet() const
{
	cout << "Pika Pika!\n";
}

void Pikachu::move1(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Pikachu!\n";
		opponent.m_Health -= ELECTRIC_SHOCK_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= ELECTRIC_SHOCK_STR;
	}
	if (rand() % DEMOBILIZE_FACTOR == 0)
	{
		opponent.m_Conscious = false;
		cout << "Pikachu has demobilized the opponent!\n";
	}
}

void Pikachu::move2(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Pikachu!\n";
		opponent.m_Health -= ELECTRIC_WAVE_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= ELECTRIC_WAVE_STR;
	}
}

void Pikachu::move3(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Pikachu!\n";
		opponent.m_Health -= THUNDER_SHOCK_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= THUNDER_SHOCK_STR;
	}
}

void Pikachu::move4(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % MISS_FACTOR != 0)
	{
		if (rand() % CRITICAL_HIT_FACTOR == 0)
		{
			cout << "Critical Hit from Pikachu!\n";
			opponent.m_Health -= THUNDER_STR*CRITICAL_HIT;
		}
		else
		{
			opponent.m_Health -= THUNDER_STR;
		}
	}
	else
	{
		cout << "Pikachu's Thunder missed...\n";
	}
}

//***************************************************Bulbasaur Class*****************************************************

const int VINE_WHIP_STR = 5;
const int POISON_POWDER_STR = 10;
const int RAZOR_LEAF_STR = 15;
const int SEED_BOMB_STR = 20;

class Bulbasaur : public Pokemon
{
public:
	virtual void Greet() const;
	virtual void move1(Pokemon& opponent);
	virtual void move2(Pokemon& opponent);
	virtual void move3(Pokemon& opponent);
	virtual void move4(Pokemon& opponent);
};

void Bulbasaur::Greet() const
{
	cout << "Da-ne Da-ne!\n";
}

void Bulbasaur::move1(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Bulbasaur!\n";
		opponent.m_Health -= VINE_WHIP_STR*CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= VINE_WHIP_STR;
	}
	if (rand() % DEMOBILIZE_FACTOR == 0)
	{
		opponent.m_Conscious = false;
		cout << "Bulbasaur has demobilized the opponent!\n";
	}
}

void Bulbasaur::move2(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Bulbasaur!\n";
		opponent.m_Health -= POISON_POWDER_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= POISON_POWDER_STR;
	}
}

void Bulbasaur::move3(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % CRITICAL_HIT_FACTOR == 0)
	{
		cout << "Critical Hit from Bulbasaur!\n";
		opponent.m_Health -= RAZOR_LEAF_STR * CRITICAL_HIT;
	}
	else
	{
		opponent.m_Health -= RAZOR_LEAF_STR;
	}
}

void Bulbasaur::move4(Pokemon& opponent)
{
	srand(time(0));
	if (rand() % MISS_FACTOR != 0)
	{
		if (rand() % CRITICAL_HIT_FACTOR == 0)
		{
			cout << "Critical Hit from Bulbasaur!\n";
			opponent.m_Health -= SEED_BOMB_STR * CRITICAL_HIT;
		}
		else
		{
			opponent.m_Health -= SEED_BOMB_STR;
		}
	}
	else
	{
		cout << "Bulbasaur's Seed Bomb missed...\n";
	}
}

//***************************************************Program Utility******************************************************

Pokemon* PokemonSelect(Pikachu& Pika, Bulbasaur& Bulba, int choice);

int main()
{
	cout << "Welcome to Pokemon Battle Arena!\n\n";
	cout << "You will be able to pick a pokemon of your choice for the battle.\n";
	cout << "For this battle, you and your opponent are each given " << MAX_POTION << " potions.\n\n";
	cout << "Please select a pokemon from the following: \n";
	cout << "1 - Pikachu\n";
	cout << "2 - Bulbasaur\n";

	int choice;
	cin >> choice;

	Pikachu Pika;
	Bulbasaur Bulba;

	Pokemon* Player1 = PokemonSelect(Pika, Bulba, choice);
	Pokemon* Player2;

	int potion_count_p1 = MAX_POTION;
	int potion_count_p2 = MAX_POTION;

	(*Player1).Greet();
	
	if (choice == 1)
	{
		cout << "You have chosen a Pikachu!\n";
		cout << "You will be fighting against a Bulbasaur.\n\n";
		Player2 = &Bulba;
	}
	else
	{
		cout << "You have chosen a Bulbasaur!\n";
		cout << "You will be fighting against a Pikachu.\n\n";
		Player2 = &Pika;
	}

	while (((*Player1).m_Health > 0) && ((*Player2).m_Health > 0))
	{
		cout << "Your health is now " << (*Player1).m_Health << ".\n";
		cout << "Your opponent's health is now " << (*Player2).m_Health << ".\n\n";

		int move;
		cout << "Please select your next move from the following: \n";

		if (choice == 1)
		{
			cout << "1 - Electric Shock\n";
			cout << "2 - Electric Wave\n";
			cout << "3 - Thunder Shock\n";
			cout << "4 - Thunder\n";
			cout << "5 - Take a Potion\n";
		}
		else
		{
			cout << "1 - Vine Whip\n";
			cout << "2 - Poison Powder\n";
			cout << "3 - Razor Leaf\n";
			cout << "4 - Seed Bomb\n";
			cout << "5 - Take a Potion\n";
		}

		cin >> move;
		while (move != 1 && move != 2 && move != 3 && move != 4 && move != 5)
		{
			cout << "You have made an invalid move. Please select your move again: \n";
			cin >> move;
		}
		if ((*Player1).m_Conscious)
		{
			switch (move)
			{
			case 1:
			{
				if (choice == 1)
				{
					cout << "Pikachu uses Electric Shock.\n\n";
				}
				else
				{
					cout << "Bulbasaur uses Vine Whip.\n\n";
				}
				(*Player1).move1(*Player2);
				break;
			}
			case 2:
			{
				if (choice == 1)
				{
					cout << "Pikachu uses Electric Wave.\n\n";
				}
				else
				{
					cout << "Bulbasaur uses Poison Powder.\n\n";
				}
				(*Player1).move2(*Player2);
				break;
			}
			case 3:
			{
				if (choice == 1)
				{
					cout << "Pikachu uses Thunder Shock.\n\n";
				}
				else
				{
					cout << "Bulbasaur uses Razor Leaf.\n\n";
				}
				(*Player1).move3(*Player2);
				break;
			}
			case 4:
			{
				if (choice == 1)
				{
					cout << "Pikachu uses Thunder.\n\n";
				}
				else
				{
					cout << "Bulbasaur uses Seed Bomb.\n\n";
				}
				(*Player1).move4(*Player2);
				break;
			}
			case 5:
			{
				if (potion_count_p1 > 0)
				{
					if (choice == 1)
					{
						cout << "Pikachu uses Potion. Health replenished by 50 HP.\n\n";
					}
					else
					{
						cout << "Bulbasaur uses Potion. Health replenished by 50 HP.\n\n";
					}
					(*Player1).Potion();
					potion_count_p1--;
					break;
				}
				else
				{
					cout << "You've run out of potion!.\n\n";
					break;
				}
			}
			}
		}
		else
		{
			if (choice == 1)
			{
				cout << "Sorry, your Pikachu is still unable to move. You miss a turn.\n";
				srand(time(0));
				if (rand() % RECOVER_FACTOR != 0)
				{
					(*Player1).m_Conscious = true;
					cout << "Your Pikachu has recovered and is once again ready for battle!\n";
				}
			}
			else
			{
				cout << "Sorry, your Bulbasaur is still unable to move. You miss a turn.\n";
				srand(time(0));
				if (rand() % RECOVER_FACTOR != 0)
				{
					(*Player1).m_Conscious = true;
					cout << "Your Bulbasaur has recovered and is once again ready for battle!\n";
				}
			}
		}

		if (((*Player2).m_Health) > 0 && ((*Player2).m_Conscious))
		{
			cout << "You've made your move. Now, it's your opponent's turn!\n\n";

			if ((*Player2).m_Health <= 20 && (potion_count_p2 != 0))
			{
				if (choice == 1)
				{
					cout << "Bulbasaur uses Potion. Health replenished by 50 HP.\n\n";
				}
				else
				{
					cout << "Pikachu uses Potion. Health replenished by 50 HP.\n\n";
				}
				(*Player2).Potion();
				potion_count_p2--;
			}
			else
			{
				srand(time(0));
				int retaliate = ((rand() % 4) + 1);
				switch (retaliate)
				{
				case 1:
				{
					if (choice == 1)
					{
						cout << "Bulbasaur uses Vine Whip.\n\n";
					}
					else
					{
						cout << "Pikachu uses Electric Shock.\n\n";
					}
					(*Player2).move1(*Player1);
					break;
				}
				case 2:
				{
					if (choice == 1)
					{
						cout << "Bulbasaur uses Poison Powder.\n\n";
					}
					else
					{
						cout << "Pikachu uses Electric Wave.\n\n";
					}
					(*Player2).move2(*Player1);
					break;
				}
				case 3:
				{
					if (choice == 1)
					{
						cout << "Bulbasaur uses Razor Leaf.\n\n";
					}
					else
					{
						cout << "Pikachu uses Thunder Shock.\n\n";
					}
					(*Player2).move3(*Player1);
					break;
				}
				case 4:
				{
					if (choice == 1)
					{
						cout << "Bulbasaur uses Seed Bomb.\n\n";
					}
					else
					{
						cout << "Pikachu uses Thunder.\n\n";
					}
					(*Player2).move4(*Player1);
					break;
				}
				}
			}
		}
		else if (!(*Player2).m_Conscious)
		{
			if (choice == 1)
			{
				cout << "Your opponent Bulbasaur is unable to move. Your opponent misses a turn.\n";
				srand(time(0));
				if (rand() % RECOVER_FACTOR != 0)
				{
					(*Player2).m_Conscious = true;
					cout << "Bulbasaur has recovered and is once again ready for battle!\n";
				}
			}
			else
			{
				cout << "Your opponent Pikachu is unable to move. Your opponent misses a turn.\n";
				srand(time(0));
				if (rand() % RECOVER_FACTOR != 0)
				{
					(*Player2).m_Conscious = true;
					cout << "Pikachu has recovered and is once again ready for battle!\n";
				}
			}
		}
		else
		{
			if (choice == 1)
			{
				cout << "Congratulations! You've defeated your opponent Bulbasaur.\n";
			}
			else
			{
				cout << "Congratulations! You've defeated your opponent Pikachu.\n";
			}
			cout << "Your remaining health is " << (*Player1).m_Health << ".\n\n";
		}
	}

	if ((*Player1).m_Health <= 0)
	{
		if (choice == 1)
		{
			cout << "Your Pikachu has fainted. Game Over!\n";
			cout << "Better luck next time.\n";
		}
		else
		{
			cout << "Your Bulbasaur has fainted. Game Over!\n";
			cout << "Better luck next time.\n";
		}
	}

    return 0;
}


Pokemon* PokemonSelect(Pikachu& Pika, Bulbasaur& Bulba, int choice)
{
	while (choice != 1 && choice != 2)
	{
		cout << "You have entered an invalid choice. Please choose again: ";
		cin >> choice;
	}
	if (choice == 1)
	{
		Pikachu* pPika = &Pika;
		return pPika;
	}
	else
	{
		Bulbasaur* pBulba = &Bulba;
		return pBulba;
	}
}