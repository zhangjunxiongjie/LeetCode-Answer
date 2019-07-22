/*
 * @lc app=leetcode.cn id=74 lang=c
 *
 * [74] 搜索二维矩阵
 */

// 对矩阵数组坐标进行线性映射，然后使用二分查找是一个不错的选择。
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){

    if ( matrixSize == 0 || (*matrixColSize) == 0 )
        return false;

    if(target < matrix[0][0] || target > matrix[matrixSize - 1][(*matrixColSize) - 1])
        return false;
    
    int xmax = (*matrixColSize), ymax = matrixSize;

    // 映射关系：x = port % xmax; y = port / xmax; 
    int left = 0, right = (xmax * ymax) - 1;
    
    while (true)
    {
        // 将搜索下标转化为矩阵数组下标
        int left_x = left % xmax, left_y = left / xmax;
        int right_x = right % xmax, right_y = right / xmax;  

        int middle = (left + right) / 2;

        int middle_x = middle % xmax;
        int middle_y = middle / xmax;

        // 二分查找关键代码
        if (left == right && matrix[left_y][left_x] != target)
        {
            return false;
        }
        else if( abs(left - right) == 1 && matrix[left_y][left_x] != target && matrix[right_y][right_x] != target )
        {
            return false;
        }
        else if(matrix[middle_y][middle_x] == target || matrix[left_y][left_x] == target || matrix[right_y][right_x] == target)
        {
            return true;
        }
        else if(matrix[middle_y][middle_x] < target)
        {
            left = middle;
        }
        else if(matrix[middle_y][middle_x] > target)
        {
            right = middle;
        }
        
    }
    
}



