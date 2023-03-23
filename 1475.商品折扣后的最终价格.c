/*
 * @lc app=leetcode.cn id=1475 lang=c
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize){
    
    int *resultVector = malloc(sizeof(int) * pricesSize);
    (*returnSize) = pricesSize;

    for (int i = 0; i < pricesSize; i++) {

        int j = (i + 1);
        for (; j < pricesSize; j++) {

            if (prices[i] >= prices[j]) {

                resultVector[i] = (prices[i] - prices[j]);
                break;
            }
        }

        if (j >= pricesSize) {

            resultVector[i] = prices[i];
        }        
    }


    return resultVector;
}


// @lc code=end

