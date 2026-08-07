#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#if defined(TEST_PRINT_NUMBERS)
void ft_print_numbers(void);
int main(void) { ft_print_numbers(); ft_print_numbers(); return (0); }
#elif defined(TEST_STRCPY)
char *ft_strcpy(char *, char *);
int main(void) { char d[16]; printf("%s,", ft_strcpy(d, "Piscine")); printf("%s", ft_strcpy(d, "")); return (0); }
#elif defined(TEST_STRLEN)
int ft_strlen(char *);
int main(void) { printf("%d,%d", ft_strlen("Piscine"), ft_strlen("")); return (0); }
#elif defined(TEST_PUTSTR)
void ft_putstr(char *);
int main(void) { ft_putstr("42 Piscine"); ft_putstr(""); return (0); }
#elif defined(TEST_SWAP)
void ft_swap(int *, int *);
int main(void) { int a = -4; int b = 42; ft_swap(&a, &b); ft_swap(&a, &a); printf("%d,%d", a, b); return (0); }
#elif defined(TEST_ATOI)
int ft_atoi(const char *);
int main(void) { printf("%d,%d,%d", ft_atoi(" \t-42x"), ft_atoi("-214"), ft_atoi("abc")); return (0); }
#elif defined(TEST_STRDUP)
char *ft_strdup(char *);
int main(void) { char *s=ft_strdup("copy me");char *e=ft_strdup("");if(!s||!e)return(1);printf("%s,%s",s,e);free(s);free(e);return(0); }
#elif defined(TEST_REVERSE_BITS)
unsigned char reverse_bits(unsigned char);
int main(void) { printf("%u,%u,%u", (unsigned int)reverse_bits(0x12), (unsigned int)reverse_bits(0), (unsigned int)reverse_bits(255)); return (0); }
#elif defined(TEST_SWAP_BITS)
unsigned char swap_bits(unsigned char);
int main(void) { printf("%u,%u,%u", (unsigned int)swap_bits(0x41), (unsigned int)swap_bits(0), (unsigned int)swap_bits(255)); return (0); }
#elif defined(TEST_MAX)
int max(int *, unsigned int);
int main(void) { int t[] = {-9, -2, -7}; printf("%d,%d", max(t, 3), max(t, 0)); return (0); }
#elif defined(TEST_PRINT_BITS)
void print_bits(unsigned char);
int main(void) { print_bits(42); write(1, ",", 1); print_bits(0); return (0); }
#elif defined(TEST_STRCMP)
int ft_strcmp(char *, char *);
int main(void) { printf("%d,%d,%d", ft_strcmp("abc", "abc"), ft_strcmp("abd", "abc") > 0, ft_strcmp("ab", "abc") < 0); return (0); }
#elif defined(TEST_STRREV)
char *ft_strrev(char *);
int main(void) { char a[] = "abcde"; char b[] = ""; printf("%s,%s", ft_strrev(a), ft_strrev(b)); return (0); }
#elif defined(TEST_POWER2)
int is_power_of_2(unsigned int);
int main(void) { printf("%d,%d,%d", is_power_of_2(1), is_power_of_2(64), is_power_of_2(0)); return (0); }
#elif defined(TEST_LIST_SIZE)
typedef struct s_list { struct s_list *next; void *data; } t_list;
int ft_list_size(t_list *);
int main(void) { t_list c = {0, 0}; t_list b = {&c, 0}; t_list a = {&b, 0}; printf("%d,%d", ft_list_size(&a), ft_list_size(0)); return (0); }
#elif defined(TEST_RRANGE)
int *ft_rrange(int, int);
int main(void) { int i; int *a=ft_rrange(1,-2);int *b=ft_rrange(7,7);if(!a||!b)return(1);i=0;while(i<4){if(i)printf(",");printf("%d",a[i++]);}printf(",%d",b[0]);free(a);free(b);return(0); }
#elif defined(TEST_LCM)
unsigned int lcm(unsigned int, unsigned int);
int main(void) { printf("%u,%u", lcm(21, 6), lcm(0, 8)); return (0); }
#elif defined(TEST_ATOI_BASE)
int ft_atoi_base(const char *, int);
int main(void) { printf("%d,%d,%d", ft_atoi_base("-2A", 16), ft_atoi_base("101101", 2), ft_atoi_base("77", 8)); return (0); }
#elif defined(TEST_RANGE)
int *ft_range(int, int);
int main(void) { int i; int *a = ft_range(-2, 2); if (!a) return (1); i = 0; while (i < 4) { if (i) printf(","); printf("%d", a[i++]); } free(a); printf(";%d", ft_range(2, 2) == 0); return (0); }
#elif defined(TEST_REMOVE_IF)
typedef struct s_list { struct s_list *next; void *data; } t_list;
void ft_list_remove_if(t_list **, void *, int (*)());
static int same(void *a, void *b) { return (strcmp((char *)a, (char *)b)); }
int main(void) { t_list *a = malloc(sizeof(*a)); t_list *b = malloc(sizeof(*b)); t_list *c = malloc(sizeof(*c)); t_list *p; if (!a || !b || !c) return (1); a->data="x"; a->next=b; b->data="keep"; b->next=c; c->data="x"; c->next=0; ft_list_remove_if(&a, "x", same); p=a; while(p){printf("%s",(char *)p->data);p=p->next;} free(a);a=0;ft_list_remove_if(&a,"x",same);printf(",%d",a==0);return(0); }
#elif defined(TEST_SORT_LIST)
typedef struct s_list { int data; struct s_list *next; } t_list;
t_list *sort_list(t_list *, int (*)(int, int));
static int ascending(int a, int b) { return (a <= b); }
int main(void) { t_list c={2,0}; t_list b={1,&c}; t_list a={3,&b}; t_list *p=sort_list(&a,ascending); while(p){printf("%d",p->data);p=p->next;} printf(",%d",sort_list(0,ascending)==0);return(0); }
#elif defined(TEST_ITOA)
char *ft_itoa(int);
int main(void) { char *a=ft_itoa(-2147483647-1); char *b=ft_itoa(0); if(!a||!b)return(1); printf("%s,%s",a,b); free(a);free(b);return(0); }
#elif defined(TEST_ITOA_BASE)
char *ft_itoa_base(int, int);
int main(void) { char *a=ft_itoa_base(-42,16); char *b=ft_itoa_base(42,2); if(!a||!b)return(1); printf("%s,%s",a,b); free(a);free(b);return(0); }
#elif defined(TEST_FLOOD_FILL)
typedef struct s_point { int x; int y; } t_point;
void flood_fill(char **, t_point, t_point);
int main(void) { char a[]="1110";char b[]="1000";char c[]="1110";char *t[]={a,b,c};char d[]="0";char *u[]={d};int i;flood_fill(t,(t_point){4,3},(t_point){0,0});i=0;while(i<3){printf("%s",t[i++]);if(i<3)printf("/");}flood_fill(u,(t_point){1,1},(t_point){0,0});printf(",%s",d);return(0); }
#elif defined(TEST_LIST_FOREACH)
typedef struct s_list { struct s_list *next; void *data; } t_list;
void ft_list_foreach(t_list *, void (*)(void *));
static void inc(void *p) { (*(int *)p)++; }
int main(void) { int x=1,y=4;t_list b={0,&y};t_list a={&b,&x};ft_list_foreach(&a,inc);ft_list_foreach(0,inc);printf("%d,%d",x,y);return(0); }
#elif defined(TEST_SPLIT)
char **ft_split(char *);
int main(void) { char **a=ft_split("  one\ttwo three ");char **b;int i=0;if(!a)return(1);while(a[i]){if(i)printf(",");printf("%s",a[i]);free(a[i++]);}free(a);b=ft_split(" \t ");if(!b)return(1);printf(",%d",b[0]==0);free(b);return(0); }
#elif defined(TEST_SORT_INT)
void sort_int_tab(int *, unsigned int);
int main(void) { int t[]={3,-1,3,0};int i=0;sort_int_tab(t,4);sort_int_tab(t,0);while(i<4){if(i)printf(",");printf("%d",t[i++]);}return(0); }
#elif defined(TEST_PRINT_MEMORY)
#include <stddef.h>
void print_memory(const void *, size_t);
int main(void) { const unsigned char s[]="Hello";print_memory(s,0);print_memory(s,5);return(0); }
#elif defined(TEST_CYCLE)
typedef struct s_list { int data; struct s_list *next; } t_list;
int cycle_detector(const t_list *);
int main(void) { t_list c={3,0};t_list b={2,&c};t_list a={1,&b};int plain=cycle_detector(&a);c.next=&b;printf("%d,%d",plain,cycle_detector(&a));return(0); }
#else
# error Select one TEST_* macro
#endif
