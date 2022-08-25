#include <iostream>

/*
* 
* Command Pattern (Ŀ�ǵ� ����)
* ����� classȭ �Ͽ�, Object�ν� ����ϵ��� �����Ѵ�.
* �θ� Ŭ������ Command�� ������ �̸� ������ ��ӹ޾Ƽ� ���ο� Ŀ�ǵ� Ŭ������ �����ϰ�,
* �̵��� ��Ƽ� �����ϴ� Invoker Ŭ������ ����鼭 �̵��� ����Ѵ�.
* 
*/

class Command
{
public:
	virtual void Execute() = 0;
};

class PrintCommand : public Command
{
	friend class MovementCommand;
public:
	PrintCommand() = default;
	explicit PrintCommand(std::string&& context) : context(context)
	{
	}
public:
	virtual void Execute() override
	{
		std::cout << context << std::endl;
	}

private:
	std::string context;
};


class MovementCommand : public Command
{
public:	
	MovementCommand() = default;
	explicit MovementCommand(std::shared_ptr<PrintCommand> printCommand) : _printCommand(printCommand)
	{
	}
public:
	virtual void Execute() override
	{
		_printCommand->context = "Movement..";
		_printCommand->Execute();
	}

public:
	std::shared_ptr<PrintCommand> _printCommand;
};

int main(void)
{
	std::shared_ptr<Command> command_01 = std::make_shared<PrintCommand>("Hello");
	std::shared_ptr<Command> command_02 = std::make_shared<MovementCommand>(std::dynamic_pointer_cast<PrintCommand>(command_01));
	command_01->Execute();
	command_02->Execute();

	return 0;
}