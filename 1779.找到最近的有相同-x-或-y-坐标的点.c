/*
 * @lc app=leetcode.cn id=1779 lang=c
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize){

    int resultIndex = -1;
    int minimumDistance = INT_MAX;

    for (int i = 0; i < pointsSize; i++) {                

        if ((points[i][0] == x) || (points[i][1] == y)) {

            int middle = (abs(points[i][0] - x) + abs(points[i][1] - y));

            if (middle < minimumDistance) {

                minimumDistance = middle;

                resultIndex = i;
            }
            
        }

    }

    return resultIndex;
}

// @lc code=end

