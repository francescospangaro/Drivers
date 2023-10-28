/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    driver and application

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_UmdfDriver,
    0x4bececdf,0x19fc,0x478a,0xb1,0x74,0xe4,0x24,0x31,0x26,0x95,0xb5);
// {4bececdf-19fc-478a-b174-e424312695b5}
