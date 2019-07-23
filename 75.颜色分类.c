/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 */
// 还有更加简洁优胜的算法，即使用双“指针”，
// 对数组遍历，时间复杂度比数组长度的一半还小。

// 单“指针”，一遍遍历，常数级变量
void sortColors(int* nums, int numsSize){
    
    int head = 0, tail = numsSize - 1;

    int move = 0;

    while (numsSize)
    {
        
        if (move != head && nums[move] == 0)
        {
            int middle = nums[move];
            nums[move] = nums[head];
            nums[head++] = middle;
            
            // 这里move减1是为了能够确保交换后的数也能够被操作，而不被遗漏。    
            move--;
        }
        // 这里move要大于零是为了确保执行了上面的循环后move减1的数取数组值时不会越界。
        if (move >= 0 && move != tail && nums[move] == 2)
        {
            int middle = nums[move];
            nums[move] = nums[tail];
            nums[tail--] = middle;
            
            move--;
        }
        
        if (move < tail)
        {
            move++;
        }
        else
        {
            break;
        }
        
    }

}



/* 
// 第一版，两次遍历，常数级变量
void sortColors(int* nums, int numsSize){
    
    int color0 = 0, color1 = 0, color2 = 0;
    int i = 0;
    bool flag = true;
    while(i >= 0 && numsSize > 0)
    {
        
        if (flag)
        {
            if (i < numsSize && nums[i] == 1)
            {
                color1++;
            }
            else if (i < numsSize && nums[i] == 2)
            {
                color2++;
            }
      

            if (i < numsSize)
            {
                i++;
            }
            else
            {
                flag = false;
                i--;
            }
            
        }
        else
        {
            if (color2)
            {
                nums[i] = 2;
                color2--;
            }
            else if(color1)
            {
                nums[i] = 1;
                color1--;
            }
            else
            {
                nums[i] = 0;
            }
            
            i--;
        }
    }
}
*/


