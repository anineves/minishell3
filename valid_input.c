/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:24:16 by mimoreir          #+#    #+#             */
/*   Updated: 2023/05/13 18:20:49 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdbool.h>

void rmvSpaces(char *input) 
{
    int i;
    int	j;
    int k;
    int inDQuotes = 0;
    int inSQuotes = 0;
    int len = strlen(input);
    
    i=0;
    k= 1;
    while (i < len) 
    {
        if (input[i] == '"')
            inDQuotes = !inDQuotes;
        if (input[i] == '\'')
            inSQuotes = !inSQuotes;
        input[j] = input[i];
        j++;
        if (input[i] == ' ' && !inDQuotes && !inSQuotes) {
   		k = i + 1;
            while (k < len && input[k] == ' ')
                k++;
            i = k - 1;
        }
     i++;
    }
    input[j] = '\0';
}

bool closed_quotes2(int single_quote, int double_quote)
{
	if (single_quote == 1 || double_quote == 1) 
	{
        	printf("unclosed quotes\n");
        	return (0);
    	}
    	else
        	return (1);
}

bool closed_quotes(t_data *shell) 
{
    int tam;
    int single_quote = 0;
    int double_quote = 0;
    int i;
    
    i = 0;
    single_quote = 0;
    double_quote = 0;
    tam = ft_strlen(shell->input);
    while (i < tam) 
    {
        if (shell->input[i] == '\'') 
        {
            if (double_quote % 2 == 0)
                single_quote = !single_quote;
        }
        else if (shell->input[i] == '\"') 
        {
            if (single_quote % 2 == 0) 
                double_quote = !double_quote;
        }
        i++;
    }
    return (closed_quotes2(single_quote, double_quote));
}

bool last_char(t_data *shell)
{
	char *input;
	int i;
	
	input = shell->input;
	i = 0;
	while(input[i] != '\0')
		i++;
	i--;
	while(input[i] == 32)
		i--;
	if((input[i] == '|') || (input[i] == '<') || (input[i] == '>'))
	{
		printf("Unexpected last char \n");
		return(0);
	}
	return(1);
}

bool first_char(t_data *shell)
{
	char *input;
	int i;
	
	input = shell->input;
	i = 0;
	while(input[i] == 32)
		i++;
	if((input[i] == '|') || (input[i] == '<'))
	{
		printf("Unexpected first char \n");
		return(0);
	}
	return(1);
}

int	verify_input(t_data *shell)
{
	if(*shell->input == '\0')
	{
		//free
		return (0);
	}
	if(!closed_quotes(shell))
	{
		//free
		return (0);
	}
	if(!first_char(shell))
	{
		return (0);
	}
	if(!last_char(shell))
	{
		return(0);
	}
	//rmvSpaces(shell->input);
	return (1);
}

