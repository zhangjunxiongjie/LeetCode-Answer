/*
 * @lc app=leetcode.cn id=1281 lang=c
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start


int subtractProductAndSum(int n){

    int sum = 0;
    int product = 1;

    while (n != 0) {

        int middle = (n % 10);

        product *= middle;
        sum += middle;

        n /= 10;
    }

    // printf ("%d, %d\n", product, sum);

    return (product - sum);
}

// @lc code=end

