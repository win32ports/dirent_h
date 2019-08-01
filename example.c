#ifdef NDEBUG
#undef NDEBUG
#endif

#include <dirent.h>
#include <assert.h>
#include <stdio.h>

static int alphasort_reverse(const void* a, const void* b)
{
	return -alphasort(a, b);
}

int main()
{
	DIR* d = opendir("C:\\Windows");
	if (!d)
		return -1;
	struct dirent* entry = NULL;
	while (entry = readdir(d))
		printf("%s\n", entry->d_name);
	closedir(d);
	struct dirent** namelist = NULL;
	struct dirent** p;
	scandir("C:\\Windows", &namelist, NULL, alphasort_reverse);

	printf("reversed\n");

	for (p = namelist; *p != NULL; ++p)
	{
		printf("%s\n", (*p)->d_name);
		free(*p);
	}
	free(namelist);
	
	return 0;
}
