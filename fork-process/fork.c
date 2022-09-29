#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
  pid_t pid = fork();
 while(1)
 {
  if(pid == 0)
  {

    printf("我是子进程！pid=%d ppid=%d\n", getpid(), getppid());
    sleep(1);
  }
  else
  {
    printf("我是父进程！pid=%d ppid=%d\n", getpid(), getppid());

    sleep(1);
  }
 }
  return 0;
}
