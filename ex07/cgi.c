#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <zconf.h>

#define PORT 3183
#define QLEN 10
#define BUFFER_SIZE 1024

void *handle(int csock);
void s_error(int csock);
void msg_get(int client_sock);
void msg_post(int client_sock);

int main(int argc, char* argv[]){
    int sockfd, new_fd;
    struct sockaddr_in s_address;
    struct sockaddr_in c_addrress;

    int alen;
    fd_set readfds, activefds;

    int i, maxfd = 0, numbytes;
    char buffer[BUFFER_SIZE];

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket() failed");
        exit(1);
    }

    memset(&s_address, 0, sizeof(s_address));
    s_address.sin_family = AF_INET;
    s_address.sin_port = htons(PORT);
    s_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd, (struct sockaddr *)&s_address, sizeof(s_address)) < 0){
        perror("bind() failed");
        exit(1);
    }

    if(listen(sockfd, QLEN) < 0){
        fprintf(stderr, "listen failed\n");
        exit(1);
    }

    alen = sizeof(c_address);
    FD_ZERO(&activefds);
    FD_SET(sockfd, &activefds);
    maxfd = sockfd;

    fprintf(stderr, "Server on!\n");
    while(1){
        //printf("SERVER: Waiting for contact...%d\n", maxfd);
        readfds = activefds;

        if(select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0){
            perror("select");
            exit(EXIT_FAILURE);
        }

        for(i = 0; i <= maxfd; i++){
            if(FD_ISSET(i, &readfds)){

                if(i == sockfd){
                    if((new_fd = accept(sockfd, (struct sockaddr *)&c_address, &alen)) < 0){
                        fprintf(stderr, "accept failed\n");
                        exit(1);
                    }
                    FD_SET(new_fd, &activefds);
                    if(new_fd > maxfd){
                        maxfd = new_fd;
                    }
                }
                else{
                    printf("handle clnt\n");
                    handle(i);
                    close(i);
                    FD_CLR(i, &activefds);
                }
            }
        }
    }
    close(sockfd);
    return 0;
}

void *handle(int csock){
    int recv = 0, str_len = 0;
    char message[BUFFER_SIZE];
    char method[10];

    if((str_len = read(csock, &message[recv], BUFFER_SIZE)) == -1){
        printf("read() error!\n");
        exit(1);
    }
    recv += str_len;
    strcpy(method, strtok(message, " "));
    if(strcmp(method, "GET") != 0){
        s_error(csock);
    }else if(strcmp(method, "GET") == 0){
        msg_get(csock);
    }
    else if(strcmp(method, "POST") == 0){
        msg_post(csock);
    }else {
        s_error(csock);
    }
    return NULL;
}

void s_error(int csock){
    char proto[] = "HTTP/1.1 400 Bad Request\r\n";
    char server[] = "Server:Netscape-Enterprise/6.0\r\n";
    char contenttype[] = "Content-Type:text/html\r\n";
    char html[] = "<html><head>BADConnection</head><body><H1>BadRequest</H1></body></html>\r\n";
    char end[]="\r\n";

    printf("send err\n");
    write(csock, proto, strlen(proto));
    write(csock, server, strlen(server));
    write(csock, contenttype, strlen(contenttype));
    write(csock, end, strlen(end));
    write(csock, html, strlen(html));
    fflush(fdopen(csock, "w"));
}

void msg_get(int client_sock) // send to all
{
    char proto[] = "HTTP/1.1 200 OK\r\n";
    char server[] = "Server:Netscape-Enterprise/6.0\r\n";
    char contenttype[] = "Content-Type:text/html\r\n";
    char html[] = "<html><head>get test</head><body><H1>POST DONGDONG</H1></body></html>\r\n";
    char contentlength[] = "Content-Length: ";
    sprintf(contentlength, "%d", strlen(html));
    strcat(contentlength, "\r\n");
    char end[] = "\r\n";

    printf("send msg, len=%d\n", strlen(html));
    write(client_sock, proto, strlen(proto));
    write(client_sock, server, strlen(server));
    write(client_sock, contentlength, strlen(contentlength));
    write(client_sock, contenttype, strlen(contenttype));
    write(client_sock, end, strlen(end));
    write(client_sock, html, strlen(html));
    fflush(fdopen(client_sock, "w"));
}

void msg_post(int client_sock){
    char protocol[] = "HTTP/1.1 200 OK\r\n";
    char server[] = "Server:Netscape-Enterprise/6.0\r\n";
    char contenttype[] = "Content-Type:text/html\r\n";
    char html[] = "<html><head>post test</head><body><H1>POST DONGDONG</H1></body></html>\r\n";
    char contentlength[] = "Content-Length: ";
    sprintf(contentlength, "%d", strlen(html));
    strcat(contentlength, "\r\n");
    char end[] = "\r\n";

    printf("send msg, len=%d\n", strlen(html));
    write(client_sock, protocol, strlen(protocol));
    write(client_sock, server, strlen(server));
    write(client_sock, contentlength, strlen(contentlength));
    write(client_sock, contenttype, strlen(contenttype));
    write(client_sock, end, strlen(end));
    write(client_sock, html, strlen(html));
    fflush(fdopen(client_sock, "w"));
}

