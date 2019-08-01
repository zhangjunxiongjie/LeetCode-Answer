/*
 * @lc app=leetcode.cn id=85 lang=c
 *
 * [85] 最大矩形
 */


// 第二版，这一版同样向右方和下方延伸，但是不同的是在搜索上进行优化
// 上一版是从最小的可能开始搜索这一版从最大的可能开始。
typedef struct site
{
    int x;
    int y;
}place;

bool judge(char** middle, place start, place over)
{
    for (int i = start.y; i <= over.y; i++)
    {
        for (int j = start.x; j <= over.x; j++)
        {
            if (middle[i][j] != '1')
            {
                return false;
            }
            
        }
        
    }

    return true;
}

int dispatch(char** middle, place bound, place begin, int now_result)
{
    int max = 1;
    place cache = begin;
    
    
    // 找出最大可能；
    int between;
    while (++cache.x < bound.x && judge(middle, begin, cache));
    between = cache.x;

    cache = begin;
    while (++cache.y < bound.y && judge(middle, begin, cache)); 
    cache.x = between;

    if ((cache.y - begin.y) * (cache.x - begin.x) < now_result)
        return 0; 
    
    if((cache.y - begin.y) > (cache.x - begin.x))
        max = cache.y - begin.y;
    else
        max = cache.x - begin.x;

    while (begin.y < --cache.y)
    {
        place buffer = cache;
        while( begin.x < --buffer.x ) 
        {
            int info = (buffer.x - begin.x + 1) * (buffer.y - begin.y + 1);
            if (judge(middle, begin, buffer))
            {
                if (info > max)
                    max = info;
                break;  
            }
             
        }
    
    }
    
    return max;
}


int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    
    if (matrixSize == 0 || *matrixColSize == 0)
    {
        return 0;
    }
    place bound;
    bound.x = *matrixColSize;
    bound.y = matrixSize;

    int result = 0;
    
    for (int i = 0; i < bound.y; i++)
    {
        for (int j = 0; j < bound.x; j++)  
        {
            if (matrix[i][j] == '1')  // 找字符为‘1’的元素
            {
                place now_site;
                now_site.y = i;
                now_site.x = j;
                
                int middle = dispatch(matrix, bound, now_site, result);
                if (middle > result)
                    result = middle;                
                
            }
            
        }
        
    }

    return result;
}


/* 
// 第一版，向右方和下方延伸
typedef struct site
{
    int x;
    int y;
}place;

bool judge(char** middle, place start, place over)
{
    for (int i = start.y; i <= over.y; i++)
    {
        for (int j = start.x; j <= over.x; j++)
        {
            if (middle[i][j] != '1')
            {
                return false;
            }
            
        }
        
    }

    return true;
}

int dispatch(char** middle, place bound, place begin)
{
    int max = 1;
    place cache = begin;
    while (cache.y < bound.y)
    {
        place buffer = cache;
        while( buffer.x < bound.x ) 
        {
            int info = (buffer.x - begin.x + 1) * (buffer.y - begin.y + 1);
            if (judge(middle, begin, buffer))
            {
                if (info > max)
                    max = info;
               
            }
            else if(buffer.x == cache.x)
                return max;
            else
                break;
            
            buffer.x++; 
        }
        
        cache.y++;

    }
    return max;
}


int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    
    if (matrixSize == 0 || *matrixColSize == 0)
    {
        return 0;
    }
    place bound;
    bound.x = *matrixColSize;
    bound.y = matrixSize;

    int result = 0;
    
    for (int i = 0; i < bound.y; i++)
    {
        for (int j = 0; j < bound.x; j++)  
        {
            if (matrix[i][j] == '1')  // 找字符为‘1’的元素
            {
                place now_site;
                now_site.y = i;
                now_site.x = j;
                
                int middle = dispatch(matrix, bound, now_site);
                if (middle > result)
                    result = middle;                
                
            }
            
        }
        
    }

    return result;
}
*/


