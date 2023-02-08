#pragma once

class CStudent;

class CMainGame
{
public :
	CMainGame();
	~CMainGame();

	void Initialize();
	void Update();
	void Release();

private :
	CStudent* m_pStudent;
};

