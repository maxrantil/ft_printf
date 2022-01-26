/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:07:47 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/23 17:12:52 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputstr(t_list **alst)
{
	t_list	*ptr;

	if (*alst == NULL)
		return ;
	ptr = *alst;
	while (ptr != NULL)
	{
		ft_putendl((char *)ptr->content);
		ptr = ptr->next;
	}
}
