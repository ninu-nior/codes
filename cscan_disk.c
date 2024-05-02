#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
int n, mov = 0, cp, index[50], min, a[50], j = 0, mini, cp1;
printf("Enter the current position:\n");
scanf("%d", &cp);
printf("Enter the number of requests:\n");
scanf("%d", &n);
int *req = (int *)malloc(n * sizeof(int));
cp1 = cp;
printf("Enter the request order:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &req[i]);
}
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (req[i] > req[j]) {
int temp = req[i];
req[i] = req[j];
req[j] = temp;
}
}
}
int index_cp = 0;
for (int i = 0; i < n; i++) {
if (cp < req[i]) {
index_cp = i;
break;
}
}
for (int i = index_cp; i < n; i++) {
a[j++] = req[i];
mov += abs(cp - req[i]);
cp = req[i];
}
if (index_cp > 0) {
mov += (199 - cp);
cp = 199;
for (int i = 0; i < index_cp; i++) {
a[j++] = req[i];
mov += abs(cp - req[i]);
cp = req[i];
}
} else {
mov += cp;
cp = 0;
for (int i = n - 1; i >= 0; i--) {
a[j++] = req[i];
mov += abs(cp - req[i]);
cp = req[i];
}
}
printf("Sequence is: ");
for (int i = 0; i < n; i++) {
printf("%d", a[i]);
if (i < n - 1) printf(" -> ");
}
printf("\n");
printf("Total head movement = %d\n", mov);
free(req);
return 0;
}
