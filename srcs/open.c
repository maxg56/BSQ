/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:44:23 by mgendrot          #+#    #+#             */
/*   Updated: 2024/08/26 16:45:47 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i_d;
	unsigned int	i_s;

	i_d = 0;
	i_s = 0;
	while (dest[i_d])
		i_d++;
	while (src[i_s] && i_s < nb)
	{
		dest[i_d] = src[i_s];
		i_d++;
		i_s++;
	}
	dest[i_d] = '\0';
	return (dest);
}

#define BUFFER_SIZE 128


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
		write(1, "map error\n", 40);
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

