#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define LSH_RL_BUFSIZE 1024

char *lsh_read_line(void) {
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1){
        //read a char 
        c = getchar();

        //if EOF, replace it with a null char and return
        if (c == EOF || c == '\n'){
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        //if we have exceeded the buffer, reallocate.
        if (position >= bufsize){
            
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer,bufsize);
            if (!buffer){
            fprintf(stderr,"lsh: allocation error\n");
            exit(EXIT_FAILURE);
            }
        }
    }
}
    

void lsh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf(">");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);
}




int main(int argc, char **argv) {


    lsh_loop();

    return EXIT_SUCCESS;


}

