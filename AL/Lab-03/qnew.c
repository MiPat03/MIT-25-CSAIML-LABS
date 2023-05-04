#include <stdio.h>
#include <string.h>

int main() {
    char s1[50], s2[50];
    int i, flag = 1, opCount = 0;
    printf("Enter string 1 ");
    scanf("%s",s1);
    printf("Enter string 2 ");
    scanf("%s",s2);
    for (i=0; i < strlen(s1); i++)
        opCount++;
        if (s1[i] != s2[i]) 
            flag = 0;
    if (flag)
        printf("Strings are equal");
    else
        printf("Strings are not equal");
    printf("\nOpCount is %d",opCount);
}