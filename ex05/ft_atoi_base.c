/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:27:41 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/10 21:48:00 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	indexof(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base, int *len)
{
	int	i;

	*len = 0;
	while (base[*len] != '\0')
	{
		if (indexof(base[*len], "+- \f\n\r\t\v") != -1)
			return (1);
		i = *len;
		while (base[++i] != '\0')
			if (base[*len] == base[i])
				return (1);
		(*len)++;
	}
	return (*len <= 1);
}

void	skip_arbitrary(char *str, int *sign, int *i)
{
	*i = 0;
	*sign = 1;
	while (indexof(str[*i], " \f\n\r\t\v") != -1)
		(*i)++;
	while (indexof(str[*i], "+-") != -1)
	{
		if (str[(*i)++] == '-')
			*sign *= -1;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	sign;
	int	base_len;

	if (check_base(base, &base_len))
		return (0);
	skip_arbitrary(str, &sign, &i);
	n = 0;
	while (indexof(str[i], base) != -1)
		n = n * base_len + indexof(str[i++], base);
	return (sign * n);
}
