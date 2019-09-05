/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week07-02-saddle-point.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月30日
*   Description ：
        鞍点（5分）
        题目内容：
        
        给定一个n*n矩阵A。矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第j列上的最小数。一个矩阵A也可能没有鞍点。
        
        你的任务是找出A的鞍点。
        
        输入格式:
        
        输入的第1行是一个正整数n, （1<=n<=100），然后有n行，每一行有n个整数，同一行上两个整数之间有一个或多个空格。
        
        
        
        输出格式：
        
        对输入的矩阵，如果找到鞍点，就输出其下标。下标为两个数字，第一个数字是行号，第二个数字是列号，均从0开始计数。
        
        如果找不到，就输出
        
        NO
        
        题目所给的数据保证了不会出现多个鞍点。
        
        
        
        输入样例：
        
        4 
        
        1 7 4 1 
        
        4 8 3 6 
        
        1 6 1 2 
        
        0 7 8 9
        
        
        
        输出样例：
        
        2 1
        
        
        我的样例：
        1 7 4 11
        4 8 3 60
        1 9 1 8
        0 7 8 29
        输出：
        NO
        
        1 7 4 11
        4 8 3 60
        1 9 1 10
        0 7 8 29
        输出：
        2 3
        
        1 8 3
        4 7 6
        9 9 0
        输出：
        1 1
        
        0 0 0 0
        0 0 0 0
        0 0 0 0
        0 0 0 0
        
        10 10 10 10
        10 10 10 10
        10 10 10 10
        10 10 10 10
        
        以上两个测试点结果都为：
        0 0
        
        
        时间限制：500ms内存限制：32000kb
================================================================*/
#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    if (n >= 1 && n <= 100) {
        int matrix[n][n];

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        /*
        printf("\n=====================\n");
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                printf("%d%c", matrix[i][j], (j == n - 1) ? '\n' : ' ');
            }
        }
        printf("\n=====================\n");
        */

        
        int max_row, max_col, min_row, min_col;
        char flag = 1, find = 0;
        int max[n][2], min[n][2];
        for (int i = 0; i < n; i ++) {
            flag = 1;
            for (int j = 0;j < n; j ++) {
                if (flag) {
                    max_row = i;
                    max_col = j;
                    flag = 0;
                    continue;
                }

                // 比上一次大时，重设游标
                if (matrix[i][j] > matrix[max_row][max_col]) {
                    max_row = i;
                    max_col = j;
                    //printf("row: %d col: %d\n", max_row, max_col);
                    //printf("i: %d j: %d\n", i, j);
                }
            }
            max[i][0] = max_row;
            max[i][1] = max_col;

            //printf("Max: %d MaxRow: %d MaxCol: %d\n", matrix[max_row][max_col],max_row, max_col);

            flag = 1;
            for (int k = 0; k < n; k ++) {
                if (flag) {
                    min_row = k;
                    min_col = i;
                    flag = 0;
                    continue;
                }

                if (matrix[k][i] < matrix[min_row][min_col]) {
                    min_row = k;
                    min_col = i;
                }
            }
            min[i][0] = min_row;
            min[i][1] = min_col;
            //printf("Min: %d MinRow: %d MinCol: %d\n", matrix[min_row][min_col],min_row, min_col);
        }

        //printf("\n%d %d %d %d %d %d\n", row, col, max_row, max_col,min_row, min_col);
     
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (min[j][0] == max[i][0] && min[j][1] == max[i][1] && matrix[min[j][0]][max[i][1]] == matrix[max[i][0]][min[j][1]]) {
                    printf("%d %d", min[j][0], min[j][1]);
                    find = 1;
                    break;
                }
            }

            if (find)
                break;
        }

        if (!find)
            printf("NO");

        // OJ 判题时可能不能用换行符
        // 注释掉即可
        //printf("\n");
    }


    return 0;
}
