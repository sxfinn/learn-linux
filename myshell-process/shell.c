#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#define NUM 1024
#define N 50
#define SPI " "
char command_line[NUM];
char* command_arg[N];
int main()
{
  while(1)
  {
    printf("[sx@Centos7.9 learn-linux]$ ");
    fgets(command_line, NUM, stdin);
    command_line[strlen(command_line) - 1] = '\0';
    pid_t id = fork();
    int cnt = 0;
    command_arg[cnt++] = strtok(command_line, SPI);
    while(command_arg[cnt++] = strtok(NULL, SPI));
    //int i = 0;
    //for( i = 0; i < cnt; i++)
    //{
    //  printf("%s\n", command_arg[i]);
    //}
    if(id == 0)
    {
      execvp(command_arg[0], command_arg);
      exit(1);//退出
    }
    int status = 0;
    pid_t ret = waitpid(id, &status, 0);
    if(ret > 0)
      printf("等待子进程成功！ signal:%d, code:%d\n", status&0x7f, (status>>8)&0xff);
  }
  return 0;
}
