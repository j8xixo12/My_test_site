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
#include <boost/shared_ptr.hpp>

class Publisher : public boost::enable_shared_from_this<Publisher> {
    public:
        Publisher(std::string _topic) { this->topic_ = _topic; };
        void publish(std::string _msg);
    private:
        std::string topic_;
};

#endif // PUBLISHER_HPP_