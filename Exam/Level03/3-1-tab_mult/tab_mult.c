#include <unistd.h>
static void	putnbr(int n){char c;if(n>9)putnbr(n/10);c=n%10+'0';write(1,&c,1);}
static int	to_int(char *s){int n=0;while(*s>='0'&&*s<='9')n=n*10+*s++-'0';return(n);}
int	main(int ac,char **av){int n;int i=1;if(ac==2){n=to_int(av[1]);while(i<=9){putnbr(i);write(1," x ",3);putnbr(n);write(1," = ",3);putnbr(i*n);write(1,"\n",1);i++;}}return(0);}
