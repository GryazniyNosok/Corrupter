#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
char **files = NULL; //Array of strings
int fileCount = 0;



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
        char **temp = realloc(files, sizeof(char *) * (fileCount + 1));
        if(temp == NULL)
        {
            printf("Memory reallocation failed\n");
            closedir(dr);
            return ;
        }
        files = temp;

        files[fileCount] = (char *)malloc(strlen(de->d_name)+1);
        if(files[fileCount]==NULL)
        {
            closedir(dr);
            return;
        }
        
        strcpy(files[fileCount], de->d_name);
        fileCount++;
        
    }

    for(int x = 0; x < fileCount; x++)
    {
        printf("%s\n", files[x]);
    }

    closedir(dr);
    
}

int main() {
    
    
    getDirectories();
    for (int i = 0; i < fileCount; i++)
    {
        free(files[i]);
    }
    free(files);
    return 0;


}
