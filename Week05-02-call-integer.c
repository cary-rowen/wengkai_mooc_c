/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week05-02-call-integer.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月11日
*   Description ：
            念整数（5分）
            题目内容：
            
            你的程序要读入一个整数，范围是[-100000,100000]。然后，用汉语拼音将这个整数的每一位输出出来。
            
            如输入1234，则输出：
            
            yi er san si
            
            注意，每个字的拼音之间有一个空格，但是最后的字后面没有空格。当遇到负数时，在输出的开头加上“fu”，如-2341输出为：
            
            fu er san si yi
            
            
            
            输入格式:
            
            一个整数，范围是[-100000,100000]。
            
            
            
            输出格式：
            
            表示这个整数的每一位数字的汉语拼音，每一位数字的拼音之间以空格分隔，末尾没有空格。
            
            
            
            输入样例：
            
            -30
            
            
            
            输出样例：
            
            fu san ling
            
            时间限制：500ms内存限制：32000kb

================================================================*/
#include <stdio.h>

/*
            if (num == 0)
                printf("ling");
            else if(num == 1)
                printf("yi");
            else if (num == 2)
                printf("er");
            else if (num == 3)
                printf("san");
            else if (num == 4)
                printf("si");
            else if (num == 5)
                printf("wu");
            else if (num == 6)
                printf("liu");
            else if (num == 7)
                printf("qi");
            else if (num == 8)
                printf("ba");
            else
                printf("jiu");
*/


int main() {
    
    int input;
    scanf("%d", &input);
    unsigned char is_first = 1;

    if (input >= -100000 && input <= 100000) {

        if (!input) {
            printf("ling");
            return 0;
        }

        if (input < 0) {
            printf("fu ");
            input = -1 * input;
        }

        while (input >= 1) {

            int ten = 1;
            int num = 0;
            int tmp = 0;
            while (1) {
                num = tmp; // 0 30 3
                tmp = input / ten; // 30 3 0
                if (tmp >= 1)
                    ten *= 10; // 10 100
                else
                    break;
            }


            if (!is_first)
                printf(" ");

            //printf("%d ", num);

            if (num == 0)
                printf("ling");
            else if(num == 1)
                printf("yi");
            else if (num == 2)
                printf("er");
            else if (num == 3)
                printf("san");
            else if (num == 4)
                printf("si");
            else if (num == 5)
                printf("wu");
            else if (num == 6)
                printf("liu");
            else if (num == 7)
                printf("qi");
            else if (num == 8)
                printf("ba");
            else
                printf("jiu");

            input = input - num * ten / 10;


            if (input == 0) {
                if (num * ten / 10 >= 10) {
                    ten /= 10;
                    while (ten >= 10) {
                        printf(" ");
                        ten /= 10;
                        printf("ling");
                    }
                } 
            }

            is_first = 0;
        }

    }

    return 0;
}

