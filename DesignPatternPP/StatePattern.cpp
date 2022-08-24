#include <iostream>

/**
* State Pattern (상태 패턴)
* 직접 IF-ELSE 문을 활용해서 상태를 비교하지 않고
* 상태 자체를 객체와 하여 상태 자체가 행동을 할 수 있도록 위밈하는 패턴이다.
* 
* 객체의 상태를 클래스로 만들고 클래스에서는 상태에 대한 행위를 정의한다.
* 그리고 이들을 인터페이스로 캡슐화하여 따른 호출자에서 이들을 호출한다.
* 
* 예를 들면 신호등 (빨간불, 파란불)이 있다.
* 
*/


class AnimationState
{
public:
	virtual void Animate() = 0;
};

class AnimationStateMachine
{
public:
	void SetAnimationState(std::shared_ptr<AnimationState> animationState) 
	{
		_aniamtionState = animationState;
	}

	void Launch()
	{
		_aniamtionState->Animate();
	}
protected:
	std::shared_ptr<AnimationState> _aniamtionState;
};

class MoveAnimationState : public AnimationState
{
public:
	virtual void Animate() override
	{
		std::cout << "Launch Move Animation" << std::endl;
	}
};

class VibrateAnimationState : public AnimationState
{
public:
	virtual void Animate() override
	{
		std::cout << "Launch Vibrate Animation" << std::endl;
	}
};

class EmojiAnimationState : public AnimationState
{
public:
	virtual void Animate() override
	{
		std::cout << "Launch Emoji Animation" << std::endl;
	}
};

AnimationStateMachine MyStateMachine;

int main(void)
{
	MyStateMachine.SetAnimationState(std::make_shared<MoveAnimationState>());
	MyStateMachine.Launch();
	MyStateMachine.SetAnimationState(std::make_shared<EmojiAnimationState>());
	MyStateMachine.Launch();
	MyStateMachine.SetAnimationState(std::make_shared<VibrateAnimationState>());
	MyStateMachine.Launch();


	return 0;
}