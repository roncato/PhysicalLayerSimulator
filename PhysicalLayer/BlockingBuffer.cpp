#include "BlockingBuffer.h"

BlockingBuffer::BlockingBuffer(int size)
{

}

BlockingBuffer::~BlockingBuffer()
{
}

void BlockingBuffer::Push(char const& value)
{
	{
		std::unique_lock<std::mutex> lock(this->_mutex);
		_queue.push_front(value);
	}
	this->_conditionVar.notify_one();
}

char BlockingBuffer::Take()
{
	std::unique_lock<std::mutex> lock(this->_mutex);
	this->_conditionVar.wait(lock, [=]{ return !this->_queue.empty(); });
	char rc(std::move(this->_queue.back()));
	this->_queue.pop_back();
	return rc;
}