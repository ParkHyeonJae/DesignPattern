#pragma once

template<typename T>
class Singleton
{
protected:
	Singleton() {}
	virtual ~Singleton() {}
	Singleton(const Singleton& s) {}
	static void destroy() { delete _instance; }
public:
	static T* GetInstance()
	{
		if (_instance) {
			_instance = new T();
			atexit(destroy);
		}
		return _instance;
	}
private:
	static T* _instance;
};
template<typename T> T* Singleton<T>::_instance = nullptr;