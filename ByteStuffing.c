#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    printf("enter number of frames");
    scanf("%d", &n);
    char str[n][100];
    int len;
    char leng[10], output[1000];
    for(int i=0; i<n; i++)
    {
        printf("enter %d frame bits", i+1);
        scanf("%s", str[i]);
        len = strlen(str[i]);
        sprintf(leng, "%d", len);
        strcat(output, str[i]);
        strcat(output, leng);
    }
    printf("1000001-");
    printf("%s", output);
    printf("-1000001");
    return 0;
}
