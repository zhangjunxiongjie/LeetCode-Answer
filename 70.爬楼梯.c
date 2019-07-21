/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// 应该还可以使用归并的方法，虽不能证伪但也不能证实，先暂且留于此。 


// 优化后的递归实现
int buffer[50];  // 全局数组初始值为零

int climbStairs(int n){
    
    if (n == 0)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {   if(buffer[n - 1] != 0 && buffer[n - 2] != 0 )
            return buffer[n - 1] + buffer[n -2];
        else if(buffer[n - 1] != 0)
        {
            buffer[n -2] = climbStairs(n - 2);
        }
        else if(buffer[n - 2] != 0)
        {
            buffer[n -1] = climbStairs(n - 1);
        }
        else
        {
            buffer[n -1] = climbStairs(n -1);
            buffer[n -2] = climbStairs(n -2);
        }
        return buffer[n - 1] + buffer[n - 2];
    }
}

/*
// 简单的递归实现方法,简单倒是简单，但是时间复杂度太高了。
int climbStairs(int n){
    if (n == 0)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}
 */


