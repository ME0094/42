#include <unistd.h>
#include <stdlib.h>
static void	hex(unsigned int n){char *b="0123456789abcdef";if(n>15)hex(n/16);write(1,&b[n%16],1);}
int	main(int ac,char **av){if(ac==2)hex((unsigned int)atoi(av[1]));write(1,"\n",1);return(0);}
