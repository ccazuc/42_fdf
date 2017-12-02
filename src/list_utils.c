/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 06:31:57 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/13 06:47:11 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdflist	*create_elem(char *data)
{
	t_fdflist	*result;

	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	result->next = NULL;
	result->datas = data;
	return (result);
}

void		list_push_back(t_fdflist **begin_list, char *data)
{
	t_fdflist	*list;

	if (!*begin_list)
	{
		*begin_list = create_elem(data);
		return ;
	}
	list = *begin_list;
	while (list->next)
		list = list->next;
	list->next = create_elem(data);
}
