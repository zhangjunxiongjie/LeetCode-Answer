/*
 * @lc app=leetcode.cn id=1720 lang=c
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    
    int *arr = malloc(sizeof(int) * (encodedSize + 1));
    
    arr[0] = first;

    for (int i = 1; i <= encodedSize; i++) {

        arr[i] = encoded[i - 1] ^ arr[i - 1];
    }

    (*returnSize) = (encodedSize + 1);

    return arr;
}

// @lc code=end

