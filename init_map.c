#include "shell.h"

map_t *initMp(void)
{
	map_t *map = (map_t *)malloc(sizeof(map_t));
	int iterator;

	iterator = 0;
	while (iterator < BACKET_SIZE)
	{
		map->backets[iterator] = NULL;
		iterator++;
	}
	return (map);
}
