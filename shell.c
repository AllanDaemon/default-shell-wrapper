#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <linux/limits.h>
#include <unistd.h>

#ifndef USER_ID
#define USER_ID 1000
#endif

int get_default_shell(char *shell_path)
{
	struct passwd* entry;

	while( entry = getpwent() )
	{
		if( entry->pw_uid == USER_ID )
		{
			strncpy(shell_path, entry->pw_shell, PATH_MAX);
			endpwent();
			return 0;
		}
	}
	endpwent();
	return 1;
}


int main(int argc, const char *argv[])
{
	char shell_path[PATH_MAX];
	
	if(get_default_shell(shell_path))
	{
		perror("User not found");
		return -1;
	}

	// printf("DBG: %u -> %s\n", USER_ID, shell_path);
	argv[0] = shell_path;
	execv(shell_path, (char * const*) argv);

	perror("Error on exec");
	return -1;
}
