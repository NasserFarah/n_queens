
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	is_safe(int col, int row, int *arr)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (row == arr[i])
			return (0);
		if (abs(i - col) == abs(arr[i] - row))
			return (0);
		i++;
	}
	return (1);
}

void	queens(int n, int col, int row, int *arr)
{
	int	i;

	if (n == col)
	{
		i = 0;
		while (i < col)
		{
			printf("%i ", arr[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	while (row < n)
	{
		if (is_safe(col, row, arr))
		{
			arr[col] = row;
			queens(n, col + 1, 0, arr);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 2)
	{
		n = atoi(av[1]);
		int	arr[n];
		queens(n, 0, 0, arr);
	}
	return (0);
}
