/************************************/
/*  clipboard utility               */
/*  Copyright (C) 2021  Ørjan Malde */
/*  Released under MIT; see LICENSE */
/************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

extern void *GetClipboardData(uint32_t format);
extern int   CloseClipboard(void);
extern int   OpenClipboard(void *window);
extern int   IsClipboardFormatAvailable(uint32_t format);

#ifndef CF_TEXT
#define CF_TEXT 1
#endif

int main()
{
	if(!OpenClipboard(0))
		return 1;

	if(!IsClipboardFormatAvailable(CF_TEXT))
		return 1;

	printf("%s\n", (const char *)GetClipboardData(CF_TEXT));

	CloseClipboard();

	return 0;
}
