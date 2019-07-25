/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 */


// 最简单容易的解决办法莫过于递归了。

int judge(int m, int n, int (*assistant)[101])
{
    if (m > 1 && n > 1)
    {
        if (assistant[m - 1][n] && assistant[m][n - 1])
        {
            return assistant[m - 1][n] + assistant[m][n - 1];    
        }
        else if(assistant[m - 1][n])
        {
            assistant[m][n - 1] = judge(m, n -1, assistant);
            
            return assistant[m - 1][n] + assistant[m][n - 1];
        }
        else if(assistant[m][n - 1])
        {
            assistant[m - 1][n] = judge(m - 1, n, assistant);

            return assistant[m - 1][n] + assistant[m][n - 1];
        }
        else
        {
            assistant[m][n - 1] = judge(m, n -1, assistant);
            assistant[m - 1][n] = judge(m - 1, n, assistant);

            return assistant[m - 1][n] + assistant[m][n - 1];
        }
        
    }
    else if(m > 1)
    {
        assistant[m - 1][n] = judge(m - 1, n, assistant);

        return assistant[m - 1][n];
    }
    else if(n > 1)
    {
        assistant[m][n - 1] = judge(m, n - 1, assistant);

        return assistant[m][n - 1];
    }
    else
    {
        return 1;    
    }

}


int uniquePaths(int m, int n){
    if (m == 0 && n == 0)
    {
        return 0;
    }
    else
    {
        int assistant[101][101] = {}; // 初始化数组
        return judge(m, n, assistant);
    }
    
}



