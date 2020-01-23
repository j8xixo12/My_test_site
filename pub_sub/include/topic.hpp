/// \file topic.hpp
/// 
/// \author Chun-Hsu Lai
///
/// \date 2020/01/14

#ifndef TOPIC_HPP_
#define TOPIC_HPP_

#include <map>
#include <list>
#include <iostream>
#include <mutex>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "typedef.hpp"
#include "singleton.hpp"

class Topic : public Singleton<Topic> {
    public:
        PublisherPtr RegistPublisher(std::string _topic) {
            PublisherPtr pub = boost::make_shared<Publisher>(_topic);

            std::lock_guard<std::mutex> lock(topic_lock_);
            Publisher_Map.insert(std::pair<std::string,PublisherPtr>(_topic, pub));
            return pub;
        }
        SubscriberPtr RegistSubscriber(std::string _topic) {
            std::lock_guard<std::mutex> lock(topic_lock_);

            auto it = Subscriber_Map.find(_topic);
            SubscriberPtr sub = boost::make_shared<Subscriber>(_topic);
            
            if (it != Subscriber_Map.end()) {
                it->second->push_back(sub);
            } else { 
                SubscriberPtrList *ListPtr = new SubscriberPtrList;
                ListPtr->push_back(sub);
                Subscriber_Map.insert(std::pair<std::string,SubscriberPtrList*>(_topic, ListPtr));
            }
            // Subscriber_Map.insert(std::pair<std::string,SubscriberPtr>(_topic, sub));
            return sub;
        }

        bool notify(const std::string _topic) {
            std::lock_guard<std::mutex> lock(topic_lock_);
            
            auto sub_it = Subscriber_Map.find(_topic);
            auto pub_it = Publisher_Map.find(_topic);
            auto list_it = sub_it->second;

            for (auto &&i : *list_it) {
                i->update(pub_it->second->GetMsg());
            }
            // sub_it->second->update(pub_it->second->GetMsg());
            return true;
        }
        
    private:
        Topic() {}
        ~Topic() {
            Publisher_Map.clear();
            Subscriber_Map.clear();
        };
        std::map<std::string, PublisherPtr> Publisher_Map;
        std::map<std::string, SubscriberPtrList*> Subscriber_Map;

        std::mutex topic_lock_;

    friend class Singleton<Topic>;
};

#endif // TOPIC_HPP_