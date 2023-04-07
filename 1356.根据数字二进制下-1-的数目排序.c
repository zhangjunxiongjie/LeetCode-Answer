/*
 * @lc app=leetcode.cn id=1356 lang=c
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){

    int *arrAssistant = malloc(sizeof(int) * arrSize);

    for (int *arrPointer = arr, *arrAssistantPointer = arrAssistant; arrPointer < (arr + arrSize); arrPointer++, arrAssistantPointer++) {

        int middle = (*arrPointer);
        int middleCounter = 0;
        while (middle) {

            if (middle & 1) {
                middleCounter++;
            }
            middle >>= 1;
        }

        (*arrAssistantPointer) = middleCounter;
        // printf ("%d, ", (*arrAssistantPointer));
    }

    for (int i = 0; i < arrSize; i++) {

        int target = i;
        for (int j = (target + 1); j < arrSize; j++) {

            if (arrAssistant[target] > arrAssistant[j]) {

                target = j;
            }
            else if ((arrAssistant[target] == arrAssistant[j]) && (arr[target] > arr[j])) {

                target = j;
            }
        }

        if (target != i) {

            arr[target] ^= arr[i];
            arr[i] ^= arr[target];
            arr[target] ^= arr[i];

            arrAssistant[target] ^= arrAssistant[i];
            arrAssistant[i] ^= arrAssistant[target];
            arrAssistant[target] ^= arrAssistant[i];
        }
    }
    
    free(arrAssistant);

    (*returnSize) = arrSize;
    return arr;
}

// @lc code=end

