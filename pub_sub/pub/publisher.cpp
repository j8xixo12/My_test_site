#include "publisher.hpp"
#include "topic.hpp"

void Publisher::publish() { publish_succeeded_ = Topic::Instance()->notify(topic_); }