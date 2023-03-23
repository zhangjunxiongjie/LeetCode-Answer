/*
 * @lc app=leetcode.cn id=1518 lang=c
 *
 * [1518] 换水问题
 */

// @lc code=start


int numWaterBottles(int numBottles, int numExchange){

    int resultReturn = numBottles;

    while (numBottles >= numExchange) {

        resultReturn += (numBottles / numExchange);

        numBottles = (numBottles % numExchange) + (numBottles / numExchange);
    }

    return resultReturn;
}

// @lc code=end

