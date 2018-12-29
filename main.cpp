#include <iostream>
#include <map>
#include <memory>
#include <thread>
#include <list>
#include "AlertQueue.hpp"
#include "EmailAlert.hpp"
#include "Dispatcher.hpp"
#include "EmailAlertListener.hpp"
#include "SMSAlertListener.hpp"

int main()
{
    try
    {
        Dispatcher::Ptr d = std::make_shared<Dispatcher>();
        EmailAlertListener::Ptr e = std::make_shared<EmailAlertListener>(*d);
        e->registerEvent();

        SMSAlertListener::Ptr s = std::make_shared<SMSAlertListener>(*d);
        s->registerEvent();

        for(;;) {
            EmailAlert::Ptr eAlert = std::make_shared<EmailAlert>();
            d->dispatch(eAlert);
        }
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "EROORRR "<< std::endl;
    }

    return 0;
}