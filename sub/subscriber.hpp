/// \file subscriber.hpp
/// 
/// \author Chun-Hsu Lai
///
/// \date 2020/01/12

#ifndef SUBSCRIBER_HPP_
#define SUBSCRIBER_HPP_

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

class Subscriber : public boost::enable_shared_from_this<Subscriber> {
    public:
        Subscriber(std::string _topic) { this->topic_ = _topic; }
        void update(const std::string msg_) { message_queue_.push_back(msg_); };

    private:
        std::string topic_;
        std::vector<std::string> message_queue_;
};

#endif // SUBSCRIBER_HPP_