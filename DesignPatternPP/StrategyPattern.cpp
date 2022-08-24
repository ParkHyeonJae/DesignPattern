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
	Animal() = default;
	Animal(std::string name) : _name(name) {}
	virtual ~Animal() {}
public:
	virtual void speak() const = 0;

private:
	std::string _name;
};

class Cat : public Animal
{
public:
	~Cat() {}
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

template<class T, class ...Args>
std::unique_ptr<T> makeAnimalFactory(Args&&... args)
{
	static_assert(std::is_base_of<Animal, T>());
	return std::make_unique<T, Args...>(args);
}

class AA
{
public:
	void speak() const
	{
		std::cout << "����" << std::endl;
	}
};
int main(void)
{
	makeAnimalFactory(EAnimal::CAT)->speak();
	makeAnimalFactory(EAnimal::DOG)->speak();
	makeAnimalFactory(EAnimal::COW)->speak();

	makeAnimalFactory<Cat>()->speak();
	makeAnimalFactory<Dog>()->speak();
	makeAnimalFactory<Cow>()->speak();
	//makeAnimalFactory<AA>()->speak();

	return 0;
}