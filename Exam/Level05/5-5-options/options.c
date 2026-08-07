#include <unistd.h>
static void	usage(void){write(1,"options: abcdefghijklmnopqrstuvwxyz\n",35);}
int	main(int ac,char **av){unsigned int bits=0;int i=1;int j;int bit;if(ac==1){usage();return(0);}while(i<ac){if(av[i][0]!='-'||!av[i][1]){write(1,"Invalid Option\n",15);return(0);}j=1;while(av[i][j]){if(av[i][j]=='h'){usage();return(0);}if(av[i][j]<'a'||av[i][j]>'z'){write(1,"Invalid Option\n",15);return(0);}bits|=1u<<(av[i][j]-'a');j++;}i++;}bit=31;while(bit>=0){write(1,(bits&(1u<<bit))?"1":"0",1);if(bit%8==0&&bit)write(1," ",1);bit--;}write(1,"\n",1);return(0);}
