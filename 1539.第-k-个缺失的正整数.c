/*
 * @lc app=leetcode.cn id=1539 lang=c
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
int findKthPositive(int* arr, int arrSize, int k){

    int counter = 0;
    int resultTarget = 0;

    for (int i = 1, arrIndex = 0; counter < k; i++) {

        if ((arrIndex < arrSize) && (arr[arrIndex] == i)) {
            
            arrIndex++;
        }
        else {
            resultTarget = i;
            counter++;            
        }
    }

    return resultTarget;
}

// @lc code=end

