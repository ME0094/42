#include <unistd.h>
static void	hex(unsigned int n){char *b="0123456789abcdef";if(n>15)hex(n/16);write(1,&b[n%16],1);}
static unsigned int	to_uint(char *s){unsigned int n=0;while(*s>='0'&&*s<='9')n=n*10+*s++-'0';return(n);}
int	main(int ac,char **av){if(ac==2)hex(to_uint(av[1]));write(1,"\n",1);return(0);}
