#include <stdio.h>
#include <string.h>

int bruteForce(char s1[], char s2[], int* opCount)
{
    int n = strlen(s1);
    int m = strlen(s2);
    // int Count = 0;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            *opCount+=1;

            if (s1[i + j] != s2[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

int main()
{
    char s1[50], s2[50];
    int opCount = 0;
    printf("Enter string 1: ");
    scanf("%s",s1);
    printf("Enter string 2: ");
    scanf("%s",s2);
    int result = bruteForce(s1,s2,&opCount);
    if (result == -1) {
        printf("Strint not matched!\n");
    } else {
        printf("String matched at %d\n", result);
    }
    printf("OpCount is %d",opCount);
    return 0;
}
    