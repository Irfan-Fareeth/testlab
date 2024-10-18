#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<bits/stdc++.h>
using namespace std;
#define MAX 80
#define PORT 53033
#define SA struct sockaddr
void func(int connfd)
{
	
	char buff[MAX];
	for(;;)
	{
		bzero(buff, MAX);
		cout<<"From client";
		read(connfd, buff, sizeof(buff));
		cout<<buff;
		cout<<"\n";
		bzero(buff, sizeof(buff));
		cout<<"Enter message to client:";
		cin>>buff;
		write(connfd, buff, sizeof(buff));

	}
}
int main()
{
	int connfd, sockfd;
	unsigned int len;
	struct sockaddr_in servaddr, cli;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd!=-1)
	{
		cout<<"socket created successfully!\n";
	}
	else
	{
		cout<<"socket creation failed!\n";
		exit(0);
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	if(bind(sockfd, (SA*)&servaddr, sizeof(servaddr))!=0)
	{
		cout<<"socket binding failed!\n";
		exit(0);
	}
	else
	{
		cout<<"socket binding successfully!\n";
	}
	if(listen(sockfd, 5)!=0)
	{
		cout<<"socket listen failed!\n";
		exit(0);
	}
	else
		cout<<"listening....\n";
	
	len = sizeof(cli);
	connfd = accept(sockfd, (SA*)&cli, &len);
	if(connfd <0)
	{
		cout<<"socket is not accepted!\n";
		exit(0);
	}
	else
		cout<<"socket accepted\n";
	func(connfd);
	close(sockfd);
}


