#include <stdio.h>
#include <stdlib.h>
int main() {
int i, n, r[50], m = 0, c, idx[50], min, a[50], j = 0, mini, c1;
printf("Enter the current position: ");
scanf("%d", &c);
printf("Enter the number of requests: ");
scanf("%d", &n);
c1 = c;
printf("Enter the request order:\n");
for (i = 0; i < n; i++) {
scanf("%d", &r[i]);
}
for (int k = 0; k < n; k++) {
for (i = 0; i < n; i++) {
idx[i] = abs(c - r[i]);
}
min = idx[0];
mini = 0;
for (i = 1; i < n; i++) {
if (min > idx[i]) {
min = idx[i];
mini = i;
}
}
a[j] = r[mini];
j++;
c = r[mini];
r[mini] = 999;
}
printf("Sequence is: %d", c1);
m += abs(c1 - a[0]);
printf(" -> %d", a[0]);
for (i = 1; i < n; i++) {
m += abs(a[i] - a[i - 1]);
printf(" -> %d", a[i]);
}
printf("\nTotal head movement = %d\n", m);
return 0;
}
