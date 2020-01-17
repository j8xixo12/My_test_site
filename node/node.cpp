#include "node.hpp"

void Node::RegSubscriber(const std::string _topic) {
    sub_ptr_ = Topic::Instance()->RegistSubscriber(_topic);
    return;
}

void Node::RegPublisher(const std::string _topic) {
    pub_ptr_ = Topic::Instance()->RegistPublisher(_topic);
    return;
}
