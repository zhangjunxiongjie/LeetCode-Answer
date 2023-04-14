/*
 * @lc app=leetcode.cn id=1791 lang=c
 *
 * [1791] 找出星型图的中心节点
 */

// @lc code=start


int findCenter(int** edges, int edgesSize, int* edgesColSize){

    if ((edges[0][0] == edges[1][0]) || (edges[0][0] == edges[1][1])) {

        return edges[0][0];
    }
    else if ((edges[0][1] == edges[1][0]) || (edges[0][1] == edges[1][1])) {

        return edges[0][1];
    }
    
    return -1;
}

// @lc code=end

