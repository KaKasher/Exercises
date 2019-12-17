#include <iostream>
#include <vector>
#include <string>

class Player
{
public:
	// attributes
	std::string name{ "Player" };
	unsigned int health = 100;
	unsigned int xp = 0;

	// methods
	void talk(std::string);
	bool isDead();

};

class Account
{
public:
	std::string name;
	double balance;

	// methods
	void deposit(double bal);
	void withdraw(double bal);
};

int main()
{
	Player player1;
	Player player2;

	std::vector<Player*> playerVec{ &player1 };
	playerVec.push_back(&player2);

	player1.name = "kaka";

	for (const Player* player : playerVec)
	{
		std::cout << player->name << std::endl;
	}
}