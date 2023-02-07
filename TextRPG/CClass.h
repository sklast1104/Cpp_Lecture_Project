#pragma once
#include <string>
using std::string;

class CClass
{
private :
	string job_name;
	int health;
	int attack;

public :
	CClass(string job_name, int health, int attack);
	virtual ~CClass();

	void SetJobName(string job_name) {
		this->job_name = job_name;
	}

	const string& GetJobName() const {
		return job_name;
	}

	void Sethealth(int health) {
		this->health = health;
	}

	const int& GetHealth() const {
		return health;
	}

	void SetAttack(int attack){
		this->attack = attack;
	} 

	const int& GetAttack() const {
		return attack;
	}

};

