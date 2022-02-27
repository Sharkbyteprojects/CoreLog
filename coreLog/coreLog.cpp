#include "../osInf/osInf.h"
#include <iostream>

void listCall(const char* x, const char* xt, bool& ok, osinft vec);

int main(int argc, char** argv)
{
	std::vector<wchar_t*> adout;
	bool ok = false;
#define stdListCall(x, xt) listCall(x, xt, ok, (osinft)&adout)
	ok = OSinfv("Win32_OperatingSystem", L"Name", adout);
	if (ok && adout.size() > 0)
		std::wcout << "OS Name: " << adout[0] << "\n";
	clVec(adout);

	ok = OSinfv("Win32_Baseboard", L"Product", adout);
	if (ok && adout.size() > 0)
		std::wcout << "Mainboard: " << adout[0] << "\n";
	clVec(adout);

	ok = OSinfv("Win32_BIOS", L"SerialNumber", adout);
	if (ok && adout.size() > 0)
		std::wcout << "BIOS Serialnumber: " << adout[0] << "\n\n";
	clVec(adout);

	stdListCall("Win32_Processor", "CPU");
	stdListCall("Win32_VideoController", "GPU");
	stdListCall("Win32_Printer", "Printer");
	stdListCall("Win32_SerialPort", "Serial Port");
	stdListCall("Win32_SoundDevice", "Sound Device");

#undef stdListCall
	std::cout << std::flush;
}

void listCall(const char* x, const char* xt, bool& ok, osinft vec) {
	ok = OSinf(x, L"Name", vec);
	if (ok && vec->size() > 0) {
		std::cout << xt << ":\n";
		for (size_t s = 0; s < vec->size(); s++) {
			std::wcout << "\t" << s << ": " << (*vec)[s] << "\n";
		}
	}
	freeVec(vec);
	std::cout << "\n";
}
