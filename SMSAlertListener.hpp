#ifndef ZEROTOHERO_SMSALERTLISTENER_HPP
#define ZEROTOHERO_SMSALERTLISTENER_HPP

#include "IAlertListener.hpp"
#include "EmailAlert.hpp"
#include "Dispatcher.hpp"

class SMSAlertListener : public IAlertListener
{
public:
    SMSAlertListener(const Dispatcher& dispatcher)
            : dispatcher_(dispatcher)
    {}

    void registerEvent()
    {
        dispatcher_.registerEvent(1, shared_from_this());
    }

    using Ptr = std::shared_ptr<SMSAlertListener>;

    virtual void handleEvent(IAlert::Ptr alert) override
    {
        auto emailAlert = std::dynamic_pointer_cast<EmailAlert::Ptr>(alert);
        std::cout << "SMS Alert"<< std::endl;
    }

private:
    const Dispatcher& dispatcher_;
};

#endif //ZEROTOHERO_SMSALERTLISTENER_HPP
