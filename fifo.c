#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int already_present(int frame[],int curr){
for(int i=0;i<3;i++){
if(frame[i]==curr){
return 1;}
}
return 0;
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
ind=ind%n;
frame[ind]=curr;
ind+=1;
}
printf("%d %d %d\n",frame[0],frame[1],frame[2]);

}
}
