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
	auto hr = server.CreateInstance(__uuidof(Server));
	if (SUCCEEDED(hr))
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
			disp->Release();
		}
	}
	else
	{
		printf("CoCreateInstance failed:0x%08X\n", hr);
	}
	CoUninitialize();
}
