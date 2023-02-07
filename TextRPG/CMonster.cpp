#include "CMonster.h"

CMonster::CMonster(string name, int health, int attack)
	: name{name}
	, health{health}
	, attack{attack}
{
}

CMonster::~CMonster()
{
}
