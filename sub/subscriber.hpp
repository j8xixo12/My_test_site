/// \file subscriber.hpp
/// 
/// \author Chun-Hsu Lai
///
/// \date 2020/01/12

#ifndef SUBSCRIBER_HPP_
#define SUBSCRIBER_HPP_

#include "publisher.hpp"
#include <vector>

class Subscriber {
    public:
        Subscriber();
        void update(Publisher *_pub, std::string _msg);

    private:
        std::vector<std::string> message_queue_;
};

#endif // SUBSCRIBER_HPP_