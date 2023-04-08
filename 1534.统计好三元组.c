/*
 * @lc app=leetcode.cn id=1534 lang=c
 *
 * [1534] 统计好三元组
 */

// @lc code=start


int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){

    int resultCounter = 0;

    for (int i = 0; i < arrSize; i++) {

        for (int j = (i + 1); j < arrSize; j++) {

            if ((abs(arr[i] - arr[j]) <= a)) {

                for (int z = (j + 1); z < arrSize; z++) {

                    if ((abs(arr[j] - arr[z]) <= b) &&
                        (abs(arr[i] - arr[z]) <= c)
                        ) {

                        resultCounter ++;
                    }
                }
            }            
        }
    }

    return resultCounter;
}

// @lc code=end

