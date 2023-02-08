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

	cout << "학생 수를 입력하세요 : ";
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
		cout << "이름 입력 : ";
		cin >> m_pInfo[i].szName;

		cout << "국어 입력 : ";
		cin >> m_pInfo[i].iKor;

		cout << "영어 입력 : ";
		cin >> m_pInfo[i].iEng;

		cout << "수학 입력 : ";
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
		cout << "이름 : " << m_pInfo[i].szName << endl;
		cout << "국어 : " << m_pInfo[i].iKor << endl;
		cout << "영어 : " << m_pInfo[i].iEng << endl;
		cout << "수학 : " << m_pInfo[i].iMath << endl;
		cout << "총점 : " << m_pInfo[i].iTotal << endl;
		cout << "평균 : " << m_pInfo[i].fAver << endl;
	}

	system("pause");
}

void CStudent::Release()
{
	SAFE_DELETE_ARRAY(m_pInfo);
}
