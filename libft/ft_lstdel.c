/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:51:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/12 14:35:10 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*upcoming;
	t_list	*current;

	current = *alst;
	while (current != NULL)
	{
		upcoming = current->next;
		(*del)(current->content, current->content_size);
		free(current);
		current = upcoming;
	}
	*alst = NULL;
}
