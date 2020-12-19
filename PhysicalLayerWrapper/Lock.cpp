#include "Stdafx.h"
#include "Lock.h"

Lock::Lock(Object ^ object) : _lock(object) {
	Monitor::Enter(_lock);
}
Lock::~Lock() {
	Monitor::Exit(_lock);
}