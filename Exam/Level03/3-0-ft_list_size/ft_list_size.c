#include "ft_list.h"
int	ft_list_size(t_list *list){int n=0;while(list){n++;list=list->next;}return(n);}
