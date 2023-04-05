/*
 * @lc app=leetcode.cn id=1399 lang=c
 *
 * [1399] 统计最大组的数目
 */

// @lc code=start


int countLargestGroup(int n){

    int assistantVector[37];
    int maximumCounter = 0;
    int resultCounter = 0;

    memset(assistantVector, 0, (sizeof(int) * 37));

    for (int i = 1; i <= n; i++) {
        
        int sum = 0;
        int middle = i;
        while (0 != middle) {

            sum += (middle % 10);
            middle /= 10;
        }

        assistantVector[sum]++;
        if (maximumCounter < assistantVector[sum]) {
            
            maximumCounter = assistantVector[sum];
        }

    }

    for (int i = 0; i < 37; i++) {

        if (assistantVector[i] == maximumCounter) {
            
            resultCounter++;
        }
    }

    return resultCounter;
}

// @lc code=end

