#include <unistd.h>
#include <stdlib.h>
static void	putnbr(int n){char c;if(n>9)putnbr(n/10);c=n%10+'0';write(1,&c,1);}
int	main(int ac,char **av){int n;int i=1;if(ac==2){n=atoi(av[1]);while(i<=9){putnbr(i);write(1," x ",3);putnbr(n);write(1," = ",3);putnbr(i*n);write(1,"\n",1);i++;}}return(0);}
