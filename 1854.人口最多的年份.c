/*
 * @lc app=leetcode.cn id=1854 lang=c
 *
 * [1854] 人口最多的年份
 */

// @lc code=start


int maximumPopulation(int** logs, int logsSize, int* logsColSize){

    char mayYear[101];    
    int resultYear = 1950;

    memset(mayYear, 0, (sizeof(char) * 101));

    for (int i = 0; i < logsSize; i++) {

        for (int j = logs[i][0]; j < logs[i][1]; j++)
        {
            mayYear[j - 1950]++;
        }
    }

    for (int i = 0; i < 101; i++) {

        if (mayYear[i] > mayYear[resultYear - 1950]) {
                        
            resultYear = (i + 1950);
        }
    }

    return resultYear;
}


// @lc code=end

