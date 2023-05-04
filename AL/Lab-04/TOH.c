#include <stdio.h>

int Opcount = 0;

void TOH(int n, char src, char aux, char dest) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", src, dest);
        Opcount++;
        return;
    }
    TOH(n - 1, src, dest, aux);
    printf("Move disk %d from rod %c to rod %c\n", n, src, dest);
    TOH(n - 1, aux, src, dest);
    Opcount++;
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C');
    printf("Total number of operations: %d\n", Opcount);
    return 0;
}
