#include <iostream>
#include <memory>

/*
* 
* Strategy Pattern
* 
* OCP (Open Closed Principle) ���ϰ� ������ ����
* 
* Ư�� �Լ��� ���� �� �ش� �Լ��� ������ �״�� �θ鼭
* �߰� Ȯ�忡 ���� ��Ÿ�ӿ� �Լ��� ������ �����ǵ��� ��
* 
*/

class Animal
{
public:
	virtual void speak() const = 0;
};

class Cat : public Animal
{
public:
	void speak() const override
	{
		std::cout << "�߿�" << std::endl;
	}
};

class Dog : public Animal
{
public:
	void speak() const override
	{
		std::cout << "�۸�" << std::endl;
	}
};

class Cow : public Animal
{
public:
	void speak() const override
	{
		std::cout << "����" << std::endl;
	}
};

enum class EAnimal
{
	CAT,
	DOG,
	COW
};

std::unique_ptr<Animal> makeAnimalFactory(EAnimal InType)
{
	switch (InType)
	{
		case EAnimal::CAT: return std::make_unique<Cat>();
		case EAnimal::DOG: return std::make_unique<Dog>();
		case EAnimal::COW: return std::make_unique<Cow>();
		default: return nullptr;
	}
}

int main(void)
{
	makeAnimalFactory(EAnimal::CAT)->speak();
	makeAnimalFactory(EAnimal::DOG)->speak();
	makeAnimalFactory(EAnimal::COW)->speak();

	return 0;
}