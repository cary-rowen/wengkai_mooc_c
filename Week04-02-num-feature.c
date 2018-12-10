/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week04-02-num-feature.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月10日
*   Description ：
            数字特征值（5分）
            题目内容：
            
            对数字求特征值是常用的编码算法，奇偶特征是一种简单的特征值。对于一个整数，从个位开始对每一位数字编号，个位是1号，十位是2号，以此类推。这个整数在第n位上的数字记作x，如果x和n的奇偶性相同，则记下一个1，否则记下一个0。按照整数的顺序把对应位的表示奇偶性的0和1都记录下来，就形成了一个二进制数字。比如，对于342315，这个二进制数字就是001101。
            
            
            这里的计算可以用下面的表格来表示：
            
            你的程序要读入一个非负整数，整数的范围是[0,1000000]，然后按照上述算法计算出表示奇偶性的那个二进制数字，输出它对应的十进制值。
            
            
            
            提示：将整数从右向左分解，数位每次加1，而二进制值每次乘2。
            
            
            
            输入格式:
            
            一个非负整数，整数的范围是[0,1000000]。
            
            
            
            输出格式：
            
            一个整数，表示计算结果。
            
            
            
            输入样例：
            
            342315
            
            
            
            输出样例：
            
            13

================================================================*/
#include <stdio.h>

int main() {

    int input = 0;

    scanf("%d", &input);

    if (input >= 0 && input <= 1000000) {

        int n = 1, x = 1, binary = 0;
        
        while (x) {
            x = 0;
            int ten = 1;
            for (int i = n; i > 1; i--) {
                ten *= 10; 
            } 

            x = input / ten % 10;

            if (x > 0) {
                if (((!(x % 2)) && (!(n % 2))) || ((x % 2) && (n % 2)))  {
                    binary += ten;
                }
            }

            n ++;
        }
    
        //printf("%d", binary);
        int result = 0, cnt = 0, current = 0, ten = 1;

        while (binary >= 1) {
            current = binary % 10;

            //printf("%d ", current);
            int tmp = 1;
            for (int i = cnt; i > 0; i--)
                tmp *= 2;

            result += current * tmp;


            binary = (binary - current) / 10; 

            cnt ++;
        }

        printf("%d", result);
    }

    return 0;
}


