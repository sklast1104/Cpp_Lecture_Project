#pragma once

class CClass;
class CMonster;

class CCore
{
public :
	static CCore* GetInst() {
		static CCore mgr;
		return &mgr;
	}

	void Run();

	void GoDungeon(CClass* job);
	void SelectDungeonLevel(CClass* job, int level);
	void SelectDungeonLevel(CClass* job, int level, CMonster* monster);

	void StatusPrint(CClass* job);
	void DungeonPrint(CClass* job);

private :
	CCore();
	~CCore();
};

