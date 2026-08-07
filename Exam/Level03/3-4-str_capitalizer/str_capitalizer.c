#include <unistd.h>
int	main(int ac,char **av){int a=1;int i;char c;while(a<ac){i=0;while(av[a][i]){c=av[a][i];if(c>='A'&&c<='Z')c+=32;if(c>='a'&&c<='z'&&(i==0||av[a][i-1]==' '||av[a][i-1]=='\t'))c-=32;write(1,&c,1);i++;}write(1,"\n",1);a++;}if(ac==1)write(1,"\n",1);return(0);}
