#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
  
int main(int argc, char *argv[]) {  
    int sock;  
    struct sockaddr_in addr;  
    char buffer[1024];  
    int recv_len;  
  
    if (argc != 2) {  
        printf("Usage: %s <port>\n", argv[0]);  
        exit(EXIT_FAILURE);  
    }  
  
    sock = socket(AF_INET, SOCK_DGRAM, 0);  
    if (sock == -1) {  
        perror("socket");  
        exit(EXIT_FAILURE);  
    }  
  
    memset(&addr, 0, sizeof(addr));  
    addr.sin_family = AF_INET;  
    addr.sin_addr.s_addr = htonl(INADDR_ANY);  
    addr.sin_port = htons(atoi(argv[1]));  
  
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {  
        perror("bind");  
        exit(EXIT_FAILURE);  
    }  
  
    while (1) {  
        recv_len = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);  
        if (recv_len == -1) {  
            perror("recvfrom");  
            exit(EXIT_FAILURE);  
        }  
        buffer[recv_len] = '\0';  
        printf("Received message: %s\n", buffer);  
    }  
  
    return 0;  
}  