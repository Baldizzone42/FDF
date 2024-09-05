/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:45:44 by jormoral          #+#    #+#             */
/*   Updated: 2024/05/14 17:42:33 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ult;

	if (*lst == NULL)
		(*lst) = new;
	else
	{
		ult = *lst;
		while (ult->next != NULL)
			ult = ult->next;
		(ult)->next = new;
	}
}
