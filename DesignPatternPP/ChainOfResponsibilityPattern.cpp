#include <iostream>

#define TO_STRING(x) TO_STRING_INTERNAL(x)
#define TO_STRING_INTERNAL(x) #x

/*
* 
* Chain Of Responsibility Pattern (책인 연쇄 패턴)
* 일련의 명령과 처리 객체를 포함하는 디자인 패턴 
* 각각의 체인마다 명령과 그에 따른 처리를 할 수 있다.
* 해당 처리를 못하였을 경우 다음 체인에 이를 맏길 수 있다.
*/

struct ConfigData
{
	std::string type;
};


class Handler abstract
{
public:
	void SetNext(std::shared_ptr<Handler>&& handle) { _handle = handle; }
	std::shared_ptr<Handler> GetNextHandle() const { return _handle; }
	virtual void Handle(const ConfigData& const data) = 0;
private:
	std::shared_ptr<Handler> _handle;
};


class PricePackageHandler : public Handler
{
public:
	virtual void Handle(const ConfigData& const data) override
	{
		if (data.type == TO_STRING(PricePackageHandler))
		{
			std::cout << "This is " << data.type << std::endl;
		}

		std::cout << "Process Price Package ..." << std::endl;

		auto nextHandle = GetNextHandle();
		if (nextHandle != nullptr)
		{
			nextHandle->Handle(data);
		}
	}
};

class PaymentPackageHandler : public Handler
{
public:
	virtual void Handle(const ConfigData& const data) override
	{
		if (data.type == TO_STRING(PaymentPackageHandler))
		{
			std::cout << "This is " << data.type << std::endl;
		}

		std::cout << "Process Payment Package ..." << std::endl;

		auto nextHandle = GetNextHandle();
		if (nextHandle != nullptr)
		{
			nextHandle->Handle(data);
		}
	}
};

class LevelupPackageHandler : public Handler
{
public:
	virtual void Handle(const ConfigData& const data) override
	{
		if (data.type == TO_STRING(LevelupPackageHandler))
		{
			std::cout << "This is " << data.type << std::endl;
		}

		std::cout << "Process Levelup Package ..." << std::endl;

		auto nextHandle = GetNextHandle();
		if (nextHandle != nullptr)
		{
			nextHandle->Handle(data);
		}
	}
};

class SeasonPassHandler : public Handler
{
public:
	virtual void Handle(const ConfigData& const data) override
	{
		if (data.type == TO_STRING(SeasonPassHandler))
		{
			std::cout << "This is " << data.type << std::endl;
		}

		std::cout << "Process Season Pass..." << std::endl;

		auto nextHandle = GetNextHandle();
		if (nextHandle != nullptr)
		{
			nextHandle->Handle(data);
		}
	}
};


int main(void)
{
	auto priceHandler	= std::make_shared< PricePackageHandler >();
	auto paymentHandler = std::make_shared< PaymentPackageHandler >();
	auto levelupHandler = std::make_shared< LevelupPackageHandler >();
	auto seasonHandler  = std::make_shared< SeasonPassHandler >();

	priceHandler->SetNext(paymentHandler);
	paymentHandler->SetNext(levelupHandler);
	levelupHandler->SetNext(seasonHandler);

	priceHandler->Handle(ConfigData { TO_STRING(SeasonPassHandler) });

	return 0;
}