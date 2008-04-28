/*  Glue functions for the minIni library, based on the FatFs and Tiny-FatFs
 *  libraries, see http://elm-chan.org/fsw/ff/00index_e.html
 *
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

#define INI_BUFFERSIZE  256       /* maximum line length, maximum path length */

/* You must set _USE_STRFUNC to 1 or 2 in the include file ff.h (or tff.h)
 * to enable the "string functions" fgets() and fputs().
 */
#include "ff.h"                   /* include tff.h for Tiny-FatFs */
#define INI_FILETYPE    FIL

#define ini_openread(filename,file)   (f_open((file),(filename), \
                                        FA_READ+FA_OPEN_EXISTING) == 0)
#define ini_openwrite(filename,file)  (f_open((file),(filename), \
                                        FA_WRITE+FA_CREATE_ALWAYS) == 0)
#define ini_close(file)               f_close(file)
#define ini_read(buffer,size,file)    fgets((buffer),(size),(file))
#define ini_write(buffer,file)        fputs((buffer),(file))
#define ini_rename(source,dest)       f_rename((source),(dest))
#define ini_remove(filename)          f_unlink(filename)
