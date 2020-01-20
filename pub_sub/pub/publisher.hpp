/// \file publisher.hpp
///
/// \author Chun-Hsu Lai
///
/// \date 2020/01/12

#ifndef PUBLISHER_HPP_
#define PUBLISHER_HPP_

#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

class Publisher : public boost::enable_shared_from_this<Publisher> {
    public:
        Publisher(std::string _topic) : publish_succeeded_(false) { this->topic_ = _topic; };
        ~Publisher() {};
        void publish();
        std::string GetMsg() { return this->message_; }
        void SetMsg(std::string _msg) { this->message_ = _msg; }
    private:
        std::string topic_;
        std::string message_;
        bool publish_succeeded_;
};

#endif // PUBLISHER_HPP_