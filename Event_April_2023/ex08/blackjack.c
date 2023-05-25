#include <stdio.h>
#include <stdlib.h>

static	int get_card_value(char card)
{
    if (card >= '2' && card <= '9')
        return card - '0';
	else if (card == 'T' || card == 'J' || card == 'D' || card == 'K')
        return 10;
	else
        return 0;
}

int	main(int ac, char **av)
{
	int	point;
	int	i;
	int	value;

	point = 0;
	i = 0;
	if (ac != 2)
		return (printf("arguments error\n"), exit(1), 0);
	while (av[1][i])
	{
		point += get_card_value(av[1][i]);
		i++;
	}
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == 'A')
		{
			if (point < 21)
				point += 11;
			else
				point += 1;
		}
		i++;
	}
	printf("%d\n", point);
	return (0);
}