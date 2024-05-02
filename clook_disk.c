#include <stdio.h>
#include <stdlib.h>
int main() {
int i, n, req[50], mov = 0, cp, index[50], min, a[50], j = 0, mini, cp1;
printf("Enter the current position: ");
scanf("%d", &cp);
printf("Enter the number of requests: ");
scanf("%d", &n);
cp1 = cp;
printf("Enter the request order:\n");
for (i = 0; i < n; i++) {
scanf("%d", &req[i]);
}
for (i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (req[j] > req[j + 1]) {
int temp = req[j];
req[j] = req[j + 1];
req[j + 1] = temp;
}
}
}
int next_index = 0;
for (i = 0; i < n; i++) {
if (req[i] > cp) {
next_index = i;
break;
}
}
for (i = next_index; i < n; i++) {
a[j] = req[i];
j++;
mov += abs(cp - req[i]);
cp = req[i];
}
for (i = 0; i < next_index; i++) {
a[j] = req[i];
j++;
mov += abs(cp - req[i]);
cp = req[i];
}
printf("Sequence is: %d", cp1);
for (i = 0; i < n; i++) {
printf(" -> %d", a[i]);
}
printf("\nTotal head movement = %d\n", mov);
return 0;
}
