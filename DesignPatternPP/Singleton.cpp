#include "stdafx.h"

class Singleton
{
private:
	static Singleton* _instance;
	Singleton() {}
	~Singleton() {}
public:
	void Hello() { cout << "Hello" << endl; }
	static Singleton* instance() {
		if (_instance == nullptr) {
			_instance = new Singleton();
		}
		return _instance;
	}
	
};
Singleton* Singleton::_instance = nullptr;

int main()
{
	Singleton::instance()->Hello();	
	return 0;
}