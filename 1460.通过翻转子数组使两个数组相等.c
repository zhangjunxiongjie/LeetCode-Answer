/*
 * @lc app=leetcode.cn id=1460 lang=c
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
bool canBeEqual(int* target, int targetSize, int* arr, int arrSize){
    
    bool resultBool = true;

    for (int i = 0; i < targetSize; i++) {

        int targetIndex = i;
        int arrIndex = i;
        for (int j = (i + 1); j < targetSize; j++) {

            if (target[targetIndex] > target[j]) {

                targetIndex = j;
            }

            if (arr[arrIndex] > arr[j]) {
                
                arrIndex = j;
            }
        }

        if (targetIndex != i) {

            target[targetIndex] ^= target[i];
            target[i] ^= target[targetIndex];
            target[targetIndex] ^= target[i];
        }

        if (arrIndex != i) {

            arr[arrIndex] ^= arr[i];
            arr[i] ^= arr[arrIndex];
            arr[arrIndex] ^= arr[i];
        }

        if (arr[i] != target[i]) {

            resultBool = false;
            break;
        }
    }

    return resultBool;
}

// @lc code=end

