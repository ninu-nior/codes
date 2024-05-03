/* Filename: fifoserver.c */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FIFO_FILE "/tmp/fifo_twoway"
void reverse_string(char *);
int main() {
char readbuf[80], end[10];
int to_end, fd, read_bytes;
/* Create the FIFO if it does not exist */
mkfifo(FIFO_FILE, S_IFIFO|0640);
strcpy(end, "end");
Dr. Pradeep K V CSE1004 - Network Programming 32/ 101
IPC - Named Pipes / FIFOS XII
fd = open(FIFO_FILE, O_RDWR);
while(1) {
read_bytes = read(fd, readbuf, sizeof(readbuf));
readbuf[read_bytes] = '\0';
printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
to_end = strcmp(readbuf, end);
if (to_end == 0) { close(fd); break; }
reverse_string(readbuf);
printf("FIFOSERVER: Sending Reversed String: \"%s\"
" and length is %d\n", readbuf, (int) strlen(readbuf));
write(fd, readbuf, strlen(readbuf));
/* sleep - This is to make sure other process reads this,
* otherwise this process would retrieve the message */
sleep(2);
}
return 0;
}
void reverse_string(char *str) {
int last, limit, first;
Dr. Pradeep K V CSE1004 - Network Programming 33/ 101
IPC - Named Pipes / FIFOS XIII
char temp;
last = strlen(str) - 1; limit = last/2; first = 0;
while (first < last) {
temp = str[first]; str[first] = str[last];
str[last] = temp; first++;
last--;
}
return;
}
/* Filename: fifoclient.c */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FIFO_FILE "/tmp/fifo_twoway"
Dr. Pradeep K V CSE1004 - Network Programming 34/ 101
IPC - Named Pipes / FIFOS XIV
int main() {
int fd, end_process, stringlen, read_bytes;
char readbuf[80], end_str[5];
printf("FIFO_CLIENT: Send messages, infinitely, to end enter "
"end\"\n");
fd = open(FIFO_FILE, O_CREAT|O_RDWR);
strcpy(end_str, "end");
while (1) {
printf("Enter string: ");
fgets(readbuf, sizeof(readbuf), stdin);
stringlen = strlen(readbuf);
readbuf[stringlen - 1] = '\0';
end_process = strcmp(readbuf, end_str);
//printf("end_process is %d\n", end_process);
if (end_process != 0) {
write(fd, readbuf, strlen(readbuf));
Dr. Pradeep K V CSE1004 - Network Programming 35/ 101
IPC - Named Pipes / FIFOS XV
printf("FIFOCLIENT: Sent string: \"%s\" and string length"
" is %d\n", readbuf, (int)strlen(readbuf));
read_bytes = read(fd, readbuf, sizeof(readbuf));
readbuf[read_bytes] = '\0';
printf("FIFOCLIENT: Received string: \"%s\" and length "
"is %d\n", readbuf, (int)strlen(readbuf));
}
else {
write(fd, readbuf, strlen(readbuf));
printf("FIFOCLIENT: Sent string: \"%s\" and string length is "
"%d\n", readbuf, (int)strlen(readbuf));
close(fd);
break;
}
}
return 0;
}
