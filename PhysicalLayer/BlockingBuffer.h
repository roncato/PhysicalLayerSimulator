#ifndef _BLOCKING_QUEUE_
#define _BLOCKING_QUEUE_

#include <mutex>
#include <condition_variable>
#include <deque>

class BlockingBuffer
{
private:
	std::mutex              _mutex;
	std::condition_variable _conditionVar;
	std::deque<char>        _queue;
public:
	BlockingBuffer(int);
	~BlockingBuffer();
	void Push(char const& value);
	char Take();
};

#endif