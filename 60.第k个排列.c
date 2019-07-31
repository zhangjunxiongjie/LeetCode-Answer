/*
 * @lc app=leetcode.cn id=60 lang=c
 *
 * [60] 第k个排列
 */

// 第三版，去掉函数。
char* getPermutation(int n, int k) {
	
	int employee[9] = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }; 

	char* result = (char*)(malloc(sizeof(char) * n + 1));

	int ret = -1;     // 记录当前所处位置；

	for (int i = 0; i < n; i++) 
	{
		result[i] = (i + 1) + 48; // 加48变为字符

		if (ret == -1 && employee[i] >= k)
			ret = i;    // 放在这个循环里的额外工作。

	}

	k = k - 1;  // 这里把‘第k个排列’变换为‘做k次变换’；
	while (k > 0)
	{
		int place = n - 1 - ret; // 建立映射关系

		int spacer = k / employee[ret - 1]; // 临时变量,移动距离
		
		int space = spacer + place; // 计算要交换的下标

		if (spacer)   // 每次下标向后移动都要保证后面的整个区块是其所对应的的最小值即第一个值。
		{

			k = k % employee[ret - 1]; // 更新k值
			
			int middle = result[space];
			for (int i = space - 1; i >= place; i--)
				result[i + 1] = result[i];
			result[place] = middle;
			
		}	
		ret--;
	}

	result[n] = '\0';  // 

	return result;
}


/* 
// 第二版，取消了排序，改为了更合理也更准确的移动
void move(char* target, int left, int right) // 移动
{
	int middle = target[right];
	
	for (int i = right - 1; i >= left; i--)
		target[i + 1] = target[i];

	target[left] = middle;

}

char* getPermutation(int n, int k) {
	
	int employee[9] = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }; 
	// 需要使用到的辅助数组

	char* result = (char*)(malloc(sizeof(char) * n + 1));

	int ret = -1; // 记录当前所处位置；

	// 一方面对字符数组进行初始化另一方面还做了一点额外工作就是找到第一级变换下标。
	for (int i = 0; i < n; i++) 
	{

		result[i] = (i + 1) + 48; // 加48变为字符

		if (ret == -1 && employee[i] >= k)
			ret = i;    // 放在这个循环里的额外工作。

	}

	k = k - 1;  // 这里把‘第k个排列’变换为‘做k次变换’；
	while (k > 0)
	{
		int place = n - 1 - ret; // 建立映射关系

		int spacer = k / employee[ret - 1]; // 临时变量,移动距离
		
		int space = spacer + place; // 计算要交换的下标

		if (spacer)   // 每次下标向后移动都要保证后面的整个区块是其所对应的的最小值即第一个值。
		{

			k = k % employee[ret - 1]; // 更新k值
			
			move(result, place, space); // 传入要移动的一些参数 
			
		}	

		ret--;
	}

	result[n] = '\0';  // 

	return result;
}
*/

/* 第一版，
// 它巧妙地发现并使用了变换的规律，而并不是从头开始寻找；
void sort(char* target, int left, int right) // 排序
{
	for (int i = left; i < right; i++)
	{
		for (int j = i + 1; j < right; j++)
		{
			if (target[i] > target[j])
			{
				char middle = target[i];
				target[i] = target[j];
				target[j] = middle;
			}
		}
	}
}

char* getPermutation(int n, int k) {
	//int employee[9] = { 6362880, 40320, 5040, 720, 120, 24, 6, 2, 1 };
	int employee[9] = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }; 
	// 需要使用到的辅助数组

	char* result = (char*)(malloc(sizeof(char) * n + 1));

	int ret = -1; // 记录当前所处位置；

	// 一方面对字符数组进行初始化另一方面还做了一点额外工作就是找到第一级变换下标。
	for (int i = 0; i < n; i++) 
	{

		result[i] = (i + 1) + 48; // 加48变为字符

		if (ret == -1 && employee[i] >= k)
			ret = i;    // 放在这个循环里的额外工作。

	}

	k = k - 1;  // 这里把‘第k个排列’变换为‘做k次变换’；
	while (k > 0)
	{
		int place = n - 1 - ret; // 因为字符数组是从后往前而辅助数组是从前往后所以这里进行一下转换，
		// 但是并不能直接将辅助数组改成与字符数组一至，这由字符所占区块有关（因为字符数组都是从0下标开始）

		int spacer = k / employee[ret - 1]; // 临时变量
		
		int space = spacer + place; // 计算要交换的下标

		int middle = result[space];  // 进行交换操作。
		result[space] = result[place];
		result[place] = middle;

		if (spacer)   // 每次下标向后移动都要保证后面的整个区块是其所对应的的最小值即第一个值。
		{
			k = k % employee[ret - 1]; // 更新k值
			if(spacer > 1)
				sort(result, place + 1, n);
		}	

		ret--;
	}

	result[n] = '\0';  // 

	return result;
}
*/


