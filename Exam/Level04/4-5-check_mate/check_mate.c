#include <unistd.h>
static int	abs_i(int n){return(n<0?-n:n);}
static int	clear(char **b,int r,int c,int kr,int kc){int dr=(kr>r)-(kr<r);int dc=(kc>c)-(kc<c);r+=dr;c+=dc;while(r!=kr||c!=kc){if(b[r][c]!='.')return(0);r+=dr;c+=dc;}return(1);}
static int	attacks(char **b,int r,int c,int kr,int kc){char p=b[r][c];int dr=abs_i(kr-r);int dc=abs_i(kc-c);if(p=='P')return(kr==r-1&&dc==1);if(p=='R'&&(r==kr||c==kc))return(clear(b,r,c,kr,kc));if(p=='B'&&dr==dc)return(clear(b,r,c,kr,kc));if(p=='Q'&&(r==kr||c==kc||dr==dc))return(clear(b,r,c,kr,kc));return(0);}
int	main(int ac,char **av){int r,c,kr=-1,kc=-1;if(ac<2){write(1,"Fail\n",5);return(0);}r=0;while(r<ac-1){c=0;while(av[r+1][c]){if(av[r+1][c]=='K'){kr=r;kc=c;}c++;}r++;}r=0;while(r<ac-1){c=0;while(av[r+1][c]){if(attacks(av+1,r,c,kr,kc)){write(1,"Success\n",8);return(0);}c++;}r++;}write(1,"Fail\n",5);return(0);}
