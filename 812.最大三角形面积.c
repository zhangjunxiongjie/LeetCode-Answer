/*
 * @lc app=leetcode.cn id=812 lang=c
 *
 * [812] 最大三角形面积
 */

// @lc code=start


double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){

    double resultArea = 0;

    for (int i = 0; i < pointsSize; i++) {

        for (int j = (i + 1); j < pointsSize; j++) {

            for (int z = (j + 1); z < pointsSize; z++) {

                double sideLengthA = sqrt(pow((points[i][0] - points[j][0]), 2) + pow((points[i][1] - points[j][1]), 2));
                
                double sideLengthB = sqrt(pow((points[i][0] - points[z][0]), 2) + pow((points[i][1] - points[z][1]), 2));

                double sideLengthC = sqrt(pow((points[j][0] - points[z][0]), 2) + pow((points[j][1] - points[z][1]), 2));

                double perimeter = (sideLengthA + sideLengthB + sideLengthC);

                perimeter = (perimeter / 2.0);

                double tempArea = sqrt(perimeter * (perimeter - sideLengthA) * (perimeter - sideLengthB) * (perimeter - sideLengthC));

                if (tempArea > resultArea) {
                    
                    resultArea = tempArea;
                }
            }
        }
    }

    return resultArea;
}

// @lc code=end

