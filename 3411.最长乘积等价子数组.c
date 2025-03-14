/*
 * @lc app=leetcode.cn id=3411 lang=c
 *
 * [3411] 最长乘积等价子数组
 */

// @lc code=start

// 计算两个数的最大公因数
int gcd_two_numbers(int a, int b) {

    while (b != 0) {

        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算数组所有元素的最大公因数
int gcd(int arr[], int n) {

    int result = arr[0]; // 初始化最大公因数为第一个元素
    for (int i = 1; i < n; i++) {
        result = gcd_two_numbers(result, arr[i]); // 逐步计算最大公因数
        if (result == 1) {
            return 1; // 如果任何时候最大公因数为 1，直接返回 1
        }
    }

    return result;
}

// 计算两个数的最小公倍数（LCM）
int lcm_two_numbers(int a, int b) {
    return (a * b) / gcd_two_numbers(a, b); // 根据 LCM(a, b) = (a * b) / GCD(a, b)
}

// 计算数组所有元素的最小公倍数
int lcm(int arr[], int n) {
    int result = arr[0]; // 初始化最小公倍数为第一个元素
    for (int i = 1; i < n; i++) {
        result = lcm_two_numbers(result, arr[i]); // 逐步计算最小公倍数
    }
    return result;
}

// 计算数组所有元素的乘积
long long prod(int arr[], int n) {
    
    long long result = 1; // 初始化积为 1

    for (int i = 0; i < n; i++) {
        result *= arr[i]; // 将当前元素与积相乘
    }

    return result;
}


int maxLength(int* nums, int numsSize) {
    



}

// @lc code=end

