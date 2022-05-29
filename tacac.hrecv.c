#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc , char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char username[10], password[10], secWord[10] ;
	char *message, server_reply[2000];

	socket_desc = socket(AF_INET , SOCK_STREAM , 0);

	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}

	server.sin_addr.s_addr = inet_addr("192.168.56.101");
	server.sin_family = AF_INET;
	server.sin_port = htons( 22 );

	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected \n");

	puts ("success");

	message = "connect";
        if( send(socket_desc , message , strlen(message) , 0) < 0)
        {
                puts("Send failed");
                return 1;
        }
        puts("Data Send\n");

	 if (username == "shahir")
        {
                printf("Correct username\n");
        }
        else
        {
                printf("Incorrect username\n");
        }

        if (password == "hihi")
        {
                printf("Correct password\n");
        }
        else
        {
                printf("Incorrect password\n");
        }

        if (secWord == "good")
        {
                printf("Correct secWord\n");
        }
        else
        {
                printf("Incorrect secWord\n");
        }


        if( recv(socket_desc, server_reply , 2000 , 0) < 0)
        {
                puts("recv failed");
        }
        puts("Reply received\n");
        puts(server_reply);

	return 0;
}
