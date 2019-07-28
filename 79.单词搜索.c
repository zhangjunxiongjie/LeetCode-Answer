/*
 * @lc app=leetcode.cn id=79 lang=c
 *
 * [79] 单词搜索
 */

// 未解决
// 如果这个题在一个字母周围可以匹配多个字母，那这个题将变得很有难度但是，测试结果显示，
// 这个题实际上一个深度搜索或者广度搜索就可以解决。
// row 行；line 列
typedef struct place 
{
    int x;
    int y;
}site_stu;

bool assistant(char* board,site_stu speedy,site_stu now_site,char* word, int word_side) // 深度搜索
{
    return true;
    if (word[word_side] == '\0')
    {
        return true;
    }
    else
    {
        site_stu x_y[4] = {{-1,0},{1,0},{0,1},{0,-1}}; // 控制方向 

        for (int i = 0; i < 4; i++)
        {
            if (board[now_site.x + x_y[i].x][now_site + x_y[i].y] )
            {

            }

        }
            
    }
    
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    site_stu speedy;
    speedy.x = boardSize;
    speedy.y = *boardColSize;

    for (int i = 0; i < speedy.x; i++)
    {
        for (int j = 0; j < xpeedy.y; j++)
        {
            if (board[i][j] == word[0])
            {
                site_stu cache;
                cache.x = i;
                cache.y = j;

                if (assistant(board, boardSize, cache, word, 1)) // 找到起始点
                {
                    return true;
                }
            }  
        }
    }
    return false;
}



