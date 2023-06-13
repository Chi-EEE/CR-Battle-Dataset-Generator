#pragma once

#ifndef BETTER_ENUMS_MACRO_FILE_H
#define BETTER_ENUMS_MACRO_FILE_H

#define BETTER_ENUMS_PP_MAP(macro, data, ...) \
    BETTER_ENUMS_ID( \
        BETTER_ENUMS_APPLY( \
            BETTER_ENUMS_PP_MAP_VAR_COUNT, \
            BETTER_ENUMS_PP_COUNT(__VA_ARGS__)) \
        (macro, data, __VA_ARGS__))

#define BETTER_ENUMS_PP_MAP_VAR_COUNT(count) BETTER_ENUMS_M ## count

#define BETTER_ENUMS_APPLY(macro, ...) BETTER_ENUMS_ID(macro(__VA_ARGS__))

#define BETTER_ENUMS_ID(x) x

#define BETTER_ENUMS_M1(m, d, x) m(d,0,x)
#define BETTER_ENUMS_M2(m,d,x,...) m(d,1,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M1(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M3(m,d,x,...) m(d,2,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M2(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M4(m,d,x,...) m(d,3,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M3(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M5(m,d,x,...) m(d,4,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M4(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M6(m,d,x,...) m(d,5,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M5(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M7(m,d,x,...) m(d,6,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M6(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M8(m,d,x,...) m(d,7,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M7(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M9(m,d,x,...) m(d,8,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M8(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M10(m,d,x,...) m(d,9,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M9(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M11(m,d,x,...) m(d,10,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M10(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M12(m,d,x,...) m(d,11,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M11(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M13(m,d,x,...) m(d,12,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M12(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M14(m,d,x,...) m(d,13,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M13(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M15(m,d,x,...) m(d,14,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M14(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M16(m,d,x,...) m(d,15,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M15(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M17(m,d,x,...) m(d,16,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M16(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M18(m,d,x,...) m(d,17,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M17(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M19(m,d,x,...) m(d,18,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M18(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M20(m,d,x,...) m(d,19,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M19(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M21(m,d,x,...) m(d,20,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M20(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M22(m,d,x,...) m(d,21,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M21(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M23(m,d,x,...) m(d,22,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M22(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M24(m,d,x,...) m(d,23,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M23(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M25(m,d,x,...) m(d,24,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M24(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M26(m,d,x,...) m(d,25,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M25(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M27(m,d,x,...) m(d,26,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M26(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M28(m,d,x,...) m(d,27,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M27(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M29(m,d,x,...) m(d,28,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M28(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M30(m,d,x,...) m(d,29,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M29(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M31(m,d,x,...) m(d,30,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M30(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M32(m,d,x,...) m(d,31,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M31(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M33(m,d,x,...) m(d,32,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M32(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M34(m,d,x,...) m(d,33,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M33(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M35(m,d,x,...) m(d,34,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M34(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M36(m,d,x,...) m(d,35,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M35(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M37(m,d,x,...) m(d,36,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M36(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M38(m,d,x,...) m(d,37,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M37(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M39(m,d,x,...) m(d,38,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M38(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M40(m,d,x,...) m(d,39,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M39(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M41(m,d,x,...) m(d,40,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M40(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M42(m,d,x,...) m(d,41,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M41(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M43(m,d,x,...) m(d,42,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M42(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M44(m,d,x,...) m(d,43,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M43(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M45(m,d,x,...) m(d,44,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M44(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M46(m,d,x,...) m(d,45,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M45(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M47(m,d,x,...) m(d,46,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M46(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M48(m,d,x,...) m(d,47,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M47(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M49(m,d,x,...) m(d,48,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M48(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M50(m,d,x,...) m(d,49,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M49(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M51(m,d,x,...) m(d,50,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M50(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M52(m,d,x,...) m(d,51,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M51(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M53(m,d,x,...) m(d,52,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M52(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M54(m,d,x,...) m(d,53,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M53(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M55(m,d,x,...) m(d,54,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M54(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M56(m,d,x,...) m(d,55,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M55(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M57(m,d,x,...) m(d,56,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M56(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M58(m,d,x,...) m(d,57,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M57(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M59(m,d,x,...) m(d,58,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M58(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M60(m,d,x,...) m(d,59,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M59(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M61(m,d,x,...) m(d,60,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M60(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M62(m,d,x,...) m(d,61,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M61(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M63(m,d,x,...) m(d,62,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M62(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M64(m,d,x,...) m(d,63,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M63(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M65(m,d,x,...) m(d,64,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M64(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M66(m,d,x,...) m(d,65,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M65(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M67(m,d,x,...) m(d,66,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M66(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M68(m,d,x,...) m(d,67,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M67(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M69(m,d,x,...) m(d,68,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M68(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M70(m,d,x,...) m(d,69,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M69(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M71(m,d,x,...) m(d,70,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M70(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M72(m,d,x,...) m(d,71,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M71(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M73(m,d,x,...) m(d,72,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M72(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M74(m,d,x,...) m(d,73,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M73(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M75(m,d,x,...) m(d,74,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M74(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M76(m,d,x,...) m(d,75,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M75(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M77(m,d,x,...) m(d,76,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M76(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M78(m,d,x,...) m(d,77,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M77(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M79(m,d,x,...) m(d,78,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M78(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M80(m,d,x,...) m(d,79,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M79(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M81(m,d,x,...) m(d,80,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M80(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M82(m,d,x,...) m(d,81,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M81(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M83(m,d,x,...) m(d,82,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M82(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M84(m,d,x,...) m(d,83,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M83(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M85(m,d,x,...) m(d,84,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M84(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M86(m,d,x,...) m(d,85,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M85(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M87(m,d,x,...) m(d,86,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M86(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M88(m,d,x,...) m(d,87,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M87(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M89(m,d,x,...) m(d,88,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M88(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M90(m,d,x,...) m(d,89,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M89(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M91(m,d,x,...) m(d,90,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M90(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M92(m,d,x,...) m(d,91,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M91(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M93(m,d,x,...) m(d,92,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M92(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M94(m,d,x,...) m(d,93,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M93(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M95(m,d,x,...) m(d,94,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M94(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M96(m,d,x,...) m(d,95,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M95(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M97(m,d,x,...) m(d,96,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M96(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M98(m,d,x,...) m(d,97,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M97(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M99(m,d,x,...) m(d,98,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M98(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M100(m,d,x,...) m(d,99,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M99(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M101(m,d,x,...) m(d,100,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M100(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M102(m,d,x,...) m(d,101,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M101(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M103(m,d,x,...) m(d,102,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M102(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M104(m,d,x,...) m(d,103,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M103(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M105(m,d,x,...) m(d,104,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M104(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M106(m,d,x,...) m(d,105,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M105(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M107(m,d,x,...) m(d,106,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M106(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M108(m,d,x,...) m(d,107,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M107(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M109(m,d,x,...) m(d,108,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M108(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M110(m,d,x,...) m(d,109,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M109(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M111(m,d,x,...) m(d,110,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M110(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M112(m,d,x,...) m(d,111,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M111(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M113(m,d,x,...) m(d,112,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M112(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M114(m,d,x,...) m(d,113,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M113(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M115(m,d,x,...) m(d,114,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M114(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M116(m,d,x,...) m(d,115,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M115(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M117(m,d,x,...) m(d,116,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M116(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M118(m,d,x,...) m(d,117,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M117(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M119(m,d,x,...) m(d,118,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M118(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M120(m,d,x,...) m(d,119,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M119(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M121(m,d,x,...) m(d,120,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M120(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M122(m,d,x,...) m(d,121,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M121(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M123(m,d,x,...) m(d,122,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M122(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M124(m,d,x,...) m(d,123,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M123(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M125(m,d,x,...) m(d,124,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M124(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M126(m,d,x,...) m(d,125,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M125(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M127(m,d,x,...) m(d,126,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M126(m,d,__VA_ARGS__))
#define BETTER_ENUMS_M128(m,d,x,...) m(d,127,x) \
    BETTER_ENUMS_ID(BETTER_ENUMS_M127(m,d,__VA_ARGS__))

