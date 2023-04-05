/*
 * @lc app=leetcode.cn id=2540 lang=c
 *
 * [2540] 最小公共值
 */

// @lc code=start

bool isSubset(int *nums, int numsSize, int target)
{
    int numsLeftIndex = 0;
    int numsRightIndex = (numsSize - 1);

    do
    {
        int middle = (numsLeftIndex + numsRightIndex) / 2;

        if (nums[numsLeftIndex] == target) {
            return true;
        }

        if (nums[numsRightIndex] == target) {
            return true;
        }

        if (nums[middle] == target) {
            return true;
        }
        else if (nums[middle] < target) {
            numsLeftIndex = middle;            
        }
        else if (nums[middle] > target) {
            numsRightIndex = middle;
        }
        
    }
    while (numsLeftIndex < (numsRightIndex - 1));

    return false;
}


int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size){


    if ((nums1[0] > nums2[nums2Size - 1]) && 
        (nums1[nums1Size - 1] > nums2[0])
    ) {
        return -1;
    }

    if (nums1Size < nums2Size) {

        for (int i = 0; i < nums1Size; i++) {

            if (isSubset(nums2, nums2Size, nums1[i])) {
                
                return nums1[i];
            }

            while (((i + 1) < nums1Size) && (nums1[i] == nums1[i + 1])) {
                
                i++;
            }
        }
    }
    else {

        for (int i = 0; i < nums2Size; i++) {

            if (isSubset(nums1, nums1Size, nums2[i])) {
                
                return nums2[i];
            }

            while (((i + 1) < nums2Size) && (nums2[i] == nums2[i + 1])) {
                
                i++;
            }
        }
    }

    return -1;
}


// @lc code=end

