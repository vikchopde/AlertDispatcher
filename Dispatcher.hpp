#ifndef ZEROTOHERO_DISPATCHER_HPP
#define ZEROTOHERO_DISPATCHER_HPP

#include <memory>
#include <thread>
#include <map>
#include "AlertQueue.hpp"
#include <list>
#include "IAlertListener.hpp"

class IAlert;

class Dispatcher
{
public:
    using Ptr = std::shared_ptr<Dispatcher>;

    Dispatcher()
    {
        run();
    }

    void run();

    void registerEvent(uint32_t eventid, std::shared_ptr<IAlertListener> ptr) const
    {
        eventCallBackMap_[eventid].insert(eventCallBackMap_[eventid].end(), ptr);
    }

    void dispatch(std::shared_ptr<IAlert> event) const
    {
        q_.push(event);
    }

private:
    using EventIDCallbackMap =  std::map<uint32_t, std::list<std::shared_ptr<IAlertListener>>>;
    mutable EventIDCallbackMap eventCallBackMap_;
    mutable threadsafe_queue<std::shared_ptr<IAlert>> q_;
};


#endif //ZEROTOHERO_DISPATCHER_HPP
