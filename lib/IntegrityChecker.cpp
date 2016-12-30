//
// Created by alin on 12/30/16.
//

#include <unistd.h>
#include <sys/wait.h>

#include "../include/IntegrityChecker.h"

std::string IntegrityChecker::hashForFile(const char *path)
{
    int pipefd[2];
    pipe(pipefd);

    int pid = fork();
    if (!pid)
    {
        close(1);
        dup(pipefd[1]);
        execlp ("sha1sum", "sha1sum", path, NULL);
        fprintf (stderr, "exec - 1\n");
        exit (1);
    }
    else
    {
        wait(NULL);
        char c;
        char* hash = (char*) malloc(50);
        int i = 0;
        while (read(pipefd[0],&c,1))
        {
            if (c!=' ')
            {
                hash[i++] = c;
            }
            else break;
        }
        hash[i] = 0;
        return std::string(hash);
    }

}

bool IntegrityChecker::checkIntegrity(FileDescription fileDescription, const char *path) {
    using std::string;
    string hash = hashForFile(path);
    if (!hash.compare(fileDescription.getHash()))
        return true;
    return false;

}
