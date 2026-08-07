#include <stdlib.h>
int	*ft_rrange(int start,int end){int len;int *a;int i=0;len=(start>end)?start-end+1:end-start+1;a=malloc(sizeof(int)*len);if(!a)return(0);while(i<len){a[i++]=end;if(end<start)end++;else end--;}return(a);}
