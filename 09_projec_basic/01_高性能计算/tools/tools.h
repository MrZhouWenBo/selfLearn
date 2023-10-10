/**************************************************************************

Copyright:MyCompany

Author: jose

Date:2023-09-08

Description:  工具函数和类型定义   

**************************************************************************/
#pragma once
#include <iostream>
#include <map>
#include<vector>
#include <stdio.h>
#include <stdint.h>
#include <map>
#include <string.h>
#include <fstream>
#include <dirent.h>
#include <cstring>
#include <algorithm>
#include"cmath"
#include "omp.h"
#include <sys/time.h>


#define __FILENAME__ (strrchr(__FILE__, '/') + 1) // 文件名
#ifdef DEBUG
#define LOGD(format, ...) printf("[%s][%s][%d]: " format "\n", __FILENAME__, __FUNCTION__,\
                            __LINE__, ##__VA_ARGS__)
#else
#define LOGD(format, ...)
#endif

class AutoTimeC{
public:
    AutoTimeC(int line, const char* func);
    ~AutoTimeC();

private:
    int mLine;
    char* mName;
    uint64_t mCurrentTime;
    uint64_t mLastResetTime;
};

#ifdef TIME_TRACE
#define AUTOTIMEC AutoTimeC ___t(__LINE__, __PRETTY_FUNCTION__)
#else
#define AUTOTIMEC
#endif


AutoTimeC::AutoTimeC(int line, const char* func)
{
    mName = strdup(func);
    mLine = line;

    struct timeval Current;
    gettimeofday(&Current, NULL);
    mLastResetTime = Current.tv_sec * 1000000 + Current.tv_usec;
}

AutoTimeC::~AutoTimeC()
{
    struct timeval Current;
    gettimeofday(&Current, NULL);
    uint64_t lastTime = Current.tv_sec * 1000000 + Current.tv_usec;
    uint64_t timeInUs = lastTime - mLastResetTime;

    printf("[%s]@%d, cost time: %f ms\n", mName, mLine, (float)timeInUs / 1000.0f);
    free(mName);
}


