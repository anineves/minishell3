#include "minishell.h"
void execute(t_data *shell)
{
	if (!shell->args[0])
		return ;
	if (ft_strncmp(shell->args[0], "echo", 4) == 0)
		ft_echo(shell->args);
	else if (ft_strncmp(shell->args[0], "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(shell->args[0], "env", 3) == 0)
		ft_env(shell);
	
	
	return;
}
