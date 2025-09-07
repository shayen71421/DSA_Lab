#include <stdio.h>
int main() {
    int n, key, i, flag = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("Element not found\n");
    return 0;
}
