#include <iostream>
#include <thread>
#include <mutex>
#include "singleton.hpp"
#include "publisher.hpp"
#include "subscriber.hpp"
#include "topic.hpp"
#include "node.hpp"

// class Num : public Singleton<Num> {
// 	public:
// 		int GetNum() { return ++num; }
// 	private:
// 		Num(){ num = 0; }
// 		int num;
// 		~Num(){};
// 		friend class Singleton<Num>;
// };

std::mutex TMutex;

// void ThreadTask() {
// 	TMutex.lock();
// 	std::cout << Num::Instance()->GetNum() << std::endl;
// 	TMutex.unlock();
// 	return ;
// }

int main(int argc, char *argv[]) {
	Node pub, sub, sub2, sub3;

	pub.RegPublisher("\aaa");
	sub.RegSubscriber("\aaa");
	sub2.RegSubscriber("\aaa");
	sub3.RegSubscriber("\aaa");

	pub.Publish("Fuck You!");


	std::cout << sub;
	std::cout << sub2;
	std::cout << sub3;
	pub.Publish("Fuck You2!");

	std::cout << sub;

	return 0;
}
