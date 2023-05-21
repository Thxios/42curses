/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:09:45 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/21 17:29:48 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "utils/matrix.h"
#include "utils/vector.h"

typedef struct s_edge
{
	int	st;
	int	ed;
}		t_edge;

typedef struct s_vertex
{
	t_vec	rel_pos;
	t_vec	pos;
}			t_vertex;

typedef struct s_obj3d
{
	t_mat4		transform;
	int			n_vertices;
	t_vertex	*vertices;
	int			n_edges;
	t_edge		*edges;
}			t_obj3d;

#endif
