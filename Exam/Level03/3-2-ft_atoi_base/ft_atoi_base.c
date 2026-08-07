static int	digit(char c){if(c>='0'&&c<='9')return(c-'0');if(c>='a'&&c<='f')return(c-'a'+10);if(c>='A'&&c<='F')return(c-'A'+10);return(-1);}
int	ft_atoi_base(const char *str,int base){int sign=1;int n=0;int d;if(base<2||base>16)return(0);if(*str=='-'){sign=-1;str++;}while((d=digit(*str))>=0&&d<base){n=n*base+d;str++;}return(n*sign);}
