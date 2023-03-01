/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:31:19 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/03/01 16:59:59 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../push_swap.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

int					ft_atoi(const char *str);
t_stack				*ft_lstnew(int data);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstdelone(t_stack *lst, void (*del)(int));
void				ft_lstclear(t_stack **lst, void (*del)(int));
void				ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack				*ft_lstmap(t_stack *lst, void *(*f)(void *),
						void (*del)(void *));

#endif //ends condition