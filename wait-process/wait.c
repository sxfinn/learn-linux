#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
  pid_t pid = fork();
  int state = 0;
  if(pid == 0)
  {
    while(1)
    {
      printf("i am child process, 10s后我将死亡 pid=%d\n", getpid());
      sleep(10);
      break;
    }
    exit(1);
  }
  else
  {
    printf("i am father process, 我要准备等待子进程了！\n");
    pid_t ret = waitpid(-1, &state, 0);
    if(ret > 0)
    {
      if(WIFEXITED(state))
        printf("子进程正常终止！return:%d\n", WEXITSTATUS(state));
      else if(WIFSIGNALED(state))
        printf("子进程异常终止！signal:%d\n", WTERMSIG(state));
    }
  }
  return 0;
}
