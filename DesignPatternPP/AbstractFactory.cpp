#include "stdafx.h"

class AbstractProductA
{
public:
	virtual void Print() = 0;
};

class AbstractProductB
{
public:
	virtual void Print() = 0;
};

class ConcreteProductA1 : public AbstractProductA
{
public:
	void Print() override
	{
		cout << "Concrete ProductA1" << endl;
	}
};

class ConcreteProductA2 : public AbstractProductA
{
public:
	void Print() override
	{
		cout << "Concrete ProductA2" << endl;
	}
};

class ConcreteProductB1 : public AbstractProductB
{
public:
	void Print() override
	{
		cout << "Concrete ProductB1" << endl;
	}
};

class ConcreteProductB2 : public AbstractProductB
{
public:
	void Print() override
	{
		cout << "Concrete ProductB2" << endl;
	}
};

class AbstractFactroy
{
public:
	virtual AbstractProductA* createProductA() = 0;
	virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactroy
{
public:
	AbstractProductA* createProductA() override {
		return new ConcreteProductA1;
	}
	AbstractProductB* createProductB() override {
		return new ConcreteProductB1;
	}
};

class ConcreteFactory2 : public AbstractFactroy
{
public:
	AbstractProductA* createProductA() override {
		return new ConcreteProductA2;
	}
	AbstractProductB* createProductB() override {
		return new ConcreteProductB2;
	}
};

int main(int argc, char* argv[])
{
	ConcreteFactory1 concreteFactory1;
	ConcreteFactory2 concreteFactory2;

	AbstractProductA* concreteProductA1 = concreteFactory1.createProductA();
	concreteProductA1->Print();
	AbstractProductB* concreteProductB1 = concreteFactory1.createProductB();
	concreteProductB1->Print();
	
	AbstractProductA* concreteProductA2 = concreteFactory2.createProductA();
	concreteProductA1->Print();
	AbstractProductB* concreteProductB2 = concreteFactory2.createProductB();
	concreteProductB2->Print();

	delete concreteProductA1;
	delete concreteProductB1;
	delete concreteProductA2;
	delete concreteProductB2;


	return 0;
}