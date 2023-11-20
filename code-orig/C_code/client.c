#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>
int cmp(char* str1,char* str2){
	int j = 0;
	for(j=0;j<4;j++){
		if(str1[j]!=str2[j])return -1;
	}
	return 0;
}
int main(){
	int clientfd,port;
	struct sockaddr_in servaddr;
	char msg1[50];
	int len;
	char str1[50]="quit";
	char str2[20];	
	clientfd = socket(AF_INET,SOCK_STREAM,0);
	servaddr.sin_family = AF_INET;
	printf("Enter port number of the server\n");
	scanf("%d",&port);
	printf("Enter the IP address of the server\n");
	scanf("%s",str2);
	servaddr.sin_port = htons(port);
	inet_pton(AF_INET,str2,&servaddr.sin_addr);
	if(connect(clientfd,(struct sockaddr*)&servaddr,sizeof(servaddr))!=-1)printf("Connected to the server\n");
	else{printf("Connection failed\n");
    close(clientfd);
    exit(1);}
	printf("Enter messages to be sent to the server\n");
	while(true){	
	len = strlen(fgets(msg1,50,stdin));
	write(clientfd,msg1,strlen(msg1));
	
    if(cmp(msg1,str1)==0&&len==5)break;}
    close(clientfd);
    return 0;
}
