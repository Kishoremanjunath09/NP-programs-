//leakybucket
#include <stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x
int main()
{
    int orate,n,i=0,sum=0,x,cap;
    int condition;
    //printf("ente the bucket size:");
    //scanf("%d",&n);
    printf("enter the capacity:");
    scanf("%d",&cap);
    printf("enter the output rate:");
    scanf("%d",&orate);
    
    int input[15];
    do{
        printf("enter the packets coming in at %d :",i+1);
        scanf("%d",&input[i]);
        sum+=input[i];
        if(input[i]>cap){
            printf("bucket overflow");
            exit(0);
        }
        i++;
        printf("enter 1 to continue/ 0 to end ");
        scanf("%d",&condition);
    }
    while(condition);
    
    int nsec=i,remain=0,discard=0;
    printf("sec\t\t incoming\t\t out \t\t remain\t\t discard\n");
    for(int i=0;remain||i<nsec;i++){
        printf("%d",i+1);
        printf("\t\t%d",input[i]);
        printf("\t\t\t\t%d",MIN((input[i]+remain),orate));
        if((x=input[i]+remain-orate)>0){
            if(x>cap){
                remain=cap;
                discard=x-cap;
            }
            else{
                remain=x;
                discard=0;
            }
        }
        else{
            remain=0;
            discard=0;
        }
        printf("\t%d\t\t%d\n",remain,discard);
    }

    return 0;
}
