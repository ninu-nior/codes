#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int find_use(int ref[],int ind,int curr,int n){
for(int i = ind + 1; i < n; i++) {
if(ref[i]==curr){
return i;}
}
return n+1;
}

int max_index(int arr[]){
    int max_index = 0; // Initialize max_index to the index of the first element
    int max = arr[0];  // Initialize max to the value of the first element
    for(int i = 1; i < 3; i++){ // Start from the second element
        if(arr[i] > max){
            max_index = i;  // Update max_index if a larger value is found
            max = arr[i];   // Update max value
        }
    }
    return max_index;
}
int already_present(int frame[],int curr){
for(int i=0;i<3;i++){
if(frame[i]==curr){
return 1;}
}
return 0;
}

int check_least_empty(int frame[]){
for(int i=0;i<3;i++){
if(frame[i]==-1){
return i;}
}
return -1;
}
int main(){
int ref[22]={ 7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
int n=3;
int ind=0;
int hits=0,faults=0;
int frame[3]={-1,-1,-1};
for(int i=0;i<22;i++){
int curr=ref[i];
if(already_present(frame,curr)==1){
hits+=1;
}
else{
faults+=1;
if(check_least_empty(frame)!=-1){
int m=check_least_empty( frame);
frame[m]=curr;
}
else{
int arr[3] = {find_use(ref, i, frame[0], 22), find_use(ref, i, frame[1], 22), find_use(ref, i, frame[2], 22)};
int m= max_index(arr);
frame[m]=curr;
}}
printf("%d %d %d %d\n",curr,frame[0],frame[1],frame[2]);

}
}
