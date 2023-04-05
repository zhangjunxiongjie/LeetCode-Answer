/*
 * @lc app=leetcode.cn id=762 lang=c
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start

const int assistantVector[33] = {

    0, 0, 2, 3, 0, 5, 0, 7, 
    0, 0, 0, 11, 0, 13, 0, 0, 
    0, 17, 0, 19, 0, 0, 0, 23, 
    0, 0, 0, 0, 0, 29, 0, 31, 
    0
};

int setBitCounter(int target)
{  
    int resultCounter = 0;
    /*
    for (int i = 0; i < 32; i++) {
        
        if ((target >> i) & 1) {
            
            resultCounter++;
        }
    }
    */
    // printf ("%d: %d\n", target, resultCounter);
    
    while (target) {

        if ((target % 2) != 0) {

            resultCounter++;
        }

        target /= 2;
    }

    return resultCounter;
}

int countPrimeSetBits(int left, int right){

    int resultCounter = 0;
    
    for (; left <= right; left++) {

        if (assistantVector[setBitCounter(left)]) {
            
            resultCounter++;
        }
    }
    

    // return setBitCounter(9);

    return resultCounter;
}
// @lc code=end

