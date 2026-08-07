#include "ft_list.h"
void	ft_list_foreach(t_list *list,void (*f)(void *)){while(list){f(list->data);list=list->next;}}
