#include <unistd.h>
static int	pal(char *s,int a,int b){while(a<b)if(s[a++]!=s[b--])return(0);return(1);}
int	main(int ac,char **av){int n=0;int len;int start;int best=0;int pos=0;if(ac==2){while(av[1][n])n++;len=1;while(len<=n){start=0;while(start+len<=n){if(len>=best&&pal(av[1],start,start+len-1)){best=len;pos=start;}start++;}len++;}write(1,av[1]+pos,best);}write(1,"\n",1);return(0);}
