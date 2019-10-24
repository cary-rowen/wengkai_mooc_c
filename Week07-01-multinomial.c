/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week07-01-sum.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月30日
*   Description ：
        多项式加法（5分）
        题目内容：
        
        一个多项式可以表达为x的各次幂与系数乘积的和，比如： 2x6+3x5+12x3+6x+20
        
        现在，你的程序要读入两个多项式，然后输出这两个多项式的和，也就是把对应的幂上的系数相加然后输出。
        
        程序要处理的幂最大为100。
        
        输入格式:
        
        总共要输入两个多项式，每个多项式的输入格式如下：
        
        每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，所有的系数都是整数。第一行一定是最高幂，最后一行一定是0次幂。
        
        注意第一行和最后一行之间不一定按照幂次降低顺序排列；如果某个幂次的系数为0，就不出现在输入数据中了；0次幂的系数为0时还是会出现在输入数据中。
        
        输出格式：
        
        从最高幂开始依次降到0幂，如：
        
        2x6+3x5+12x3-6x+20
        
        注意其中的x是小写字母x，而且所有的符号之间都没有空格，如果某个幂的系数为0则不需要有那项。
        
        输入样例：
        
        6 2
        5 3
        3 12
        1 6
        0 20
        6 2
        5 3
        2 12
        1 6
        0 20
        
        输出样例：
        
        4x6+6x5+12x3+12x2+12x+40
        
        时间限制：500ms内存限制：32000kb
================================================================*/
#include <stdio.h>
#include <stdlib.h> // abs()

#define MAX_POWER 100

void make_mutinomial(int[], int);

void print_array(int arr[], int length) {
    for (int i = 0;i < length; i ++) {
        printf("Pri: %d %d\n", i, arr[i]);
    }
}

int main() {

    int power = 0, coefficient = 0;

    // 从 0 到 100，所以要加上 1
    // 又，有两个多项式，所以 x2
    const int elem_length = MAX_POWER + 1;
    int elements[MAX_POWER + 1] = {0};

    // 将数组元素全部置为 0
    // for (int i = 0; i < elem_length; i ++){
    //     elements[i] = 0;
    // }

    for (int i = 0; i < elem_length && scanf("%d %d", &power, &coefficient); i++) {
        if (power <= MAX_POWER && power >= 0 ) {
            // 因为数组元素全是 0
            if (!elements[power])
                elements[power] = coefficient;
            else
                elements[power] = elements[power] + coefficient;
        }

        if (power == 0)
            break;
    }

    for (int i = 0; i < elem_length && scanf("%d %d", &power, &coefficient); i++) {
        if (power <= MAX_POWER && power >= 0 ) {
            if (!elements[power])
                elements[power] = coefficient;
            else
                elements[power] = elements[power] + coefficient;
        }

        if (power == 0)
            break;
    }

    //print_array(elements, elem_length);

    //printf("\n4x6+6x5+12x3+12x2+12x+40\n");
    make_mutinomial(elements, elem_length);

    return 0;
}

void make_mutinomial(int arr[], int length) {

    int temp;
    unsigned char flag = 0;
    for (int i = length - 1; i >= 0; i --) {
        temp = arr[i];

        if (temp == -1) {
            flag = 1;
            printf("-");
            if (i == 0) {
                printf("%d", abs(temp));
            } else if (i == 1) {
                printf("x");
            } else {
                printf("x%d", i);
            }
        } else if (temp < -1) {
            flag = 1;
            printf("-");
            if (i == 0) {
                printf("%d", abs(temp));
            } else if (i == 1) {
                printf("%dx", abs(temp));
            } else {
                printf("%dx%d", abs(temp), i);
            }
        } else if (temp == 1) {
            if (flag)
                printf("+");
            flag = 1;
            if (i == 0) {
                printf("%d", temp);
            } else if (i == 1) {
                printf("x");
            } else 
                printf("x%d",i);
        } else if (temp == 0 && i == 0) {
            if (!flag)
                printf("0");
        } 
        else if (temp > 0) {
            if (flag)
                printf("+");
            flag = 1;
            if (i == 0) {
                printf("%d", temp);
            } else if (i == 1) {
                printf("%dx", temp);
            } else {
                printf("%dx%d", temp, i);
            }
        }


    }

    // 在线判题系统可能不要空格
    //printf("\n");
}
