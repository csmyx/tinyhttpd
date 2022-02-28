#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEBUG_ 1

int main(int argc, char *argv[])
{
 int sockfd;
 int len;
 struct sockaddr_in address;
 int result;

 short server_port = 8080;
 char *url = "/b.cgi";
 if (argc == 3) {
   short server_port = (short)atoi(argv[1]); 
   char *url = argv[2];
 } else if (!DEBUG_) {
   printf("please input SERVER_PORT and URL!\n");
   exit(1);
 }

 //申请一个流 socket
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 //填充地址结构，指定服务器的 IP 和 端口
 address.sin_family = AF_INET;
 //inet_addr 可以参考 man inet_addr
 //可以用现代的inet_pton()替代inet_addr(), example 中有参考例子
 address.sin_addr.s_addr = inet_addr("124.221.128.53");
 address.sin_port = htons(server_port);
 len = sizeof(address);
 
 //下面的语句可以输出连接的 IP 地址
 //但是inet_ntoa()是过时的方法，应该改用 inet_ntop(可参考 example)。但很多代码仍然遗留着inet_ntoa.
 //printf("%s\n", inet_ntoa( address.sin_addr));
 
 result = connect(sockfd, (struct sockaddr *)&address, len);

 if (result == -1)
 {
  perror("oops: client1");
  exit(1);
 }
 
 char buf[1024];
 sprintf(buf, "GET %s\r\n\r\n", url);
 // send to server 
 write(sockfd, buf, strlen(buf));

 printf("recv form server:\n");
 int sz = 0;
 while ((sz = read(sockfd, buf, sizeof(buf))) != 0) {
  write(1, buf, sz);
 }
 close(sockfd);
 exit(0);
}
