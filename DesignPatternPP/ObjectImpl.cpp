#include "VisitorCorePch.h"

void Animal::accept(std::shared_ptr<AnimalVisitor> visitor)
{
	visitor->visit(shared_from_this());
}
