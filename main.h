#include <stdio.h>
#include <hidapi/hidapi.h>
#include <hidapi/hidapi_winapi.h>

#define DEV_PID 0x237
#define DEV_VID 0x1532
#define DEV_USAGE_PAGE 0x1
#define DEV_USAGE 0x2
#define DEV_INTERFACE_NUMBER 0x2

unsigned char data[] =  "\x00\x00\x1f\x00\x00\x00\x08\x0f\x03\x00\x00\x00\x00" \
			"\x00\x00\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" \
			"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" \
			"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" \
			"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" \
			"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfb\x00";

hid_device *find_BWE();
