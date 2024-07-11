#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

static int total_nodes;

// Prints subset found
void printSubset(int A[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%*d", 5, A[i]);
    }
    printf("\n");
}

// qsort compare function
int comparator(const void *pLhs, const void *pRhs) {
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;
    return (*lhs - *rhs);
}

// Inputs
// s - set vector
// t - tuplet vector
// s_size - set size
// t_size - tuplet size so far
// sum - sum so far
// ite - nodes count
// target_sum - sum to be found
void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
    total_nodes++;
    if(target_sum == sum) {
        // We found sum
        printSubset(t, t_size);
        // Constraint check
        if(ite + 1 < s_size && sum - s[ite] + s[ite+1] <= target_sum) {
            // Exclude previous added item and consider next candidate
            subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum);
        }
        return;
    } else {
        // Constraint check
        if(ite < s_size && sum + s[ite] <= target_sum) {
            // Generate nodes along the breadth
            for(int i = ite; i < s_size; i++) {
                t[t_size] = s[i];
                if(sum + s[i] <= target_sum) {
                    // Consider next level node (along depth)
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}

// Wrapper that prints subsets that sum to target_sum
void generateSubsets(int s[], int size, int target_sum) {
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
    int total = 0;
    // Sort the set
    qsort(s, size, sizeof(int), &comparator);
    for(int i = 0; i < size; i++) {
        total += s[i];
    }
    if(s[0] <= target_sum && total >= target_sum) {
        subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    }
    free(tuplet_vector);
}

int main() {
    int n, target;
    
    printf("Enter the number of weights: ");
    scanf("%d", &n);
    
    int *weights = (int *)malloc(n * sizeof(int));
    
    printf("Enter the weights: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    printf("Enter the target sum: ");
    scanf("%d", &target);
    
    generateSubsets(weights, n, target);
    
    printf("Nodes generated: %d\n", total_nodes);
    
    free(weights);
    
    return 0;
}
