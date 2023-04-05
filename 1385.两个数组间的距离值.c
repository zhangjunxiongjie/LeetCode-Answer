/*
 * @lc app=leetcode.cn id=1385 lang=c
 *
 * [1385] 两个数组间的距离值
 */

// @lc code=start


int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d){
    
    int resultCounter = 0;

    for (int *arr1Pointer = arr1; arr1Pointer < (arr1 + arr1Size); arr1Pointer++) {
        
        bool flag = true;

        for (int *arr2Pointer = arr2; arr2Pointer < (arr2 + arr2Size); arr2Pointer++) {
            
            // printf ("%d, %d, %d\n", arr1[i], arr2[j], abs(arr1[i] - arr2[j]));

            if (abs((*arr1Pointer) - (*arr2Pointer)) <= d) {
                
                flag = false;   
                break;             
            }
        }

        if (flag) {

            resultCounter++;
        }
    }

    return resultCounter;
}


// @lc code=end

