/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:14:26 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/07 20:54:55 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	void		*mlx;
	t_rt		*rt;
	struct stat	path_stat;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	if (ft_strequ(argv[1], "-h"))
	{
		ft_putstr(LEGEND);
		return (0);
	}
	stat(argv[1], &path_stat);
	if (!(S_ISREG(path_stat.st_mode)))
		return (ft_puterror(USAGE, -1));
	mlx = mlx_init();
	if (!(rt = initialize_rt(mlx, argv[1])))
		return (ft_puterror("Failed to initialize. Terminating.\n", -1));
	mlx_loop(mlx);
	return (0);
}
