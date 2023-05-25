#include "minishell.h"

int ft_pwd(t_data *shell)
{
	printf("%s\n", shell->cwd);
	return (EXIT_SUCCESS);

}

