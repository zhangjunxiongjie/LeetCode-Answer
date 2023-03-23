/*
 * @lc app=leetcode.cn id=1287 lang=c
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

// @lc code=start


int findSpecialInteger(int* arr, int arrSize){

    int index0 = 0;
    int index1 = (arrSize / 4);
    int index2 = ((arrSize * 2) / 4);
    int index3 = ((arrSize * 3) / 4);
    int index4 = (arrSize - 1);

    if (arr[index0] == arr[index1]) {

        return arr[index0];
    }
    else if (arr[index1] == arr[index2]) {

        return arr[index1];
    }
    else if (arr[index2] == arr[index3]) {

        return arr[index2];
    }
    else if (arr[index3] == arr[index4]) {

        return arr[index3];
    }
    else {
        
        int left = index1, right = index1;

        while ((arr[left] == arr[index1]) ||
                (arr[right] == arr[index1])
        ) {
            if (arr[left] == arr[index1]) {
                // 不会越界
                left--;
            }

            if (arr[right] == arr[index1]) {
                // 不会越界
                right++;
            }            
        }

        if ((right - left - 1) > (arrSize / 4)) {

            return arr[index1];
        }

        left = index2, right = index2;

        while ((arr[left] == arr[index2]) ||
                (arr[right] == arr[index2])
        ) {
            if (arr[left] == arr[index2]) {
                // 不会越界
                left--;
            }

            if (arr[right] == arr[index2]) {
                // 不会越界
                right++;
            }            
        }

        if ((right - left - 1) > (arrSize / 4)) {

            return arr[index2];
        }

        left = index3, right = index3;

        while ((arr[left] == arr[index3]) ||
                (arr[right] == arr[index3])
        ) {
            if (arr[left] == arr[index3]) {
                // 不会越界
                left--;
            }

            if (arr[right] == arr[index3]) {
                // 不会越界
                right++;
            }            
        }

        if ((right - left - 1) > (arrSize / 4)) {

            return arr[index3];
        }
    }

    printf ("%d, %d, %d, %d\n", arr[index0], arr[index1], arr[index2], arr[index3]);

    return 0;
}

// @lc code=end

