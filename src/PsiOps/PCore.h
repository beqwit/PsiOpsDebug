#pragma once
#include "../framework.h"

class CString
{
public:
    CString(char* Str);
    ~CString();

    std::string* GetData();
    bool Compare(char* Str);
};

class CStringVector
{
public:
    CStringVector();
    ~CStringVector();

    void Pushback(CString* str);
    int Size();
    CString* GetElement(int n);
};

struct CVector3
{
public:
    float x, y, z;
};

class CBase {};