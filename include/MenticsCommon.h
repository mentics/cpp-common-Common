#pragma once
#include "nn.hpp"
#include "spdlog\spdlog.h"

#define ONLY_MOVE(class_name) \
public:\
    class_name(class_name&&) = default;\
private:\
    class_name(const class_name&) = delete;\
    class_name& operator=(const class_name&) = delete

#define FOREVER 1E16

typedef uint64_t TimePoint;
typedef uint64_t TimeDuration;

#define PTRS(TypeName)\
using TypeName##Ptr = nn::nn<TypeName*>;\
using TypeName##UniquePtr = nn::nn<std::unique_ptr<TypeName> >;

#define PTRS1(TypeName, TemplateName)\
template <typename TemplateName>\
class TypeName;\
template <typename TemplateName>\
using TypeName##Ptr = nn::nn<TypeName<TemplateName>*>;\
template <typename TemplateName>\
using TypeName##UniquePtr = nn::nn<std::unique_ptr<TypeName<TemplateName>>>;

#define PTRS1S(TypeName, TemplateName)\
template <typename TemplateName>\
struct TypeName;\
template <typename TemplateName>\
using TypeName##Ptr = nn::nn<TypeName<TemplateName>*>;\
template <typename TemplateName>\
using TypeName##UniquePtr = nn::nn<std::unique_ptr<TypeName<TemplateName>>>;

#define PTRS2(TypeName, TemplateName1, TemplateName2)\
template <typename TemplateName1, typename TemplateName2>\
class TypeName;\
template <typename TemplateName1, typename TemplateName2>\
using TypeName##Ptr = nn::nn<TypeName<TemplateName1, TemplateName2>*>;\
template <typename TemplateName1, typename TemplateName2>\
using TypeName##UniquePtr = nn::nn<std::unique_ptr<TypeName<TemplateName1, TemplateName2>>>;

#define PTRS2S(TypeName, TemplateName1, TemplateName2)\
template <typename TemplateName1, typename TemplateName2>\
struct TypeName;\
template <typename TemplateName1, typename TemplateName2>\
using TypeName##Ptr = nn::nn<TypeName<TemplateName1, TemplateName2>*>;\
template <typename TemplateName1, typename TemplateName2>\
using TypeName##UniquePtr = nn::nn<std::unique_ptr<TypeName<TemplateName1, TemplateName2>>>;

typedef uint8_t byte;

namespace nn = dropbox::oxygen;

namespace MenticsGame {

extern std::shared_ptr<spdlog::logger> mlog;
const std::string EMPTY_STRING;
uint64_t currentTimeMillis();
uint64_t currentTimeNanos();

template<typename T>
nn::nn<T*> notNull(T* obj) {
    return NN_CHECK_ASSERT(obj);
}

template<typename T>
nn::nn<T*> toPtr(nn::nn_unique_ptr<T> const& obj) {
    return nn::nn_addr(*obj);
}

template <typename T, typename... Args>
nn::nn_unique_ptr<T> uniquePtr(Args &&... args) {
    return nn::nn_unique_ptr<T>(nn::i_promise_i_checked_for_null,
        std::unique_ptr<T>(new T(std::forward<Args>(args)...)));
}

template <typename T, typename TC, typename... Args>
nn::nn_unique_ptr<T> uniquePtrC(Args &&... args) {
    return nn::nn_unique_ptr<T>(nn::i_promise_i_checked_for_null,
        std::unique_ptr<T>(new TC(std::forward<Args>(args)...)));
}

}
