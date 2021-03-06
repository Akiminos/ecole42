/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twos_complement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:28:37 by bdruez            #+#    #+#             */
/*   Updated: 2019/12/09 17:54:55 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_twos_complement(int nb)
{
	return (~(nb) + 1);
}
