#include "stdafx.h"

class Adaptee
{
public:
	void Print() { cout << "Adaptee Print Operate" << endl; }
};
class Adapter abstract
{
public:
	virtual void operation() = 0;
};

// Inheritance Adapter
class ConcreteClassA : public Adapter, public Adaptee
{
public:
	void operation() override { Print(); }
};


// class Adapter
class ConcreteClassB : public Adapter
{
public:
	void operation() override { adaptee.Print(); }
private:
	Adaptee adaptee;
};


int main()
{
	ConcreteClassA concreteA;
	ConcreteClassB concreteB;

	concreteA.operation();
	concreteB.operation();
	return 0;
}