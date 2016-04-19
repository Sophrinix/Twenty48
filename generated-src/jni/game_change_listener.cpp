// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from twenty_forty_eight.idl

#include "game_change_listener.hpp"  // my header

namespace twentyfortyeight { namespace jni {

GameChangeListener::GameChangeListener() : ::djinni::JniInterface<::twentyfortyeight::cpp::GameChangeListener, GameChangeListener>() {}

GameChangeListener::~GameChangeListener() = default;

GameChangeListener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

GameChangeListener::JavaProxy::~JavaProxy() = default;

void GameChangeListener::JavaProxy::OnGameStateChanged() {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::twentyfortyeight::jni::GameChangeListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onGameStateChanged);
    ::djinni::jniExceptionCheck(jniEnv);
}

} }  // namespace twentyfortyeight::jni