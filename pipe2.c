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

read(pipedes[0], readmessage, sizeof(readmessage));
printf("the read message is %s\n",readmessage);
read(pipedes[0],reads,sizeof(reads));
printf("the read message is %s\n",reads);
read(pipedes[0],reads,sizeof(reads));
printf("the read message is %s\n",reads);
read(pipedes[0],reads,sizeof(reads));
printf("the read message is %s\n",reads);
close(pipedes[0]);
}
else{
close(pipedes[0]);

write(pipedes[1],writes[0],sizeof(writes[0]));
printf("The message %d is written\n",0);

write(pipedes[1],writes[1],sizeof(writes[1]));
printf("The message %d is written\n",1);
write(pipedes[1],writes[2],sizeof(writes[2]));
printf("The message %d is written\n",2);
write(pipedes[1],writes[3],sizeof(writes[3]));
printf("The message %d is written\n",3);
close(pipedes[1]);
}


}
