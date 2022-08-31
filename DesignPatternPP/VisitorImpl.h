#pragma once

class AnimalVisitor abstract
{
public:
	virtual void visit(std::shared_ptr<Animal> self) = 0;
};

class DogVisitor : public AnimalVisitor
{
public:
	virtual void visit(std::shared_ptr<Animal> self) {
		std::cout << "Detail -> Dog" << " Age -> " << self->_age << " Name -> " << self->_name << std::endl;
	}
};

class CatVisitor : public AnimalVisitor
{
public:
	virtual void visit(std::shared_ptr<Animal> self) {
		std::cout << "Detail -> Cat" << " Age -> " << self->_age << " Name -> " << self->_name << std::endl;
	}
};