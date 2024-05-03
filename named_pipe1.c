/* Filename: fifoserver.c */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FIFO_FILE "MYFIFO"
int main() {
int fd;
char readbuf[80], end[10];
int to_end, read_bytes;
Dr. Pradeep K V CSE1004 - Network Programming 26/ 101
IPC - Named Pipes / FIFOS VI
/* Create the FIFO if it does not exist */
mknod(FIFO_FILE, S_IFIFO|0640, 0);
strcpy(end, "end");
while(1) {
fd = open(FIFO_FILE, O_RDONLY);
read_bytes = read(fd, readbuf, sizeof(readbuf));
readbuf[read_bytes] = '\0';
printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
to_end = strcmp(readbuf, end);
if (to_end == 0) {
close(fd);
break;
}
}
return 0;
}
Dr. Pradeep K V CSE1004 - Network Programming 27/ 101
IPC - Named Pipes / FIFOS VII
/* Filename: fifoclient.c */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FIFO_FILE "MYFIFO"
int main() {
int fd, end_process;
int stringlen;
char readbuf[80];
char end_str[5];
printf("FIFO_CLIENT: Send messages, infinitely,"
"to end enter \"end\"\n");
fd = open(FIFO_FILE, O_CREAT|O_WRONLY);
strcpy(end_str, "end");
Dr. Pradeep K V CSE1004 - Network Programming 28/ 101
IPC - Named Pipes / FIFOS VIII
while (1) {
printf("Enter string: ");
fgets(readbuf, sizeof(readbuf), stdin);
stringlen = strlen(readbuf);
readbuf[stringlen - 1] = '\0';
end_process = strcmp(readbuf, end_str);
//printf("end_process is %d\n", end_process);
if (end_process != 0) {
write(fd, readbuf, strlen(readbuf));
printf("Sent string: \"%s\" and string length is %d\n",
readbuf, (int)strlen(readbuf));
} else {
write(fd, readbuf, strlen(readbuf));
printf("Sent string: \"%s\" and string length is %d\n",
readbuf, (int)strlen(readbuf));
close(fd); break;
}
}
return 0;
}
