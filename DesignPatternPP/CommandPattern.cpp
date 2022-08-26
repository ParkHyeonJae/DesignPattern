#include <iostream>
#include <vector>

/*
* 
* Command Pattern (커맨드 패턴)
* 명령을 class화 하여, Object로써 사용하도록 설계한다.
* 부모 클래스로 Command가 있으며 이를 하위로 상속받아서 새로운 커맨드 클래스를 정의하고,
* 이들을 모아서 실행하는 Invoker 클래스를 만들면서 이들을 사용한다.
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

class CommandInvoker
{
public:
	inline void AddCommand(std::shared_ptr<Command>& command)
	{
		_commands.emplace_back(command);
	}
	void Run() const
	{
		for (auto& command : _commands)
		{
			command->Execute();
		}
	}
private:
	std::vector<std::shared_ptr<Command>> _commands;
};

int main(void)
{
	std::shared_ptr<Command> command_01 = std::make_shared<PrintCommand>("Hello");
	std::shared_ptr<Command> command_02 = std::make_shared<MovementCommand>(std::dynamic_pointer_cast<PrintCommand>(command_01));

	//command_01->Execute(); 
	//command_02->Execute();

	CommandInvoker myCommandInvoker;
	myCommandInvoker.AddCommand(command_01);
	myCommandInvoker.AddCommand(command_02);

	myCommandInvoker.Run();

	return 0;
}