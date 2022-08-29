#include <iostream>

#define TO_STRING(x) TO_STRING_INTERNAL(x)
#define TO_STRING_INTERNAL(x) #x

/*
* 
* Chain Of Responsibility Pattern (å�� ���� ����)
* �Ϸ��� ��ɰ� ó�� ��ü�� �����ϴ� ������ ���� 
* ������ ü�θ��� ��ɰ� �׿� ���� ó���� �� �� �ִ�.
* �ش� ó���� ���Ͽ��� ��� ���� ü�ο� �̸� ���� �� �ִ�.
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