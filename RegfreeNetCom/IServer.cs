using System.Runtime.InteropServices;

namespace RegfreeNetCom;

[ComImport, Guid("38268d0f-eae8-4c95-bac7-9d96c083ea7c"), InterfaceType(ComInterfaceType.InterfaceIsDual)]
public interface IServer
{
    double ComputePi();
}
