#include "stdafx.h"
#include "CMainGame.h"

int main()
{
	CMainGame		MainGame;	// ��ü ����

	MainGame.Initialize();

	MainGame.Update();

	MainGame.Release();
}