int is_equal_plus(char *argument)
{
	int len;
	int index;

	len = 0;
	index = 0;
	while(argument && argument[len] && argument[len] != '=')
		len++;
	if (argument[len] == '=')
		len++;
	while(index < len)
	{
		if (argument[index] == '+')
		{
			if (argument[index + 1] == argument[len])
				return (1);
			return(0);
		}
		index++;
	}
	return (1);
}
int is_forbidden_char(char *argument)
{
	int len;
	int index;

	len = 0;
	index = 0;
	while(argument && argument[len] && argument[len] != '=')
		len++;
	while(index < len)
	{
		if(!ft_isalnum(argument[index]))
			return(1);
		index++;
	}
	return (0);
}

int is_value(char *argument)
{
	int i;
	
	i = 0;
	while (argument && argument[i])
	{
		if (argument[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

char **reset_forbidden_env(char **name)
{
	char **env = name;
	while (name && *name)
	{
		if ((!ft_isalpha(*name[0]) || is_forbidden_char(*name) || !is_equal_plus(*name)))
			remove_env(name);
		else
			name++;
	}
	return (env);
	
}