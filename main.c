#include "inc/ft_printf.h"

int		main()
{
	int ret1;
	int ret2;

	ret1 = 0;
	ret2 = 0;
	ret1 = ft_printf("{%C}\n", L'é');
	ret2 = printf("{%C}\n", L'é');
//	ret2 = printf("{%S}\n", L"米");
	printf("%d, %d\n", ret1, ret2);
	return (0);
}
