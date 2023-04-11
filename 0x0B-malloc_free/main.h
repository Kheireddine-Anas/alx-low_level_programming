#ifndef FILE_MAIN
#define FILE_MAIN

char *create_array(unsigned int size, char c);
char *_strdup(char *str);
char **strtow(char *str);
char *argstostr(int ac, char **av);
int **alloc_grid(int width, int height);

#endif
