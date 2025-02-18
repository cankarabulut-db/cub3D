/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgokcu <sgokcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:29:33 by erkoc             #+#    #+#             */
/*   Updated: 2025/02/07 15:29:37 by sgokcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_all(t_cub *parser)
{
	free_double_ptr(parser->file);
	free(parser->north_img);
	free(parser->west_img);
	free(parser->south_img);
	free(parser->east_img);
	free_double_ptr(parser->map);
}
