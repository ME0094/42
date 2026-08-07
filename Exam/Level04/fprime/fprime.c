#include <stdio.h>
#include <stdlib.h>
int	main(int ac,char **av){int n;int d=2;int first=1;if(ac==2){n=atoi(av[1]);if(n==1)printf("1");while(n>1){while(n%d==0){if(!first)printf("*");printf("%d",d);first=0;n/=d;}d++;}}printf("\n");return(0);}
