/*
 * @lc app=leetcode.cn id=55 lang=c
 *
 * [55] 跳跃游戏
 */
// 第三版
bool canJump(int* nums, int numsSize){
    
    if (numsSize <= 1)
        return true;
    
    for(int number = 0, max = number + nums[number]; number <= max; number++)
    {
        if(max >= numsSize - 1)
            return true;
        if (number + nums[number] > max)
            max = number + nums[number];
    }

    return false;
}




/*
// 第二版
bool canJump(int* nums, int numsSize){
    
    if (numsSize <= 1)
    {
        return true;
    }
    
    int number = numsSize -1;

    numsSize = number--;
    
    while(number >= 0)
    {
        if (number + nums[number] >= numsSize)
        {
            if (number == 0)
            {
                return true;
            }
                
            numsSize = number;
        
        }
        number--;
    }

    return false;
}
*/

/* 第一版
// 设置一个只放和读堆栈降低一个元素设置为数组倒数第一个元素，
// 从倒数第二个位置开始往前找能够到达堆栈中任何一个元素的下标志，
// 对于符合条件的下标将其放于堆栈知道判断出第一个元素符合条件则返回true，
// 否则直到寻找结束返回false。

bool canJump(int* nums, int numsSize){
    
    if (numsSize <= 1)
    {
        return true;
    }
    
    int stack[numsSize],head = 0; // 定义堆栈
    int number = numsSize -1;
    stack[head++] = number--;
    
    while(number >= 0)
    {
        for (int i = head - 1; i >= 0; i--)
        {
            if (number + nums[number] >= stack[i])
            {
                if (number == 0)
                {
                    return true;
                }
                
                stack[head++] = number;
                break;
            }
        }
        number--;
    }

    return false;
}

 */

