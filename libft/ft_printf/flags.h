/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:05:16 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 12:41:02 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# define F_NO_SIGN 0
# define F_SIGN_SPACE 1
# define F_SIGN_PLUS 2
# define F_NO_PADDING 0
# define F_ZERO_PADDING 1
# define F_ZERO_PRECISION 2

typedef struct s_flags{
	char	left_align;
	char	zero_padding;
	char	sign;
	char	base_visible;
	size_t	width;
	size_t	precision;
}	t_flags;
#endif
