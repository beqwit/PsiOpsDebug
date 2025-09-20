#include "PCore.h"

CString::CString(char* Str)
{
    CallMethod<0x402210, CString*, char*>(this, Str);
}

CString::~CString()
{
    CallMethod<0x401E40, CString*>(this);
}

std::string* CString::GetData()
{
    return CallMethodAndReturn<std::string*, 0x64E1B0, CString*>(this);
}

bool CString::Compare(char* Str)
{
    return CallMethodAndReturn<bool, 0x41B440, CString*, char*>(this, Str);
}

CStringVector::CStringVector()
{
    CallMethod<0x47E1A0, CStringVector*>(this);
}

CStringVector::~CStringVector()
{
    CallMethod<0x47E1D0, CStringVector*>(this);
}

int CStringVector::Size()
{
    return CallMethodAndReturn<int, 0x47EBD0, CStringVector*>(this);
}

CString* CStringVector::GetElement(int num)
{
    return CallMethodAndReturn<CString*, 0x4AB450, CStringVector*, int>(this, num);
}

void CStringVector::Pushback(CString* str)
{
    CallMethod<0x47E1F0, CStringVector*, CString*>(this, str);
}