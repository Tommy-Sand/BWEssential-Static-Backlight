#include "main.h"


int main(int argc, char **argv){
	
	if(libusb_init(NULL) != 0)
		return 1;

	libusb_device_handle *dev_handle;

	find_BWE(dev_handle);

	libusb_exit(NULL);

	return 0;
}

int find_BWE(libusb_device_handle *dev_handle){

	if((dev_handle = libusb_open_device_with_vid_pid(NULL, 0x1532, 0x0237)) == NULL){
		printf("Razer BlackWidow Essential not found or could not be opened");
		return 1;
	}

	return 0;
}

int send_request(libusb_device_handle *dev_handle){ 
	return 0;
}

void safe_exit(libusb_device **list){
	libusb_free_device_list(list, 1);
	libusb_exit(NULL);
}
