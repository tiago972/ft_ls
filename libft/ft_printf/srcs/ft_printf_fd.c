#include "../includes/ft_printf.h"

static void		ft_reinit_struct_fd(t_printf *v_printf, int fd)
{
	v_printf->flags = 0;
	v_printf->width = 0;
	v_printf->prec = -2;
	v_printf->conv = 0;
	v_printf->tmp = 0;
	v_printf->power = 0;
	v_printf->col = 0;
	v_printf->fd = fd;
}
int				ft_printf_fd(int fd, const char *str, ...)
{
	t_printf		v_printf;
	static t_funptr	funptr[14];

	if (!str)
		return (0);
	ft_begin(&v_printf, str, funptr);
	va_start(v_printf.ap, str);
	while (*(v_printf.str))
	{
		if (*(v_printf.str) && *(v_printf.str) == '%' && v_printf.str++)
		{
			ft_reinit_struct_fd(&v_printf, fd);
			ft_get_info(&v_printf, funptr);
		}
		else
		{
			ft_buff(&v_printf, v_printf.str, 1);
			v_printf.str++;
		}
	}
	if (v_printf.ret_progress > 0)
		ft_flush(&v_printf);
	va_end(v_printf.ap);
	return (v_printf.ret_tot);
}
