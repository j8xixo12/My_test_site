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
        Node(): sub_ptr_(nullptr), pub_ptr_(nullptr) {};
        void RegSubscriber(const std::string _topic);
        void RegPublisher(const std::string _topic);
        void Subscribe();
        void Publish(const std::string _msg);
        std::string GetMsg() { return mail_box_; }
    private:
        SubscriberPtr sub_ptr_;
        PublisherPtr pub_ptr_;
        std::string sub_topic_;
        std::string pub_topic_;
        std::string mail_box_;
};

std::ostream & operator<< (std::ostream &ostr, Node &node);

#endif // NODE_HPP_