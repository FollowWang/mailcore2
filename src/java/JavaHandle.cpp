#include "JavaHandle.h"

using namespace mailcore;

static jfieldID getField(JNIEnv * env, jobject obj, const char * fieldName)
{
    jclass c = env->GetObjectClass(obj);
    return env->GetFieldID(c, fieldName, "J");
}

static jfieldID getHandleField(JNIEnv * env, jobject obj)
{
    return getField(env, obj, "nativeHandle");
}

void * mailcore::getHandle(JNIEnv * env, jobject obj)
{
    jlong handle = env->GetLongField(obj, getHandleField(env, obj));
    return (void *) handle;
}

void mailcore::setHandle(JNIEnv *env, jobject obj, void *t)
{
    jlong handle = reinterpret_cast<jlong>(t);
    env->SetLongField(obj, getHandleField(env, obj), handle);
}

void * mailcore::getCustomHandle(JNIEnv * env, jobject obj, const char * fieldName)
{
    jlong handle = env->GetLongField(obj, getField(env, obj, fieldName));
    return (void *) handle;
}

void mailcore::setCustomHandle(JNIEnv *env, jobject obj, const char * fieldName, void *t)
{
    jlong handle = reinterpret_cast<jlong>(t);
    env->SetLongField(obj, getField(env, obj, fieldName), handle);
}

jobject mailcore::getObjectField(JNIEnv *env, jobject obj, const char * fieldName)
{
    return env->GetObjectField(obj, getField(env, obj, fieldName));
}