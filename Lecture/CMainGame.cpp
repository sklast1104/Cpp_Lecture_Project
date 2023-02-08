#include "stdafx.h"
#include "CStudent.h"
#include "CMainGame.h"

CMainGame::CMainGame()
	: m_pStudent{nullptr}
{

}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if (!m_pStudent)
		m_pStudent = new CStudent;

	m_pStudent->Initialize();
}

void CMainGame::Update()
{
	int		iInput = 0;

	while (true)
	{
		system("cls");

		cout << "1. 입력 2. 출력 3. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pStudent->Input_Data();
			break;

		case 2:
			m_pStudent->Output_Data();
			break;

		case 3:
			return;

		default:
			break;
		}

	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pStudent);
}
