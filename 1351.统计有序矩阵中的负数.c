/*
 * @lc app=leetcode.cn id=1351 lang=c
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start


typedef struct list_node {

    int x;
    int y;
    struct list_node *next_p;

} Link_Table;


Link_Table *list_head = NULL;
Link_Table *list_tail = NULL;

bool list_is_empty(void) {

    if ((list_head == NULL)) {
        
        return true;
    }
    else {

        return false;
    }
}

bool push_node(int x, int y) {

    Link_Table *current_p;

    current_p = malloc(sizeof(Link_Table));
    current_p->x = x;
    current_p->y = y;
    current_p->next_p = NULL;

    if (list_is_empty()) {        

        list_head = current_p;
        list_tail = current_p;
    }
    else {

        list_tail->next_p = current_p;
        list_tail = current_p;
    }

    return true;
}

Link_Table pop_node(void) {

    Link_Table current_p;
    Link_Table *free_p;

    if (list_is_empty()) {
                
        list_head = NULL;
        list_tail = NULL;
    }
    else {
        
        current_p.x = list_head->x;
        current_p.y = list_head->y;

        free_p = list_head;
        list_head = list_head->next_p;
        free(free_p);
    }

    return current_p;
}


int countNegatives(int** grid, int gridSize, int* gridColSize){     
    /*
    int gridColSizeNum = (*gridColSize);
    int resultCounter = 0;

    if ((gridSize != 0) && (gridColSizeNum != 0)) {

        push_node((gridSize - 1), (gridColSizeNum - 1));
    }
    else if ((gridSize == 0) && (gridColSizeNum != 0)) {

        push_node(0, (gridColSizeNum - 1));
    }
    else if ((gridSize != 0) && (gridColSizeNum == 0)) {

        push_node((gridSize - 1), 0);
    }
    else {
        
    }
    
    while (!list_is_empty()) {

        Link_Table current_p = pop_node();
        int x = current_p.x;
        int y = current_p.y;

        if (grid[x][y] < 0) {
            grid[x][y] = 0;

            resultCounter++;

            printf ("%d, %d, %d\n", x, y, grid[x][y]);
        }

        if (((x - 1) >= 0) && (grid[x - 1][y] < 0)) {

            push_node((x - 1), y);
        }

        if (((y - 1) >= 0) && (grid[x][y - 1] < 0)) {

            push_node(x, (y - 1));
        }
    }

    return resultCounter;
    */

    int resultCounter = 0;

    int current_x = 0;
    int current_y = ((*gridColSize) - 1);
    
    // 向右向右
    // 向上向上
    while (true) {

        int leftIndex = 0;
        int RightIndex = current_y;

        while (true) {
            
            int middleIndex = ((leftIndex + RightIndex) / 2);

            if (grid[current_x][leftIndex] < 0) {
                
                current_y = leftIndex;
                break;
            }

            if (grid[current_x][middleIndex] < 0) {

                RightIndex = middleIndex;
            }
            else {
                
                if (leftIndex == middleIndex) {
                    // left right 相邻
                    current_y = RightIndex;
                    break;
                }
                else {
                    leftIndex = middleIndex;
                }
            }
        }

        if (grid[current_x][current_y] >= 0) {
            
            resultCounter += ((*gridColSize) - current_y - 1);
        }
        else {

            resultCounter += ((*gridColSize) - current_y);
        }
        
        if ((current_x + 1) < (gridSize)) 
        {
            current_x++;
        }
        else 
        {
            break;                    
        }
        /*
        if (grid[current_x][current_y] < 0) {

            if ((current_y - 1) >= 0) {
                
                current_y--;
            }
            else {
                resultCounter += ((*gridColSize) - current_y);

                if ((current_x + 1) < (gridSize)) 
                {
                    current_x++;
                }
                else 
                {
                    break;                    
                }
            }
        }
        else {
            resultCounter += ((*gridColSize) - current_y - 1);

            if ((current_x + 1) < (gridSize)) 
            {        
                current_x++;
            }             
            else 
            {
                break;
            }  
        }
        */
    }

    /*
    int current_x = (gridSize - 1);
    int current_y = 0;

    // 向左向左
    // 向下向下
    while (true) {
        
        if ((grid[current_x][current_y] < 0)) {
            
            if ((current_x - 1) >= 0) {
                
                current_x--;
            }
            else {
                resultCounter += (gridSize - current_x);

                if ((current_y + 1) < (*gridColSize)) 
                {                    
                    current_y++;
                }                
                else 
                {
                    break;
                }
            }
        }
        else {
            resultCounter += (gridSize - current_x - 1);

            if ((current_y + 1) < (*gridColSize)) 
            {        
                current_y++;
            }             
            else 
            {
                break;
            }  
        }
    }
    */

    return resultCounter;
}

// @lc code=end

