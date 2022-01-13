/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:38:28 by marius            #+#    #+#             */
/*   Updated: 2022/01/13 11:03:14 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 1
# define MAX_SIZE 1000

/*typedef struct	s_node
{
	struct s_node	*up;
	struct s_node	*down;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*column;
	char			*name;
	int				size;
}					t_node;

typedef struct	s_node_header
{
	struct s_node	*column;
	}					t_column_header;

typedef	struct	s_header
{
	struct			*right;
	struct			*left;
}					t_header;
*/

char	*read_file(int fd, int *error);
int		check_valid(char *tetrimino);

#endif
