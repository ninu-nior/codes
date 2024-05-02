#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void min_index_check(int bt[], int at[],int pr[], int time,int check[],int wt[],int tat[]){
int min_index=-1;
int min_value=99999;
for (int i=0;i<4;i++){
if(pr[i]<min_value && at[i]<=time && check[i]>0){
min_value=pr[i];
min_index=i;
}
}
check[min_index]-=1;
if(check[min_index]==0){
wt[min_index]=time-at[min_index];
tat[min_index]=wt[min_index]+bt[min_index];
}



}
int checker(int check[]){
for (int i=0;i<4;i++){
if (check[i]>0){
return 0;}
}
return 1;
}

int main(){
int bt[4]={2,5,3,4};
int at[4]={0,2,1,3};
int pr[4]={1,3,2,4};
int check[4]={2,5,3,4};
int n=4;
int wt[n];
int tat[n];
int min;
int time=0;
while (checker(check) == 0) {
min_index_check(bt,at,pr,time,check,wt,tat);
time+=1;

}

for (int i = 0; i < n; i++) {
    printf("%d %d %d %d %d %d\n", i, pr[i], bt[i], at[i], wt[i], tat[i]);
}

}
