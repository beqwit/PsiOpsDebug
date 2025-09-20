#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include "Utils/MemoryMgr.h"

typedef unsigned char uint8;
typedef unsigned int  uint32;

template <unsigned int address, typename... Args>
static void Call(Args... args) {
	reinterpret_cast<void(__cdecl*)(Args...)>(address)(args...);
}

template <typename Ret, unsigned int address, typename... Args>
static Ret CallAndReturn(Args... args) {
	return reinterpret_cast<Ret(__cdecl*)(Args...)>(address)(args...);
}

template <unsigned int address, typename... Args>
static void STDCall(Args... args) {
	reinterpret_cast<void(__stdcall*)(Args...)>(address)(args...);
}

template <typename Ret, unsigned int address, typename... Args>
static Ret STDCallAndReturn(Args... args) {
	return reinterpret_cast<Ret(__stdcall*)(Args...)>(address)(args...);
}

template <unsigned int address, typename... Args>
static void FASTCall(Args... args) {
	reinterpret_cast<void(__fastcall*)(Args...)>(address)(args...);
}

template <typename Ret, unsigned int address, typename... Args>
static Ret FASTCallAndReturn(Args... args) {
	return reinterpret_cast<Ret(__fastcall*)(Args...)>(address)(args...);
}


template <unsigned int address, typename C, typename... Args>
static void CallMethod(C _this, Args... args) {
	reinterpret_cast<void(__thiscall*)(C, Args...)>(address)(_this, args...);
}

template <typename Ret, unsigned int address, typename C, typename... Args>
static Ret CallMethodAndReturn(C _this, Args... args) {
	return reinterpret_cast<Ret(__thiscall*)(C, Args...)>(address)(_this, args...);
}

using namespace Memory::VP;