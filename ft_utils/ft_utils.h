/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:24:38 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/02 16:36:08 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdio.h>

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <signal.h>

int	ft_printf(const	char *string, ...);
int	ft_putchar(char c);
int	ft_putstr(char *string);
int	ft_print_ptr(unsigned long address, char *hex_vocabulary);
int	ft_print_address(unsigned long address, char *hex_vocabulary);
int	ft_print_int(int number);
int	ft_print_u_int(unsigned int number);
int	ft_print_num_hex(unsigned int hex_number, char *hex_vocabulary);
int	ft_atoi(char *str);

#endif
