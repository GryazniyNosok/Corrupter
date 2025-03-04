#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

char *files; 

void getDirectories()
{
    struct dirent *de;

    DIR *dr = opendir(".");

    if(dr == NULL)
    {
        printf("Couldn't open directory");
    }

    while ((de = readdir(dr)) != NULL)
    {
        char *file;
        

        //printf("%s\n", de->d_name);
        //files += (de->d_name);
    }

    closedir(dr);
    
}

int main() {
    
    
    getDirectories();
    return 0;


}
