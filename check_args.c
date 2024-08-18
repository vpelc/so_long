/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:55:45 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/08 16:03:28 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < (n - 1) && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_args(int argc, char *argv[])
{
	if (argc < 2)
		pass;
		//call error too little
	if (argc > 2)
		pass;
		//call error too much
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
		pass; 
		//call error not .ber file
}