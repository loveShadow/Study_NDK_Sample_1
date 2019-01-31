//
// Created by Administrator on 2019/1/30.
//
#include "com_study_ndk_NDKDemo.h"
#include <jni.h>
#include <android/log.h>

/**
 * 导入Android Log 的.h文件及定义宏
 */
#define LOG_TAG "libSum"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


JNIEXPORT jint JNICALL Java_com_study_ndk_NDKDemo_sum
        (JNIEnv * env, jclass jc, jint arg1, jint arg2) {
    /**
     * 计算结果
     */
    jint result = arg1 + arg2;

    /**
     * 调用Android的logcat进行打印
     */
    LOGI("sum | arg1 = %d, arg2 = %d, result = %d", arg1, arg2, result);
    return result;
}

JNIEXPORT jint JNICALL Java_com_study_ndk_NDKDemo_mult
        (JNIEnv * env, jclass jc, jint arg1) {
    /**
     * 找到要调用的类
     */
    jclass javaClass = env->FindClass("com/study/ndk/JavaClass");
    /**
     * 判断是否为空指针
     */
    if (nullptr == javaClass) {
        LOGE(LOG_TAG, "cannot find JavaClass");
        return -1;
    }

    /**
     * 获取构造方法
     */
    jmethodID initMethod = env->GetMethodID(javaClass, "<init>", "()V");
    if (nullptr == initMethod) {
        LOGE(LOG_TAG, "cannot find init");
        return -1;
    }

    /**
     * 构造对象
     */
    jobject object = env->NewObject(javaClass, initMethod);
    if (nullptr == object) {
        LOGE(LOG_TAG, "cannot create object");
        return -1;
    }

    /**
     * 找到要调用的方法
     * 第一个：Java类对象
     * 第二个：方法名
     * 第三个：该方法的签名[例如：参数是int类型，返回值void，则签名是(I)V]
     */
    jmethodID methodID = env->GetMethodID(javaClass, "getMultiplier", "()I");
    if (nullptr == methodID) {
        LOGE(LOG_TAG, "cannot find getMultiplier");
        return -1;
    }

    jint arg2 = env->CallIntMethod(object, methodID);
    LOGI(LOG_TAG, "get arg2 = %d", arg2);

    int result = arg1 * arg2;
    return result;
}