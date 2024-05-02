#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
int n, m = 0, cp, a[50], j = 0, d;
printf("Enter the current position:\n");
scanf("%d", &cp);
int c = cp;
printf("Enter the number of requests:\n");
scanf("%d", &n);
int r[n];
printf("Enter the request order:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &r[i]);
}
printf("Enter the direction (0 for left, 1 for right):\n");
scanf("%d", &d);
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (r[i] > r[j]) {
int t = r[i];
r[i] = r[j];
r[j] = t;
}
}
}
int s = 0;
if (d == 0) {
for (int i = 0; i < n; i++) {
if (cp < r[i]) {
s = i - 1;
break;
}
}
for (int i = s; i >= 0; i--) {
a[j++] = r[i];
m += abs(cp - r[i]);
cp = r[i];
}
m += cp;
cp = 0;
for (int i = s + 1; i < n; i++) {
a[j++] = r[i];
m += abs(cp - r[i]);
cp = r[i];
}
} else {
for (int i = 0; i < n; i++) {
if (cp < r[i]) {
s = i;
break;
}
}
for (int i = s; i < n; i++) {
a[j++] = r[i];
m += abs(cp - r[i]);
cp = r[i];
}
m += (199 - cp);
cp = 199;
for (int i = s - 1; i >= 0; i--) {
a[j++] = r[i];
m += abs(cp - r[i]);
cp = r[i];
}
}
printf("Sequence is: %d -> ", c);
for (int i = 0; i < n; i++) {
printf("%d", a[i]);
if (i < n - 1) printf(" -> ");
}
printf("\n");
printf("Total head movement = %d\n", m);
return 0;
}
