/*
 * @lc app=leetcode.cn id=2427 lang=c
 *
 * [2427] 公因子的数目
 */

// @lc code=start


int commonFactors(int a, int b){
    
    int resultCounter = 0;

    if (a < b) {

        for (int i = a; i > 0; i--) {

            if (((b % i) == 0) && ((a % i) == 0)) {
                
                resultCounter++;
            }
        }
    }
    else {

        for (int i = b; i > 0; i--) {

            if (((a % i) == 0) && ((b % i) == 0)) {
                
                resultCounter++;
            }
        }
    }

    return resultCounter;
}

// @lc code=end

