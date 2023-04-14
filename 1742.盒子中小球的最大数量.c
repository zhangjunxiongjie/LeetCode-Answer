/*
 * @lc app=leetcode.cn id=1742 lang=c
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start


int countBalls(int lowLimit, int highLimit){

    int resultNumber = 0;
    int sumMaximum[46];

    memset (sumMaximum, 0, (sizeof(int) * 46));

    for (int i = lowLimit; i <= highLimit; i++) {
        
        int middle = i;
        int sum = 0;
        while (middle) {
            
            sum += (middle % 10);
            middle = (middle / 10);
        }

        sumMaximum[sum]++;
        if (sumMaximum[sum] > resultNumber) {

            resultNumber = sumMaximum[sum];
        }
    }

    return resultNumber;
}

// @lc code=end

