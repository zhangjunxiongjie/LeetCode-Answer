/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除排序数组中的重复项 II
 */

// 由结果可以得出这样一个结论:某个数如果等于前面那个数就不能与后面的数相等，
// 如果与后面的数相等就不可以与前面的数相等
// 那么由这个结论我们就可以直接对数组进行遍历按顺序查看每一个数
// 另外对于数组元素个数小于2的情况是不需要做任何处理的
int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2)
        return numsSize;
    
    int head = 0, move = 1;
    bool sign = false;    // 标志当前head所在元素是否与前面元素相等。
    
    while(move < numsSize)
    {
    
        if (nums[move] != nums[head])
        {
            nums[++head] = nums[move++];
            sign = false;
        }
        else if(!sign)
        {
            nums[++head] = nums[move++];
            sign = true;
        }
        else
            move++;
    
    }
    
    return head + 1;
}



