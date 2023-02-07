#include "pch.h"
#include "define.h"
#include "CCore.h"

#include "CClass.h"
#include "CWarrior.h"
#include "CMagician.h"
#include "CRogue.h"

#include "CMonster.h"

void CCore::Run()
{
	int input;

	CClass* cls = nullptr;

	while (true) {

		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";

		cin >> input;

		system("cls");

		Job job = Job::None;

		if (input == 1) {
			cls = new CWarrior(100, 10);
		}
		else if (input == 2) {
			cls = new CMagician(100, 10);
		}
		else if (input == 3) {
			cls = new CRogue(100, 10);
		}

		assert(cls);

		GoDungeon(cls);
	}
}

void CCore::GoDungeon(CClass* job)
{
	StatusPrint(job);

	int input;
	cout << "1. 사냥터 2. 종료 : ";

	cin >> input;

	system("cls");

	if (input == 1) {
		DungeonPrint(job);
	}
	else if (input == 2) {
		exit(0);
	}
}

void CCore::SelectDungeonLevel(CClass* job, int level)
{
	StatusPrint(job);

	CMonster* monster = nullptr;

	if (level == 1) {
		monster = new CMonster("초급", 30, 3);
	}
	else if (level == 2) {
		monster = new CMonster("중급", 60, 6);
	}
	else if (level == 3) {
		monster = new CMonster("고급", 90, 9);
	}
	else if (level == 4) {
		GoDungeon(job);
	}

	cout << "==========================\n";
	cout << "이름 : " << monster->GetJobName() << "\n";
	cout << "체력 : " << monster->GetHealth() << "\t" << "공격력 : " << monster->GetAttack() << "\n";
	cout << "1. 공격 2. 도망 : ";

	int input;
	cin >> input;

	if (input == 2) {

		delete monster;
		monster = nullptr;

		system("cls");

		DungeonPrint(job);
	}

	system("cls");

	int playerHealth = job->GetHealth() - monster->GetAttack();
	int monsterHealth = monster->GetHealth() - job->GetAttack();

	job->Sethealth(playerHealth);
	monster->Sethealth(monsterHealth);

	SelectDungeonLevel(job, level, monster);
}

void CCore::SelectDungeonLevel(CClass* job, int level, CMonster* monster)
{
	StatusPrint(job);

	cout << "==========================\n";
	cout << "이름 : " << monster->GetJobName() << "\n";
	cout << "체력 : " << monster->GetHealth() << "\t" << "공격력 : " << monster->GetAttack() << "\n";
	cout << "1. 공격 2. 도망 : ";

	int input;
	cin >> input;

	if (input == 2) {

		delete monster;
		monster = nullptr;

		system("cls");

		DungeonPrint(job);
	}

	int playerHealth = job->GetHealth() - monster->GetAttack();
	int monsterHealth = monster->GetHealth() - job->GetAttack();

	job->Sethealth(playerHealth);
	monster->Sethealth(monsterHealth);

	if (playerHealth <= 0) {
		cout << "플레이어 사망 \n";
		system("pause");

		job->Sethealth(100);

		delete monster;
		monster = nullptr;

		system("cls");

		DungeonPrint(job);
	}
	else if (monsterHealth <= 0) {
		cout << "승리 \n";
		system("pause");

		delete monster;
		monster = nullptr;

		system("cls");

		DungeonPrint(job);
	}

	system("cls");

	SelectDungeonLevel(job, level, monster);
}

void CCore::StatusPrint(CClass* job)
{
	string job_name = "";

	cout << "==========================\n";
	cout << "이름 : " << job->GetJobName() << "\n";
	cout << "체력 : " << job->GetHealth() << "\t" << "공격력 : " << job->GetAttack() << "\n";
}

void CCore::DungeonPrint(CClass* job)
{
	StatusPrint(job);

	int input;
	cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";

	cin >> input;

	if (input == 4) {
		system("cls");

		GoDungeon(job);
	}

	system("cls");

	SelectDungeonLevel(job, input);
}

CCore::CCore()
{
	
}

CCore::~CCore()
{
}
