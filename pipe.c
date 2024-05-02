#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
int pipedes[2];
int returnstatus=pipe(pipedes);
if(returnstatus==-1){
printf("failed to create the pipe");
return 1;
}
char writes[2][20]={"hello","World"};
char reads[20];

printf("Writing the message %s",writes[0]);
write(pipedes[1],writes[0],sizeof(writes[0]));

read(pipedes[0],reads,sizeof(reads));
printf("the message read from pipe %s",reads);

printf("Writing the message %s",writes[1]);
write(pipedes[1],writes[0],sizeof(writes[1]));

read(pipedes[0],reads,sizeof(reads));
printf("the message read from pipe %s",reads);

}
