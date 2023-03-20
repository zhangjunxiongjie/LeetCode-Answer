/*
 * @lc app=leetcode.cn id=1523 lang=c
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start


int countOdds(int low, int high){
    
    int resultCounter;

    // if (((low % 2) == 0) && ((high % 2) == 0)) {

    //     resultCounter = ((high - low) / 2);
    // }
    // else if (((low % 2) == 1) && ((high % 2) == 1)) {
        
    //     resultCounter = ((high - low) / 2) + 1;
    // }
    // else if (((low % 2) == 0) && ((high % 2) == 1)) {

    //     resultCounter = ((high - low) / 2) + 1;
    // }
    // else if (((low % 2) == 1) && ((high % 2) == 0)) {

    //     resultCounter = ((high - low) / 2) + 1;
    // }

    if (((low % 2) == 0) && ((high % 2) == 0)) {

        resultCounter = ((high - low) / 2);
    }
    else {
        
        resultCounter = ((high - low) / 2) + 1;
    }
    
    return resultCounter;
}
// @lc code=end

