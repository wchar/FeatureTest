//
//  Tester.h
//  SpeedTest
//
//  Created by wcchan on 15/11/14.
//  Copyright © 2015年 wcchan. All rights reserved.
//

#ifndef __TESTER_H__
#define __TESTER_H__

#include <stdio.h>
#include <sys/time.h>

namespace test
{
    timeval* __t()
    {
        static timeval s_t = { 0, 0 };
        return &s_t;
    }

    void flag()
    {
        gettimeofday(__t(), nullptr);
    }

    void duration()
    {
        timeval t_start = *__t();
        timeval t_end;
        gettimeofday(&t_end, nullptr);
        unsigned long t_s = t_end.tv_sec - t_start.tv_sec;
        unsigned long t_u = t_end.tv_usec - t_start.tv_usec;
        printf("%ldus\n", 1000000 * t_s + t_u);
    }

    template <typename T>
    class EnterCase
    {
    public:
        EnterCase(bool timer);
        void run();
    };

#define __ENTER_CASE_CONCATENATE_IMPL(s1, s2) s1##s2
#define __ENTER_CASE_CONCATENATE(s1, s2) __ENTER_CASE_CONCATENATE_IMPL(s1, s2)

#define __ENTER_CASE(ClassName, TIMER)                                                \
    namespace                                                                         \
    {                                                                                 \
        struct ClassName;                                                             \
    }                                                                                 \
    static test::EnterCase<ClassName> __ENTER_CASE_CONCATENATE(s_, ClassName)(TIMER); \
    template <>                                                                       \
    void test::EnterCase<ClassName>::run()

#define ENTER_CASE \
    __ENTER_CASE(__ENTER_CASE_CONCATENATE(ENTER_CASE_NAME, __LINE__), false)

    template <typename T>
    EnterCase<T>::EnterCase(bool timer)
    {
        if (timer)
        {
            flag();
        }
        run();
        if (timer)
        {
            duration();
        }
    }

#define TEST_CASE(CaseName)                                        \
    __ENTER_CASE(__ENTER_CASE_CONCATENATE(PRINT, __LINE__), false) \
    {                                                              \
        printf("%s:\n", CaseName);                               \
    }                                                              \
    __ENTER_CASE(__ENTER_CASE_CONCATENATE(ENTER_CASE_NAME, __LINE__), true)
}

#endif
