/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:34 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/16 11:46:09 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct node
{
	int		i;
	int		input_file;
	char	*command;
	char	**arguments;
	int		output_file;
	int		checker;
}			t_node;

typedef struct s_helper
{
	int	checker;
	int	sh_lvl;
}	t_helper;

extern t_helper	g__helper;

enum	e_exit_status
{
	M_SIG_INT = 78
};

enum	e_file_input
{
	NONE = -3,
	NO_FILE = -1,
	ERROR = -2,
};

typedef struct s_tree
{
	int				op;
	char			*content;

	struct s_tree	*left;
	struct s_tree	*right;
	struct node		*node;
}					t_tree;

typedef struct proccess
{
	int	length;
	int	*proccess;
}	t_proccess;

typedef struct cp_flags
{
	int	*qute_flag;
	int	mode;
	int	*index;
}	t_cp_flags;

typedef struct s_process
{
	int		pipes[2];
	int		in;
}	t_process;
#endif
