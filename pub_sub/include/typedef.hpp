#ifndef TYPEDEF_HPP_
#define TYPEDEF_HPP_

#include <list>
#include "publisher.hpp"
#include "subscriber.hpp"

typedef boost::shared_ptr<Subscriber> SubscriberPtr;
typedef boost::shared_ptr<Publisher> PublisherPtr;
typedef std::list<SubscriberPtr> SubscriberPtrList;


#endif // TYPEDEF_HPP_