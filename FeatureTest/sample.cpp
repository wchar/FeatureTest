//
//  sample.cpp
//  SpeedTest
//
//  Created by wcchan on 15/11/14.
//  Copyright © 2015年 wcchan. All rights reserved.
//

#include "Tester.h"

ENTER_CASE
{
    puts("This is a normal sample test.");
}

TEST_CASE("loop 100 times")
{
    for (int i = 1; i < 100; i++)
    {
    }
}

TEST_CASE("getchar() duration")
{
    getchar();
}

ENTER_CASE
{
    puts("getchar() one more time:");
    test::flag();
    getchar();
    test::duration();
    puts("测试结束");
}
