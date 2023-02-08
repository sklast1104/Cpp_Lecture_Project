#pragma once

#include "Define.h"

class CStudent
{
public :
	CStudent();
	~CStudent();

	void Initialize();
	void Input_Data();
	void Output_Data();
	void Release();

private :
	INFO* m_pInfo;
	int m_iSize;


};

