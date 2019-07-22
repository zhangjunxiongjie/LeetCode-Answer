/*
 * @lc app=leetcode.cn id=73 lang=c
 *
 * [73] 矩阵置零
 */

// 第三版，继续优化空间复杂度
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    
    bool xstate = false, ystate = false;
    
    // 记录第一行第一列的状态
    for (int i = 0; i < (matrixSize > (*matrixColSize) ? matrixSize : (*matrixColSize)); i++) 
    {  
        if(i < matrixSize && matrix[i][0] == 0)
            ystate = true;
        if(i < (*matrixColSize) && matrix[0][i] == 0)
            xstate = true;
        if (xstate && ystate)
            break;
    }    

    // 判断除第一行第一列外的其他行其他列的状态并记录在第一行第一列
    for (int i = 1; i < matrixSize; i++)  
    {
        for (int j = 1; j < (*matrixColSize); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // 根据第一行第一列存储的状态对除第一行第一列的每一行和每一列进行设置
    // 要注意的是这里外层循环是从第二行第二列开始而不是从第一行第一列
    // 原因在于第一行第一列存储着其余每行每列的状态信息，如果这里对其进行设置了
    // 将会覆盖掉矩阵设置所需的状态信息，将导致所有行所有列全为零的情况
    // (通常情况，如果原矩阵有哪怕一个数为零都会导致这样的结果）
    for (int i = 1; i <  (matrixSize > (*matrixColSize) ? matrixSize : (*matrixColSize)); i++) 
    {  
        if(i < matrixSize && matrix[i][0] == 0)
        {
            for (int j = 1; j < (*matrixColSize); j++)
            {
                matrix[i][j] = 0;
            }
            
        }
        if(i < (*matrixColSize) && matrix[0][i] == 0)
        {
            for (int j = 1; j < matrixSize; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    
    // 对第一行第一列进行设置
    if(xstate)
        for(int i = 0; i < (*matrixColSize); i++)
            matrix[0][i] = 0;

    if(ystate)
        for(int i = 0; i < matrixSize; i++)
            matrix[i][0] = 0;
    
} 





/*
// 第二版，空间复杂度为常数。思路：先判断第一行第一列是否存在零
// 存在的话第一行或第一列就全为零记录下两个状态
// 然后遍历除第一行第一列外的其他行和列将每行的状态存储至第一行，
// 每一列的状态存储至第一列。
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){

    int xmax = (*matrixColSize), ymax = (matrixSize);
    int xymax = ymax > xmax ? ymax : xmax;
    
    bool xstate = false, ystate = false;
    
    // 记录第一行第一列的状态
    for (int i = 0; i < xymax; i++) 
    {  
        if(i < ymax && matrix[i][0] == 0)
            ystate = true;
        if(i < xmax && matrix[0][i] == 0)
            xstate = true;
        if (xstate && ystate)
            break;
    }    

    // 判断除第一行第一列外的其他行其他列的状态并记录在第一行第一列
    for (int i = 1; i < ymax; i++)  
    {
        for (int j = 1; j < xmax; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // 根据第一行第一列存储的状态对除第一行第一列的每一行和每一列进行设置
    // 要注意的是这里外层循环是从第二行第二列开始而不是从第一行第一列
    // 原因在于第一行第一列存储着其余每行每列的状态信息，如果这里对其进行设置了
    // 将会覆盖掉矩阵设置所需的状态信息，将导致所有行所有列全为零的情况
    // (通常情况，如果原矩阵有哪怕一个数为零都会导致这样的结果）
    for (int i = 1; i <  xymax; i++) 
    {  
        if(i < ymax && matrix[i][0] == 0)
        {
            for (int j = 1; j < xmax; j++)
            {
                matrix[i][j] = 0;
            }
            
        }
        if(i < xmax && matrix[0][i] == 0)
        {
            for (int j = 1; j < ymax; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    
    // 对第一行第一列进行设置
    if(xstate)
        for(int i = 0; i < xmax; i++)
            matrix[0][i] = 0;

    if(ystate)
        for(int i = 0; i < ymax; i++)
            matrix[i][0] = 0;
    
} 
*/


/* 
// 第一版，n + m 的空间复杂度
void empty(int** target, int* result, int ymax, int xmax)
{
    for(int i = 0; i < ymax; i++)
    {
        for (int j = 0; j < xmax; j++)
        {
            if (result[i + xmax] || result[j])
            {
                target[i][j] = 0;
            }
        }
    }
}


void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int sum = matrixSize + (*matrixColSize);

    int xy[sum];  // 映射
    
    for (int i = 0; i < sum; i++)
    {
        xy[i] = 0;
    }
    
    for (int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < (*matrixColSize); j++)
        {
            if (matrix[i][j] == 0)
            {
                xy[i + (*matrixColSize)] = 1;
                xy[j] = 1;
            }
        }
    }
    
    empty(matrix, xy, matrixSize, (*matrixColSize));

}
*/


