#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	safe(int col, int row, int *arr)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (arr[i] == row)
			return (0);
		if (abs(arr[i] - row) == abs(i - col))
			return (0);
		i++;
	}
	return (1);
}

void print_solution(int q, int *arr)
{
    int i;

    i = 0;
    while (i < q)
    {
        printf("%d ", arr[i] + 1); // +1 for human-readable (1..N)
        i++;
    }
    printf("\n");
}

void solve(int col, int row, int q, int *arr)
{
	if (col == q)
    {
        print_solution(q, arr);
        return;
    }
	while (row < q)
	{
		if (safe(col, row, arr))
		{
			arr[col] = row;
			solve(col + 1, 0, q, arr);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int	q;
	int	columns;
	int	rows;

	if (ac == 2)
	{
		q = atoi(av[1]);
		int	arr[q];
		rows = 0;
		columns = 0;
		solve(columns, rows, q, arr);
	}
	return (1);
}
