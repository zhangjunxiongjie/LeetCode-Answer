/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */
// gridColSize表示行数即外层，gridSize表示列数即内层；
/*   
 if (gridSize == 0 || *gridColSize == 0)
{
    return 0;
}  // 判断传入二维数组的特殊情况； 
*/

/*
这个题还可以对空间复杂度进行优化。(可以直接在原数组上进行操作)
 */
// 版本三，动态规划，从终点开始往起点找。
// 先确定终点附近能够确定到终点最短距离的点
// 然后向外扩展，通过比较其右边和下边相邻点到终点的最短距离。
// 就可以依次确定附近点到终点的最短距离。
/*
int Min(int right, int down)
{
    if (right > down)
    {
        return down;
    }
    else
    {
        return right;
    }
    
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || *gridColSize == 0)
    {
        return 0;
    }
    else
    {
        int y = gridSize;
        int x = *gridColSize;

        int assistant[y][x];  // 存储每个点到终点的最短距离

        for (int i = y - 1; i >= 0; i--)
        {
            for (int j = x - 1; j >= 0; j--)
            {
                if (i == y - 1 && j == x - 1) // 终点到终点的距离是可以直接确定的
                {
                    assistant[i][j] = grid[i][j];
                }
                else if (i == y - 1)  // 最右边那一列和最下边那一行确定最短距离的方法和其余列行有所不同
                {
                    assistant[i][j] = assistant[i][j + 1] + grid[i][j];
                }
                else if(j == x - 1)
                {
                    assistant[i][j] = assistant[i + 1][j] + grid[i][j];
                }
                else
                {
                    assistant[i][j] = Min(assistant[i + 1][j] + grid[i][j], assistant[i][j + 1] + grid[i][j]);
                }
                
            }
            
        }
        
        return assistant[0][0];
    }
    
}
*/


// 版本二，递归优化，增加辅助数组，降低时间复杂度。
// 虽然对递归优化了时间复杂度，但是由于递归本身的性质造成的空间复杂度的恶劣，并不能很好地得到缓解。
typedef struct site
{
    int x;
    int y;
}Place;

int Min(int right, int down)
{
    if (right > down)
        return down;
    else
        return right;
    
}

void Find_min(Place now_site,Place conven, int** grid)
{

    if (now_site.x < conven.x - 1 && now_site.y == conven.y - 1)
    {
        grid[now_site.y][now_site.x] += grid[now_site.y][now_site.x + 1];
    }
    else if (now_site.x == conven.x - 1 && now_site.y < conven.y - 1)
    {
        grid[now_site.y][now_site.x] += grid[now_site.y + 1][now_site.x];
    }
    else if (now_site.x < conven.x - 1 && now_site.y < conven.y - 1)
    {
        grid[now_site.y][now_site.x] += Min(grid[now_site.y + 1][now_site.x], grid[now_site.y][now_site.x + 1]);
    }


    if (now_site.x == 0 && now_site.y > 0) // 换行
    {
        Place next_site;
        next_site.x = conven.x - 1;
        next_site.y = now_site.y - 1;

        Find_min(next_site, conven, grid);
    }
    else if(now_site.x > 0 && now_site.y >= 0) // 换列
    {
        Place next_site;
        next_site.x = now_site.x - 1;
        next_site.y = now_site.y;

        Find_min(next_site, conven, grid);
    }
    
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || *gridColSize == 0)
    {
        return 0;
    }
    else
    {
        
        Place conven;  // 边界坐标
        conven.x = *gridColSize;
        conven.y = gridSize;

        Place start;   // 起始地址坐标
        start.x = *gridColSize - 1;
        start.y = gridSize - 1;
        
        Find_min(start, conven, grid);
        return grid[0][0];

    }
    
}

/*
// 版本一，递归的解答方法。(超时，但是思路是正确的)
typedef struct site
{
    int x;
    int y;
}Place;

void Find_min(Place now_site, Place conven, int** grid, int* result)
{
    if (now_site.x == conven.x - 1 && now_site.y == conven.y - 1)
    {
        if (*result == -1)
        {
            *result = grid[0][0];   // 在起始位置存储路径信息
        }
        else if (*result > grid[0][0])
        {
            *result = grid[0][0];
        }

    }
    else
    {
        Place dirc[2];    // 定义方向矢量
        dirc[1].y = dirc[0].x = 0;
        dirc[1].x = dirc[0].y = 1;

        for (int i = 0; i < 2; i++)
        {
            Place next_site;
            next_site.x = now_site.x + dirc[i].x;
            next_site.y = now_site.y + dirc[i].y;

            if ((next_site.x < conven.x) && (next_site.y < conven.y))
            {
                int middle = grid[0][0];
            
                grid[0][0] += grid[next_site.y][next_site.x];
            
                Find_min(next_site, conven, grid, result); 
            
                grid[0][0] = middle;
            }

        }
        
    }
    
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || *gridColSize == 0)
    {
        return 0;
    }
    else
    {
        Place conven;  // 边界坐标
        conven.y = gridSize;
        conven.x = *gridColSize;
        
        int result = -1;  // 表示现在是最初的状态；

        Place start;   // 起始地址坐标
        start.x = 0;
        start.y = 0;
        
        Find_min(start, conven, grid, &result);

        return result;
    }
    
}
*/



