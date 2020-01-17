#include <iostream>
#include <thread>
#include <mutex>
#include "singleton.hpp"
#include "publisher.hpp"
#include "subscriber.hpp"
#include "topic.hpp"

class Num : public Singleton<Num> {
	public:
		int GetNum() { return ++num; }
	private:
		Num(){ num = 0; }
		int num;
		~Num(){};
		friend class Singleton<Num>;
};

std::mutex TMutex;

void ThreadTask() {
	TMutex.lock();
	std::cout << Num::Instance()->GetNum() << std::endl;
	TMutex.unlock();
	return ;
}

int main(int argc, char *argv[]) {

	return 0;
}
