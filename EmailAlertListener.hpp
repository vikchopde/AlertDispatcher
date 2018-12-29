#ifndef ZEROTOHERO_EMAILALERTLISTENER_HPP
#define ZEROTOHERO_EMAILALERTLISTENER_HPP

#include "IAlertListener.hpp"
#include "EmailAlert.hpp"
#include "Dispatcher.hpp"

class EmailAlertListener : public IAlertListener
{
public:

    using Ptr = std::shared_ptr<EmailAlertListener>;

    EmailAlertListener(const Dispatcher& dispatcher)
            : dispatcher_(dispatcher)
    {}

    void registerEvent() {
        dispatcher_.registerEvent(1, shared_from_this());
    }

    virtual void handleEvent(IAlert::Ptr alert) override {
        auto emailAlert = std::dynamic_pointer_cast<EmailAlert::Ptr>(alert);
        std::cout << "Email Alert"<< std::endl;
    }

private:
    const Dispatcher& dispatcher_;
};


#endif //ZEROTOHERO_EMAILALERTLISTENER_HPP
