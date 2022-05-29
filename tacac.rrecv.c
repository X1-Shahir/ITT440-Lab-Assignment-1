#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>


int main(int argc , char *argv[])
{
        int socket_desc;
        struct sockaddr_in server;
        char *message , server_reply[2000];

        socket_desc = socket(AF_INET , SOCK_STREAM , 0);

        char username[10], password[10], secWord[10] ;

        server.sin_addr.s_addr = inet_addr("192.168.56.101");
        server.sin_family = AF_INET;
        server.sin_port = htons( 22 );

        if ( connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
                puts("connect error");
                return 1;
        }

        puts("Connected \n");

        puts("Data Send\n");
        printf ("Enter username: ");
        scanf ("%s", username);
        printf ("Enter password: ");
        scanf ("%s", password);
        printf("Enter your secureWord : ");
        scanf (" %s", secWord);

	message = "connect";
        if( send(socket_desc , message , strlen(message) , 0) < 0)
        {
                puts("Send failed");
                return 1;
        }

        return 0;
}

