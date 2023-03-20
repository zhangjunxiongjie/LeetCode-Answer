/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start
int searchInsert(int* nums, int numsSize, int target){
    
    unsigned short numsIndexMin = 0;
    unsigned short numsIndexMax = (numsSize - 1);
    unsigned short numsIndexMiddle = (unsigned short)((numsIndexMax + numsIndexMin) / 2);
    int result = 0;

    while (1) {
        
        numsIndexMiddle = (unsigned short)((numsIndexMin + numsIndexMax) / 2);

        if ((nums[numsIndexMin] >= target) 
        ) {
            
            result = (int)(numsIndexMin);
            break;
        }        
        else if ((nums[numsIndexMax] <= target) 
        ) {
            
            if ((numsIndexMax == (numsSize - 1)) && 
                (nums[numsIndexMax] < target)
            ) {

                result = numsSize;
            }
            else {
                result = (int)(numsIndexMax);
            }
            break;
        }        
        else if ((nums[numsIndexMin] < target) &&
                (nums[numsIndexMax] > target)
        ) {
            
            if ((numsIndexMax - numsIndexMin) == 1) {

                result = (int)(numsIndexMax);
                break;
            }
            else {

                if (nums[numsIndexMiddle] < target) {

                    numsIndexMin = numsIndexMiddle;
                }
                else if (nums[numsIndexMiddle] > target){
                    
                    numsIndexMax = numsIndexMiddle;
                }
                else {

                    result = (int)(numsIndexMiddle);
                    break;
                }
            }
        }        
    }

    return result;
}
// @lc code=end

