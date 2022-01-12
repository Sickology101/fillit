/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:03:03 by marius            #+#    #+#             */
/*   Updated: 2022/01/12 15:03:29 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	if_connected(char **tetrimino, int i, int j, int c)
{
	if (tetrimino[i][j - 1] == '#' || tetrimino[i][j - 1] == c)
		return (1);
	if (tetrimino[i][j + 1] == '#' || tetrimino[i][j + 1] == c)
		return (1);
	if (tetrimino[i - 1][j] == '#' || tetrimino[i - 1][j] == c)
		return (1);
	if (tetrimino[i + 1][j] == '#' || tetrimino[i + 1][j] == c)
		return (1);
	return (0);
}

int	check_valid(char **tetrimino, int c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (tetrimino[i] != NULL && i < 5)
	{
		j = 0;
		while (tetrimino[i][j] != '\0' && j < 5)
		{
			if (tetrimino[i][j] != '.')
			{
				if (tetrimino[i][j] == '#' && if_connected(tetrimino, i, j))
					{
						tetrimino[i][j] = c;
						index++;
					}
				else
					return (0);
			}
			j++;
		}
		if (j != 3 || index > 4)
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}