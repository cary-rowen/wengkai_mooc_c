/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week07-02-find_point.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月19日
*   Description ：
================================================================*/
#include <stdio.h>

int main() {

    short int n;
    scanf("%d", &n);

    if (n >= 1 && n <= 100) {
        int matrix[n][n];

        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;

        for (int i = 0; i < n; i++) {
            getchar();
            for (int j = 0; j < n; j++) {
                char c = getchar();

            }
        }

        printf("\n==========\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
    }

    return 0;
}

