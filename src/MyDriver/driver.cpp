#include "driver.hpp"

_Function_class_(DRIVER_UNLOAD) _IRQL_requires_(PASSIVE_LEVEL)
_IRQL_requires_same_ static void
DriverUnload(_In_ PDRIVER_OBJECT DriverObject)
{
    dprintf("[MyDriver] DriverUnload\n");
}

_Function_class_(DRIVER_INITIALIZE) _IRQL_requires_same_ _IRQL_requires_(PASSIVE_LEVEL)
extern "C" NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
    // Set callback functions
    DriverObject->DriverUnload = DriverUnload;

    dprintf("[MyDriver] DriverEntry\n");

    return STATUS_SUCCESS;
}
