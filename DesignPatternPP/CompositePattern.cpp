#include <iostream>
#include <vector>
#include <memory>

/*
Composite 패턴은 Tree 구조를 이루는 설계에서 모든 노드들을
순차적으로 호출하고 싶을 때 유용하게 쓰이는 패턴이다.
하나의 공통의 인터패이스를 만들고 하위로 단일 대상 오브젝트(LEAF)와
단일 대상 오브젝트들을 묶는 그룹(Composite)을 정의하고 이들을 묶는 하나의 객체(Root)에서
특정 함수를 점화시키도록 설계하면 된다.
*/

class Animal
{
public:
    explicit Animal() = default;
    virtual ~Animal() = default;
    virtual void Speak() = 0;
};

class Cat : public Animal
{
public:
    virtual ~Cat() 
    {
        std::cout << "<DEAD> Cat" << std::endl;
    }
    virtual void Speak() override
    {
        std::cout << "Meow!" << std::endl;
    }
};

class Dog : public Animal
{
public:
    virtual ~Dog()
    {
        std::cout << "<DEAD> Dog" << std::endl;
    }
    virtual void Speak() override
    {
        std::cout << "Brag!!!" << std::endl;
    }
};

class AnimalGroup : public Animal
{
public:
    void Add(std::shared_ptr<Animal> animal)
    {
        animals.emplace_back(animal);
    }
    virtual void Speak() override
    {
        std::cout << "Start Group" << std::endl;
        for (auto animal : animals)
        {
            animal->Speak();
        }
    }

private:
    std::vector<std::shared_ptr<Animal>> animals;
};

class AnimalFactory
{
public:
    enum EAnimal
    {
        DOG,
        CAT,
    };
    static std::shared_ptr<Animal> Make(EAnimal animal)
    {
        switch (animal)
        {
            case AnimalFactory::EAnimal::DOG: return std::make_shared<Dog>();
            case AnimalFactory::EAnimal::CAT: return std::make_shared<Cat>();
            default: return nullptr;
        }
    }
};

int main(void)
{
    std::shared_ptr<AnimalGroup> cat_group = std::make_shared<AnimalGroup>();;
    cat_group->Add(AnimalFactory::Make(AnimalFactory::CAT));
    cat_group->Add(AnimalFactory::Make(AnimalFactory::CAT));
    cat_group->Add(AnimalFactory::Make(AnimalFactory::CAT));

    std::shared_ptr<AnimalGroup> dog_group = std::make_shared<AnimalGroup>();
    dog_group->Add(AnimalFactory::Make(AnimalFactory::DOG));
    dog_group->Add(AnimalFactory::Make(AnimalFactory::DOG));
    dog_group->Add(AnimalFactory::Make(AnimalFactory::DOG));

    std::shared_ptr<AnimalGroup> dog_cat_group = std::make_shared<AnimalGroup>();
    dog_cat_group->Add(AnimalFactory::Make(AnimalFactory::DOG));
    dog_cat_group->Add(AnimalFactory::Make(AnimalFactory::CAT));
    dog_cat_group->Add(AnimalFactory::Make(AnimalFactory::DOG));

    AnimalGroup zoo;

    zoo.Add(cat_group);
    zoo.Add(dog_group);
    zoo.Add(dog_cat_group);
    zoo.Add(AnimalFactory::Make(AnimalFactory::CAT));

    zoo.Speak();

    return 0;
}