/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */


// 这个题的关键在于要使子串的括号能够完全匹配
// 即对于不能完全进行括号匹配的子串是不能考虑在内的。
int longestValidParentheses(char * s){
    
    int max = 0;

    int count = 0;

    int len = 0;

    while (s[len++]);
    

    while ( s[count] )
    {
        if (len - count < max)
        {
            break;
        }
        
        int number = 0;
        int top = 0;
        int intercount = count;
        
        while ( s[intercount] )
        {
            if (s[intercount] == '(')
            {
                if(top == 0 && max < number)  
                    max = number;

                top = top + 1;         
            }
            
            if(s[intercount] == ')')
            {

                if (top == 0)
                {
                    if(max < number)
                        max = number;

                    break;
                }

                if(top > 0)
                {
                    top = top - 1;
                    number = number + 2;
                }

            }

            intercount++;
        }
        if(top == 0 && max < number)  
            max = number;
        // 只有当top为零时才是能完全匹配到的子串，而题目要求就是必须要完全匹配即top不能不为零，
        // 而在内循环中可能会出现这样一种情况就是某一个子串到
        // 最后一个字符正好能够完全匹配，可是这个时候下一次将退出循环
        // 而这里的这个判断就是将那些情况也包括进来，避免遗漏

        count++;        
    }

    return max;
}



