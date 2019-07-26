/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */

// 递归的实现方法
int assistant(char* s, int needle)
{
    if (s[needle] == '0')
    {
        return 0;
    }
    else if (s[needle] == '\0')
    {
        return 1;
    }
    else if(s[needle + 1] == '\0')
    {
        return 1;
    }
    else
    {
        int number = (s[needle] - 48) * 10 + (s[needle + 1] - 48);
        if(number == 10 || number == 20)
        {
            return assistant(s, needle + 2);
        }
        else if (number <= 26)
        {
            return assistant(s, needle + 1) + assistant(s, needle + 2);
        }
        else
        {
            return assistant(s, needle + 1);
        }
    }

}


int numDecodings(char * s){
    if (s[0] == '\0' || s[0] == '0')
    {
        return 0;
    }
    
    return assistant(s, 0);
}



