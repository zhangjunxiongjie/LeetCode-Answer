/*
 * @lc app=leetcode.cn id=1893 lang=c
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */

// @lc code=start


bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right){
    
    // 差分数组 前缀和大于零时表示当前值存在区间内
    int assistantDiff[52];
    memset(assistantDiff, 0, sizeof(int) * 52);

    // 构造差分数组
    for (int index = 0; index < rangesSize; index++) {

        assistantDiff[ranges[index][0]]++;
        assistantDiff[ranges[index][1] + 1]--;
    }

    int prefixSum = 0;

    // 遍历所有目标区间内的数据判断是否有目标值超出范围
    for (int index = 0; index <= right; index++) {

        prefixSum += assistantDiff[index];

        if ((index <= right) && (index >= left) && (prefixSum <= 0)) {

            return false;
        }
    }

    return true;

    /*
    bool whileFlag = true;
    int lastLeft = left;
    int lastRight = right;

    while (whileFlag) {

        whileFlag = false;
        
        lastLeft = left;
        lastRight = right;

        for (int i = 0; i < rangesSize; i ++) {

            if (left >= ranges[i][0]) {

                if (left <= ranges[i][1]) {
                    
                    if (right <= ranges[i][1]) {
                        
                        return true;
                    }
                    else {
                        left = (ranges[i][1] + 1);
                    }
                }
                else {

                    continue;
                }
            }
            else {

                if (right <= ranges[i][1]) {

                    if (right >= ranges[i][0]) {

                        right = (ranges[i][0] - 1);
                    }
                    else {

                        continue;
                    }
                }
                else {

                    // whileFlag = true;
                    continue;
                }
            } 

            if (left > right) {

                return true;
            }
            else {

                if (lastLeft != left) {

                    whileFlag = true;
                }

                if (lastRight = right) {

                    whileFlag = true;
                }
            }

            // printf ("%d, %d\n", left, right);    
        }
    }

    return false;
    */
}

// @lc code=end

