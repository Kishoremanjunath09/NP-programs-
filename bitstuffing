#include <iostream>
using namespace std;
void unstuffing(int arr[],int N)
{
     int op[30];
     int i=0,j=0,k=0;
     int count=1;
     while(i<N)
     {
         if(arr[i]==0)
         {
             op[j] = arr[i];
             for(int k=i+1;k<N&&arr[k]==1 && count<=5;k++)
             {
                 op[++j]=arr[k];
                 count++;
                 if(count==5)
                 {
                     k++;
                 }
                 i=k;
             }
         }
         else{
             op[j] = arr[i];
         }
         i++;
         j++;
     }
     cout<<"Reciver end: " ;
     for (int i = 0; i < j; i++)
        cout << op[i]<<"  ";
}
void bitStuffing(int N, int arr[])
{
     int op[30];
     int i=0,j=0,k=0;
     int count=0;
     while(i<N)
     {
         if(arr[i]==0)
         {
             op[j] = arr[i];
             count=0;
             
             for(int k=i+1;k<N&&arr[k]==1 && count<=5;k++)
             {
                 //k=6
                 op[++j]=arr[k];
                 count++;//6
                 if(count==5)  
                 {
                     op[++j]=0;
                 }
                 i=k;//i=6
             }
         }
         else{
             op[j] = arr[i];
         }
         i++;
         j++;
     }
     cout<<"Sender sent: "<<"0 1 1 1 1 1 1 0    ";
     for (int i = 0; i < j; i++)
        cout << op[i]<<"  ";
     cout<<"   0 1 1 1 1 1 1 0";
     cout<<endl;
     unstuffing(op,j);
}

int main()
{
   int bits;
   int arr[30];
   cout<<"Enter the data size in bits: ";
   cin>>bits;
   cout<<"Populate"<<endl;
   for(int i=0;i<bits;i++){
       cin>>arr[i];
   }
   bitStuffing(bits, arr);
   return 0;
}
