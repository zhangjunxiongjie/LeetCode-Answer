/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    
    int into = 1;
    for (int i = digitsSize - 1; ( into && i >= 0 ); i--) //
    {
        int buffer = into + digits[i];
        if (buffer >= 10)
        {
            into = buffer / 10; 
        }
        else
        {
            into = 0; 
        }
        digits[i] = buffer % 10;

    }
    
    int* space = malloc(sizeof(int) * (digitsSize + into));  // 确保有进位时不会越界；
    
    if (into)
    {
        space[0] = into;
    }
    
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        space[i + into] = digits[i];
    }
    
    *returnSize = digitsSize + into;
   
    return space;
}



