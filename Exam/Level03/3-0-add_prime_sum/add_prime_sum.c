#include <unistd.h>
#include <stdlib.h>

static int	prime(int n){int d=2;if(n<2)return(0);while(d*d<=n){if(n%d==0)return(0);d++;}return(1);}
static void	putnbr(int n){char c;if(n>9)putnbr(n/10);c=n%10+'0';write(1,&c,1);}
int	main(int ac,char **av){int n;int sum=0;if(ac==2){n=atoi(av[1]);while(n>1){if(prime(n))sum+=n;n--;}}putnbr(sum);write(1,"\n",1);return(0);}
