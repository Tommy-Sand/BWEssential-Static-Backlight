#include <stdio.h>
#include <stdbool.h>
#include "libusb-1.0/libusb.h"

void safe_exit(libusb_device **list);
int find_BWE(libusb_device_handle *dev_handle);
int send_request(libusb_device_handle *dev_handle);
