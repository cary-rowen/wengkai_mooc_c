/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week05-01-sum.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月11日
*   Description ：
*               素数和（5分）
                题目内容：
                
                我们认为2是第一个素数，3是第二个素数，5是第三个素数，依次类推。
                
                现在，给定两个整数n和m，0<n<=m<=200，你的程序要计算第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。
                
                
                
                输入格式:
                
                两个整数，第一个表示n，第二个表示m。
                
                
                
                输出格式：
                
                一个整数，表示第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。
                
                
                
                输入样例：
                
                2 4
                
                
                
                输出样例：
                
                15
                
                时间限制：500ms内存限制：32000kb

================================================================*/
#include <stdio.h>

int main() {

    int sum = 0, n, m;
    scanf("%d %d", &n, &m);

    if (n > 0 && m > 0 && m <= 200 && n <= 200 && n <= m) {
        int num = 2;
        int outer_switchy = 1;
        int cnt = 0;

        while (outer_switchy) {

            int is_not_prime = 0;
            for (int i = 2; i <= (num / 2); i ++)  {
                if (!(num % i) && (i != num)) {
                    is_not_prime = 1;
                    break;
                }
            }

            if (!is_not_prime) {
                cnt ++;
                if (cnt >= n && cnt <= m) {

                    sum += num;
                    //printf("%d ", num);
                }


                if (cnt == m)
                    outer_switchy = 0;
            }

            num ++;
        }

        printf("%d", sum);
    }

    return 0;
}

