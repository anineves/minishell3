#include "minishell.h"

t_token *create_token(char *lexeme, token_type type) {
    t_token *token = (t_token *)malloc(sizeof(t_token));
    token->str = ft_strdup(lexeme);
    token->type = type;
    token->next = NULL;
    return token;
}

void print_tokens(t_token *tokens) {
    t_token *current = tokens;
    while (current != NULL) {
        printf("Token: %s\tType: %d\n", current->str, current->type);
        current = current->next;
    }
}

void add_token(t_token **head, t_token **tail, t_token *token) {
    if (*head == NULL) {
        *head = token;
        *tail = token;
    } else {
        (*tail)->next = token;
        *tail = token;
    }
}

token_type get_token_type(const char *token_str) {
    if (strcmp(token_str, "|") == 0)
        return PIPE;
    else if (strcmp(token_str, "<<") == 0)
        return HEREDOC;
    else if (strcmp(token_str, ">>") == 0)
        return APPEND;
    else if (strcmp(token_str, ">") == 0)
        return RD_OUT;
    else if (strcmp(token_str, "<") == 0)
        return RD_IN;
    else if (strcmp(token_str, "end") == 0)
        return END;
    else
        return WORD;
}

void tokenizacao(t_data *shell) 
{
    char *input;
    t_token *head;
    t_token *tail;
    char *token_str;
    token_type type;
    
    input = shell->input;
    tail = NULL;
    head = NULL;
    token_str = ft_strtok(input, " ");
    type = WORD;
    while (token_str != NULL) 
    {
	type = get_token_type(token_str);
	t_token *token = create_token(token_str, type);
	add_token(&head, &tail, token);
        token_str = ft_strtok(NULL, " ");
    }
    shell->tokens = head;
    print_tokens(shell->tokens);
}
