/************************************/
/*  clipboard utility               */
/*  Copyright (C) 2021  Ørjan Malde */
/*  Released under MIT; see LICENSE */
/************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <psxxfi/xfi_unicode.h>

#include "win32.h"

int main()
{
	char *buf;
	void *handle;
	unsigned short *p;
	unsigned int buf_len;

	if(!OpenClipboard(0))
		return 1;

	if(!IsClipboardFormatAvailable(CF_UNICODETEXT))
		return 1;

	handle = GetClipboardData(CF_UNICODETEXT);

	buf_len = (GlobalSize(handle) * 4) + 1;
	buf = malloc(buf_len);

	/* should never happen right? */
	/* My computer has 64 gigabytes of ram... */
	if(!buf)
	{
		fprintf(stderr, "allocation error\n");
		return 1;
	}

	memset(buf, '\0', buf_len);
	p = handle;

	__xfi_strconv_utf16_to_utf8(p, buf, buf_len, NULL);

	fprintf(stdout, "%s\n", buf);
#ifdef DEBUG
	while(*buf != '\0')
		fprintf(stdout, "%02X", *(buf++)&0xff);
	fprintf(stdout, "\n");
#endif

	CloseClipboard();
	return 0;
}
