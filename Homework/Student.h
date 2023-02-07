#pragma once

#include <string>
using std::string;

class Student
{
private:

	string name;
	int score;

public :
	Student();
	~Student();

	void SetName(const string& name) {
		this->name = name;
	}

	const string& GetName() {
		return name;
	}

	void SetScore(int score) {
		this->score = score;
	}

	int GetScore() {
		return score;
	}
};

