#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/signal.h>
#include <pthread.h>


    int cmp(char* str1,char* str2){
    int j =0;
    for(j=0;j<4;j++){
        if(str1[j]!=str2[j])return -1;
    }
    return 0;
}

void* thr_func(void* sock){
    char buf2[100];
    char str3[50] = "quit";
    int clisock = *((int*)sock);
    while(true){
    int bytesread = read(clisock,buf2,100);
    if(bytesread<=0)continue;
    
    buf2[bytesread]='\0';
    if(cmp(buf2,str3)==0&&bytesread == 5)break;
    
    printf("Message received at thread %ld from client is-  %s \n",pthread_self(),buf2);}
    close(clisock);
    printf("Terminating thread %ld \n",pthread_self());
    pthread_exit(NULL);
    }
int main(){
	int serverfd,valread,port;
	struct sockaddr_in myaddr;
	struct sockaddr_in clientaddr;
	int addrlen = sizeof(myaddr);
	int cliaddrlen = sizeof(clientaddr);
	char buf1[100];
	serverfd = socket(AF_INET,SOCK_STREAM,0);

    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = INADDR_ANY;
    printf("Enter port number for the server\n");
    scanf("%d",&port);
    myaddr.sin_port = htons(port);
    if(bind(serverfd,(struct sockaddr*)&myaddr,addrlen)==0){
    	printf("Server address is %d.%d.%d.%d and port number is %d\n",myaddr.sin_addr.s_addr,myaddr.sin_addr.s_addr,myaddr.sin_addr.s_addr,myaddr.sin_addr.s_addr,port);
    }
    char str[50]="quit"; 
    if(listen(serverfd,1)!=-1)printf("Listening for clients\n");
    pthread_t tid[5];
    int i=0;
    int clientsock;

    while(true){
    if(i!=5){    
    clientsock  = accept(serverfd,(struct sockaddr*)&clientaddr,(int*)&cliaddrlen);
    printf("A client connected\n");
    valread = read(clientsock,buf1,100);
    //thr_func(&clientsock);
    if((pthread_create(&tid[i++],NULL,thr_func,&clientsock))!=0){
        printf("Failed to create thread\n");
    }}
    else{
        printf("Cannot connect anymore clients after this one\n");
        i=0;
        while(i<5){
            pthread_join(tid[i++],NULL);
        }
        i=0;
    }    
    }
    shutdown(serverfd,SHUT_RDWR);
    return 0; 
}
