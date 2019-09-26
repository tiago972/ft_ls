/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/15 16:50:42 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <string.h>
# define F_SIZE 1001
# define BUFF_SIZE 2048
# define MINUS (1 << 0)
# define PLUS (1 << 1)
# define ZERO (1 << 2)
# define SP (1 << 3)
# define POUND (1 << 4)
# define B (1 << 5)
# define DOT (1 << 6)
# define STAR (1 << 7)
# define H (1 << 8)
# define HH (1 << 9)
# define L (1 << 10)
# define LL (1 << 11)
# define LF (1 << 12)
# define C (1 << 0)
# define S (1 << 1)
# define D (1 << 2)
# define I (1 << 3)
# define O (1 << 4)
# define U (1 << 5)
# define X (1 << 6)
# define XX (1 << 7)
# define P (1 << 8)
# define J (1 << 9)
# define Z (1 << 10)
# define POURCENT (1 << 11)
# define UU (1 << 12)
# define F (1 << 13)
# define RED (1 << 0)
# define BLUE (1 << 1)
# define GREEN (1 << 2)
# define YELLOW (1 << 3)

typedef struct	s_printf
{
	char			*str;
	int				flags;
	int				width;
	int				prec;
	int				conv;
	char			buff[BUFF_SIZE + 1];
	int				ret_progress;
	int				ret_tot;
	va_list			ap;
	int				tmp;
	uintmax_t		power;
	int				col;
}				t_printf;

typedef struct	s_float
{
	char			*res;
	long double		f_arg;
	char			*mant;
	int				exp;
	int				sign;
	char			*tmp;
	char			*dec;
	unsigned char	*ptr;
	int				int_size;
}				t_float;

typedef struct	s_funptr
{
	int		conv;
	void	(*f)(t_printf *);
}				t_funptr;

typedef struct	s_col
{
	int		nb;
	char	col[6];
}				t_col;

int				ft_printf(const char *str, ...);
void			ft_begin(t_printf *v_printf, const char *str,
				t_funptr funptr[14]);
void			ft_buff(t_printf *v_printf, char *str, int n);
void			ft_inifunptr(t_funptr funptr[14]);
void			ft_inifunptr2(t_funptr funptr[14]);
void			ft_inivprintf(t_printf *v_printf, const char *str);
void			ft_get_info(t_printf *v_printf, t_funptr funptr[14]);
void			ft_get_size(t_printf *v_printf);
void			ft_dispatch(t_printf *v_printf, t_funptr funptr[14]);
uintmax_t		ft_log(uintmax_t nb, uintmax_t base);
void			ft_pad_c(t_printf *v_printf);
void			ft_pad_s(t_printf *v_printf);
char			*ft_pad_s2(int *tmp, char *str_arg,
				t_printf *v_printf, int *len);
void			ft_pad_i(t_printf *v_printf);
void			ft_pad_p(t_printf *v_printf);
void			ft_pad_u(t_printf *v_printf);
void			ft_handle_f(t_printf *v_printf);
void			ft_handle_f2(t_printf *v_printf, t_float *f, char *cpy_str);
void			ft_pad_escape(t_printf *v_printf);
void			ft_dispatch_jz(t_printf *v_printf);
uintmax_t		ft_log_dispatch(t_printf *v_printf, uintmax_t uintarg);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
intmax_t		ft_get_arg_i(t_printf *v_printf);
void			ft_putnbr_pf(t_printf *v_printf, intmax_t n, uintmax_t power);
void			ft_get_conversion(t_printf *v_printf);
uintmax_t		ft_abs(intmax_t a);
void			ft_llong_min(t_printf *v_printf, intmax_t int_arg);
void			ft_fill_nb_i(t_printf *v_printf, intmax_t int_arg, int opt);
uintmax_t		ft_get_arg_u(t_printf *v_printf);
void			ft_putnbr_pf_u(t_printf *v_printf, uintmax_t nb, char *base,
				uintmax_t power);
void			ft_pad_nbr(t_printf *v_printf, uintmax_t uintarg);
void			ft_print_u(t_printf *v_printf, uintmax_t uintarg,
				uintmax_t power);
void			ft_get_width(t_printf *v_printf);
uintmax_t		ft_leading_zero(uintmax_t nb);
void			ft_particular_octal(t_printf *v_printf, uintmax_t uintarg);
long double		ft_get_arg_f(t_printf *v_printf);
void			ft_sign_f(t_float *f);
void			ft_get_exp(t_float *f);
intmax_t		ft_iterative_power(intmax_t nb, int power);
int				ft_isna(t_float *f, t_printf *v_printf);
int				ft_isinf(t_float *f, t_printf *v_printf);
int				ft_initialize_f_char(t_float *f_float);
void			ft_get_mant(t_float *f_float);
void			ft_expand_mant(t_float *f_float);
void			ft_calc_int(t_float *f_float);
void			ft_power_to_char(t_float *f_float,
				int power, int mant_firstnbr);
int				ft_where_is_not_0(char *str, int index);
void			ft_add_in_char(t_float *f);
void			ft_calc_dec(t_float *f);
void			ft_add_dec_in_char(t_float *f);
void			ft_to_front(t_float *f);
void			ft_del_f(t_float *f);
void			ft_pad_f(t_printf *v_printf, t_float *f, int opt);
void			ft_pad_f_opt(t_printf *v_printf, t_float *f, int opt);
void			ft_round(t_printf *v_printf, t_float *f);
void			ft_getcol(t_printf *v_printf);
void			ft_inicol(t_col col[4]);
void			ft_printcol(t_printf *v_printf);
void			ft_bin(t_printf *vprintf);
void			*ft_get_arg_b(t_printf *v_printf);
void			*ft_malloc_tmp(t_printf *v_printf);
unsigned		ft_i_size_i(t_printf *v_printf);
int				ft_begin_f(t_float *f, t_printf *v);
void			ft_if_f(t_float *f, t_printf *v_printf, int opt);

#endif
