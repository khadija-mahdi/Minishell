/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:22:08 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/04 05:09:38 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_name(void)
{
	printf("\e[1;1H\e[2J\n");
	printf("\n");
	printf(BOLDGREEN" *****     *****  ***  *****     ***  ***  "
		BOLDBLUE"*********   ***      ***  *********  ***        ***      \n");
	printf(BOLDGREEN" *** **   ** ***  ***  *** **    ***  ***  "
		BOLDBLUE"***         ***      ***  ***        ***        ***      \n");
	printf(BOLDGREEN" ***  ** **  ***  ***  ***  **   ***  *** "
		BOLDBLUE" ***         ***      ***  ***        ***        ***      \n");
	printf(BOLDGREEN" ***   ***   ***  ***  ***   **  ***  *** "
		BOLDBLUE" **********  ************  ********   ***        ***      \n");
	printf(BOLDGREEN" ***    *    ***  ***  ***    ** ***  *** "
		BOLDBLUE"        ***  ***      ***  ***        ***        ***      \n");
	printf(BOLDGREEN" ***         ***  ***  ***     *****  ***        "
		BOLDBLUE" ***  ***      ***  ***        ***        ***      \n");
	printf(BOLDGREEN" ***         ***  ***  ***      ****  ***  "
		BOLDBLUE"*********   ***      ***  *********  *********  *********\n");
	printf(RESET "\n");
}
