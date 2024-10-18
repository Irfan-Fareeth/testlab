#include<iostream>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#define MAX 80
#define PORT 53033
#define SA struct sockaddr
using namespace std;
void func(int connfd)
{
	char buff[MAX];
	for(;;)
	{
		bzero(buff, sizeof(buff));
		cout<<"Enter a message to server:";
		cin>>buff;
		write(connfd, buff, sizeof(buff));
		cout<<"From server:";
		bzero(buff, sizeof(buff));
		read(connfd, buff, sizeof(buff));
		cout<<buff;
	}


}
int main()
{
	int sockfd;
	unsigned int len;
	struct sockaddr_in servaddr, cli;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd==-1)
	{
		cout<<"socket creation failed!\n";
		exit(0);
	}
	else
	{
		cout<<"socket created successfully!\n";
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("10.5.12.254");
	servaddr.sin_port = htons(PORT);

	if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr))!=0)
	{
		cout<<"sockedt connected failed!\n";
		exit(0);
	}
	else
	{	   cout<<"socket is connected succesffully!\n";
		   
	}
	func(sockfd);
	close(sockfd);
}

