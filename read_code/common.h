/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  edge common头文件
 *
 *        Version:  1.0
 *        Created:  07/26/2017 09:34:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhaoxiaobiao, 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef COMMON_H
#define COMMON_H 

#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

#ifdef __MACH__
#define _talogD _talog 
#define _talogI _talog 
#define _talogE _talog 
#define _talog(prefix, format, ...) \
    printf("t0dbg[" prefix "][thread_id:0x%ld][%s:%d %s]" format "\n", (long)pthread_self(), __FILE__, __LINE__, __func__, ##__VA_ARGS__);

#else
    #ifdef __TEST__ 
        #define _talogD _talog 
        #define _talogI _talog 
        #define _talogE _talog 
        #define _talog(prefix, format, ...) printf(format "\n", ##__VA_ARGS__);
    #else
        #include <android/log.h>
        #include <pthread.h>
        #define _talogD(prefix, format, ...)  \
        __android_log_print(ANDROID_LOG_DEBUG, "t0dbg", "[" prefix "][thread_id:0x%lx][%s:%d %s]" format "\n", (long)pthread_self(), __FILE__, __LINE__, __func__, ##__VA_ARGS__)
        #define _talogI(prefix, format, ...)  \
        __android_log_print(ANDROID_LOG_INFO, "t0dbg", "[" prefix "][thread_id:0x%lx][%s:%d %s]" format "\n", (long)pthread_self(), __FILE__, __LINE__, __func__, ##__VA_ARGS__)
        #define _talogE(prefix, format, ...)  \
        __android_log_print(ANDROID_LOG_ERROR, "t0dbg", "[" prefix "][thread_id:0x%lx][%s:%d %s]" format "\n", (long)pthread_self(), __FILE__, __LINE__, __func__, ##__VA_ARGS__)
    #endif
#endif

#if TA_LOG == 1     //DEBUG, INFO, ERROR
    #define USE_LOGD
    #define USE_LOGI
    #define USE_LOGE
#elif TA_LOG == 2   //INFO, ERROR
    #define USE_LOGI
    #define USE_LOGE
#elif TA_LOG == 3   //ERROR
    #define USE_LOGE
#else
#endif


#ifdef USE_LOGD
    #define LOGD(format, ...) _talogD("D", format, ##__VA_ARGS__)
#else
    #define LOGD(format, ...)
#endif

#ifdef USE_LOGI
    #define LOGI(format, ...) _talogI("I", format, ##__VA_ARGS__)
#else
    #define LOGI(format, ...)
#endif

#ifdef USE_LOGE
    #define LOGE(format, ...) _talogE("E", format, ##__VA_ARGS__)
#else
    #define LOGE(format, ...)
#endif



#define EDGE_INT32_LEN   (sizeof("-2147483648") - 1)
#define EDGE_INT64_LEN   (sizeof("-9223372036854775808") - 1)
#define EDGE_MAX_INT_T_VALUE  2147483647
#define EDGE_MAX_UINT32_VALUE  (uint32_t) 0xffffffffLL
#define EDGE_MAX_SIZE_T_VALUE  9223372036854775807LL
#define EDGE_MAX_OFF_T_VALUE  9223372036854775807LL
#define EDGE_MAX_TIME_T_VALUE  9223372036854775807LL
#define EDGE_OK          0
#define EDGE_ERROR      -1
#define EDGE_AGAIN      -2
#define EDGE_BUSY       -3
#define EDGE_DONE       -4
#define EDGE_ABORT      -6
#define EDGE_DECLINED    1


//store_cache + wb config
#define SW_CLOSE            0x00  //关闭白盒+缓存
#define SW_WB_OPEN          0x01  //开启白盒
#define SW_STORE_OPEN       0x02  //开启EDGE_KV_STORE缓存
#define SW_STORE_MEM_OPEN   0x04  //开启EDGE_KV_STORE_MEM缓存

long long time_milliseconds(void);
#endif
