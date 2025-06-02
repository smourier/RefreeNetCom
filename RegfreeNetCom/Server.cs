using System.Runtime.InteropServices;

namespace RegfreeNetCom;

[ComVisible(true), Guid("cd42c360-c635-44fe-a8ab-793d188512a9"), ProgId("RegfreeNetCom.Server"), ClassInterface(ClassInterfaceType.AutoDual)]
public class Server : IServer
{
    public double ComputePi()
    {
        Console.WriteLine($"Computing PI from .NET Core x{(IntPtr.Size == 8 ? "64" : "86")}...");
        return Math.PI;
    }
}
