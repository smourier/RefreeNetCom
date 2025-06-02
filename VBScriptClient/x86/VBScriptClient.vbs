Set actx = CreateObject("Microsoft.Windows.ActCtx")
actx.Manifest = "VBScriptClient.manifest"
Set server = actx.CreateObject("RegfreeNetCom.Server")
WScript.Echo server.ComputePi()