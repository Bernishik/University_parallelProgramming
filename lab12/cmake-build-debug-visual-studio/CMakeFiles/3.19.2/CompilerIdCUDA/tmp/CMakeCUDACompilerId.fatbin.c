#ifndef __SKIP_INTERNAL_FATBINARY_HEADERS
#include "fatbinary_section.h"
#endif
#define __CUDAFATBINSECTION  ".nvFatBinSegment"
#define __CUDAFATBINDATASECTION  ".nv_fatbin"
#ifdef __cplusplus
extern "C" {
#endif

#pragma data_seg(__CUDAFATBINDATASECTION)
static const __declspec(allocate(__CUDAFATBINDATASECTION)) unsigned long long fatbinData[]= {0x00100001ba55ed50ull,0x0000000000000480ull,0x0000004001010002ull,0x00000000000003b8ull,
0x0000000000000000ull,0x0000003400010007ull,0x0000000000000000ull,0x0000000000000041ull,
0x0000000000000000ull,0x0000000000000000ull,0x33010102464c457full,0x0000000000000007ull,
0x0000007100be0002ull,0x0000000000000000ull,0x0000000000000310ull,0x00000000000001d0ull,
0x0038004000340534ull,0x0001000500400003ull,0x7472747368732e00ull,0x747274732e006261ull,
0x746d79732e006261ull,0x746d79732e006261ull,0x78646e68735f6261ull,0x666e692e766e2e00ull,
0x65722e766e2e006full,0x6e6f697463612e6cull,0x72747368732e0000ull,0x7274732e00626174ull,
0x6d79732e00626174ull,0x6d79732e00626174ull,0x646e68735f626174ull,0x6e692e766e2e0078ull,
0x722e766e2e006f66ull,0x6f697463612e6c65ull,0x000000000000006eull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0004000300000032ull,0x0000000000000000ull,
0x0000000000000000ull,0x000000000000004bull,0x222f0a1008020200ull,0x0000000008000000ull,
0x0000000008080000ull,0x0000000008100000ull,0x0000000008180000ull,0x0000000008200000ull,
0x0000000008280000ull,0x0000000008300000ull,0x0000000008380000ull,0x0000000008000001ull,
0x0000000008080001ull,0x0000000008100001ull,0x0000000008180001ull,0x0000000008200001ull,
0x0000000008280001ull,0x0000000008300001ull,0x0000000008380001ull,0x0000000008000002ull,
0x0000000008080002ull,0x0000000008100002ull,0x0000000008180002ull,0x0000000008200002ull,
0x0000000008280002ull,0x0000000008300002ull,0x0000000008380002ull,0x0000002c14000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000300000001ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000040ull,
0x0000000000000041ull,0x0000000000000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x000000030000000bull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000081ull,
0x0000000000000041ull,0x0000000000000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x0000000200000013ull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000000c8ull,
0x0000000000000030ull,0x0000000100000002ull,0x0000000000000008ull,0x0000000000000018ull,
0x7000000b00000032ull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000000f8ull,
0x00000000000000d8ull,0x0000000000000000ull,0x0000000000000008ull,0x0000000000000008ull,
0x0000000500000006ull,0x0000000000000310ull,0x0000000000000000ull,0x0000000000000000ull,
0x00000000000000a8ull,0x00000000000000a8ull,0x0000000000000008ull,0x0000000500000001ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000008ull,0x0000000600000001ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000008ull,0x0000004801010001ull,0x0000000000000040ull,0x000000400000003dull,
0x0000003400070003ull,0x0000000000000000ull,0x0000000000002041ull,0x0000000000000000ull,
0x0000000000000046ull,0x0000000000000000ull,0x2e27f000020a0d2aull,0x206e6f6973726576ull,
0x61742e0a0d332e37ull,0x5f6d732074656772ull,0x6464612e0a0d3235ull,0x7a69735f73736572ull,
0x0a0d0a0d34362065ull,0x000000000a0d0a0dull
};
#pragma data_seg()

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
#pragma data_seg(".nvFatBinSegment")
__declspec(allocate(__CUDAFATBINSECTION)) __declspec(align(8)) static const __fatBinC_Wrapper_t __fatDeviceText= 
	{ 0x466243b1, 1, fatbinData, 0 };
#pragma data_seg()
#ifdef __cplusplus
}
#endif
