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
#include <err.h>
#include <uuid.h>

int
main(void)
{
   int i;
   char *p, d[33];
   uuid_t uuid;

   if(uuidgen(&uuid, 1) != 0) {
      err(1, "uuidgen()");
   }

   uuid_to_string(&uuid, &p, NULL);
   for(i = 0; i < 32; i++) {
      if(i == 8 || i == 12 || i == 16 || i == 20) {
         p++;
      }
      d[i] = *p++;
   }

   d[32] = '\0';
   free(p);

   printf("%s\n", d);

   return EXIT_SUCCESS;
}
