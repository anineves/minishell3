#include "minishell.h"

void parsing(t_data *shell) {
    t_token *current;
    current = shell->tokens;
    int i;
    int capacity;
    
    i = 0;
    capacity = 16;
    shell->args = malloc(capacity * sizeof(char *));
    if (shell->args == NULL) {
        // free
        return;
    }
    while (current != NULL && current->type == WORD) {
        shell->args[i] = ft_strdup(current->str);
        i++;
        current = current->next;
    }
    shell->args[i] = NULL;
}
