/*
 * @lc app=leetcode.cn id=1342 lang=c
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start


int numberOfSteps(int num){
    
    int resultCounter = 0;

    while (num > 0) {

        if ((num % 2) == 0) {
            
            num /= 2;
            resultCounter++;
        }
        else {

            num -= 1;
            resultCounter++;
        }

    }

    return resultCounter;
}



// @lc code=end

