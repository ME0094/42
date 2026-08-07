#include <unistd.h>
#include <stddef.h>
static void	hex(unsigned char c){char *b="0123456789abcdef";write(1,&b[c/16],1);write(1,&b[c%16],1);}
void	print_memory(const void *addr,size_t size){const unsigned char *p=addr;size_t i=0;size_t j;while(i<size){j=0;while(j<16){if(i+j<size)hex(p[i+j]);else write(1,"  ",2);if(j%2)write(1," ",1);j++;}j=0;while(j<16&&i+j<size){if(p[i+j]>=32&&p[i+j]<=126)write(1,p+i+j,1);else write(1,".",1);j++;}write(1,"\n",1);i+=16;}}
