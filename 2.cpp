/*这个调试程序用于调试力扣的全国高校春季赛中第二题。 决赛 
*/
//已通过 

#include <stdio.h> 

void smallestEquivalentString(char* A, char* B, char* S);
int main()
{
	char A[1001]="adbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbccadbbebbcaaeceeacbbceaeccccccbeacbaeeadaacedceadcaaaabcbddbeaddbadedeaadabebeacccbcccaabbeabebceacbcc";
	char B[1001]="cbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaebcbbeedbbeadeddbceedaabcdbbebbaadddddcccdabbcbeaccdbabdaeacdcacedacbccbaecaeebacdbbdaaebbcaaccebceaeb";
	char S[1001]="rzzyvxvbenbojcppowyrsjmqqxahywusqtggjefrenmtdcvnxdyyhdftmcbpywadqpjlqogebvzzaadbdejshxuehuqhrvupdehverrneudyoearlmkfpyedximlemulsmlucepiebagrfxrugxxlozchxiskbbnsdjsugrweamsbtgewgbnfkylgdncatnzymseulqemhcxgbodalkwqwigslknplephmznvoqmadpvythgbfnasowlmpdhonyodsqnpuspdhvqqhlrrdolzhfbfkdmcgjdkpwcevdtnxvtwnnlrjwbjhjbaeggfronzkmphkupwzzcqeoremstlfrrfmcxvkvetygtilyyoelwbbsrmxgepauftrljvfhohdokbgtienoubivykjqqbsdhzynmdmvkqvkuhrefjvmfwhtnbaxryctvryvauvnpilafaqosoayornjsxmkasfkzogrbqugoctbqspgghbhcsbqdtszndvzmkxpernffzgnkrolrtgqkxxyhmljamefneulvmlvwnkotlpjyngujlvfptfxtvkfcbsqwpnhszymvfydfhdzmozxtesdqerennkwcetgummcbqnwjiaelmyhyopolumbuuvxorcjegpedksbjxqvfeamdwjephufvbituwwsscibxfbjvoqyaiayaqnamfbwywyuwquobnqkxlyvwatnemkjfzvxouyykttmpqqkwxiolngmoumfaapolgiqtvqxhpafhyhzwpvkjnzofqystzvhptulaonuwhyucwvxzsqwhzuoozofjpgzltgfsdunuxonzukvvmgttstrcatfmqqdcdmynbnjxwaydigbpomdhmztgqkrjzndoxfuykwjcdbugpbfstostjobynuukuzcvuijtyhkpenfadlhytkwdnyqsgtejlsjzhcrieknnwfkiaochfzakpxrxemkxxulojmdkcdzhsaiazacbwtcavclm";
	smallestEquivalentString(A,B,S);
	return 1;
}

void smallestEquivalentString(char* A, char* B, char* S) {
    int it,i,j,len=0;
    char a[1000],ch;
    char at[26][2002];  
	int atr[26];  
    int flag=0;
    int ir=0,jr=0,flag1=0,flag2=0;
    for(i=0;i<26;i++)
		for(j=0;j<26;j++)
			at[i][j]='\0'; 
    for(it=0;it<26;it++)
        atr[it]=0;
    
    for(it=0;A[it]!='\0';it++)
    {
        if(A[it]==B[it])
        {
            for(i=0;i<len;i++)
            {
                for(j=0;j<atr[i];j++)
                {
                    if(at[i][j]==A[it])
                    {
                        flag=1;
                        break;
                    }    
                }
            }
            if(flag==0)
            {    
                at[len][atr[len]]=A[it];
                
                atr[len]++;
                len++;
            }
            else
                flag=0;
        }
        else
        {
            for(i=0;i<len;i++)
            {
                for(j=0;j<atr[i];j++)
                {
                    if(flag1==0&&at[i][j]==A[it])
                    {    
                        flag1=1;
                        ir=i;
                    }
                    if(flag2==0&&at[i][j]==B[it])
                    {    
                        flag2=1;
                        jr=i;
                    }
                    
                }
            }
            
            if(flag1&&flag2==0)
            {    
            	//printf("1:%c\n",B[it]);
                at[ir][atr[ir]]=B[it];
                atr[ir]++;
                flag1=0;
            }
            else if(flag1==0&&flag2)
            {
            	//printf("2:%c:%s:%d\n",A[it],at[jr],jr); 
                at[jr][atr[jr]]=A[it];
                atr[jr]++;
                flag2=0;
            }
            else if(flag1&&flag2)
            {
            	if(ir<jr)
            	{
            		for(i=0;i<atr[jr];i++)
            		{
            			at[ir][atr[ir]]=at[jr][i];
            			atr[ir]++;
					}
				}
            	if(ir>jr)
	        	{
            		for(i=0;i<atr[ir];i++)
            		{
            			at[jr][atr[jr]]=at[ir][i];
            			atr[jr]++;
					}
				}
                flag1=0;
                flag2=0;
            }
            else if(flag1==0&&flag2==0)
            {
            	
                at[len][atr[len]]=A[it];
                atr[len]++;
                at[len][atr[len]]=B[it];
                atr[len]++;
                len++;
            }
            
        }
        //printf("%c\n",A[it]);
    }
    for(i=0;S[i]!='\0';i++)
    {
		for(j=0;j<len;j++)
		{
			for(it=0;it<atr[j];it++)
				if(at[j][it]==S[i])
					break;
			if(it!=atr[j])
				break;	
		}
		ch=S[i];    	
		for(it=0;it<atr[j];it++)
			if(ch>at[j][it])
				ch=at[j][it];
		a[i]=ch;
	}
	a[i]='\0';
    for(i=0;i<len;i++)
		printf("%s//\n",at[i]);
	printf("\n%s\n",a);
}
