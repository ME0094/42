#include <stdlib.h>
char	*ft_itoa(int n){long v=n;int len=1;int neg=v<0;char *s;if(v<0)v=-v;{long x=v;while(x>9){len++;x/=10;}}len+=neg;s=malloc(len+1);if(!s)return(0);s[len]='\0';while(len>neg){s[--len]=v%10+'0';v/=10;}if(neg)s[0]='-';return(s);}
