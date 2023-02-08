#include "stdafx.h"
#include "CStudent.h"

CStudent::CStudent()
	: m_pInfo{nullptr}
	, m_iSize{0}
{
}

CStudent::~CStudent()
{
	Release();
}

void CStudent::Initialize()
{
}

void CStudent::Input_Data()
{
	int iInput = 0;

	cout << "�л� ���� �Է��ϼ��� : ";
	cin >> iInput;

	if (nullptr == m_pInfo) {
		m_pInfo = new INFO[iInput];
	}
	else {
		INFO* pTemp = new INFO[iInput + m_iSize];

		memcpy(pTemp, m_pInfo, sizeof(INFO) * m_iSize);

		Release();

		m_pInfo = pTemp;
	}

	for (int i = m_iSize; i < m_iSize + iInput; ++i)
	{
		cout << "�̸� �Է� : ";
		cin >> m_pInfo[i].szName;

		cout << "���� �Է� : ";
		cin >> m_pInfo[i].iKor;

		cout << "���� �Է� : ";
		cin >> m_pInfo[i].iEng;

		cout << "���� �Է� : ";
		cin >> m_pInfo[i].iMath;

		m_pInfo[i].iTotal = m_pInfo[i].iKor + m_pInfo[i].iEng + m_pInfo[i].iMath;
		m_pInfo[i].fAver = float(m_pInfo[i].iTotal) / 3.f;
		cout << "=======================" << endl;
	}

	m_iSize += iInput;
}

void CStudent::Output_Data()
{
	for (int i = 0; i < m_iSize; ++i)
	{
		cout << "====================================" << endl;
		cout << "�̸� : " << m_pInfo[i].szName << endl;
		cout << "���� : " << m_pInfo[i].iKor << endl;
		cout << "���� : " << m_pInfo[i].iEng << endl;
		cout << "���� : " << m_pInfo[i].iMath << endl;
		cout << "���� : " << m_pInfo[i].iTotal << endl;
		cout << "��� : " << m_pInfo[i].fAver << endl;
	}

	system("pause");
}

void CStudent::Release()
{
	SAFE_DELETE_ARRAY(m_pInfo);
}
