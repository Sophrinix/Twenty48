// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from twenty_forty_eight.djinni

#pragma once

#include "djinni_support.hpp"
#include "move.hpp"

namespace twentyfortyeight { namespace jni {

class Move final : ::djinni::JniEnum {
public:
    using CppType = ::twentyfortyeight::cpp::Move;
    using JniType = jobject;

    using Boxed = Move;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<Move>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<Move>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    Move() : JniEnum("com/boloutaredoubeni/twentyfortyeight/djinni/Move") {}
    friend ::djinni::JniClass<Move>;
};

} }  // namespace twentyfortyeight::jni
