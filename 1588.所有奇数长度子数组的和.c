/*
 * @lc app=leetcode.cn id=1588 lang=c
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start


int sumOddLengthSubarrays(int* arr, int arrSize){
    
    int resultSum = 0;

    for (int i = 1; i <= arrSize; i += 2) {

        for (int j = 0; j <= (arrSize - i); j++) {
            
            int middleSum = 0;

            for (int z = j; z < (j + i); z++) {

                middleSum += arr[z];
                // printf ("%d, ", arr[z]);
            }

            // printf ("\n");

            resultSum += middleSum;
        }
    }

    return resultSum;
}

// @lc code=end

