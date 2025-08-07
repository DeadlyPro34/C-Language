#include <stdio.h>
#include<stdlib.h>
int main() {
    int i, n;
    int *arr1, *arr2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // malloc
    arr1 = (int *)malloc(n * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }
    printf("\nEnter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Values added using malloc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    // calloc
    arr2 = (int *)calloc(n, sizeof(int));
    if (arr2 == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }
    printf("\nValues using calloc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    free(arr1);
    free(arr2);
    return 0;
}
