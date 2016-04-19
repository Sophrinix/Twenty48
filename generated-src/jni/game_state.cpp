// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from twenty_forty_eight.idl

#include "game_state.hpp"  // my header
#include "Marshal.hpp"

namespace twentyfortyeight { namespace jni {

GameState::GameState() : ::djinni::JniInterface<::twentyfortyeight::cpp::GameState, GameState>("com/boloutaredoubeni/twentyfortyeight/djinni/GameState$CppProxy") {}

GameState::~GameState() = default;


CJNIEXPORT void JNICALL Java_com_boloutaredoubeni_twentyfortyeight_djinni_GameState_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::twentyfortyeight::cpp::GameState>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jshort JNICALL Java_com_boloutaredoubeni_twentyfortyeight_djinni_GameState_00024CppProxy_native_1score(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::twentyfortyeight::cpp::GameState>(nativeRef);
        auto r = ref->Score();
        return ::djinni::release(::djinni::I16::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_boloutaredoubeni_twentyfortyeight_djinni_GameState_00024CppProxy_native_1draw(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::twentyfortyeight::cpp::GameState>(nativeRef);
        ref->Draw();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_com_boloutaredoubeni_twentyfortyeight_djinni_GameState_00024CppProxy_native_1win(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::twentyfortyeight::cpp::GameState>(nativeRef);
        auto r = ref->Win();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

} }  // namespace twentyfortyeight::jni