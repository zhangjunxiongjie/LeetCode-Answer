/*
 * @lc app=leetcode.cn id=76 lang=c
 *
 * [76] 最小覆盖子串
 */



// 第一版， 能够实现问题求解但是时间复杂度太高，导致超时
// 对辅助数组进行初始化
bool init_em(int* input_int, int str_len, int flag)
{
    bool sign = true;
    for (int i = 0, j = str_len - 1; i <= j; i++, j--)
    {
        // 0只进行判断，1只进行初始化，其它两个都进行
        if(flag != 1)
        {
            if (input_int[i] != 1 || input_int[j] != 1)
            {
                sign = false;
            }
        }  
        
        if(flag != 0)
        {
            input_int[i] = 0; 
            input_int[j] = 0; 
        }
    }
    return sign;
}

int frist_judge(char* s, char* t, int* employee, int t_len, int it)
{
    for (int i = 0, j = t_len - 1; i <= j; i++, j--)
    {
        if ((employee[j] != 1 && s[it] == t[j]) || (employee[i] != 1 && s[it] == t[i])) 
            return i;
    
    }
    return -1;
}

int last_judge(char* s, int s_len, char* t, int t_len, int outmove, int* employee)
{
    int count = outmove;
    while(count < s_len)
    {
        int buffer = frist_judge(s, t, employee, t_len, count); 
        
        if (buffer != -1)
        {
            employee[buffer] = 1;
        }
        else if(count == outmove)
        {
            break;
        }
        
        
        // 有一种特殊情况就是t字符串中存在重复字母的情况
        if ((count - outmove) >= t_len && init_em(employee, t_len, 0))
            break;
        
        count++;
    }
    return count;
}

char* minWindow(char * s, char * t){
    
    // 得到字符串的长度；
    int t_len = 0, s_len = 0;
    for (; t[t_len] != '\0'; t_len++);
    for (; s[s_len] != '\0'; s_len++);
    
    // 进行特殊处理；
    if (t_len == 0 || s_len == 0 || t_len > s_len)
        return "";
    
    // 定义辅助数组；
    int* employee = (int*)malloc(sizeof(int) * t_len);
    init_em(employee, t_len, 1); // 只进行初始化
    
    // 定义保存结果的变量；
    int front = 0, behind = s_len; // str_min对应的下标
    int outmove = 0; // 移动下标
 
    bool sign = false; // 标识是否找到至少一个匹配字符串
    while (s_len - outmove >= t_len)
    {
        int cache = s_len;
        bool flag = false;

        cache = last_judge(s, s_len, t, t_len, outmove, employee);
        if(cache != outmove || t_len == 1)
            flag = init_em(employee, t_len, 2); // 既要进行判断还要进行初始化；

        if (flag && (behind - front) >= (cache - outmove))
        {
            behind = cache;
            front = outmove;
            if((behind - front +  1) == t_len)
                break;
            sign = true;
        }
        
        outmove++;
    }
    
    // 结果数组
    if (sign)
    {
        char* result = malloc(sizeof(char) * (behind - front + 2));
        for (int i = front, j = 0; i <= behind; i++, j++)
        {
            result[j] = s[i];
        }
        result[behind - front + 1] = '\0';
        return result;
    }
    else
        return "";
}


