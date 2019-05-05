/*这个调试程序用于调试力扣的全国高校春季赛中第三题。 决赛 
3. 最长重复子串
*/ 


#include <stdio.h>
int longestRepeatingSubstring(char* S);
int main()
{
	char S[10]="aaaaa";
	int a=longestRepeatingSubstring(S);
	printf("\n//%d//\n",a);
	return 1;
}

int longestRepeatingSubstring(char* S) {
    int len=0;
    int max=0;
    int i=0;
    for(i=0;S[i]!='\0';i++)
    {
    	printf("%c:%c:%d\n",S[i],S[i-1],len);
        if(i!=0&&S[i]==S[i-1])
            len++;
        if(i!=0&&S[i]!=S[i-1])
			len=0;	
		if(len>max)
		    max=len;
    }
    return max;
}
