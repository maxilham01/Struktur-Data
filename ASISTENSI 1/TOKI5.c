#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int w[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    int total = 0;
    int left_max = 0, right_max = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (w[left] <= w[right]) {
            if (w[left] >= left_max) {
                left_max = w[left];
            } else {
                total += left_max - w[left];
            }
            left++;
        } else {
            if (w[right] >= right_max) {
                right_max = w[right];
            } else {
                total += right_max - w[right];
            }
            right--;
        }
    }
    printf("%d\n", total);
    return 0;
}
