#include "stdafx.h"

class Cache
{
public:
	virtual void ShowCache() = 0;
};

class RealCache : public Cache
{
public:
	RealCache(const string& filename) : file(filename) {}
	~RealCache() {}
public:
	void ShowCache() override
	{
		cout << "Show Cache.. : "<< file.c_str() << endl;
	}
	void LoadCache()
	{
		cout << "Load Cache.. : " << file.c_str() << endl;
	}
private:
	string file;
};

class ProxyCache : public Cache
{
public:
	ProxyCache(const string& filename) : file(filename), mRealCache(nullptr) {};
	~ProxyCache() { if (mRealCache)delete mRealCache; };

public:
	void ShowCache() override
	{
		if (!mRealCache) {
			mRealCache = new RealCache(file);
			mRealCache->LoadCache();
		}
		mRealCache->ShowCache();
	}
private:
	string file;
	RealCache* mRealCache;
};
int main(int argc, char* argv[])
{
	Cache* mCache = new ProxyCache("Image.png");
	mCache->ShowCache();
	mCache->ShowCache();
	mCache->ShowCache();
	mCache->ShowCache();
	delete mCache;
	return 0;
}