#pragma once
#include"tools.h"
#include"opencv2/opencv.hpp"

namespace session1{
    /// @brief 开启OMP将指定区域内的代码运行多次
    void testOpenOMP(){
        omp_set_num_threads(8);
        #pragma omp parallel 
        {
            int thread_num = omp_get_thread_num();
            printf("在此运行多次 thredNum is %d \n", thread_num);   
        }
    }
    
    /// @brief 使用critical 指令 表明区域内的命令要一个个执行不能多线程同时进行 a b俩变量咱们看一下
    void testLockMem_critical()
    {
        int a = 0, b = 0;
        omp_set_num_threads(8);
        #pragma omp parallel shared(a, b)
        {
            a += 1;
            #pragma omp critical
            {
                b += 1;
            }  
        }
        LOGD("a b %d, %d", a,b);
    }


    /// @brief 测试omp for循环指令 和其节省时间对比, 奇怪的是线程开了4 执行时间却缩短了6倍还多
    void testforLoop()
    {
        int imh = 10000;
        cv::Mat testDatas = cv::Mat::zeros(cv::Size(imh,imh), CV_8UC3);
        // 单线程测试速度
        {
            AUTOTIMEC;
            for (int i = 0; i < testDatas.rows * testDatas.cols * testDatas.channels(); i+=3)
            {
                testDatas.data[i] = 255;
            }
        }
        // cv::imwrite("./imgs/singleImg.png", testDatas);

        cv::Mat testDatas_omp = cv::Mat::zeros(cv::Size(imh,imh), CV_8UC3);
        // omp测速
        {
            AUTOTIMEC;
            omp_set_num_threads(4);
            #pragma omp parallel for
            for (int i = 0; i < testDatas_omp.rows * testDatas_omp.cols * testDatas_omp.channels(); i+=3)
            {
                testDatas_omp.data[i] = 255;
            }
        

        }
        // cv::imwrite("./imgs/ompimg.png", testDatas);
        
    }
}