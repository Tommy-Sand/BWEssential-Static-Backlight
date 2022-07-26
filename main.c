#include "main.h"

int main(){
	hid_init();

	hid_device *device = find_BWE();
	if(device == NULL){
		printf("Device was not found or could not be opened");
		return 1;
	}
	

	int sent = hid_send_feature_report(device, data, sizeof(data) / sizeof(char));
	printf("datasize: %d, sizeof(char): %d , Sent: %d", sizeof(data), sizeof(char), sent); //debugging

	hid_close(device);
	
	hid_exit();
}

hid_device *find_BWE(){
	struct hid_device_info *linked_list_devices = hid_enumerate(DEV_VID, DEV_PID);
	struct hid_device_info *device_info = linked_list_devices;
	while(device_info != NULL){
		if(device_info->usage_page == 0x01 && device_info->usage == 0x02 && device_info->interface_number == 0x02){
			break;
		}
		device_info = device_info->next;
	}

	hid_device *device = hid_open_path(device_info->path);

	hid_free_enumeration(linked_list_devices); // free the linked list

	return device;
}
