/// \file type_def.hpp
///
/// \author Chun-Hsu Lai
///
/// \date 2020/1/14

#ifndef TYPE_DEF_HPP_
#define TYPE_DEF_HPP_

class Publisher;
class Subscriber;

typedef boost::shared_ptr<Publisher> PublisherPtr;
typedef boost::shared_ptr<Subscriber> SubscriberPtr;

#endif // TYPE_DEF_HPP_