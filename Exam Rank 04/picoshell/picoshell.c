#include <stdlib.h>
#include <unistd.h>

void ft_exec(char **cmd, int fd[], int prevfd, int next_pipe)
{
    if (prevfd != -1)
    {
        dup2(prevfd, 0);
        close(prevfd);
    }

    if (next_pipe)
    {
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
    }
    execvp(cmd[0], cmd);
    exit(1);
}

int ft_picoshell(char **cmds[])
{
    int fd[2];
    int prevfd = -1;
    int i = 0;
    int pid;
    int next;

    while (cmds[i])
    {
        next = 0;
        if (cmds[i + 1])
            next = 1;
        if (next)
            pipe(fd);
        pid = fork();
        if (pid == 0)
            ft_exec(cmds[i], fd, prevfd, next);
        if (prevfd != -1)
            close(prevfd);
        if (next)
        {
            prevfd = fd[0];
            close(fd[1]);
        }
        i++;
    }
    while (wait(NULL) > 0)
        ;

    return 1;
}

#include <stdio.h>

int main(void)
{
    char *cmd0[] = {"ls", "-l", NULL};
    char *cmd1[] = {"grep", "c", NULL};
    char **cmds[] = {cmd0, cmd1, NULL};

    ft_picoshell(cmds);
}