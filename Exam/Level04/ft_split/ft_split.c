#include <stdlib.h>
static int	space(char c){return(c==' '||c=='\t'||c=='\n');}
static int	words(char *s){int n=0;while(*s){while(space(*s))s++;if(*s)n++;while(*s&&!space(*s))s++;}return(n);}
char	**ft_split(char *s){char **out;int i=0;int len;int j;out=malloc(sizeof(char*)*(words(s)+1));if(!out)return(0);while(*s){while(space(*s))s++;if(!*s)break;len=0;while(s[len]&&!space(s[len]))len++;out[i]=malloc(len+1);if(!out[i])return(0);j=0;while(j<len){out[i][j]=s[j];j++;}out[i++][j]='\0';s+=len;}out[i]=0;return(out);}
