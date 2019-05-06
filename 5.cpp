//力扣	28.实现strStr() 
//已通过 

#include <stdio.h>

int strStr(char * haystack, char * needle){
    int it,itr,i=0;
    if(needle[0]=='\0') 
        return 0;
    for(it=0;haystack[it]!='\0';it++)
        if(haystack[it]==needle[i])
        {
        	printf("%d:%c:\n",it,needle[i]);
            if(i==0)
                itr=it;
            i++;
            if(needle[i]=='\0')
                break;
        }
        else
        {
            if(i!=0)
            {
			    it=itr;
            	printf("%d:%c:\n",it,haystack[it]);
            }
			i=0;
        }    
    if(needle[i]=='\0')
        return itr;
    else
        return -1;
}

int main()
{
	strStr("mississippi","pi");
	return 0;
}
