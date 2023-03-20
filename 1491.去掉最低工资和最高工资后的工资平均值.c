/*
 * @lc app=leetcode.cn id=1491 lang=c
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start


double average(int* salary, int salarySize){
    unsigned int minimum = 1000000;
    unsigned int maximum = 1000;
    unsigned int sum = 0;

    for (int i = 0; i < salarySize; i++) {

        sum += salary[i];

        if (salary[i] > maximum) {
            maximum = salary[i];
        }

        if (salary[i] < minimum) {
            minimum = salary[i];
        }
    }

    sum -= maximum;
    sum -= minimum;

    return (double)((double)sum / (double)(salarySize - 2));

}

// @lc code=end

