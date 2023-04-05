/*
 * @lc app=leetcode.cn id=724 lang=c
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
int pivotIndex(int* nums, int numsSize){
    
    int resultInt = -1;
    int siteIndex = (numsSize - 1);
    long int leftSum = 0;
    long int rightSum = 0;

    for (; siteIndex > 0; siteIndex--) {

        rightSum += nums[siteIndex];
    }

    while (siteIndex < numsSize) {

        if (leftSum == rightSum) {

            resultInt = siteIndex;
            break;
        }

        siteIndex++;
        if (siteIndex < numsSize) {

            leftSum += nums[siteIndex - 1];
            rightSum -= nums[siteIndex];
        }
        else {
            break;
        }
    }

    return resultInt;
}
// @lc code=end

