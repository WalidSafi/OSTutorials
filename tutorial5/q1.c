#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *hello_world(void *params);
void *good_bye(void *params);

int main() {

  srand(time(NULL));

  pthread_t hello; pthread_t goodbye;

  pthread_create(&hello,NULL,hello_world,NULL);
  pthread_create(&goodbye,NULL,good_bye,NULL);

  pthread_join(hello,NULL);
  pthread_join(goodbye,NULL);
}

void *hello_world(void *params){

int randomInterval = rand() %3 + 1;

sleep(randomInterval);

puts("hello World");

return 0;

}

void *good_bye(void *params){

int randomInterval = rand() %5 + 1;

sleep(randomInterval);

puts("goodbye");

return 0;
}
