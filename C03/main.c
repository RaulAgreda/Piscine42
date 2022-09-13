int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_strstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

void	printstr(char *str)
{
	if (str == 0)
	{
		write(1, "NULL\n", 5);
		return;
	}
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
	write(1, str, 1);
	write(1, "\n", 1);
}

void	clean_buffer(char *buf, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (i == size - 1)
			buf[i] = 0;
		buf[i] = ' ';
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char dest[1024];

		switch (atoi(argv[1]))
		{
			case 0: 
				printf("my function: 		%d\n", ft_strcmp(argv[2], argv[3]));
				printf("original function: 	%d\n", ft_strcmp(argv[2], argv[3]));
				break;
			case 1:
				printf("my function: %d\n", ft_strncmp(argv[2], argv[3], atoi(argv[4])));
				printf("original function: %d\n", strncmp(argv[2], argv[3], atoi(argv[4])));
				break;
			case 2:
				ft_strcpy(dest, argv[2]);
				write(1, "my function:\n", 13);
				printstr(ft_strcat(dest, argv[3]));
				ft_strcpy(dest, argv[2]);
				write(1, "original function:\n", 19);
				printstr(strcat(dest, argv[3]));
				break;
			case 3:
				ft_strcpy(dest, argv[2]);
				write(1, "my function:			", 14);
				printstr(ft_strncat(dest, argv[3], atoi(argv[4])));
				ft_strcpy(dest, argv[2]);
				write(1, "original function:	", 19);
				printstr(strncat(dest, argv[3], atoi(argv[4])));
				break;
			case 4:
				write(1, "my function:\n", 13);
			   	printstr(ft_strstr(argv[2], argv[3]));
				write(1, "original function:\n", 19);
				printstr(strstr(argv[2], argv[3]));
				break;
			case 5:
				ft_strcpy(dest, argv[2]);
				printf("%s\n", dest);
				printf("my_function:		n: %d %s\n", ft_strlcat(dest, argv[3], atoi(argv[4])), dest);
				ft_strcpy(dest, argv[2]);
				printf("%s\n", dest);
				printf("original function:	n: %lu %s\n", strlcat(dest, argv[3], atoi(argv[4])), dest);
				break;
		}
	}
	return (0);
}
