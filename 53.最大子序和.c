/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 */


int maxSubArray(int* nums, int numsSize){
    int number, result;
    int tailsum = 0, headsum = 0;
    bool flag = false, sign = false;
    for ( result = 0, number = 0; number < numsSize; number++)
    {
        if(headsum < 0) // 实现为负一直加的
        {
            sign =true;
            headsum = headsum + nums[number];
        }
        else
        {
            if(sign)
                flag = true;
            headsum = nums[number];
        }
        
        result = result + nums[number];

        if(tailsum < 0 && result > tailsum)
        {
            result = result - tailsum;
            tailsum = 0;
        }  
        
        tailsum = tailsum + nums[number];
    }

    if (headsum < 0 && flag)
    {
        result = result - headsum;
    }
    
    if (result <= 0)   // 当出现所有数值都为负数时找出最大的那一个数即可。
    {
        result =nums[0];
        for(number = 0; number < numsSize; number++)  
            if (result < nums[number])
                result =nums[number];
    }

    return result;
}


