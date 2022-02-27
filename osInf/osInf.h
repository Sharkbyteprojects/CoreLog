#ifdef OSINF_EXPORTS
#define OSINF_API __declspec(dllexport)
#else
#define OSINF_API __declspec(dllimport)
#endif
#include <vector>
typedef std::vector<wchar_t*>* osinft;
OSINF_API bool osinf(const char* hardwareclass, const wchar_t* val, osinft outp);
OSINF_API void freeVec(osinft freev);
#define OSinf(hardwareclass, value, outp) !osinf(hardwareclass, value, outp)
#define OSinfv(hardwareclass, value, outp) OSinf(hardwareclass, value, (osinft)&outp)
#define clVec(v) freeVec((osinft)&v)
