using namespace System::Threading;
ref class Lock 
{
	Object^ _lock;
public:
	Lock(Object ^ object);
	~Lock();
};