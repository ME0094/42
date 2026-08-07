#include <stdio.h>
#include <stdlib.h>
int	main(int ac,char **av){int a;int b;int r;if(ac==3){a=atoi(av[1]);b=atoi(av[2]);while(b){r=a%b;a=b;b=r;}printf("%d",a);}printf("\n");return(0);}
