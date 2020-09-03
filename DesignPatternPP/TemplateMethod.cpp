#include "stdafx.h"

class AbstractClass abstract
{
private:
	virtual void subMethod() = 0;
public:
	void templateMethod() { subMethod(); }
};
class ConcreteClasss : public AbstractClass
{
private:
	void subMethod() sealed override { cout << "subMethod" << endl; }
};

int main()
{
	unique_ptr< AbstractClass >class01(new ConcreteClasss);
	class01.get()->templateMethod();
	return 0;
}