/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:06:29 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/13 18:14:29 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	(void)env;
	t_data	*shell;

	shell = malloc(sizeof(t_data));
	if (!init_data(shell, env))
		return(EXIT_FAILURE);
	init_signals();
	while (1)
	{
		shell->input = readline("prompt% ");
		if (shell->input == NULL)
		{
			free(shell->input);
			ft_printf("exit\n"); //substituir por uma funcao de exit
			free(shell);
			return (EXIT_FAILURE);
		}
		add_history(shell->input);
		if (verify_input(shell))
		{
			ft_printf("%s\n", shell->input);
			tokenizacao(shell);
			parsing(shell);
		}
				
		free(shell->input);
	}
	free(shell);
	return (0);
}

