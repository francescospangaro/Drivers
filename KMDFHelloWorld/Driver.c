#include <ntddk.h>
#include <wdf.h>

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD KMDFHelloWorldEvtDeviceAdd;

NTSTATUS
DriverEntry(
	_In_ PDRIVER_OBJECT		DriverObject,
	_In_ PUNICODE_STRING	RegistryPath
)
{
	// Variable used to record either success or failure
	NTSTATUS status = STATUS_SUCCESS;

	// This is the driver configuration object
	WDF_DRIVER_CONFIG config;

	// Print "Hello World" for driver entry
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KMDFHelloWorld: DriverEntry\n"));

	// Initialize the driver configuration obj to register the
	// entry point for the EvtDeviceAdd callback
	WDF_DRIVER_CONFIG_INIT(&config,
		KMDFHelloWorldEvtDeviceAdd);

	// Create the driver object
	status = WdfDriverCreate(DriverObject,
		RegistryPath,
		WDF_NO_OBJECT_ATTRIBUTES,
		&config,
		WDF_NO_HANDLE);

	return status;
}

NTSTATUS
KMDFHelloWorldEvtDeviceAdd(
	_In_	WDFDRIVER		Driver,
	_Inout_ PWDFDEVICE_INIT DeviceInit
)
{
	// We need to mark the driver obj as unreferenced, 
	// since we are not using it here
	UNREFERENCED_PARAMETER(Driver);

	NTSTATUS status;

	// Device object
	WDFDEVICE hDevice;

	// Actually print hello world
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KMDFHelloWorld: KMDFHelloWorldEvtDeviceAdd\n"));

	// Create the device object
	status = WdfDeviceCreate(&DeviceInit,
		WDF_NO_OBJECT_ATTRIBUTES,
		&hDevice);

	return status;
}