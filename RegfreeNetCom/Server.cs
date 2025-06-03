using System.Runtime.InteropServices;

namespace RegfreeNetCom;

[ComVisible(true), Guid("cd42c360-c635-44fe-a8ab-793d188512a9"), ProgId("RegfreeNetCom.Server"), ClassInterface(ClassInterfaceType.None)]
public class Server : IServer, Server.IDispatch
{
    public double ComputePi()
    {
        Console.WriteLine($"Computing PI from .NET Core x{(IntPtr.Size == 8 ? "64" : "86")}...");
        return Math.PI;
    }

    // This is not needed with normal COM registration, and this is not needed in out-of-process context
    // For some reason, regfree COM and .NET Core does not work without an explicit IDispatch in a coclass such as this one
    // What's weird is it doesn't work only in the case where IDispatch is directly requested in CoCreateInstance call (it works if IUnkown is queried first and IDispatch is requested later).
    // Querying IDispatch first is used (at least) by VB/VBA/VBScript clients.
    // Note however, you *must* declare IServer as dual interface, otherwise it will proably crash since this IDispatch is not defined at all.
    [ComImport, Guid("00020400-0000-0000-c000-000000000046"), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    private interface IDispatch
    {
    }
}