#define BETTER_ENUMS_PP_COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10,    \
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, \
    _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
    _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, \
    _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, \
    _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, \
    _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99, _100,\
    _101, _102, _103, _104, _105, _106, _107, _108, _109, _110, _111, _112,    \
    _113, _114, _115, _116, _117, _118, _119, _120, _121, _122, _123, _124,    \
    _125, _126, _127, _128, count, ...) count

#define BETTER_ENUMS_PP_COUNT(...) \
    BETTER_ENUMS_ID(BETTER_ENUMS_PP_COUNT_IMPL(__VA_ARGS__, 128, 127, 126, 125,\
        124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111,  \
        110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, \
        95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78,\
        77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60,\
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42,\
        41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24,\
        23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, \
        4, 3, 2, 1))

#define BETTER_ENUMS_ITERATE(X, f, l) X(f, l, 0) X(f, l, 1) X(f, l, 2)         \
    X(f, l, 3) X(f, l, 4) X(f, l, 5) X(f, l, 6) X(f, l, 7) X(f, l, 8)          \
    X(f, l, 9) X(f, l, 10) X(f, l, 11) X(f, l, 12) X(f, l, 13) X(f, l, 14)     \
    X(f, l, 15) X(f, l, 16) X(f, l, 17) X(f, l, 18) X(f, l, 19) X(f, l, 20)    \
    X(f, l, 21) X(f, l, 22) X(f, l, 23)

#endif // #ifndef BETTER_ENUMS_MACRO_FILE_H
