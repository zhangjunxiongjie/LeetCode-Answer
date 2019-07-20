/*
 * @lc app=leetcode.cn id=69 lang=c
 *
 * [69] x 的平方根
 */

// 两种方法：1.移位（有点深奥，暂时不会），2.从1开始使其无限靠近其平方根；
int mySqrt(int x){
    
    if (x == 0)
        return 0;
    
    long int target = 0;  

    int number = 1;
    
    while (true)
    {
        if (target * target <= x && (target + 1) * (target + 1) > x)
        {
            return target;
        }
        else if(target * target < x && (target + 1) * (target + 1) >= x)
        {
            return target + 1;
        }
        else if((target + number) * (target + number) < x )
        {
            target = target + number;
            number++;
        }
        else
        {
            number = 1;
        }
        
    }

}



