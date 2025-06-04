

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int allpar(char *input);
void rip(char *par, unsigned char target, int start, int replaced, int toreplace, char **arr);
int isbalanced(char *input);
char *ft_strdup(char *str);
int openclosed(char *str);
void *ft_calloc(size_t count, size_t size);
void push(char **arr, char *new);
void free2d(char **arr);
int ft_strcmp(char *s1, char *s2);
void printarr(char **arr);

void ll(void)
{
	system("leaks a.out");
}
int main(int argc, char *argv[])
{
	int odd;
	unsigned char target;
	char *input;
	char *result;
	char **arr;

	if (argc != 2)
		return (1);

	arr = ft_calloc(100000, sizeof(char *));
	if (!arr)
		return (1);
	input = ft_strdup(argv[1]);
	if (!input)
	{
		free(arr);
		return (1);
	}
	if (!allpar(input))
		return (1);
	odd = isbalanced(input);
	if (!odd && openclosed(input) == 0)
	{
		printf("%s\n", input);
		free(input);
		return (0);
	}
	if (odd > 0)
		target = '(';
	else
	{
		target = ')';
		odd *= -1;
	}
	rip(input, target, 0, 0, odd, arr);
	printarr(arr);
	free(input);
	free2d(arr);
	//atexit(ll);
	return (0);
}

void rip(char *par, unsigned char target, int start, int replaced, int toreplace, char **arr)
{

	int star;
	int wasreplaced;

	wasreplaced = 0;
	if (replaced == toreplace)
	{

		push(arr, par);
		return;
	}
	star = start;
	while (par[star])
	{
		if (par[star] == target)
		{
			par[star] = ' ';
			wasreplaced = 1;
			rip(par, target, 0, replaced + 1, toreplace, arr);
            par[star] = target;
		}
		star++;
	}

}

void printarr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

char *ft_strdup(char *str)
{
	int idx;
	char *input;

	idx = 0;
	if (!str)
		return (0);
	while (str[idx])
		idx++;

	input = malloc(sizeof(char) * idx + 1);
	if (!input)
		return (NULL);
	while (idx >= 0)
	{
		input[idx] = str[idx];
		idx--;
	}
	return (input);
}

int isbalanced(char *input)
{
	int i = 0;
	int result;

	result = 0;
	while (input[i])
	{
		if (input[i] == '(')
			result++;
		else if (input[i] == ')')
			result--;
		i++;
	}
	return (result);
}

int allpar(char *input)
{
	int i = 0;
	if (!input)
		return (0);
	while (input[i])
	{
		if (input[i] != ')' && input[i] != '(')
			return (0);
		i++;
	}
	return (1);
}

int openclosed(char *str)
{
    int open;
    int close;
    int i;

    i = 0;
    open = 0;
    close = 0;

    while (str && str[i])
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
        {
            close++;
            if (open)
            {
                open--;
                close--;
            }
        }
        i++;
    }
    return (open == 0 && (open == close));
}



void *ft_calloc(size_t count, size_t size)
{
	long tot;
	size_t idx;
	char **arr;

	tot = count * size;
	idx = 0;

	arr = (char **)malloc(tot);
	if (!arr)
		return (NULL);
	while (idx < count)
	{
		arr[idx] = NULL;
		idx++;
	}
	return (arr);
}


void push(char **arr, char *new)
{
	static size_t idx;
	int i;
	int j;

	i = 0;
	if (idx == 0)
	{
		arr[idx] = ft_strdup(new);
		idx++;
		return;
	}
	else
	{
		while (arr[i])
		{
			int j = 0;
			while (arr[j] && ft_strcmp(arr[j], arr[i]))
				j++;
			if (arr[j] == arr[j] && openclosed(arr[j]) != 0)
			{
				arr[idx] = ft_strdup(new);
				idx++;
				return;
			}
			i++;
		}
	}
	idx++;
}


int ft_strcmp(char *s1, char *s2)
{
	if (*s1 || *s2)
		return (0);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


void free2d(char **arr)
{
	int i;
	i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}