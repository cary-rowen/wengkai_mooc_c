/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week08-02-gps-data-handle.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月29日
*   Description ：
                GPS数据处理（6分）
                题目内容：
                
                NMEA-0183协议是为了在不同的GPS（全球定位系统）导航设备中建立统一的BTCM（海事无线电技术委员会）标准，由美国国家海洋电子协会（NMEA-The National Marine Electronics Associa-tion）制定的一套通讯协议。GPS接收机根据NMEA-0183协议的标准规范，将位置、速度等信息通过串口传送到PC机、PDA等设备。
                
                
                
                NMEA-0183协议是GPS接收机应当遵守的标准协议，也是目前GPS接收机上使用最广泛的协议，大多数常见的GPS接收机、GPS数据处理软件、导航软件都遵守或者至少兼容这个协议。
                
                
                
                NMEA-0183协议定义的语句非常多，但是常用的或者说兼容性最广的语句只有$GPGGA、$GPGSA、$GPGSV、$GPRMC、$GPVTG、$GPGLL等。
                
                
                
                其中$GPRMC语句的格式如下：
                
                    $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
                
                
                
                这里整条语句是一个文本行，行中以逗号“,”隔开各个字段，每个字段的大小（长度）不一，这里的示例只是一种可能，并不能认为字段的大小就如上述例句一样。
                
                    字段0：$GPRMC，语句ID，表明该语句为Recommended Minimum Specific GPS/TRANSIT Data（RMC）推荐最小定位信息
                
                    字段1：UTC时间，hhmmss.sss格式
                
                    字段2：状态，A=定位，V=未定位
                
                    字段3：纬度ddmm.mmmm，度分格式（前导位数不足则补0）
                
                    字段4：纬度N（北纬）或S（南纬）
                
                    字段5：经度dddmm.mmmm，度分格式（前导位数不足则补0）
                
                    字段6：经度E（东经）或W（西经）
                
                    字段7：速度，节，Knots
                
                    字段8：方位角，度
                
                    字段9：UTC日期，DDMMYY格式
                
                    字段10：磁偏角，（000 - 180）度（前导位数不足则补0）
                
                    字段11：磁偏角方向，E=东W=西
                
                    字段16：校验值
                
                这里，“*”为校验和识别符，其后面的两位数为校验和，代表了“$”和“*”之间所有字符（不包括这两个字符）的异或值的十六进制值。上面这条例句的校验和是十六进制的50，也就是十进制的80。
                
                
                
                提示：^运算符的作用是异或。将$和*之间所有的字符做^运算(第一个字符和第二个字符异或，结果再和第三个字符异或，依此类推)之后的值对65536取余后的结果，应该和*后面的两个十六进制数字的值相等，否则的话说明这条语句在传输中发生了错误。注意这个十六进制值中是会出现A-F的大写字母的。
                
                
                
                现在，你的程序要读入一系列GPS输出，其中包含$GPRMC，也包含其他语句。在数据的最后，有一行单独的
                
                    END
                
                表示数据的结束。
                
                
                
                你的程序要从中找出$GPRMC语句，计算校验和，找出其中校验正确，并且字段2表示已定位的语句，从中计算出时间，换算成北京时间。一次数据中会包含多条$GPRMC语句，以最后一条语句得到的北京时间作为结果输出。
                
                你的程序一定会读到一条有效的$GPRMC语句。
                
                
                
                输入格式:
                
                多条GPS语句，每条均以回车换行结束。最后一行是END三个大写字母。
                
                
                
                输出格式：
                
                6位数时间，表达为：
                
                    hh:mm:ss
                
                其中，hh是两位数的小时，不足两位时前面补0；mm是两位数的分钟，不足两位时前面补0；ss是两位数的秒，不足两位时前面补0。
                
                
                
                输入样例：
                
                $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
                
                END
                
                我的样例：
                校验正确：
                $GPRMC,224813.620,A,3158.8108,N,11848.3737,E,10.05,324.27,150706,,,A*5F
                $GPRMC,094813.650,A,3151.4808,N,11848.3737,E,10.05,324.27,150706,,,A*5D
                $GPRMC,124813.680,A,3158.1608,N,11848.3737,E,10.05,324.27,150706,,,A*58
                $GPRMC,104813.040,A,3158.4621,N,11848.3737,E,10.05,324.27,150706,,,A*5E
                $GPRMC,234813.640,A,3158.4088,N,11848.3737,E,10.05,324.27,150706,,,A*5D

                校验失败：
                $GPRMC,134813.680,A,3158.1608,N,11841.3737,E,10.05,324.27,150706,,,A*1A
                $GPRMC,112813.040,A,3158.4621,N,11848.3737,E,10.05,324.27,150706,,,A*8F
                $GPRMC,115013.640,A,3158.4088,N,11848.3737,E,10.05,324.27,150706,,,A*6b
                $ACOMC,102033.640,A,3950.4888,N,11848.3787,E,10.05,324.27,150706,,,A*5A

                
                输出样例：
                
                10:48:13
                
                时间限制：500ms内存限制：32000kb
