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
            int is_num = 0;
            int cnt_space = 0;
            for (int j = 0; j < n; j++) {
                int c = getchar();

                if (c == ' ')
                    cnt_space ++;


                /*
                 *
                 * 4
32 43 45 234
34 4 6 33 23
0 9 3 8
32 9 2 34 543

32 43 45 2
34 34 4 6
33 23 0 9
3 8 32 9

                 *
                 */

                if (is_num && (c - '0' >= 0 && c - '0' < 10)) {
                    j --;
                    matrix[i][j] = matrix[i][j] * 10 + (c - '0' + 0);
                    continue;
                }

                if (c == ' ' || c == '\n') {
                    j --;
                    cnt_space ++;
                    is_num = 0;
                    continue;;
                }

                is_num = 1;;

                matrix[i][j] = c - '0' + 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
    }

    return 0;
}

