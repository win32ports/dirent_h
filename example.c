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

int main(int argc, char * argv[])
{
	DIR* d;
	char * path;
	if (argc > 1)
		path = argv[1];
	else
		path = "C:\\Windows";

	d = opendir(path);
	if (!d)
		return -1;
	struct dirent* entry = NULL;
	while (entry = readdir(d))
		printf("%s\n", entry->d_name);
	closedir(d);
	struct dirent** namelist = NULL;
	struct dirent** p;
	scandir(path, &namelist, NULL, alphasort_reverse);

	printf("reversed\n");

	for (p = namelist; *p != NULL; ++p)
	{
		if ((*p)->d_type == DT_DIR)
			printf("%s\\\n", (*p)->d_name);
		else
			printf("%s\n", (*p)->d_name);
		free(*p);
	}
	free(namelist);
	
	return 0;
}
