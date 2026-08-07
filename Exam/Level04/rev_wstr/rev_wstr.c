#include <unistd.h>
int	main(int ac,char **av){int end;int start;int first=1;if(ac==2){end=0;while(av[1][end])end++;while(end>0){while(end>0&&(av[1][end-1]==' '||av[1][end-1]=='\t'))end--;start=end;while(start>0&&av[1][start-1]!=' '&&av[1][start-1]!='\t')start--;if(!first)write(1," ",1);write(1,av[1]+start,end-start);first=0;end=start;}}write(1,"\n",1);return(0);}
