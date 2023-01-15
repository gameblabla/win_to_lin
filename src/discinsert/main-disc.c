#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int printdir(char *dir, int depth)
{
	int numberfiles = 0;
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return 0;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL) 
    {
        lstat(entry->d_name,&statbuf);

        if(S_ISDIR(statbuf.st_mode)) {
            /* Found a directory, but ignore . and .. */
            if(strcmp(".",entry->d_name) == 0 ||
                strcmp("..",entry->d_name) == 0)
                continue;
            printf("%*s%s/\n",depth,"",entry->d_name);

            /* Recurse at a new indent level */
            printdir(entry->d_name,depth+4);
        }
        else printf("%*s%s\n",depth,"",entry->d_name);
    }
    chdir("..");
    closedir(dp);
    
    return 1;
}

int countfiles(char *path) {
    size_t count = 0;
    struct dirent *res;
    struct stat sb;

    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)){
        DIR *folder = opendir ( path );

        if (access ( path, F_OK ) != -1 ){
            if ( folder ){
                while ( ( res = readdir ( folder ) ) ){
                    if ( strcmp( res->d_name, "." ) && strcmp( res->d_name, ".." ) ){
                        //printf("%zu) - %s\n", count + 1, res->d_name);
                        count++;
                    }
                }

                closedir ( folder );
            }else{
                return 0;
            }
        }

    }else{
        return 0;
    }

    return count;
}


int main()
{
    printf("Directory scan of CDROM:\n");
    printf("Number of files : %d\n", countfiles("/media/cdrom"));

    exit(0);
}
