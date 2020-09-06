#pragma once
#include "stdafx.h"

template<typename T>
class Singleton
{
protected:
	Singleton() {}
	virtual ~Singleton() {}
	Singleton(const Singleton& s) {}
	static void destroy() { delete _instance; }
public:
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	// ÀÌ¿Â°ג Â¯
	static T* GetInstance()
	{
		if (_instance) {
			_instance = new Singleton();
			atexit(destroy);
		}
		return _instance;
	}
private:
	static Singleton* _instance;
};