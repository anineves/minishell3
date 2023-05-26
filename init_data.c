#include "minishell.h"

size_t	size_env(char **env)
{
	size_t		len;
	int		i;

	i = 0;
	len = 0;
	while (env[i])
	{
		len+= ft_strlen(env[i]);
		i++;
	}
	return (len + i);
}


int	init_env(t_data *shell, char **env)
{
	int		i;
	size_t		len;
	
	i = 0;
	len = 0;
	len = size_env(env);
	shell->len_env = len;
	shell->copy_env = malloc(sizeof(char *) * (len + 1));
	if (!shell->copy_env)
		return (0);
	i = 0;
	while (env[i])
	{
		shell->copy_env[i] = ft_strdup(env[i]);
		if (!shell->copy_env[i])
			return (0);
		i++;
	}
	return (1);
}


int	init_data(t_data *shell, char **env)
{
	if (!shell)
		return (0);
	if(!init_env(shell, env))	
		return (0);
	shell->input = NULL;
	shell->spl_in = NULL;
	shell->token = NULL;
	shell->cwd = getcwd(NULL, 4096); 
	return (1);
}
