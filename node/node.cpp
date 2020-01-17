#include "node.hpp"

void Node::RegSubscriber(const std::string _topic) {
    sub_ptr_ = Topic::Instance()->RegistSubscriber(_topic);
    sub_topic_ = _topic;
    return;
}

void Node::RegPublisher(const std::string _topic) {
    pub_ptr_ = Topic::Instance()->RegistPublisher(_topic);
    pub_topic_ = _topic;
    return;
}

void Node::Subscribe() {
    mail_box_ = sub_ptr_->GetMsg();
}

void Node::Publish(const std::string _msg) {
    pub_ptr_->SetMsg(_msg);
    pub_ptr_->publish();
    return;
}