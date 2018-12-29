#ifndef ZEROTOHERO_IALERTLISTENER_HPP
#define ZEROTOHERO_IALERTLISTENER_HPP

#include "IAlert.hpp"
#include <memory>

class IAlertListener : public std::enable_shared_from_this<IAlertListener>
{
public:
    using Ptr = std::shared_ptr<IAlertListener>;

    virtual void handleEvent(IAlert::Ptr) = 0;
};

#endif //ZEROTOHERO_IALERTLISTENER_HPP
