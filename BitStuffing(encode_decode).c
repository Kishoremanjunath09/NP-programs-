#include <stdio.h>

void bitStuffing(int arr[], int n)
{
    int count1 = 0;// to count no of 1's
    int k = 0;//new array index
    int array[20];//new output(stuffed) array

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count1++;
            array[k] = arr[i];
            k++;
            //if a zero is followed by 5 1's then append 0 -->bit stuffing
            if (count1 == 5 && arr[i - 5] == 0)
            {
                array[k] = 0;
                k++;
            }
        }
        else
        {
            count1 = 0;
            array[k] = arr[i];
            k++;
        }
    }

    printf("Bit-stuffed array: ");
    for (int a = 0; a < k; a++)
    {
        printf("%d ", array[a]);
    }
    printf("\n");
}

void bitUnstuffing(int arr[], int n)
{
    int count1 = 0;
    int k = 0;
    int array[20];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count1++;
            array[k] = arr[i];
            k++;
            //if a zero is followed by 5 1's, skip the appended 0 -->bit unstuffing
            if (count1 == 5 && arr[i-5]==0 && arr[i + 1] == 0)
            {
                i++;
            }
        }
        else
        {
            count1 = 0;
            array[k] = arr[i];
            k++;
        }
    }

    printf("Bit-unstuffed array: ");
    for (int a = 0; a < k; a++)
    {
        printf("%d ", array[a]);
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Enter the size of the bit string to be sent: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the bit string of length %d: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bitStuffing(arr, n);//encoding
    printf("----------------------------------------------------------------\n");
    bitUnstuffing(arr, n);//decoding

    return 0;
}
