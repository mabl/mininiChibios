/*  Glue functions for the minIni library, based on the EFS Library, see
 *  http://www.efsl.be/
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

#include "efs.h"
#define INI_FILETYPE    EmbeddedFile
#define INI_LINETERM    "\r\n"    /* set line termination explicitly */


extern EmbeddedFileSystem g_efs;

#define ini_openread(filename,file)   (file_fopen((file),&g_efs.myFs, \
                                        (char*)(filename),'r') == 0)
#define ini_openwrite(filename,file)  (file_fopen((file),&g_efs.myFs, \
                                        (char*)(filename),'w') == 0)
#define ini_close(file)               file_fclose(file)
#define ini_read(buffer,size,file)    (file_read((file),(size),(buffer)) > 0)
#define ini_write(buffer,file)        file_write((file),strlen(buffer),(char*)(buffer))
#define ini_remove(filename)          rmfile(&g_efs.myFs,(char*)(filename))

/* EFSL lacks a rename function, so instead we copy the file to the new name
 * and delete the old file
 */
static int ini_rename(char *source, const char *dest)
{
  EmbeddedFile fr, fw;
  int n;

  if (file_fopen(&fr, &g_efs.myFs, source, 'r') != 0)
    return 0;
  if (rmfile(&g_efs.myFs, (char*)dest) != 0)
    return 0;
  if (file_fopen(&fw, &g_efs.myFs, (char*)dest, 'w') != 0)
    return 0;

  /* With some "insider knowledge", we can save some memory: the
   * "source" parameter holds a filename that was built from the
   * "dest" parameter. It was built in buffer and this buffer has
   * the size INI_BUFFERSIZE. We can reuse this buffer for copying
   * the file.
   */
  while (n=file_read(&fr, INI_BUFFERSIZE, source))
    file_write(&fw, n, source);

  file_fclose(&fr);
  file_fclose(&fw);

  /* Now we need to delete the source file. However, we have garbled
   * the buffer that held the filename of the source. So we need to
   * build it again.
   */
  ini_tempname(source, dest, INI_BUFFERSIZE);
  return rmfile(&g_efs.myFs, source) == 0;
}
