#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
    DIR* FD;
    struct dirent* in_file;
    FILE    *common_file;
    FILE    *entry_file;
    char    buffer[BUFSIZ];
    /* Scanning the in directory */
    if (NULL == (FD = opendir ("."))) 
    {
        fprintf(stderr, "Error : Failed to open input directory - %s\n", strerror(errno));
        fclose(common_file);

        return 1;
    }
    while ((in_file = readdir(FD))) 
    {
        /* On linux/Unix we don't want current and parent directories
         * On windows machine too
         */
        if (!strcmp (in_file->d_name, "."))
            continue;
        if (!strcmp (in_file->d_name, ".."))    
            continue;
        /* Open directory entry file for common operation */
        /* TODO : change permissions  */
        entry_file = fopen(in_file->d_name, "rw");
        if (entry_file == NULL)
        {
            fprintf(stderr, "Error : Failed to open entry file - %s\n", strerror(errno));
            fclose(common_file);

            return 1;
        }
        /* Doing some struf with entry_file : */
        while (fgets(buffer, BUFSIZ, entry_file) != NULL)
        {
            /* Use fprintf or fwrite to write some stuff into common_file*/
           puts(buffer);
        }

        /* When you finish with the file, close it */
        fclose(entry_file);
    }
    /* Close common file before leaving */
    fclose(common_file);
    return 0;
}

/* TODO: Delete files */
int delete(char *argv[]) {
   if (remove(argv[0]) == 0) 
      printf("Deleted successfully"); 
   else
      printf("Unable to delete the file"); 
  
   return 0; 
}

/* TODO: Search tag into selected files */
void searchTag(){}
/* TODO: Delete all code between tag into selected files */
void deleteSelectedTag(){}
/* TODO: Format selected files */
void formatFile(){}
/* TODO: Launch Bash script */
void lunchBash(){}