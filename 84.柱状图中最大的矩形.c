/*
 * @lc app=leetcode.cn id=84 lang=c
 *
 * [84] 柱状图中最大的矩形
 */


// 测试遇到问题
int largestRectangleArea(int* heights, int heightsSize){

    int area = 0;
    
    int number = 0;

    while (number < heightsSize)
    {
        
        /*
        if( heights[number] == 0 || (area != 0 && (area / heightsSize) > heights[number]) )
        {
            break;
        }
        */
        
        int count = 1;

        int left = number - 1;
        int right = number + 1;
        
       
        while ((left >= 0 && heights[left] >= heights[number]) || (right < heightsSize && heights[right] >= heights[number]) )
        {
            
            if (left >= 0 && heights[left] >= heights[number])
            {
                count++;
                left--;
            }

            if(right < heightsSize && heights[right] >= heights[number])
            { 
                count++;
                right++;
            }
            
        }

        if (area < heights[number] * count)
        {
            area = heights[number] * count;
        }

        number++;
        
    }
    

    return area;
}



