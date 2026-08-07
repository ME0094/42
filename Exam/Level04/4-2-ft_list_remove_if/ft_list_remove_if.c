#include <stdlib.h>
#include "ft_list.h"
void	ft_list_remove_if(t_list **list,void *ref,int (*cmp)())
{t_list *node;while(*list){if(cmp((*list)->data,ref)==0){node=*list;*list=(*list)->next;free(node);}else list=&(*list)->next;}}
