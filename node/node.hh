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

class Node {
    public:
        Node(): sub_ptr_(nullptr), pub_ptr_(nullptr) {};

    private:
        SubscriberPtr sub_ptr_;
        PublisherPtr pub_ptr_;
}

#endif // NODE_HPP_