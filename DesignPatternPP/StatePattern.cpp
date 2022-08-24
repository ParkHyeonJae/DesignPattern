#include <iostream>

/**
* State Pattern (���� ����)
* ���� IF-ELSE ���� Ȱ���ؼ� ���¸� ������ �ʰ�
* ���� ��ü�� ��ü�� �Ͽ� ���� ��ü�� �ൿ�� �� �� �ֵ��� �����ϴ� �����̴�.
* 
* ��ü�� ���¸� Ŭ������ ����� Ŭ���������� ���¿� ���� ������ �����Ѵ�.
* �׸��� �̵��� �������̽��� ĸ��ȭ�Ͽ� ���� ȣ���ڿ��� �̵��� ȣ���Ѵ�.
* 
* ���� ��� ��ȣ�� (������, �Ķ���)�� �ִ�.
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