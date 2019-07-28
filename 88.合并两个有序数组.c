/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

void into(int* s, int place, int* operator, int oper_sum)
{
    int middle = s[place];
    s[place] = operator[0];

    int i;
    for (i = 1; i < oper_sum; i++)
    {
        if (middle > operator[i])
            operator[i - 1] = operator[i];
        else
        {
            operator[i - 1] = middle; 
            break;           
        }
    }
    if (i == oper_sum && oper_sum > 0)
        operator[i - 1] = middle;

}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for (int i = 0; i < m; i++)
    {
        if (n > 0 && nums1[i] > nums2[0])
        {
            into(nums1, i, nums2, n);
            continue;
        }
    }
    for (int i = 0; i < n; i++)
        nums1[i + m] = nums2[i];
        
}



