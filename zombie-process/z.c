#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
  pid_t pid = fork();
  int cnt1=5;
  int cnt2 = 10;
  while(1)
  {

    if(pid == 0)
    {
      printf("我是子进程，我还有%ds就死了 pid=%d ppid=%d\n", cnt1, getpid(), getppid());
      sleep(1);
      cnt1--;
      if(cnt1 == 0)
        break;
    }
    else
    {
      printf("我是父进程，我还有%ds就死了 pid=%d ppid=%d\n", cnt2, getpid(), getppid());
      sleep(1);
      cnt2--;
      if(cnt2 == 0)
        break;
    }
  }
    return 0;
  
}
