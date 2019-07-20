/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 */


// 较简单
int lengthOfLastWord(char * s){

    int tail_len = 0;  // 遍历到的字符串的最后一个单词的长度
    bool sign = true;  // 标志位，标志前面为空格还是字母

    for(int number = 0; s[number] != '\0'; number++)
    {
        if (s[number] != ' ')
        {
            if (sign)
                tail_len = 0;
            
            tail_len++;
            sign = false;
        }
        else
            sign = true;
    }

    return tail_len;
}



