#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* A knapsack item */
typedef struct {
    unsigned int id;
    double weight;
    double profit;
    double profit_density;
} item;

/* Compare items by lesser profit density */
static int compare_items(const item *item1, const item *item2) {
    if (item1->profit_density > item2->profit_density) {
        return -1;
    }
    if (item1->profit_density < item2->profit_density) {
        return 1;
    }
    return 0;
}

/* Bounding function */
static double profit_bound(const item *items, size_t n, double capacity, double current_weight, double current_profit, unsigned int level) {
    double remaining_capacity = capacity - current_weight;
    double bound = current_profit;
    unsigned int lvl = level;

    /* Fill in order of decreasing profit density */
    while (lvl < n && items[lvl].weight <= remaining_capacity) {
        remaining_capacity -= items[lvl].weight;
        bound += items[lvl].profit;
        lvl++;
    }

    /* Pretend we can take a fraction of the next object */
    if (lvl < n) {
        bound += items[lvl].profit_density * remaining_capacity;
    }
    return bound;
}

static void knapsack_recursive(const item *items, size_t n, double capacity, unsigned int *current_knapsack, double *current_weight, double *current_profit, unsigned int *max_knapsack, double *max_profit, unsigned int level) {
    if (level == n) {
        /* Found a new max knapsack */
        *max_profit = *current_profit;
        memcpy(max_knapsack, current_knapsack, n * sizeof(unsigned int));
        return;
    }

    if (*current_weight + items[level].weight <= capacity) { /* Try adding this item */
        *current_weight += items[level].weight;
        *current_profit += items[level].profit;
        current_knapsack[items[level].id] = 1;
        knapsack_recursive(items, n, capacity, current_knapsack, current_weight, current_profit, max_knapsack, max_profit, level + 1);
        *current_weight -= items[level].weight;
        *current_profit -= items[level].profit;
        current_knapsack[items[level].id] = 0;
    }

    if (profit_bound(items, n, capacity, *current_weight, *current_profit, level + 1) > *max_profit) { /* Still promising */
        knapsack_recursive(items, n, capacity, current_knapsack, current_weight, current_profit, max_knapsack, max_profit, level + 1);
    }
}

double knapsack(const double *weights, const double *profits, size_t n, double capacity, unsigned int **max_knapsack) {
    double current_weight = 0.0;
    double current_profit = 0.0;
    double max_profit = 0.0;
    unsigned int i;
    item *items = malloc(n * sizeof(item));
    unsigned int *current_knapsack = calloc(n, sizeof(unsigned int));
    *max_knapsack = malloc(n * sizeof(unsigned int));

    if (!(items && current_knapsack && *max_knapsack)) {
        free(items);
        free(current_knapsack);
        free(*max_knapsack);
        *max_knapsack = NULL;
        return 0;
    }

    /* Populate the array of items */
    for (i = 0; i < n; i++) {
        items[i].id = i;
        items[i].weight = weights[i];
        items[i].profit = profits[i];
        items[i].profit_density = profits[i] / weights[i];
    }

    /* Sort into decreasing density order */
    qsort(items, n, sizeof(item), (int (*)(const void *, const void *))compare_items);
    knapsack_recursive(items, n, capacity, current_knapsack, &current_weight, &current_profit, *max_knapsack, &max_profit, 0);

    free(items);
    free(current_knapsack);
    return max_profit;
}

int main(void) {
    size_t n;
    double capacity;

    printf("Enter the number of items: ");
    scanf("%zu", &n);

    double *weights = malloc(n * sizeof(double));
    double *profits = malloc(n * sizeof(double));
    unsigned int *max_knapsack;

    printf("Enter the weights of the items: ");
    for (size_t i = 0; i < n; i++) {
        scanf("%lf", &weights[i]);
    }

    printf("Enter the profits of the items: ");
    for (size_t i = 0; i < n; i++) {
        scanf("%lf", &profits[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);

    double max_profit = knapsack(weights, profits, n, capacity, &max_knapsack);

    printf("Profit: %.2f\n", max_profit);
    printf("Knapsack contains:\n");
    for (size_t i = 0; i < n; i++) {
        if (max_knapsack[i] == 1) {
            printf("Item %zu with weight %.2f and profit %.2f\n", i, weights[i], profits[i]);
        }
    }

    free(weights);
    free(profits);
    free(max_knapsack);

    return 0;
}
