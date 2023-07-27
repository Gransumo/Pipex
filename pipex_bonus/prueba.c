
# include <fcntl.h>
# include "Libft/libft.h"
int main(int argc, char **argv, char **envp)
{
	char	*path = "/usr/bin/awk";
	char	m[2];
	m[0] = "awk";
	m[1] = "{count++} END {print count}";
	execve(path, m, envp);
}