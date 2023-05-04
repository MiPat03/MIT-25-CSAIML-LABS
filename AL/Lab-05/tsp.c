#include <stdio.h>
#define MAX_JOBS 10
#define MAX_COST 100

int jobs[MAX_JOBS][MAX_JOBS];
int n;
int opcount = 0;

void assign(int* worker, int* assigned, int* min_cost, int* min_assigned){
    if (*worker == n) {
        int cost = 0;
        for (int i = 0; i < n; i++) {
            opcount++;
            cost += jobs[i][assigned[i]];
        }
        if (cost < *min_cost) {
            *min_cost = cost;
            for (int i = 0; i < n; i++)
                min_assigned[i] = assigned[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (assigned[i] == -1) {
                assigned[i] = *worker;
                (*worker)++;
                assign(worker, assigned, min_cost, min_assigned);
                (*worker)--;
                assigned[i] = -1;
            }
        }
    }
}

int main(){
    printf("Enter the no of jobs and workers: ", MAX_JOBS);
    scanf("%d", &n);

    printf("Enter the cost matrix:\n", MAX_COST);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &jobs[i][j]);

    int worker = 0;
    int assigned[MAX_JOBS];
    int min_cost = MAX_COST * n;
    int min_assigned[MAX_JOBS];
    for (int i = 0; i < n; i++) {
        assigned[i] = -1;
        min_assigned[i] = -1;
    }

    assign(&worker, assigned, &min_cost, min_assigned);

    printf("Assignment is:\n");
    for (int i = 0; i < n; i++) {
        printf("Worker %d assigned to job %d\n", i+1, min_assigned[i]+1);
    }
    printf("Minimum cost is %d\n", min_cost);
    printf("Opcount: %d\n",opcount);
    return 0;
}