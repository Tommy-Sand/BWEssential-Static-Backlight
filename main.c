#include "main.h"

int main(int argc, char **argv){

	if(libusb_init(NULL) != 0){
		return 1;
	}

	libusb_device **list;

	int devices_length = libusb_get_device_list(NULL, &list);

	libusb_device *device = NULL;

	for(int i = 0; i < devices_length; i++){
		device = *(list + i);
		struct libusb_device_descriptor desc;
		if(libusb_get_device_descriptor(device, &desc) != 0){
			device = NULL;
			libusb_free_device_list(list, 1);
			libusb_exit(NULL);
			return 1;
		}
		if(desc.idVendor == 0x1532 && desc.idProduct == 0x0237){
			printf("Razer BlackWidow Essential found");
			break;
		}
	}

	if(device == NULL){
		printf("Razer BlackWidow Essential not found");
		libusb_free_device_list(list, 1);
		libusb_exit(NULL);
		return 1;
	}

	libusb_free_device_list(list, 1);

	libusb_exit(NULL);

	return 0;
}
