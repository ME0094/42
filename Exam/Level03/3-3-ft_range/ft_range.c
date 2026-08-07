#include <stdlib.h>
int	*ft_range(int start,int end){int len;int *a;int i=0;len=(start>end)?start-end+1:end-start+1;a=malloc(sizeof(int)*len);if(!a)return(0);while(i<len){a[i++]=start;if(start<end)start++;else start--;}return(a);}
