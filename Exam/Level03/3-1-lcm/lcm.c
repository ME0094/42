unsigned int	lcm(unsigned int a,unsigned int b){unsigned int x=a;unsigned int y=b;unsigned int r;if(!a||!b)return(0);while(y){r=x%y;x=y;y=r;}return(a/x*b);}
