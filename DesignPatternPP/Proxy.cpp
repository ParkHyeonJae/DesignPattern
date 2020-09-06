#include "stdafx.h"

class Subject
{
public:
	virtual void request() = 0;
};

class RealSubject : public Subject
{
public:
	virtual void request() { cout << "Response by RealSubject" << endl; }
};

class Proxy : public Subject
{
public:
	Proxy() : mReal(nullptr) {}
	~Proxy() { if (mReal)delete mReal; }

public:
	virtual void request()
	{ 
		if (!mReal)
			mReal = new RealSubject();

		cout << "Task Processing..." << endl;
		_sleep(3000);

		mReal->request();
	}

private:
	RealSubject* mReal;
};

int main(int argc, char* argv[])
{
	Subject* pProxy = new Proxy();
	pProxy->request();

	delete pProxy;
	return 0;
}