/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:14:26 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/11 12:07:07 by bpierce          ###   ########.fr       */
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
		return (ft_puterror(
					"\n[33m - Enter the name of ONE file, silly -[0m", 0));
	}
	stat(argv[1], &path_stat);
	if (!(S_ISREG(path_stat.st_mode) || EQU(argv[1], "-e")))
		return (ft_puterror(USAGE, -1));
	mlx = mlx_init();
	if (!(rt = initialize_rt(mlx, argv[1])))
		return (ft_puterror("Failed to initialize. Terminating.\n", -1));
	mlx_loop(mlx);
	return (1);
}
