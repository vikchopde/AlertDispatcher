
#include "Dispatcher.hpp"
#include "IAlert.hpp"

void Dispatcher::run()
{
auto t = std::thread([this](){
    for(;;)
    {
        IAlert::Ptr alert = this->q_.wait_and_pop();

        auto find = this->eventCallBackMap_.find(alert->descriptor());
        if (find != this->eventCallBackMap_.end()) {
            for (const auto &l : find->second)
                l->handleEvent(alert);
        }
    }
});
t.detach();
}
