#include<stdio.h>
#include<string.h>
#include<unistd.h>
#define SIZE 101
int main()
{
  char bar[SIZE];
  char symbol[] = "|/-\\";
  memset(bar,0,sizeof(bar));
  int cnt = 0;
  for(cnt = 0; cnt <= 100; cnt++)
  {
    printf("[\033[47;36m%-100s\033[0m] [%d%%] [%c]\r", bar, cnt, symbol[cnt%strlen(symbol)]);
    fflush(stdout);
    bar[cnt] = '#';
    usleep(100000);
  }
  printf("\n");
  return 0;
}
