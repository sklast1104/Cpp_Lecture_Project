#pragma once

#include <string>
using std::string;

class CMonster
{
private :
	string name;
	int health;
	int attack;

public :

	CMonster(string name, int health, int attack);
	~CMonster();

	void SetJobName(string name) {
		this->name = name;
	}

	const string& GetJobName() const {
		return name;
	}

	void Sethealth(int health) {
		this->health = health;
	}

	const int& GetHealth() const {
		return health;
	}

	void SetAttack(int attack) {
		this->attack = attack;
	}

	const int& GetAttack() const {
		return attack;
	}
};

