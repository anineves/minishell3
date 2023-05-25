#include "minishell.h"

void execute(t_data *shell)
{
	if (!shell->args[0])
		return ;
	if (ft_strncmp(shell->args[0], "echo", 4) == 0)
		ft_echo(shell->args);
	else if (ft_strncmp(shell->args[0], "pwd", 3) == 0)
		ft_pwd();
	//else if (ft_strcmp(shell->args[0], "cd") == 0)
	//	cd(att);
	//else if (ft_strcmp(shell->args[0], "export") == 0)
	//	export(att);
	//else if (ft_strcmp(shell->args[0], "unset") == 0)
	//	unset(att);
	//else if (ft_strcmp(shell->args[0], "env") == 0)
	//	env(att);
	//else if ((ft_strcmp(shell->args[0], "exit") == 0) || (ft_strcmp(tok[0], "\"exit\"") == 0))
	//	return (ft_exit(*att));
	//else
		//execute(att);
	return;
}
