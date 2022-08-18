#include <iostream>
#include <memory>

/*
* 
* Strategy Pattern
* 
* OCP (Open Closed Principle) 패턴과 유사한 개념
* 
* 특정 함수가 있을 때 해당 함수의 원본은 그대로 두면서
* 추가 확장에 따라 런타임에 함수의 내용이 결정되도록 함
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
		std::cout << "야옹" << std::endl;
	}
};

class Dog : public Animal
{
public:
	void speak() const override
	{
		std::cout << "멍멍" << std::endl;
	}
};

class Cow : public Animal
{
public:
	void speak() const override
	{
		std::cout << "음매" << std::endl;
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