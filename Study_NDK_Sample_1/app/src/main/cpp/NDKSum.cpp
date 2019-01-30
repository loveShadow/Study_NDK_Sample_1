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