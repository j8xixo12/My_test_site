/*
 * Singleton.hpp
 * 
 * Created on : 2020/01/08
 * Author : Chun-Hsu Lai
 */

#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

template<class T>
class Singleton {
  public:
		static T* Instance() {
			return &GetInstance();
		}

  protected:
		Singleton(){};
		virtual ~Singleton(){};
	
  private:
		static T &GetInstance() {
			static T single;
			return static_cast<T&>(single);
		}

};

#endif // SINGLETON_HPP_
