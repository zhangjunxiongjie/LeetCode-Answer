/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
        
    if(matrixSize == 0)  // 当行列均为零时matrixSize为零，不能取matrixColSize的值。
    {
        *returnSize = 0;    
        return NULL;
    }
    
    *returnSize = matrixSize * (*matrixColSize);
  
    int* result = malloc(sizeof(int) * (*returnSize));

    // 定义右边界，和下边界
    int right_border = (*matrixColSize) - 1, down_border = matrixSize - 1;   
    
    // 圈数
    int trun_number = 0;

    // 将方向定义为枚举，当前方向为：now_direc，初始方向为右;
    enum directions{right = 1, down = 2, left = 3, up = 4}now_direc = right;

    // 二维数组下标
    int x = 0,y = 0;

    // result下标
    int flag = 0;

    while (flag < ( *returnSize ) )
    {
        // right, 此处可能出现[[1],[2],[3]]这种特殊情况，
        // 即初始方向为右，并且行数为1的情况此时如果进入这个条件语句x值将为1大于right_border - trun_number，超出边界。
        if (now_direc == 1 && x != (right_border - trun_number))   
        {
            result[flag++] = matrix[y][x];
            x++;
            if (x == right_border - trun_number)
            {
                now_direc = 2;
            }
            
        }
        else if(now_direc == 2)  // down
        {
            result[flag++] = matrix[y][x];
            y++;
            if (y == down_border - trun_number)
            {
                now_direc = 3;
            }
        }
        else if (now_direc == 3)  // left
        {
            result[flag++] = matrix[y][x];
            x--;
            if (x == trun_number)
            {
                now_direc = 4;
            }
        }
        else if(now_direc == 4)   // up 确保now_direc不是非法值
        {
            result[flag++] = matrix[y][x];
            y--;
            if (y == trun_number + 1)
            {
                now_direc = 1;
                trun_number = trun_number + 1;
            }
        }
        else
        {
            now_direc = 2;
        }
        
    }
    
    
    return result;
}
