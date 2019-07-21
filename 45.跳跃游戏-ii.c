/*
 * @lc app=leetcode.cn id=45 lang=c
 *
 * [45] 跳跃游戏 II
 */


// 第三版，另一种时间复杂度和空间复杂度折中的方法，时间复杂度依然较高。
int jump(int* nums, int numsSize){
    if(numsSize == 0 || numsSize == 1)
        return 0;
    if (numsSize == 2)
        return 1;
    
    int left = 0, right = nums[0] + left;

    int number = 1;

    int middle = 0;

    while (true)
    {
        middle = right;  
        
        if (right >= numsSize - 1) // 确保在使用nums数组时不会越界
            return number;

        for (int i = right; i > left; i--)
            if(right < nums[i] + i)
                right = nums[i] + i;

        left = middle;

        number++;
        
    }
    
}



/*
// 第二版，从前往后找。时间复杂度依然很高，
// 当然有想到牺牲空间复杂度去争取时间复杂度方法；
// 但是那个方法过于牺牲空间复杂度，另一方面增加了程序本身的复杂度。
int jump(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1)
    {
        return 0;
    }
    
    int number = 0;    // 记步数
    int flag = numsSize - 1;   // 
    while(true)
    {
        for(int i = 0; i <= flag; i++)
        {
            if (nums[i] + i >= flag)
            {
                number++;
                if(i == 0)
                    return number;
                flag = i;
                break;
            }
        }

    }
}
*/

/*
// 第一版，从后往前找。
int jump(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1)
    {
        return 0;
    }
    
    int buffer[numsSize], head = 0;
    int number = 0;    // 记步数
    int flag = numsSize - 1;   // 
    while(true)
    {
        for(int i = flag; i >= 0; i--)
        {
            if (nums[i] + i >= flag)
            {
                buffer[head++] = i;
            }
        }

        flag = buffer[head - 1];
        head = 0;
        number++;
        if(flag == 0)
            break;
    }

    return number;
}

*/

