#include "potlood.c"
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

static uint32_t pixels[HEIGHT * WIDTH];

int main(void) {
  potlood_fill(pixels, WIDTH, HEIGHT, 0xFF0000FF);

  const char* file_path = "output.ppm";
  Errno err = potlood_save_to_ppm_file(pixels, WIDTH, HEIGHT, file_path);
  if(err) {
    fprintf(stderr, "ERROR: Could not save file %s: %s\n", file_path, strerror(errno));
    return 1;
  }
  return 0;
}
