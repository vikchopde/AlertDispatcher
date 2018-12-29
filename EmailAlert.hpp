#ifndef ZEROTOHERO_EMAILALERT_HPP
#define ZEROTOHERO_EMAILALERT_HPP

#include "IAlert.hpp"

class EmailAlert: public IAlert
{
public:
    using Ptr = std::shared_ptr<EmailAlert>;

    EmailAlert()
    {
        id_ = 1;
    }

    virtual int32_t descriptor() override
    {
        return id_;
    }
};


#endif //ZEROTOHERO_EMAILALERT_HPP
