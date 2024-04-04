extern void *GetClipboardData(unsigned format);
extern int   CloseClipboard(void);
extern int   OpenClipboard(void *window);
extern int   IsClipboardFormatAvailable(unsigned format);
extern int   CloseClipboard(void);
extern void *SetClipboardData(unsigned format, void *mem);
extern int   EmptyClipboard(void);
extern void *GlobalAlloc(unsigned flags, size_t size);
extern void *GlobalLock(void *handle);
extern int   GlobalUnlock(void *handle);
extern size_t GlobalSize(void *handle);

#ifndef CF_TEXT
#define CF_TEXT 1
#endif

#ifndef CF_UNICODETEXT
#define CF_UNICODETEXT 13
#endif
