/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_KmdfDriver,
    0xa2ff41ab,0x1439,0x44db,0xac,0x4c,0x3a,0x27,0xb4,0x55,0x73,0x64);
// {a2ff41ab-1439-44db-ac4c-3a27b4557364}
