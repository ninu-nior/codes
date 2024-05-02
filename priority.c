#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int min_index_check(int bt[], int at[],int pr[], int time,int check[]){
int min_index=-1;
int min_value=99999;
for (int i=0;i<4;i++){
if(pr[i]<min_value && at[i]<=time && check[i]==-1){
min_value=pr[i];
min_index=i;
}
}
return min_index;


}
int checker(int check[]){
for (int i=0;i<4;i++){
if (check[i]==-1){
return 0;}
}
return 1;
}

int main(){
int bt[4]={2,5,3,4};
int at[4]={0,2,1,3};
int pr[4]={1,3,2,4};
int check[4]={-1,-1,-1,-1};
int n=4;
int wt[n];
int tat[n];
int min;
int time=0;
while (checker(check) == 0) {
    min = min_index_check(bt, at, pr, time, check);
    if (min == -1) {
        time++; // No process available, increment time to the next arrival
    } else {
        time = (at[min] > time) ? at[min] : time; // Ensure time progresses to the arrival time of the next process
        check[min] = 1; // Mark the process as checked
        wt[min] = time - at[min];
        tat[min] = wt[min] + bt[min];
        time += bt[min]; // Update time after the process completion
    }
}

for (int i = 0; i < n; i++) {
    printf("%d %d %d %d %d %d\n", i, pr[i], bt[i], at[i], wt[i], tat[i]);
}

}

