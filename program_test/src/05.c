/******************************************************************************
 *     Copyright:  (C) 2023 shachi <shachi1758@outlook.com>
 *                  All rights reserved.
 *
 *      Filename:  ./src/05.c
 *   Description:  输入一个百分制的成绩M，将其转换成对应的等级
 *
 *       Version:  0.1.0
 *        Author:  shachi <shachi1758@outlook.com>
 *     ChangeLog:  1. 2023-03-13 15:44:21 创建文件
 *
 ******************************************************************************/

char get_grade(float score)
{
    switch ((int)score / 10) {
    case 10:
    case 9:
        return 'A';
    case 8:
        return 'B';
    case 7:
        return 'C';
    case 6:
        return 'D';
    case 5:
        return 'E';
    default:
        break;
    }
    return 'F';
}