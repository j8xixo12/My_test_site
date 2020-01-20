/// \file node.hpp
///
/// \author Chun-Hsu Lai
///
/// \date 2020/01/15

#ifndef NODE_HPP_
#define NODE_HPP_

#include "subscriber.hpp"
#include "publisher.hpp"
#include "topic.hpp"
#include <iostream>

class Node {
    public:
        explicit Node(std::string _name): sub_ptr_(nullptr), pub_ptr_(nullptr), name_(_name) {};
        void RegSubscriber(const std::string _topic);
        void RegPublisher(const std::string _topic);
        void Publish(const std::string _msg);
        std::string GetMsg() { return sub_ptr_->GetMsg(); }
        std::string GetName() { return name_; }
    private:
        SubscriberPtr sub_ptr_;
        PublisherPtr pub_ptr_;
        std::string sub_topic_;
        std::string pub_topic_;
        std::string name_;
};

std::ostream & operator<< (std::ostream &ostr, Node &node);

#endif // NODE_HPP_