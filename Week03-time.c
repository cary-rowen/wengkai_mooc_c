/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week03-time.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月10日
*   Description ：
*  
时间换算（5分）
题目内容：

UTC是世界协调时，BJT是北京时间，UTC时间相当于BJT减去8。现在，你的程序要读入一个整数，表示BJT的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果小时不是0而分小于10分，需要保留十位上的0；如果小时是0而分小于10分的，则不需要保留十位上的0。如1124表示11点24分，而905表示9点5分，36表示0点36分，7表示0点7分。

有效的输入范围是0到2359，即你的程序不可能从测试服务器读到0到2359以外的输入数据。

你的程序要输出这个时间对应的UTC时间，输出的格式和输入的相同，即输出一个整数，表示UTC的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果小时不是0而分小于10分，需要保留十位上的0；如果小时是0而分小于10分的，则不需要保留十位上的0。

提醒：要小心跨日的换算。


输入格式:

一个整数，表示BJT的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果小时不是0而分小于10分，需要保留十位上的0；如果小时是0而分小于10分的，则不需要保留十位上的0。



输出格式：

一个整数，表示UTC的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果小时不是0而分小于10分，需要保留十位上的0；如果小时是0而分小于10分的，则不需要保留十位上的0。



输入样例：

803



输出样例：

3

时间限制：500ms内存限制：32000kb
================================================================*/
#include <stdio.h>

int main() {
    
    int bjt;
    scanf("%d", &bjt); // 803

    if (bjt < 0 || bjt > 2359)
        return 0;

    int qianwei = 0;
    int baiwei = 0;
    int shiwei = 0;
    int gewei = 0;

    qianwei = bjt / 1000; // 0
    baiwei = (bjt - qianwei * 1000) / 100; // 8
    shiwei = (bjt - qianwei * 1000 - baiwei * 100) / 10; //0
    gewei = bjt % 10; // 3

    int hour = 0;
    int minute = 0;
    if (qianwei == 0 && baiwei >=0 && baiwei < 8)
        hour = 24 + baiwei - 8; 
    else
        hour = qianwei * 10 + baiwei - 8;

    if (!shiwei) {
        if (hour > 0 && hour < 24)
            printf("%d0", hour);
        minute = gewei; 
    }
    else {
        if (hour > 0 && hour < 24)
            printf("%d", hour); 
        minute = shiwei * 10 + gewei;
    }


    if (minute >= 0 && minute < 60)
        printf("%d", minute);

        

    

    return  0;
}
