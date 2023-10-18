#include "shell.h"

char *exclct(const char *line)
{
	int comment_position;

	comment_position = positionGet(line);
	return (stlinstttt(line, 0, comment_position));
}
