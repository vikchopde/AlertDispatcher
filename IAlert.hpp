#ifndef ZEROTOHERO_IALERT_HPP
#define ZEROTOHERO_IALERT_HPP

#include <memory>
#include <cstdint>

class IAlert
{
public:
    using Ptr = std::shared_ptr<IAlert>;

    virtual int32_t descriptor() = 0;
protected:
    uint32_t id_;
};

#endif //ZEROTOHERO_IALERT_HPP
