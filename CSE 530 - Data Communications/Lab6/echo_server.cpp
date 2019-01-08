#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 1024
void error_handling(char *message);
void* thread_main(void *arg);


#define MAX_CONNECTIONS 5
int clnt_sock[MAX_CONNECTIONS];
char message[MAX_CONNECTIONS][BUF_SIZE];
struct sockaddr_in clnt_adr[MAX_CONNECTIONS];
socklen_t clnt_adr_sz[MAX_CONNECTIONS];

int main(int argc, char *argv[])
{
	int serv_sock;
	int i=0;
	struct sockaddr_in serv_adr;
    pthread_t t_id;

	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock==-1)
		error_handling("socket() error");

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");

	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");


	for(i=0; i<MAX_CONNECTIONS; i++)
	{
       
        clnt_adr_sz[i]=sizeof(clnt_adr[i]);
		clnt_sock[i]=accept(serv_sock, (struct sockaddr*)&clnt_adr[i], &clnt_adr_sz[i]);
		if(clnt_sock[i]==-1)
			error_handling("accept() error");
		else
        {
            printf("Connected client %d \n", i+1);

            if(pthread_create(&t_id, NULL, thread_main, &i)!=0)
            {
                puts("pthread_create() error");
                return -1;
            }
        }
	}

	close(serv_sock);
	return 0;
}



void* thread_main(void *arg)
{
    int clientnum=*((int*)arg);
    clientnum--;        
    int str_len;

    printf( "(Tread %d Started)\n",clientnum);  

    while((str_len=read(clnt_sock[clientnum], message[clientnum], BUF_SIZE))!=0)
    {
        
        write(clnt_sock[clientnum], message[clientnum], str_len);
        printf( "Thread %d Wrote: ",clientnum);
        puts( message[clientnum]);
        memset( message[clientnum],0,BUF_SIZE);
    }

	close(clnt_sock[clientnum]);

	return NULL;
}



void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
