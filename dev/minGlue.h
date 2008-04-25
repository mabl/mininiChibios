/*  Glue functions for the minIni library
 *
 *  Copyright (c) ITB CompuPhase, 2008
 *
 *  This software is provided "as-is", without any express or implied warranty.
 *  In no event will the authors be held liable for any damages arising from
 *  the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1.  The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software. If you use this software in
 *      a product, an acknowledgment in the product documentation would be
 *      appreciated but is not required.
 *  2.  Altered source versions must be plainly marked as such, and must not be
 *      misrepresented as being the original software.
 *  3.  This notice may not be removed or altered from any source distribution.
 *
 *  Version: $Id$
 */

#define INI_BUFFERSIZE  512       /* maximum line length, maximum path length */

/* map required file I/O to the standard C library */
#include <stdio.h>
#define ini_read(buffer,size,fp)  fgets((buffer),(size),(FILE*)(fp))
#define ini_write(buffer,fp)      fputs((buffer),(FILE*)(fp))
#define ini_openread(filename)    fopen((filename),"rt")
#define ini_openwrite(filename)   fopen((filename),"wt")
#define ini_close(fp)             fclose((FILE*)(fp))
#define ini_rename(source,dest)   rename((source),(dest))
#define ini_remove(filename)      remove(filename)
