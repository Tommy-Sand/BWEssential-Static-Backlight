#include "main.h"


int main(int argc, char **argv){
	
	if(libusb_init(NULL) != 0)
		return 1;

	libusb_device_handle *dev_handle;

	find_BWE(&dev_handle);

	libusb_exit(NULL);

	return 0;
}

int find_BWE(libusb_device_handle **dev_handle){

	libusb_device **list;

	int devices_length = libusb_get_device_list(NULL, &list);

	libusb_device *device = NULL;

	bool notfound = true;
	for(int i = 0; i < devices_length; i++){
		device = *(list + i);
		struct libusb_device_descriptor desc;
		if(libusb_get_device_descriptor(device, &desc) != 0){
			safe_exit(list);
			return 1;
		}
		if(desc.idVendor == 0x1532 && desc.idProduct == 0x0237){
			notfound = false;
			printf("Razer BlackWidow Essential found");
		}
	}

	if(notfound){
		printf("Razer BlackWidow Essential not found");
		safe_exit(list);
		return 1;
	}

	if(libusb_open(device, dev_handle) != 0){
		printf("Razer BlackWidow Essential could not be opened");
		safe_exit(list);
		return 1;
	}

	libusb_free_device_list(list, 1);
	return 0;
}

void safe_exit(libusb_device **list){
	libusb_free_device_list(list, 1);
	libusb_exit(NULL);
}
