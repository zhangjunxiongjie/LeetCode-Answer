/*
 * @lc app=leetcode.cn id=1502 lang=c
 *
 * [1502] 判断能否形成等差数列
 */

// @lc code=start


bool canMakeArithmeticProgression(int* arr, int arrSize){

    int difference = 0;
    
    for (int i = 0; i < arrSize; i++) {
        
        int switchIndex = i;
        for (int j = (i+1); j < arrSize; j++) {

            if (arr[j] < arr[switchIndex]) {

                switchIndex = j;
            }
        }

        if (switchIndex != i) {

            int middle = arr[switchIndex];
            arr[switchIndex] = arr[i];
            arr[i] = middle;
        }

        if (i == 1) {

            difference = (arr[1] - arr[0]);
            // printf ("%d\n", difference);
        }
        else if (i > 1) {

            if (abs(arr[i] - arr[i - 1]) != difference) {
                // printf ("%d, %d, %d, %d\n", difference, arr[i], arr[i - 1], i);

                // for (int i = 0; i < arrSize; i++) {

                //     printf ("%d, %d;", i, arr[i]);
                // }

                return false;            
            }
        }           
    }

    return true;
}

// @lc code=end

