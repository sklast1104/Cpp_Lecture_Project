#include <iostream>
#include "CCore.h"

int main()
{
    CCore* pGameCore = CCore::GetInst();
    pGameCore->Run();
}

