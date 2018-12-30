#include "printf.h"

char	*str_to_arg(char *format)
{
	char	*s;
	size_t	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	s = ft_strsub(format, 0, i);
	return (s);
}

int		main()
{
	char *format;
	char *buf;
	char *string;

	string = ft_strnew(0);
	format = ft_strdup("fuck %d\nbitches %c\n");
	while (*format)
	{
		buf = str_to_arg(format);
		format += ft_strlen(buf);
		ft_putstr(buf);
		ft_putstr(format);
		string = ft_strjoin(string, buf);
		free (buf);
		if (!*format)
			break ;
		string = ft_strjoin(string, "69");
		format += flag_skip(format) + 1;
		ft_putstr(format);
	}
	ft_putstr(string);
	free (string);
	return (0);
}
