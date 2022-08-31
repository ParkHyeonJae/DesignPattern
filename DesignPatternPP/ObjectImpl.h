#pragma once

class AnimalVisitor;
class Animal : public std::enable_shared_from_this<Animal>
{
public:
	explicit Animal(int age, std::string&& name) : _age(age), _name(name) {}
	virtual ~Animal() {}

	virtual void accept(std::shared_ptr<AnimalVisitor> visitor);
public:
	int _age;
	std::string _name;
};
