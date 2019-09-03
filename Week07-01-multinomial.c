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

void sort(int[][2], int);
void swap_elem(int*, int*);
void make_mutinomial(int[][2], int);

void print_array(int arr[][2], int length) {
    for (int i = 0;i < length; i ++) {
        printf("Pri: %d %d\n", arr[i][0], arr[i][1]);
    }
}

int main() {

    int power = 0, coefficient = 0;

    // 从 0 到 100，所以要加上 1
    // 又，有两个多项式，所以 x2
    int elements[2 * (MAX_POWER + 1)][2];
    int elem_length = 2 * (MAX_POWER + 1);

    for (int i = 0; i < 2 * (MAX_POWER + 1); i ++) {
        elements[i][0] = 0;
        elements[i][1] = 0;
    }


    int line_count = 0;
    // 其实这个值已经超出一个多项式的范围
    int top_index = MAX_POWER + 1;
    while (line_count < top_index && scanf("%d %d", &power, &coefficient) == 2) {
        //printf("%d %d\n", power, coefficient);
        if (power <= MAX_POWER) {
            elements[line_count][0] = power;
            elements[line_count][1] = coefficient;
        }

        line_count ++;

        if (power == 0) {
            break;
        }
    }

    while (line_count < elem_length && scanf("%d %d", &power, &coefficient) == 2) {
        //printf("%d %d\n", power, coefficient);
        if (power <= MAX_POWER) {
            elements[line_count][0] = power;
            elements[line_count][1] = coefficient;
        }

        if (power == 0) {
            break;
        }

        line_count ++;
    }

    //print_array(elements, elem_length);

    // 对二维数组进行排序
    sort(elements, elem_length);
    //printf("\n==========================\n");
    //print_array(elements, elem_length);
    //printf("\n++++++++++++++++++++++++++\n");
    make_mutinomial(elements, elem_length);

    return 0;
}

void make_mutinomial(int arr[][2], int length) {

    int current = 0, prev = 0;
    int second_sum = 0;
    int is_first = 1;
    for (int i = 1; i < length; i++) {
        current = arr[i][0];
        prev = arr[i - 1][0];

        if (current == prev) {
            second_sum = arr[i][1] + arr[i - 1][1];
            i ++;
        } else {
            second_sum = arr[i - 1][1];
        }

        if (!second_sum) {
            if (!current && !prev && is_first) {
                printf("0");
                break;
            }
            continue;
        }

        if (second_sum > 0 && i - 1 != 1 && !is_first)
            printf("+");

        is_first = 0;

        if (second_sum != -1)
            printf("%d", second_sum);
        else
            printf("-");

        if (!current && prev) {
            if (prev == 1)
                printf("x");
            else
                printf("x%d", prev);

            continue;
        }

        if (current) {
            printf("x");
            if (current != prev) {
                if (prev != 1)
                    printf("%d", prev);
            } else if (current != 1)
                    printf("%d", current);

        }

    }

    // 在线判题系统可能不要空格
    //printf("\n");
}

void sort(int arr[][2], int length) {
    // 运用插入法进行二维数组的排序

    int index;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j > 0; j --) {
            index = j - 1;
            if (arr[j][0] > arr[index][0]) {
                swap_elem(&arr[j][0], &arr[index][0]);
                swap_elem(&arr[j][1], &arr[index][1]);
            } else if (arr[j][0] == arr[index][0]) {
                if (abs(arr[j][1]) > abs(arr[index][1])) {
                    swap_elem(&arr[j][0], &arr[index][0]);
                    swap_elem(&arr[j][1], &arr[index][1]);
                }
            }  else
                break;
        }
    }
}

void swap_elem(int *elem1, int *elem2) {
    int temp;
    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}
