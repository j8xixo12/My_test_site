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
#include <boost/make_shared.hpp>
#include "singleton.hpp"

class Subscriber;
class Publisher;
typedef boost::shared_ptr<Publisher> PublisherPtr;
typedef boost::shared_ptr<Subscriber> SubscriberPtr;

class Topic : public Singleton<Topic> {
    public:
        PublisherPtr RegistPublisher(std::string _topic) {
            PublisherPtr pub = boost::make_shared<Publisher>(_topic);
            Publisher_Map.insert(std::pair<std::string,PublisherPtr>(_topic, pub));
            return pub;
        }
        SubscriberPtr RegistSubscriber(std::string _topic) {
            SubscriberPtr sub = boost::make_shared<Subscriber>(_topic);
            Subscriber_Map.insert(std::pair<std::string,SubscriberPtr>(_topic, sub));
            return sub;
        }

        bool notify(const std::string _topic) {
            auto sub_it = Subscriber_Map.find(_topic);
            auto pub_it = Publisher_Map.find(_topic);
            sub_it->second->update(pub_it->second->GetMsg());
            return true;
        }
        
    private:
        Topic() {};
        ~Topic() {};
        std::map<std::string, PublisherPtr> Publisher_Map;
        std::map<std::string, SubscriberPtr> Subscriber_Map;

    friend class Singleton<Topic>;
};

#endif // TOPIC_HPP_