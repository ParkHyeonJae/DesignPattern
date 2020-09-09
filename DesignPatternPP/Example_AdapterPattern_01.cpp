#include "stdafx.h"


class CString
{
public:
	CString(const string& str) : _string(str) {}
	const string const GetString() { return _string; }
private:
	string _string;
};

class Adapter
{
public:
	virtual int operation() = 0;
};

class ConcreteClassA : public Adapter
{
public:
	ConcreteClassA(const string& str) : _str(str) {}
	int operation() override { return atoi(_str.GetString().c_str()); }

private:
	CString _str;
};

int main()
{
	ConcreteClassA *concreteClassA = new ConcreteClassA("-11245421");
	ConcreteClassA *concreteClassB = new ConcreteClassA("32552122");
	ConcreteClassA *concreteClassC = new ConcreteClassA("89035297");
	int A = concreteClassA->operation();
	int B = concreteClassB->operation();
	int C = concreteClassC->operation();

	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
	return 0;
}