#include "pch.h"
#include "CClass.h"

CClass::CClass(string job_name, int health, int attack)
	: job_name{ job_name }
	, health( health )
	, attack( attack )
{
}

CClass::~CClass()
{
}
