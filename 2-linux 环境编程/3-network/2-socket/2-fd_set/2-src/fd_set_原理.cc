#include <sys/select.h>

int main(int argc, char *argv[])
{
  fd_set readset;

  // Use gdb to see the value
  FD_ZERO(&readset); // readset = {fds_bits = {0 <repeats 32 times>}}

  FD_SET(0, &readset); // readset = {fds_bits = {1, 0 <repeats 31 times>}}
  FD_SET(1, &readset); // readset = {fds_bits = {3, 0 <repeats 31 times>}}
  FD_SET(2, &readset); // readset = {fds_bits = {7, 0 <repeats 31 times>}}
  FD_SET(4, &readset); // readset = {fds_bits = {23, 0 <repeats 31 times>}}
  FD_SET(8, &readset); // readset = {fds_bits = {279, 0 <repeats 31 times>}}
  FD_SET(32, &readset); // readset = {fds_bits = {279, 1, 0 <repeats 30 times>}}
  FD_SET(33, &readset); // readset = {fds_bits = {279, 3, 0 <repeats 30 times>}}
  FD_SET(1023, &readset); // readset = {fds_bits = {279, 3, 0 <repeats 29 times>, -2147483648}}

  // Wrong which is does not work, fd should between 0 <= fd <= 1023
  FD_SET(1024, &readset); // readset = {fds_bits = {279, 3, 0 <repeats 29 times>, -2147483648}}
  
  return 0;
}

/*
  g++ -E select_1.c

  Have a look what does the FD_SET() do
  
int main(int argc, char *argv[])
{
  fd_set readset;

  do { int __d0, __d1; __asm__ __volatile__ ("cld; rep; " "stosl" : "=c" (__d0), "=D" (__d1) : "a" (0), "0" (sizeof (fd_set) / sizeof (__fd_mask)), "1" (&((&readset)->fds_bits)[0]) : "memory"); } while (0);

  ((void) (((&readset)->fds_bits)[((0) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((0) % (8 * (int) sizeof (__fd_mask))))));
  ((void) (((&readset)->fds_bits)[((1) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((1) % (8 * (int) sizeof (__fd_mask))))));
  ((void) (((&readset)->fds_bits)[((2) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((2) % (8 * (int) sizeof (__fd_mask))))));
  ((void) (((&readset)->fds_bits)[((4) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((4) % (8 * (int) sizeof (__fd_mask))))));
  ((void) (((&readset)->fds_bits)[((8) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((8) % (8 * (int) sizeof (__fd_mask))))));
  ((void) (((&readset)->fds_bits)[((32) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((32) % (8 * (int) sizeof (__fd_mask))))));
  ((void) (((&readset)->fds_bits)[((33) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((33) % (8 * (int) sizeof (__fd_mask))))));
  ((void) (((&readset)->fds_bits)[((1023) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((1023) % (8 * (int) sizeof (__fd_mask))))));


  ((void) (((&readset)->fds_bits)[((1024) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) 1 << ((1024) % (8 * (int) sizeof (__fd_mask))))));

  return 0;
}
*/
