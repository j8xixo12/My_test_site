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
	std::thread T1(ThreadTask);
	std::thread T2(ThreadTask);
	std::thread T3(ThreadTask);

	T1.join();
	T2.join();
	T3.join();
	return 0;
}
