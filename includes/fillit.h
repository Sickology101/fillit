/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:38:28 by marius            #+#    #+#             */
/*   Updated: 2022/01/12 17:50:47 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "fillit/libft"
# define BUFF_SIZE 1

typedef struct	s_node
{
	struct s_node	*up;
	struct s_node	*down;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*column;
	char			*name;
	int				size;
}					t_node;
/*
typedef struct	s_node_header
{
	struct s_node	*column;
	}					t_column_header;
*/
typedef	struct	s_header
{
	struct			*right;
	struct			*left;
}					t_header;

#endif
