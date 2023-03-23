/*
 * @lc app=leetcode.cn id=704 lang=c
 *
 * [704] 二分查找
 */

// @lc code=start


int search(int* nums, int numsSize, int target){

    int left = 0;
    int right = (numsSize - 1);
    int middle = ((left + right) / 2);

    if (nums[left] == target) {

        return left;
    }
    else if (nums[right] == target) {

        return right;
    }

    while (left < right) {

        if (nums[middle] == target) {

            return middle;
        }
        else if (target > nums[middle]) {

            left = middle;
        }
        else if (target < nums[middle]) {

            right = middle;
        }

        if (((left + 1) == right)) {

            if (nums[left] == target) {
                
                return left;
            }
            else if (nums[right] == target) {

                return right;
            }
            else {
                break;
            }
        }

        middle = ((left + right) / 2);
    }

    return (-1);
}

// @lc code=end

