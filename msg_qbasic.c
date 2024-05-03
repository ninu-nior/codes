#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int msgget(key_t key, int msgflg)
int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg)
int msgrcv(int msgid, const void *msgp, size_t msgsz,
long msgtype, int msgflg)
int msgctl(int msgid, int cmd, struct msqid_ds *buf)
Where :
key : recognizes the message queue
msgflg : IPC_CREAT, IPC_EXCL (Error if Exists)
IPC_NOWAIT, MSG_NOERROR
msqid : recognizes the message queue
msgp : is the pointer to the message defined as below
struct msgbuf {
long mtype;
char mtext[1];
};
Dr. Pradeep K V CSE1004 - Network Programming 51/ 101
Message Queues IV
msgsz : size of the messages
msgtype :
0(Reads the first received message in the queue_
+Ve(Reads the first message in the queue of type msgtype)
-Ve(Reads the first message of lowest type )
cmd : IPC_STAT, IPC_SET, IPC_RMID, IPC_INFO, MSG_INFO
