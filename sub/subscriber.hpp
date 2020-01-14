/// \file subscriber.hpp
/// 
/// \author Chun-Hsu Lai
///
/// \date 2020/01/12

#ifndef SUBSCRIBER_HPP_
#define SUBSCRIBER_HPP_

#include "publisher.hpp"
#include <vector>
#include <boost/shared_ptr.hpp>

class Subscriber : public boost::enable_shared_from_this<Subscriber> {
    public:
        Subscriber(std::string _topic) { this->topic_ = _topic; }
        void update(Publisher *_pub, std::string _msg);

    private:
        std::string topic_;
        std::vector<std::string> message_queue_;
};

#endif // SUBSCRIBER_HPP_