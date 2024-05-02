#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
int i, n, mov = 0, cp; 
printf("Enter the current position:\n");
scanf("%d", &cp);
printf("Enter the number of requests:\n");
scanf("%d", &n);
int req[n]; 
printf("Enter the request order:\n");
for (i = 0; i < n; i++) {
scanf("%d", &req[i]);
}
printf("The order is: ");
mov = mov + abs(cp - req[0]);
printf("%d -> %d", cp, req[0]);
for (i = 1; i < n; i++) {
mov = mov + abs(req[i] - req[i - 1]);
printf(" -> %d", req[i]);
}
printf("\n");
printf("Total head movement = %d\n", mov);
}
