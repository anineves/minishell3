#include "minishell.h"

char *ft_strtok(char *str, const char *delim) 
{
    static char *last_token = NULL;
    char *token;
    int found_d;
    const char *d;
    
    token = NULL;
    if (str != NULL)
        last_token = str;
    if (last_token == NULL)
        return NULL;
    token = last_token;
    while (*last_token != '\0') 
    	{
        	found_d = 0;
        	d = delim;
        	while (*d != '\0') 
        	{
            		if (*last_token == *d) 
            		{
                		found_d = 1;
                		*last_token = '\0';
                		last_token++;
                		break;
            		}
            	d++;
        	}
        if (found_d) 
        {
            if (token != last_token - 1) 
                return token;
            else 
                token = last_token;
        }
        last_token++;
    }
    if (*token != '\0') 
        return token;
    else 
        return NULL;
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}
