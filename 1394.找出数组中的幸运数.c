/*
 * @lc app=leetcode.cn id=1394 lang=c
 *
 * [1394] 找出数组中的幸运数
 */

// @lc code=start


int findLucky(int* arr, int arrSize){
    
    int assistantVector[501];
    int resultNumber = -1;

    memset(assistantVector, 0, (sizeof(int) * 501));

    for (int i = 0; i < arrSize; i++) {

        assistantVector[arr[i]]++;
    }

    for (int i = 500; i > 0; i--) {

        if (i == assistantVector[i]) {

            resultNumber = i;
            break;
        }
    }

    return resultNumber;
}

// @lc code=end

