#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
int n, mov = 0, cp, index[50], min, a[50], j = 0, mini, cp1;
printf("Enter the current position:\n");
scanf("%d", &cp);
printf("Enter the number of requests:\n");
scanf("%d", &n);
int req[n];
cp1 = cp;
printf("Enter the request order:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &req[i]);
}
for (int k = 0; k < n; k++) {
for (int i = 0; i < n; i++) {
index[i] = abs(cp - req[i]);
}
min = index[0];
mini = 0;
for (int i = 1; i < n; i++) {
if (min > index[i]) {
min = index[i];
mini = i;
}
}
a[j] = req[mini];
j++;
cp = req[mini];
req[mini] = 999;
}
printf("Sequence is : ");
printf("%d", cp1);
mov = mov + abs(cp1 - a[0]);
printf(" -> %d", a[0]);
for (int i = 1; i < n; i++) {
mov = mov + abs(a[i] - a[i - 1]);
printf(" -> %d", a[i]);
}
printf("\n");
printf("Total head movement = %d\n", mov);
}
