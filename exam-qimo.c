/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：exam-qimo.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月29日
*   Description ：
================================================================*/
#include <stdio.h>

int main() {

    int a, b;
    scanf("%d/%d", &a, &b);

    if (a > 0 && b > 0) {
        int max;

        if (a > b) {
            max = b / 2;
            if (a % b == 0) {
                printf("%d/%d", a / b, 1);
                return 0;
            }
        } else if (a < b) {
            max = a / 2;
            if (b % a == 0) {
                printf("%d/%d", 1, b / a);
                return 0;
            }
        } else {
            printf("%d/%d", 1, 1);
            return 0;
        }

        for (int i = 2; i < max; i ++) {
            if ((a % i == 0) && (b % i == 0)) {
                a /= i;
                b /= i;
            }
        }

        

        printf("%d/%d", a, b);

    }
    return 0;
}

