//bit stuffing(encode and decode)
#include <stdio.h>
int data[100];

void bitstuffing(int arr[],int n){
    int array[20];
    int count1=0,k=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count1++;
            array[k]=arr[i];
            k++;
            if(count1==5 && arr[i-5]==0){
                array[k]=0;
                k++;
            }
        }
        else{
            count1=0;
            array[k]=arr[i];
            k++;
        }
    }
        for(int i=0;i<k;i++){
            data[i]=array[i];
        }
        printf("the bitstuffed data is :");
        for(int i=0;i<k;i++){
            printf("%d",data[i]);
        }
        printf("\n");
         
    
    
}

void bitunstuffing(int arr[],int n){
    int array[20];
    int count1=0,k=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count1++;
            array[k]=arr[i];
            k++;
            if(count1==5 &&arr[i-5]==0 && arr[i+1]==0){
                //array[k]=0;
                //k++
                i++;
            }
        }
        else{
            count1=0;
            array[k]=arr[i];
            k++;
        }
    }
        printf("the unbitstuffed data is :");
        for(int i=0;i<k;i++){
            printf("%d",array[i]);
        }
        printf("\n");
       
}

int main()
{
    int n;
    printf("enter the no of bits:");
    scanf("%d",&n);
    int data[n];
    printf("enter the data:");
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    bitstuffing(data,n);
    
    bitunstuffing(data,n);
    return 0;
}
