/* Filename: msgq_send.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0644
Dr. Pradeep K V CSE1004 - Network Programming 52/ 101
Message Queues V
struct my_msgbuf {
long mtype;
char mtext[200];
};
int main(void) {
struct my_msgbuf buf;
int msqid, len;
key_t key;
system("touch msgq.txt");
if ((key = ftok("msgq.txt", 'B')) == -1) {
perror("ftok");
exit(1);
}
if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1) {
perror("msgget");
exit(1);
}
Dr. Pradeep K V CSE1004 - Network Programming 53/ 101
Message Queues VI
printf("message queue: ready to send messages.\n");
printf("Enter lines of text, ^D to quit:\n");
buf.mtype = 1; /* we don't really care in this case */
while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
len = strlen(buf.mtext);
/* remove newline at end, if it exists */
if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';
if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
perror("msgsnd");
}
strcpy(buf.mtext, "end");
len = strlen(buf.mtext);
if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
perror("msgsnd");
if (msgctl(msqid, IPC_RMID, NULL) == -1) {
perror("msgctl");
exit(1);
}
Dr. Pradeep K V CSE1004 - Network Programming 54/ 101
Message Queues VII
printf("message queue: done sending messages.\n");
return 0;
}
/* Filename: msgq_recv.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PERMS 0644
struct my_msgbuf {
long mtype;
char mtext[200];
};
Dr. Pradeep K V CSE1004 - Network Programming 55/ 101
Message Queues VIII
int main(void) {
struct my_msgbuf buf;
int msqid;
int toend;
key_t key;
if ((key = ftok("msgq.txt", 'B')) == -1) {
perror("ftok");
exit(1);
}
if ((msqid = msgget(key, PERMS)) == -1) {
/* connect to the queue */
perror("msgget");
exit(1);
}
printf("message queue: ready to receive messages.\n");
Dr. Pradeep K V CSE1004 - Network Programming 56/ 101
Message Queues IX
for(;;) {
/* normally receiving never ends but just to make conclusion
/* this program ends wuth string of end */
if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1) {
perror("msgrcv");
exit(1);
}
printf("recvd: \"%s\"\n", buf.mtext);
toend = strcmp(buf.mtext,"end");
if (toend == 0)
break;
}
printf("message queue: done receiving messages.\n");
system("rm msgq.txt");
return 0;
}
