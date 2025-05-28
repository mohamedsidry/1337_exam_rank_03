

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int allpar(char *input);
void rip(char *par, unsigned char target, int start, int replaced, int toreplace);
int isbalanced(char *input);
char *ft_strdup(char *str);
int openclosed(char *str);

int main(int argc, char *argv[])
{
	int odd;
	unsigned char target;
	char *input;

	if (argc != 2)
		return (1);

	input = ft_strdup(argv[1]);
	if (!input)
		return (1);
	if (!allpar(input))
		return (1);
	odd = isbalanced(input);
	if (!odd)
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
	rip(input, target, 0, 0, odd);
	free(input);
	return (0);
}

void rip(char *par, unsigned char target, int start, int replaced, int toreplace)
{

	int star;
	int wasreplaced;

	wasreplaced = 0;
	if (replaced == toreplace)
	{

		printf("%s\n", par);
		return;
	}
	star = start;
	while (par[star])
	{
		if (par[star] == target)
		{
			par[star] = ' ';
			wasreplaced = 1;
			rip(par, target, 0, replaced + 1, toreplace);
            par[star] = target;
		}
		star++;
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

    while (str[i])
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