================================================================*/
#include <stdio.h>

void utc_to_cntime(char* utc_time) {
    if (utc_time[0] == '1') {
        if (utc_time[1] >= '6') {
            utc_time[0] = '0';
            utc_time[1] = utc_time[1] - '0' + 8 - 14 + '0';
        } else if (utc_time[1] >= '2') {
            utc_time[0] = '2';
            utc_time[1] = utc_time[1] - '0' + 8 - 10 + '0';
        } else {
            utc_time[1] = utc_time[1] - '0' + 8 + '0';
        }
    } else if (utc_time[0] == '0') {
        if (utc_time[1] >= '2') {
            utc_time[0] = '1';
            utc_time[1] = utc_time[1] - '0' + 8 - 10 + '0';
        } else {
            utc_time[1] = utc_time[1] - '0' + 8 + '0';
        }
    } else if (utc_time[0] == '2') {
        utc_time[0] = '0';
        utc_time[1] = 8 - (24 - (20 + (utc_time[1] - '0'))) + '0';

    }
}


int main() {

    //char utc_time2[] = "100201";
    //printf("%s\n", utc_time2);
    //utc_to_cntime(utc_time2);
    //printf("%s\n", utc_time2);

    //return 0;

    int c = '\0', valid_hex = 0, xor_valid = 0;
    unsigned int comma = 0;
    char temp_time[7], utc_time[7];
    unsigned char is_location = 0, is_gprmc = 0;

    c = getchar();
    while (c != EOF) {
        if (c == '\n') {
            c = getchar();
            if (c == 'E') {
                c = getchar();
                if (c == 'N') {
                    c = getchar();
                    if (c == 'D') {
                        break;
                    }
                }
            } 
            valid_hex = 0;
            comma = 0;
            xor_valid = 0;
            is_location = 0;
            is_gprmc = 0;
        }

        if (c == '$') {
            c = getchar();
            xor_valid ^= c; 
            // GPRMC
            if (c == 'G') {
                c = getchar();
                xor_valid ^= c; 
                if (c == 'P') {
                    c = getchar();
                    xor_valid ^= c; 
                    if (c == 'R') {
                        c = getchar();
                        xor_valid ^= c; 
                        if (c == 'M') {
                            c = getchar();
                            xor_valid ^= c; 
                            if (c == 'C') {
                                is_gprmc = 1;
                            }
                        }
                    }
                }
            }
            c = getchar();
            continue;
        }


        if (c == ',') {
            comma ++;

            xor_valid ^= c;

            if (comma == 1) {
                int i = 0;
                while (i <= 5) {
                    c = getchar();
                    //printf("%c\n", c);
                    xor_valid ^= c;
                    temp_time[i++] = c;
                }

                temp_time[i] = '\0';
            }

            if (comma == 2) {
                c = getchar();
                xor_valid ^= c;
                if (c == 'A')
                    is_location = 1;
            }
            c = getchar();
            continue;
        }

        if (c == '*') {
            c = getchar();
            while (c != '\n') {
                if (c >= 'a' && c <= 'f')
                    valid_hex = 16 * valid_hex + c - 'a' + 10;
                else if (c >= 'A' && c <= 'F')
                    valid_hex = 16 * valid_hex + c - 'A' + 10;
                else if (c >= '0' && c <= '9')
                    valid_hex = 16 * valid_hex + c - '0';
                
                c = getchar();
            }

            //printf("%d\n", valid_hex);
            //printf("%d\n", xor_valid % 65536);
            //break;
            if (valid_hex == xor_valid && is_location && is_gprmc) {
                int i = 0;
                for ( ; i < 6; i ++)
                    utc_time[i] = temp_time[i];
                utc_time[i] = '\0';
            }
            continue;
        }

        xor_valid ^= c;

        c = getchar();
    }

    utc_to_cntime(utc_time);
    printf("%s\n", utc_time);

    return 0;
}

