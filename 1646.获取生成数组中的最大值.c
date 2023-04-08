/*
 * @lc app=leetcode.cn id=1646 lang=c
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start


int getMaximumGenerated(int n){
    
    int assistantBuf[101];
    int resultMaximum = 1;
    memset(assistantBuf, 0, (sizeof(int) * n));
    
    if (n == 0) {

        return 0;
    }

    assistantBuf[0] = 0;
    assistantBuf[1] = 1;

    for (int i = 0; i < (n / 2 + 1); i++) {

        assistantBuf[i * 2] = assistantBuf[i];

        if (assistantBuf[(i * 2)] > resultMaximum) {

            resultMaximum = assistantBuf[((i * 2) + 1)];
        }

        if (((i * 2) + 1) <= n) {

            assistantBuf[((i * 2) + 1)] = assistantBuf[i] + assistantBuf[i + 1];

            if (assistantBuf[((i * 2) + 1)] > resultMaximum) {

                resultMaximum = assistantBuf[((i * 2) + 1)];
            }
        }        
        
    }

    return resultMaximum;
}

// @lc code=end

