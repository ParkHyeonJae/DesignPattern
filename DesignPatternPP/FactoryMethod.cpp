#include "stdafx.h"

class RTX abstract
{
protected:
	int m_price = 0;
	int m_cudaCore = 0;
	int m_rtCore = 0;
	int m_tensorCore = 0;
	int m_v_ram = 0;

	virtual int Price() = 0;
	virtual int CUDACore() = 0;
	virtual int RTCore() = 0;
	virtual int TensorCore() = 0;
	virtual int V_RAM() = 0;
public:
	void Performance()
	{
		cout << "Price : $" << Price() << endl;
		cout << "CUDA Core : " << CUDACore() << endl;
		cout << "RT Core : " << RTCore() << endl;
		cout << "Tensor Core : " << TensorCore() << endl;
		cout << "V_RAM : " << V_RAM() << "GB" << endl;
	}
};
class RTX3070 : public RTX
{
	int Price() sealed override
	{
		return m_price = 499;
	}
	int CUDACore() sealed override
	{
		return m_cudaCore = 5888;
	}
	int RTCore() sealed override
	{
		return m_rtCore = 46;
	}
	int TensorCore() sealed override
	{
		return m_tensorCore = 184;
	}
	int V_RAM() sealed override
	{
		return m_v_ram = 8;
	}
};
class RTX3080 : public RTX
{
	int Price() sealed override
	{
		return m_price = 699;
	}
	int CUDACore() sealed override
	{
		return m_cudaCore = 8704;
	}
	int RTCore() sealed override
	{
		return m_rtCore = 68;
	}
	int TensorCore() sealed override
	{
		return m_tensorCore = 272;
	}
	int V_RAM() sealed override
	{
		return m_v_ram = 10;
	}
};
class RTX3090 : public RTX
{
	int Price() sealed override
	{
		return m_price = 1499;
	}
	int CUDACore() sealed override
	{
		return m_cudaCore = 10496;
	}
	int RTCore() sealed override
	{
		return m_rtCore = 82;
	}
	int TensorCore() sealed override
	{
		return m_tensorCore = 328;
	}
	int V_RAM() sealed override
	{
		return m_v_ram = 24;
	}
};

class RTXFactory
{
public: 
	template<typename T>
	static RTX* getInstance()
	{
		RTX* t = new T();
		if (t != nullptr)
			return t;
		return nullptr;
	}

};

int main(int argc, char* argv)
{
	

	RTX* rtx = RTXFactory::getInstance<RTX3070>();
	rtx->Performance();

	delete rtx;

	cout << endl;

	rtx = RTXFactory::getInstance<RTX3080>();
	rtx->Performance();

	delete rtx;

	cout << endl;

	rtx = RTXFactory::getInstance<RTX3090>();
	rtx->Performance();

	delete rtx;
	return 0;
}