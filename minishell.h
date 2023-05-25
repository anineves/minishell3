/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:19:40 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/13 18:14:42 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <termios.h>
# include <stdbool.h>

typedef enum {
    PIPE = 1,    // |
    HEREDOC,  // <<
    APPEND,  // >>
    RD_OUT,      // >
    RD_IN,       // <
    END,
    WORD       // end
} token_type;

/*
typedef struct s_ast
{
	t_token			*token;
	char			**args;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;
*/

typedef struct s_env {
    char *key;
    char *value;
    struct s_env *next;
} t_env;

typedef struct s_token {
    int type;
    char *str;
    struct s_token *next;
} t_token;

typedef struct s_data {
    char *input;
    t_token *token;
    t_token *tokens; // Lista de tokens
    char **args;
    char **env;
    t_env *env_lst;
    char **spl_in;
    char *cwd;
} t_data;

void init_signals(void);
void sig_handler(int sig);
int init_data(t_data *shell, char **env);
int verify_input(t_data *shell);
char *ft_strtok(char *str, const char *delim);
int ft_pwd();
void tokenizacao(t_data *shell);
void parsing(t_data *shell);
void execute(t_data *shell);
void ft_echo(char **args);

#endif
