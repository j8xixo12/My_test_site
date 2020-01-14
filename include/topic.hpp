/// \file topic.hpp
/// 
/// \author Chun-Hsu Lai
///
/// \date 2020/01/14

#ifndef TOPIC_HPP_
#define TOPIC_HPP_

#include <map>
#include "publisher.hpp"
#include "subscriber.hpp"
#include <boost/shared_ptr.hpp>
#include "Singleton.hpp"
#include "type_def.hpp"

class Topic : public Singleton<Topic> {
    public:
        PublisherPtr RegistPublisher(std::string _topic) {
            PublisherPtr pub = Publisher(_topic);
            Publisher_Map.insert(std::pair<std::string,PublisherPtr>(_topic, pub));
            return pub;
        }
        SubscriberPtr RegistSubscriber(std::string _topic) {
            SubscriberPtr sub = Subscriber(_topic);
            Subscriber_Map.insert(std::pair<std::string,SubscriberPtr>(_topic, sub));
            return sub;
        }
        
    private:
        Topic() {};
        ~Topic() {};
        std::map<std::string, PublisherPtr> Publisher_Map;
        std::map<std::string, SubscriberPtr> Subscriber_Map;

    friend class Singleton<Topic>;
};

#endif // TOPIC_HPP_