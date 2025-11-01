#include <stdio.h>
int main() {
    int n, search, c, first, last, middle;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d integers\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    printf("Enter value to find\n");
    scanf("%d", &search);
    first = 0;
    last = n - 1;
    middle = (first + last)/2;
    while (first <= last) {
        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search) {
    printf("%d found at index %d\n", search, middle);
    break;
        }
         else
            last = middle - 1;
        middle = (first + last)/2;
    }
    if (first > last)
        printf("Not found! %d isn't present in the list.\n", search);
    return 0;
}
