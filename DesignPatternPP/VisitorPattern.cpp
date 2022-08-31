#include "VisitorCorePch.h"

/*
* 
* Visitor Pattern (방문자 패턴)
* Object의 내용을 수정하지 않고 내무 알고리즘을 변경하고 싶을 때 사용하는 패턴
* Object 클래스에서 accept를 정의하고 
* accept 파라매터로 Visitor 오브젝트를 받고 visit 함수를 호출한다.
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