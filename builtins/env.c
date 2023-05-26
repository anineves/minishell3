#include "../minishell.h"

void	ft_env(t_data *shell)
{
	int	i;

	i = 0;
	while (i < shell->len_env)
	{
		printf("%s\n", shell->copy_env[i]);
		i++;
	}

}
