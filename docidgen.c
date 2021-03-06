/*
 * Copyright (c) 2015 ARClab, Lionel Riem - https://arclab.ch/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * docidgen -- Document ID generator
 * Based on an UUID v4, but without hyphens.
 */

int
main(void)
{
   unsigned char r[16];
   int i;

   (void)srand((unsigned int)time(NULL));

   for(i = 0; i < 16; i++) {
      r[i] = (unsigned char)rand() % 255;
      if(i == 6) {
         r[i] = 0x40 | (r[i] & 0xf);
      }
      if(i == 8) {
         r[i] = 0x80 | (r[i] & 0x3f);
      }
      printf("%02x", r[i]);
   }

   printf("\n");

   return EXIT_SUCCESS;
}
