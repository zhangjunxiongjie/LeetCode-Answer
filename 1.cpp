/*这个程序用于调试力扣题库中的： 17. 电话号码的字母组合
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char at[100][100];
 
char** letterCombinations(char* digits, int* returnSize);
 
int main()
{
	char digits[20]="3459";
	int returnSize,i;
	char** hear=letterCombinations(digits, &returnSize);
	for(i=0;i<returnSize;i++)
	{
		printf("%s\n",hear[i]);
	}
	
	return 0;
}


char Char(char ch,int it)
{
    switch (ch)
    {
        case '2':
        {
            switch (it)
            {
                case 0: return 'a';
                case 1: return 'b';
                case 2: return 'c';
            }
        }
        case '3':
        {    
            switch (it)
            {
                case 0: return 'd';
                case 1: return 'e';
                case 2: return 'f';
            }
        }
        case '4':
        {
            switch (it)
            {
                case 0: return 'g';
                case 1: return 'h';
                case 2: return 'i';
            }
        }
        case '5':
        {    
            switch (it)
            {
                case 0: return 'j';
                case 1: return 'k';
                case 2: return 'l';
            }
        }
        case '6':
        {
            switch (it)
            {
                case 0: return 'm';
                case 1: return 'n';
                case 2: return 'o';
            }
        }
        case '7':
        {    
            switch (it)
            {
                case 0: return 'p';
                case 1: return 'q';
                case 2: return 'r';
                case 3: return 's';
            }
        }
        case '8':
        {
            switch (it)
            {
                case 0: return 't';
                case 1: return 'u';
                case 2: return 'v';
            }
        }
        case '9':
        {    
            switch (it)
            {
                case 0: return 'w';
                case 1: return 'x';
                case 2: return 'y';
                case 3: return 'z';
            }
        }
    }
    return '1';
} 

char** letterCombinations(char* digits, int* returnSize) {
	int numt;
	 
    char **at=(char**)malloc(sizeof(char*)*1000);
    int j,z;
    int i,num=1,numr=1;
    for(i=0;i<1000;i++)
    {
        at[i]=(char*)malloc(sizeof(char)*20);
        memset(at[i],0,sizeof(char)*20);
    }
    for(i=0;digits[i]!='\0';i++)
    {
        if(digits[i]=='9'||digits[i]=='7')
            numr*=4;
        else
            numr*=3;
    }
    numt=i;
    *returnSize=numr;
    for(i=0;digits[i]!='\0';i++)
    {
        if(digits[i]!='9'&&digits[i-1]!='7')
            numr/=3;//内循环
        else
            numr/=4;
        if(digits[i]=='9'||digits[i]=='7')
            num*=4;//外循环
        else
            num*=3;
        for(j=0;j<num;j++)
        {
            for(z=j*numr;z<(j+1)*numr;z++)
            {
                if(digits[i]!='7'&&digits[i]!='9')
                	at[z][i]=Char(digits[i],j%3);
                else
                	at[z][i]=Char(digits[i],j%4);
            }
        }
    }
    for(i=0;i<numr;i++)
    {
        at[i][numt]='\0';
    }
    
    return at;
}

