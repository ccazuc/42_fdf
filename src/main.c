/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:16:08 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/02 13:33:14 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	*env;

	env = init_env();
	parse(argc, argv, env);
	create_thread(env);
	printf("pre init window\n");
	init_window(env);
}
