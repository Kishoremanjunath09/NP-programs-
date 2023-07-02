#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cout<<"enter number of frames";
    cin>>n;
    string str[n];
    int len;
    string leng,output;
    for(int i=0;i<n;i++)
    {
        cout<<"enter "<<i+1<<" frame bits";
        cin>>str[i];
        len=str[i].length();
        leng=to_string(len);
        output+=str[i]+leng;

    }
    cout<<"1000001-";
    cout<<output;
    cout<<"-1000001";
}
