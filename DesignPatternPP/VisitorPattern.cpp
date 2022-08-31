#include "VisitorCorePch.h"

/*
* 
* Visitor Pattern (�湮�� ����)
* Object�� ������ �������� �ʰ� ���� �˰����� �����ϰ� ���� �� ����ϴ� ����
* Object Ŭ�������� accept�� �����ϰ� 
* accept �Ķ���ͷ� Visitor ������Ʈ�� �ް� visit �Լ��� ȣ���Ѵ�.
* 
*/

int main(void)
{
	std::shared_ptr<Animal> myJhon = std::make_shared<Animal>(4, "Jhon");
	std::shared_ptr<Animal> myAlice = std::make_shared<Animal>(2, "Alice");
	myJhon->accept(std::make_shared<DogVisitor>());
	myAlice->accept(std::make_shared<CatVisitor>());

	return 0;
}