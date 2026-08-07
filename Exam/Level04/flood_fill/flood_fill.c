#include "flood_fill.h"
static void	fill(char **t,t_point s,int x,int y,char c){if(x<0||y<0||x>=s.x||y>=s.y||t[y][x]!=c)return;t[y][x]='F';fill(t,s,x+1,y,c);fill(t,s,x-1,y,c);fill(t,s,x,y+1,c);fill(t,s,x,y-1,c);}
void	flood_fill(char **tab,t_point size,t_point begin){fill(tab,size,begin.x,begin.y,tab[begin.y][begin.x]);}
