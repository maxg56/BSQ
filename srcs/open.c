/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:44:23 by mgendrot          #+#    #+#             */
/*   Updated: 2024/08/26 16:12:12 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128
int *ft_relloc(char *pt ,int t  )
{
	int	i;
	char *ru ;
	
	i = 0 ;
	ru = malloc(t);
	while (pt[i])
	{
		ru[i] = pt[i];
		i++;
	}
    free(pt); 
	return (ru);
}

int *ft_fopen(char *n , char *result)
{
	int	fd;
	char	buffer[BUFFER_SIZE];
	size_t	totalSize;
	ssize_t	bytesRead;
	
	totalSize = 0 ;
	fd = open(n, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Erreur lors de l'ouverture du fichier.\n", 40);
		return (NULL);
	}
	result = malloc(1);
	if (result == NULL)
	{
		close(fd);
		return (NULL);
	}
	while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytesRead] = '\0';
		totalSize += bytesRead;
		result = ft_realloc(result, totalSize + 1);
		if (result == NULL)
		{
			close(fd);
			return (NULL); 
		}
		strncat(result, buffer, bytesRead);
	}
	close(fd);  
	return result;
}

int	main(void)
{
    char *fileContent = ft_fopen("tsts.txt");
    
    if (fileContent)
    {
        printf("%s", fileContent);
        free(fileContent); // Libérer la mémoire allouée
    }
    
    return 0;
}

