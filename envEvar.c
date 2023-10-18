#include "shell.h"

char *varEnvm(char *env_key)
{
	char *v;
	int n;

	if (_strcmp(env_key, "?"))
	{
		n = statusmt(GET_STATUS, 0);
		return (_itoa(n));
	}
	if (_strcmp(env_key, "$"))
		return (_itoa(getpid()));
	v = envimat(GET_VALUE, env_key, NULL);
	return (v);
}
