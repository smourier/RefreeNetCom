using System.Runtime.InteropServices;
using RegfreeNetCom;

namespace NetFxClient;

internal class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine($"Running from .NET Framework client x{(IntPtr.Size == 8 ? "64" : "86")}");
        var server = (IServer)new Server();
        Console.WriteLine($"IServer Pi = {server.ComputePi()}");
    }
}

[ComImport, Guid("cd42c360-c635-44fe-a8ab-793d188512a9")]
public class Server
{
}
