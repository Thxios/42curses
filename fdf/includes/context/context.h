/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:23:07 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/14 20:36:14 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

typedef struct s_context
{
	void	*mlx;
	void	*window;
}			t_context;

t_context	*ctx(void);
void		*mlx(void);
void		*window(void);


void	init_context(void);
void	launch_window(int width, int height, char *title);

#endif
