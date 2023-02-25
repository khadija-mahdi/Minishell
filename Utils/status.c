/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <aaitouna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 08:58:35 by aaitouna          #+#    #+#             */
/*   Updated: 2023/02/25 09:01:23 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	status(int a)
{
	static int	status;

	if (a == -1)
		return (status);
	status = a;
}

int	get_exit_status(void)
{
	return (status(-1));
}

void	set_exit_status(int status_val)
{
	status(status_val);
}