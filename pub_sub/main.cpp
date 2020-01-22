#include <iostream>
#include <thread>
#include "singleton.hpp"
#include "publisher.hpp"
#include "subscriber.hpp"
#include "topic.hpp"
#include "node.hpp"

std::mutex show_lock;

void RegPub(Node *node, std::string topic_) { node->RegPublisher(topic_); }
void RegSub(Node *node, std::string topic_) { node->RegSubscriber(topic_); }
void ShowMsg(Node *node) {
	std::lock_guard<std::mutex> lock(show_lock);
	std::cout << *node;
}
void PublishMsg(Node *node, std::string msg_) { node->Publish(msg_); }

int main(int argc, char *argv[]) {
	Node pub("Publisher"), sub("Subscriber 1"), sub2("Subscriber 2"), sub3("subscriber 3");

	std::thread T1(RegPub, &pub, "aaa");
	std::thread T2(RegSub, &sub, "aaa");
	std::thread T3(RegSub, &sub2, "aaa");
	std::thread T4(RegSub, &sub3, "aaa");

	T1.join();
	T2.join();
	T3.join();
	T4.join();

	PublishMsg(&pub, "Hello World");

	std::thread T5(ShowMsg, &sub);
	std::thread T6(ShowMsg, &sub2);
	std::thread T7(ShowMsg, &sub3);

	T5.join();
	T6.join();
	T7.join();

	return 0;
}
