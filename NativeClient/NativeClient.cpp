#include <windows.h>
#include <stdio.h>
#include <tuple>

#import "RegfreeNetCom.tlb"
using namespace RegfreeNetCom;

int main()
{
	if (sizeof(void*) == 8)
	{
		printf("Running from native client x64\n");
	}
	else
	{
		printf("Running from native client x86\n");
	}

	std::ignore = CoInitialize(nullptr);
	IServerPtr server;
	if (SUCCEEDED(server.CreateInstance(__uuidof(Server))))
	{
		auto pi = server->ComputePi();
		printf("IUnknown-derived pi:%f\n", pi);

		IDispatch* disp;
		server->QueryInterface(&disp);
		if (disp)
		{
			LPOLESTR name = (LPOLESTR)L"ComputePi";
			DISPID dispid;
			auto hr = server->GetIDsOfNames(IID_NULL, &name, 1, LOCALE_SYSTEM_DEFAULT, &dispid);
			if (SUCCEEDED(hr))
			{
				VARIANT v;
				VariantInit(&v);
				DISPPARAMS params = { };
				if (SUCCEEDED(server->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &params, &v, nullptr, nullptr)))
				{
					printf("IDispatch pi:%f\n", V_R8(&v));
					VariantClear(&v);
				}
			}
		}
	}
	CoUninitialize();
}
