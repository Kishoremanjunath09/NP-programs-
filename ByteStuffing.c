
#include <stdio.h>
#include<string.h>
int main()
{
    int n,len=0;
    printf("enter the no of frames:");
    scanf("%d",&n);
    char str[n][100];
    char op[100]="", conv[100];
    for(int i=0;i<n;i++){
        printf("enter the frame %d",i+1);
        scanf("%s",str[i]);
        len=strlen(str[i]);
        sprintf(conv,"%d",len);
        strcat(op,str[i]);
        strcat(op,conv);
        
    }
    printf("the byte stuffed data is:\n");
    printf("10000001-");
    printf("%s",op);
    printf("-10000001");
    

    return 0;
}
