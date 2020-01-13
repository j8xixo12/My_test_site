/// \file publisher.hpp
///
/// \author Chun-Hsu Lai
///
/// \date 2020/01/12

#ifndef PUBLISHER_HPP_
#define PUBLISHER_HPP_
#include <list>
#include <string>
#include "subscriber.hpp"

class Publisher {
    public:
        Publisher() {};
        void publish(std::string _msg);
    private:
        std::list<Subscriber*> subscribers_;
};

#endif // PUBLISHER_HPP_