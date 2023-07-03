#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <arpa/inet.h>
#define SIZE 1024
 
void write_file(int sockfd){
  int n;
  FILE *fp;
  char *filename = "recv1.txt";
  char buffer[SIZE];           
 
  fp = fopen(filename, "w"); 
  while (1) {
        //int recv(int socket, char *buffer, int length, int flags);
        //If successful, recv() returns the length of the message or datagram in bytes
        //If unsuccessful, recv() returns -1 
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0){
      break;
      return;
    }
    fprintf(fp, "%s", buffer);
    printf("%s", buffer);
    //bzero(buffer, SIZE);
  }
  return;
}
 
int main(){
  char *ip = "127.0.0.1";
  int port = 8080;
  int e;
 
  int sockfd, new_sock;
  struct sockaddr_in server_addr, new_addr;
  //socklen_t addr_size;
  //char buffer[SIZE];
 
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("[-]Error in socket");
    exit(1);
  }
  printf("[+]Server socket created successfully.\n");
 
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);
 //If successful, bind() returns 0.
  e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e < 0) {
    perror("[-]Error in bind");
    exit(1);
  }
  printf("[+]Binding successfull.\n");
        //int listen(int socket, int backlog);
        //backlog->Defines the maximum length for the queue of pending connections.
        //If successful, listen() returns 0.//If unsuccessful, listen() returns -1.
 if(listen(sockfd, 10) == 0){
 printf("[+]Listening....\n");
 }else{
 perror("[-]Error in listening");
    exit(1);
 }
 
  //addr_size = sizeof(new_addr);
 //If successful, accept() returns a nonnegative socket descriptor.
 
  new_sock = accept(sockfd, (struct sockaddr*)&new_addr,sizeof(new_addr));// &addr_size);
  write_file(new_sock);
  printf("[+]Data written in the file successfully.\n");
 
  return 0;
}
