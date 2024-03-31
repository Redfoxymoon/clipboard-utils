/************************************/
/*  clipboard utility               */
/*  Copyright (C) 2021  Ørjan Malde */
/*  Released under MIT; see LICENSE */
/************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <libgen.h>

#include "win32.h"

#ifndef CF_TEXT
#define CF_TEXT 1
#endif

int main(int argc, char *argv[])
{
	void *handle;
	char *data;
	(void)argc;

	if(argc < 2) {
		fprintf(stderr, "%s: <input data>", basename(argv[0]));
		return 1;
	}

	if(!OpenClipboard(0))
		return 1;

	EmptyClipboard();

	handle = GlobalAlloc(0x40, strlen(argv[1]) + 1);

	if(!handle) {
		CloseClipboard();
		return 1;
	}

	data = (char *)GlobalLock(handle);

	/* melp? */
	memcpy(data, argv[1], strlen(argv[1]));

	GlobalUnlock(handle);
	SetClipboardData(CF_TEXT, data);
	CloseClipboard();

	return 0;
}
