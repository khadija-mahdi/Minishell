/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc_interrupte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:13:43 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/09 20:13:44 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./utils.h"

int	interrupted(int value)
{
	static int	interrupted;

	if (value != -1)
		interrupted = value;
	return (interrupted);
}

void	set_interrupted(int value)
{
	interrupted(value);
}

int	is_interrupted(void)
{
	return (interrupted(-1));
}

int	return_fd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	free(file_name);
	return (fd);
}
