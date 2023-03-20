/*
 * @lc app=leetcode.cn id=1317 lang=c
 *
 * [1317] 将整数转换为两个无零整数的和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool judge_zero_function(int x)
{

    do {

        if (((x % 10) == 0)) {

            return false;
        }
        else {

            x = (x / 10);
        }

    } while (x);

    return true;
}

int* getNoZeroIntegers(int n, int* returnSize){
    
    int result1 = 0, result2 = n;
    int *resultVector = malloc(sizeof(int) * 2);

    while (1) {

        if (judge_zero_function(result1) && judge_zero_function(result2)) {

            resultVector[0] = result1;
            resultVector[1] = result2;

            (*returnSize) = 2;
            break;
        }

        result1++;
        result2--;
        if (result1 > result2) {
            
            (*returnSize) = 0;            
            break;
        }
    }    
    
    return resultVector;
}



// @lc code=end

