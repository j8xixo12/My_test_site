#include <iostream>
#include "singleton.hpp"
#include "publisher.hpp"
#include "subscriber.hpp"
#include "topic.hpp"
#include "node.hpp"

int main(int argc, char *argv[]) {
	Node pub("Publisher"), sub("Subscriber 1"), sub2("Subscriber 2"), sub3("subscriber 3");

	pub.RegPublisher("\aaa");
	sub.RegSubscriber("\aaa");
	sub2.RegSubscriber("\aaa");
	sub3.RegSubscriber("\aaa");

	pub.Publish("Hello !!");

	std::cout << sub;
	std::cout << sub2;
	std::cout << sub3;

	std::cout << "Publisher publish new message" << std::endl;
	pub.Publish("Hello !");

	std::cout << sub;
	std::cout << sub2;
	std::cout << sub3;

	return 0;
}
