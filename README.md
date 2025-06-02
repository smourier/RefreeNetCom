# RefreeNetCom
A registry-free In-Process COM server

The sample is composed of
* a .NET 8.0 COM In-Process server (supports x86 or x64)
* a native x86, x64 console client written in C++
* a .NET Framework x86 or x64 console client written in C#
* a VB6 x86 client (only works when compiled as an .exe)
* a VBScript client which currently doesn't work for some reason...

Everything is reg-free. All clients can call the .NET Server.

## Notes
Reg-Free COM is here based on a Type Library .TLB file (`RegfreeNetCom.tlb`) present aside the all clients .exe (no TLB is embedded in this sample). Both .NET and C++ projects have a specific `app.manifest` file that declares that type library.

Sadly, there's no tooling in Visual Studio C# projects to build .tlb files from .idl (there is only in Visual Studio C++ projects!), so the C# project references an extra `GetWindowsSDKPaths.targets` file (to gather various Windows SDK and Visual studio paths), plus some extra lines in the `.csproj` to do that automatically.
