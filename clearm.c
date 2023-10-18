#include "shell.h"

void clearMp(map_t *m)
{
	int iterator;

	iterator = 0;
	while (iterator < BACKET_SIZE)
	{
		free_list(m->backets[iterator], _clear_entry);
		iterator++;
	}
	free(m);
}
