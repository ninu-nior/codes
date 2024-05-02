#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
char reads[20];
char writes[4][20]={"aadi","ninu","love","together"};
char readmessage[20];
int pid;
int pipedes[2];
int returnstatus=pipe(pipedes);
if(returnstatus==-1){
printf("pipe creation failed");
}
pid=fork();
if(pid==-1){
printf("process creation failed");
}
if(pid>0){
close(pipedes[1]);
for(int i=0;i<4;i++){
wait(10);
read(pipedes[0],reads,sizeof(reads));
printf("the read message is %s\n",reads);
}
close(pipedes[0]);
}
else{
close(pipedes[0]);
for(int i=0;i<4;i++){
write(pipedes[1],writes[i],sizeof(writes[i]));
printf("The message %d is written\n",i);
}

close(pipedes[1]);
}


}
