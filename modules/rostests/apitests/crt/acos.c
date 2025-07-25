/*
 * PROJECT:     ReactOS API tests
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Tests for acos
 * COPYRIGHT:   Copyright 2021 Timo Kreuzer <timo.kreuzer@reactos.org>
 */

#if !defined(_CRTBLD) && !defined(_M_IX86)
#define _CRTBLD // we don't want inline acos!
#endif
#include "math_helpers.h"

#ifdef _MSC_VER
#pragma function(acos)
#endif

#if !defined(_M_IX86)
#define HAS_ACOSF
#elif (defined(TEST_UCRTBASE) || defined(TEST_STATIC_CRT))
#define HAS_LIBM_SSE2
#endif


// These are expected to match exactly
static TESTENTRY_DBL s_acos_exact_tests[] =
{
    { 0x0000000000000000 /*  0.000000 */, 0x3ff921fb54442d18 /*  1.570796 */ },
    { 0x8000000000000000 /* -0.000000 */, 0x3ff921fb54442d18 /*  1.570796 */ },
    { 0x7ff0000000000000 /*  1.#INF00 */, 0xfff8000000000000 /* -1.#IND00 */ },
    { 0x7ff0000000000001 /*  1.#SNAN0 */, 0x7ff8000000000001 /*  1.#QNAN0 */ },
    { 0x7ff7ffffffffffff /*  1.#SNAN0 */, 0x7fffffffffffffff /*  1.#QNAN0 */ },
    { 0x7ff8000000000000 /*  1.#QNAN0 */, 0x7ff8000000000000 /*  1.#QNAN0 */ },
    { 0x7ff8000000000001 /*  1.#QNAN0 */, 0x7ff8000000000001 /*  1.#QNAN0 */ },
    { 0x7fffffffffffffff /*  1.#QNAN0 */, 0x7fffffffffffffff /*  1.#QNAN0 */ },
    { 0xfff0000000000000 /* -1.#INF00 */, 0xfff8000000000000 /* -1.#IND00 */ },
    { 0xfff0000000000001 /* -1.#SNAN0 */, 0xfff8000000000001 /* -1.#QNAN0 */ },
    { 0xfff7ffffffffffff /* -1.#SNAN0 */, 0xffffffffffffffff /* -1.#QNAN0 */ },
    { 0xfff8000000000000 /* -1.#IND00 */, 0xfff8000000000000 /* -1.#IND00 */ },
    { 0xfff8000000000001 /* -1.#QNAN0 */, 0xfff8000000000001 /* -1.#QNAN0 */ },
    { 0xffffffffffffffff /* -1.#QNAN0 */, 0xffffffffffffffff /* -1.#QNAN0 */ },
};

void Test_acos_exact(void)
{
    for (int i = 0; i < _countof(s_acos_exact_tests); i++)
    {
        double x = u64_to_dbl(s_acos_exact_tests[i].x);
        double z = acos(x);
        ok_eq_dbl_exact("acos", s_acos_exact_tests[i].x, z, s_acos_exact_tests[i].result);
    }
}

// This table is autogenerated by `python gen_math_tests.py acos`
static TESTENTRY_DBL_APPROX s_acos_approx_tests[] =
{
//  {    x,                     {    y_rounded,               y_difference           } }
    {    -0x1.0000000000000p+0, {     0x1.921fb54442d18p+1,    0x1.1a62633145c07p-53 }, 1 }, // acos(-1.0) == 3.1415926535897932385
    {    -0x1.f5c28f5c28f5cp-1, {     0x1.787b22ce3f590p+1,   -0x1.4702362ba866fp-54 }, 1 }, // acos(-0.98) == 2.9412578112666735565
    {    -0x1.eb851eb851eb8p-1, {     0x1.6dcc57bb565fcp+1,    0x1.b1a55293db288p-53 }, 1 }, // acos(-0.96) == 2.857798544381465266
    {    -0x1.e147ae147ae14p-1, {     0x1.658f00fec9c15p+1,   -0x1.eb86bb62253a3p-53 }, 1 }, // acos(-0.94) == 2.793426632316832201
    {    -0x1.d70a3d70a3d71p-1, {     0x1.5e9383efad0d1p+1,   -0x1.8aef1de7efe68p-55 }, 1 }, // acos(-0.92) == 2.7388768120091317575
    {    -0x1.ccccccccccccdp-1, {     0x1.586476251e745p+1,    0x1.d71fc857011bep-54 }, 1 }, // acos(-0.9) == 2.6905658417935308569
    {    -0x1.c28f5c28f5c29p-1, {     0x1.52c5b4e51b555p+1,   -0x1.e34ca69d52172p-54 }, 1 }, // acos(-0.88) == 2.646658527248897725
    {    -0x1.b851eb851eb85p-1, {     0x1.4d9392170d7eap+1,   -0x1.f8671f14c5e64p-53 }, 1 }, // acos(-0.86) == 2.6060659992754053904
    {    -0x1.ae147ae147ae1p-1, {     0x1.48b6d4a69943fp+1,   -0x1.35fc99fda683cp-53 }, 1 }, // acos(-0.84) == 2.568079549166696428
    {    -0x1.a3d70a3d70a3ep-1, {     0x1.441f5ecbeef59p+1,   -0x1.44458e47cb605p-54 }, 1 }, // acos(-0.8200000000000001) == 2.5322073455589983311
    {    -0x1.999999999999ap-1, {     0x1.3fc176b7a8560p+1,    0x1.4113b1981644dp-54 }, 1 }, // acos(-0.8) == 2.4980915447965089257
    {    -0x1.8f5c28f5c28f6p-1, {     0x1.3b94437710c9fp+1,    0x1.bda12d454b328p-54 }, 1 }, // acos(-0.78) == 2.4654621440291318713
    {    -0x1.851eb851eb852p-1, {     0x1.3790e5efbaf83p+1,   -0x1.9aa722f032d4dp-56 }, 1 }, // acos(-0.76) == 2.4341094418104502805
    {    -0x1.7ae147ae147aep-1, {     0x1.33b1e74e4d7d5p+1,    0x1.bf989963bac11p-53 }, 1 }, // acos(-0.74) == 2.4038666851365444175
    {    -0x1.70a3d70a3d70ap-1, {     0x1.2ff2d932437fbp+1,    0x1.79c7ed09341d9p-53 }, 1 }, // acos(-0.72) == 2.374598645727926613
    {    -0x1.6666666666666p-1, {     0x1.2c501446cd5f1p+1,    0x1.db79e60431a1bp-53 }, 1 }, // acos(-0.7) == 2.3461938234056496208
    {    -0x1.5c28f5c28f5c2p-1, {     0x1.28c68a40a5e8bp+1,    0x1.1d2e361f2f3a4p-53 }, 1 }, // acos(-0.6799999999999999) == 2.3185589614548171149
    {    -0x1.51eb851eb851ep-1, {     0x1.2553a4a84548fp+1,    0x1.e128449289236p-56 }, 1 }, // acos(-0.6599999999999999) == 2.2916150876649861429
    {    -0x1.47ae147ae147bp-1, {     0x1.21f52c5720bdbp+1,   -0x1.64f77121c75c6p-54 }, 1 }, // acos(-0.64) == 2.2652945924214526244
    {    -0x1.3d70a3d70a3d7p-1, {     0x1.1ea93705fa172p+1,   -0x1.d9dd5fe247cc0p-56 }, 1 }, // acos(-0.62) == 2.2395390299972683677
    {    -0x1.3333333333333p-1, {     0x1.1b6e192ebbe44p+1,    0x1.71b466a88828ep-53 }, 1 }, // acos(-0.6) == 2.2142974355881809783
    {    -0x1.28f5c28f5c290p-1, {     0x1.18425b13e5ca1p+1,   -0x1.be6b8d2364709p-54 }, 1 }, // acos(-0.5800000000000001) == 2.189525017467147797
    {    -0x1.1eb851eb851ecp-1, {     0x1.1524b01c3c769p+1,    0x1.df07281f933bfp-54 }, 1 }, // acos(-0.56) == 2.1651821267959588874
    {    -0x1.147ae147ae148p-1, {     0x1.1213efeec77b4p+1,   -0x1.7bf9c739bca27p-54 }, 1 }, // acos(-0.54) == 2.1412334361948185688
    {    -0x1.0a3d70a3d70a4p-1, {     0x1.0f0f10e4a4af4p+1,   -0x1.0c452864fdf6ap-54 }, 1 }, // acos(-0.52) == 2.1176472774908407488
    {    -0x1.0000000000000p-1, {     0x1.0c152382d7366p+1,   -0x1.ee6913347c2a6p-53 }, 1 }, // acos(-0.5) == 2.0943951023931954923
    {    -0x1.eb851eb851eb8p-2, {     0x1.09254ec250419p+1,    0x1.17699c37f641fp-54 }, 1 }, // acos(-0.48) == 2.0714510391994847611
    {    -0x1.d70a3d70a3d70p-2, {     0x1.063eccfac5c08p+1,    0x1.2b1bcd61af04dp-54 }, 1 }, // acos(-0.45999999999999996) == 2.0487915253138489584
    {    -0x1.c28f5c28f5c28p-2, {     0x1.0360e94f4c6c5p+1,    0x1.a97176a34c78bp-54 }, 1 }, // acos(-0.43999999999999995) == 2.0263950001907199229
    {    -0x1.ae147ae147ae2p-2, {     0x1.008afd83485fcp+1,    0x1.509633b96e5e0p-54 }, 1 }, // acos(-0.42000000000000004) == 2.0042416468647826397
    {    -0x1.999999999999ap-2, {     0x1.fb78e047dfba5p+0,    0x1.8795be7cd2e3ep-55 }, 1 }, // acos(-0.4) == 1.9823131728623846628
    {    -0x1.851eb851eb852p-2, {     0x1.f5e965edb84a0p+0,   -0x1.c753eba1ee5e0p-54 }, 1 }, // acos(-0.38) == 1.9605926232691571876
    {    -0x1.70a3d70a3d70ap-2, {     0x1.f0668342bcfa2p+0,   -0x1.c36b61fabdab7p-54 }, 1 }, // acos(-0.36) == 1.9390642202315365859
    {    -0x1.5c28f5c28f5c2p-2, {     0x1.eaef40fd91e86p+0,    0x1.2a8ddbd3c9473p-55 }, 1 }, // acos(-0.33999999999999997) == 1.9177132243220582954
    {    -0x1.47ae147ae147ap-2, {     0x1.e582b73b88c77p+0,    0x1.1f3d2a0312d95p-55 }, 1 }, // acos(-0.31999999999999995) == 1.896525814089526727
    {    -0x1.3333333333332p-2, {     0x1.e0200bbc96ad8p+0,   -0x1.70a88d71b8addp-54 }, 1 }, // acos(-0.29999999999999993) == 1.8754889808102940574
    {    -0x1.1eb851eb851ecp-2, {     0x1.dac670561bb50p+0,   -0x1.dd480ddd09a1ep-54 }, 1 }, // acos(-0.28) == 1.8545904360032244926
    {    -0x1.0a3d70a3d70a4p-2, {     0x1.d5752193dff04p+0,   -0x1.651183c235f55p-55 }, 1 }, // acos(-0.26) == 1.8338185297033655243
    {    -0x1.eb851eb851eb8p-3, {     0x1.d02b658023fc0p+0,    0x1.861ea0e1972e4p-55 }, 1 }, // acos(-0.24) == 1.8131621778338598429
    {    -0x1.c28f5c28f5c28p-3, {     0x1.cae88a8cd3053p+0,    0x1.5cc7a8e0f89b3p-54 }, 1 }, // acos(-0.21999999999999997) == 1.7926107972916910029
    {    -0x1.9999999999998p-3, {     0x1.c5abe698d8960p+0,   -0x1.4e5eb4b36c594p-54 }, 1 }, // acos(-0.19999999999999996) == 1.7721542475852273654
    {    -0x1.70a3d70a3d708p-3, {     0x1.c074d60d624fdp+0,   -0x1.40bae2c743f74p-54 }, 1 }, // acos(-0.17999999999999994) == 1.7517827780414442633
    {    -0x1.47ae147ae147cp-3, {     0x1.bb42bb0f765cbp+0,   -0x1.3cfb0fd5cb539p-54 }, 1 }, // acos(-0.16000000000000003) == 1.7314869797468072511
    {    -0x1.1eb851eb851ecp-3, {     0x1.b614fcc2ca2c0p+0,   -0x1.810d838217ecfp-54 }, 1 }, // acos(-0.14) == 1.711257741504752433
    {    -0x1.eb851eb851eb8p-4, {     0x1.b0eb069b2fb21p+0,   -0x1.98f4530ac2a81p-54 }, 1 }, // acos(-0.12) == 1.6910862091896846861
    {    -0x1.9999999999998p-4, {     0x1.abc447ba464a0p+0,    0x1.a3867da709320p-54 }, 1 }, // acos(-0.09999999999999998) == 1.6709637479564563933
    {    -0x1.47ae147ae1478p-4, {     0x1.a6a0325763031p+0,   -0x1.1683f8b5f8728p-55 }, 1 }, // acos(-0.07999999999999996) == 1.6508819068285555929
    {    -0x1.eb851eb851eb0p-5, {     0x1.a17e3b2fdd3ddp+0,    0x1.e8033f905c630p-55 }, 1 }, // acos(-0.05999999999999994) == 1.6308323852401749839
    {    -0x1.47ae147ae1480p-5, {     0x1.9c5dd8fe1a303p+0,    0x1.cc5e1b8109e5dp-55 }, 1 }, // acos(-0.040000000000000036) == 1.610807001148885581
    {    -0x1.47ae147ae1480p-6, {     0x1.973e83f5d5c9bp+0,   -0x1.dff8acccc8f64p-55 }, 1 }, // acos(-0.020000000000000018) == 1.5907976603682871287
    {                 0x0.0p+0, {     0x1.921fb54442d18p+0,    0x1.1a62633145c07p-54 }, 1 }, // acos(0.0) == 1.5707963267948966192
    {     0x1.47ae147ae1480p-6, {     0x1.8d00e692afd96p+0,   -0x1.b67dc66e20080p-55 }, 1 }, // acos(0.020000000000000018) == 1.5507949932215061097
    {     0x1.47ae147ae1480p-5, {     0x1.87e1918a6b72dp+0,    0x1.4e95b8a2068dfp-54 }, 1 }, // acos(0.040000000000000036) == 1.5307856524409076575
    {     0x1.eb851eb851ec0p-5, {     0x1.82c12f58a8653p+0,   -0x1.8052d5e13d933p-55 }, 1 }, // acos(0.06000000000000005) == 1.5107602683496181433
    {     0x1.47ae147ae1480p-4, {     0x1.7d9f3831229ffp+0,    0x1.7cc29ccb943cep-55 }, 1 }, // acos(0.08000000000000007) == 1.4907107467612375342
    {     0x1.99999999999a0p-4, {     0x1.787b22ce3f590p+0,   -0x1.7156084c0ddfcp-54 }, 1 }, // acos(0.10000000000000009) == 1.4706289056333367336
    {     0x1.eb851eb851ec0p-4, {     0x1.735463ed55f0fp+0,    0x1.c9ff109d2b17bp-54 }, 1 }, // acos(0.1200000000000001) == 1.4505064444001084406
    {     0x1.1eb851eb851f0p-3, {     0x1.6e2a6dc5bb770p+0,    0x1.b0ba9646da925p-54 }, 1 }, // acos(0.14000000000000012) == 1.4303349120850406934
    {     0x1.47ae147ae1478p-3, {     0x1.68fcaf790f466p+0,    0x1.786e793e0bdb4p-54 }, 1 }, // acos(0.15999999999999992) == 1.4101056738429860999
    {     0x1.70a3d70a3d708p-3, {     0x1.63ca947b23534p+0,   -0x1.1500adac610fdp-55 }, 1 }, // acos(0.17999999999999994) == 1.3898098755483489752
    {     0x1.9999999999998p-3, {     0x1.5e9383efad0d1p+0,   -0x1.f37213a820979p-56 }, 1 }, // acos(0.19999999999999996) == 1.3694384060045658731
    {     0x1.c28f5c28f5c28p-3, {     0x1.5956dffbb29ddp+0,    0x1.affa3b0325cb6p-55 }, 1 }, // acos(0.21999999999999997) == 1.3489818562981022356
    {     0x1.eb851eb851eb8p-3, {     0x1.5414050861a70p+0,    0x1.71b575f1bfe9cp-54 }, 1 }, // acos(0.24) == 1.3284304757559333956
    {     0x1.0a3d70a3d70a4p-2, {     0x1.4eca48f4a5b2dp+0,   -0x1.18b277bc59848p-54 }, 1 }, // acos(0.26) == 1.3077741238864277142
    {     0x1.1eb851eb851ecp-2, {     0x1.4978fa3269ee1p+0,    0x1.20cd43f9522bfp-58 }, 1 }, // acos(0.28) == 1.2870022175865687459
    {     0x1.3333333333334p-2, {     0x1.441f5ecbeef58p+0,    0x1.8cb4898f0a272p-54 }, 1 }, // acos(0.30000000000000004) == 1.2661036727794990647
    {     0x1.47ae147ae147cp-2, {     0x1.3ebcb34cfcdb9p+0,   -0x1.dd11a56d44752p-56 }, 1 }, // acos(0.32000000000000006) == 1.2450668395002663943
    {     0x1.5c28f5c28f5c4p-2, {     0x1.3950298af3baap+0,   -0x1.01e2be9dbc10ap-55 }, 1 }, // acos(0.3400000000000001) == 1.223879429267734825
    {     0x1.70a3d70a3d70cp-2, {     0x1.33d8e745c8a8ep+0,    0x1.d364844811a9bp-54 }, 1 }, // acos(0.3600000000000001) == 1.2025284333582565336
    {     0x1.851eb851eb854p-2, {     0x1.2e56049acd590p+0,    0x1.d2932a6f3a2d1p-54 }, 1 }, // acos(0.3800000000000001) == 1.1810000303206359308
    {     0x1.999999999999cp-2, {     0x1.28c68a40a5e8bp+0,   -0x1.7b52bf4f0c4b1p-55 }, 1 }, // acos(0.40000000000000013) == 1.1592794807274084545
    {     0x1.ae147ae147ae0p-2, {     0x1.23296f81f4e39p+0,   -0x1.cf4a9d60ed855p-55 }, 1 }, // acos(0.41999999999999993) == 1.1373510067250107211
    {     0x1.c28f5c28f5c28p-2, {     0x1.1d7d97e9ecca6p+0,    0x1.16a69f7e7e105p-55 }, 1 }, // acos(0.43999999999999995) == 1.1151976533990733156
    {     0x1.d70a3d70a3d70p-2, {     0x1.17c1d092fa220p+0,    0x1.09a8f900dc7c0p-54 }, 1 }, // acos(0.45999999999999996) == 1.09280112827594428
    {     0x1.eb851eb851eb8p-2, {     0x1.11f4cd03e51fep+0,    0x1.1d5b2a2a953efp-54 }, 1 }, // acos(0.48) == 1.0701416143903084774
    {     0x1.0000000000000p-1, {     0x1.0c152382d7366p+0,   -0x1.ee6913347c2a6p-54 }, 1 }, // acos(0.5) == 1.0471975511965977462
    {     0x1.0a3d70a3d70a4p-1, {     0x1.062148bf3c449p+0,   -0x1.7dec2270ed110p-55 }, 1 }, // acos(0.52) == 1.0239453760989524896
    {     0x1.147ae147ae148p-1, {     0x1.00178aaaf6ac9p+0,   -0x1.3d05c98edf72dp-56 }, 1 }, // acos(0.54) == 1.0003592173949746697
    {     0x1.1eb851eb851ecp-1, {     0x1.f3ec14a0196bcp-1,    0x1.56f6790be1139p-56 }, 1 }, // acos(0.56) == 0.97641052679383435103
    {     0x1.28f5c28f5c290p-1, {     0x1.e77568c1741dep-1,   -0x1.99f58f4201d2ep-59 }, 1 }, // acos(0.5800000000000001) == 0.9520676361226454415
    {     0x1.3333333333334p-1, {     0x1.dac670561bb4ep-1,    0x1.a2b7f222f65e1p-55 }, 1 }, // acos(0.6000000000000001) == 0.92729521800161212141
    {     0x1.3d70a3d70a3d8p-1, {     0x1.cdd9f8f922e98p-1,    0x1.eacade6a64382p-58 }, 1 }, // acos(0.6200000000000001) == 0.90205362359252472925
    {     0x1.47ae147ae147cp-1, {     0x1.c0aa23b4884f4p-1,    0x1.fec9a5247c4e1p-55 }, 1 }, // acos(0.6400000000000001) == 0.87629806116834046956
    {     0x1.51eb851eb8520p-1, {     0x1.b330426ff6222p-1,    0x1.a5c8c57812dd7p-56 }, 1 }, // acos(0.6600000000000001) == 0.84997756592480680004
    {     0x1.5c28f5c28f5c2p-1, {     0x1.a564ac0e73a34p-1,   -0x1.65e976f4bcecap-60 }, 1 }, // acos(0.6799999999999999) == 0.82303369213497612356
    {     0x1.6666666666666p-1, {     0x1.973e83f5d5c9bp-1,    0x1.f743e968a0f60p-56 }, 1 }, // acos(0.7) == 0.79539883018414361768
    {     0x1.70a3d70a3d70ap-1, {     0x1.88b37047fd474p-1,   -0x1.7d96275fb9749p-55 }, 1 }, // acos(0.72) == 0.76699400786186662541
    {     0x1.7ae147ae147aep-1, {     0x1.79b737d7d550bp-1,    0x1.6b2727362bfd9p-55 }, 1 }, // acos(0.74) == 0.73772596845324882094
    {     0x1.851eb851eb852p-1, {     0x1.6a3b3d521f655p-1,    0x1.36dd1e3d306c2p-55 }, 1 }, // acos(0.76) == 0.70748321177934295796
    {     0x1.8f5c28f5c28f6p-1, {     0x1.5a2dc734c81e4p-1,    0x1.dc8e647501395p-56 }, 1 }, // acos(0.78) == 0.67613050956066136717
    {     0x1.999999999999ap-1, {     0x1.4978fa3269ee0p-1,    0x1.e7622994ea781p-55 }, 1 }, // acos(0.8) == 0.64350110879328431279
    {     0x1.a3d70a3d70a3ep-1, {     0x1.380159e14f6fep-1,   -0x1.0deb56ab523dbp-55 }, 1 }, // acos(0.8200000000000001) == 0.60938530803079490732
    {     0x1.ae147ae147ae2p-1, {     0x1.25a38276a6364p-1,    0x1.e23a277083a2dp-55 }, 1 }, // acos(0.8400000000000001) == 0.57351310442309660586
    {     0x1.b851eb851eb86p-1, {     0x1.12308cb4d54b9p-1,    0x1.d1d975f28ab64p-57 }, 1 }, // acos(0.8600000000000001) == 0.53552665431438763052
    {     0x1.c28f5c28f5c2ap-1, {     0x1.fad002f93be18p-2,   -0x1.de2ea6c5b1373p-58 }, 1 }, // acos(0.8800000000000001) == 0.49493412634089527975
    {     0x1.ccccccccccccep-1, {     0x1.cdd9f8f922e94p-2,   -0x1.c7b662fd94605p-57 }, 1 }, // acos(0.9000000000000001) == 0.4510268117962621269
    {     0x1.d70a3d70a3d70p-1, {     0x1.9c618aa4ae240p-2,    0x1.4a15538e41812p-58 }, 1 }, // acos(0.9199999999999999) == 0.40271584158066176421
    {     0x1.e147ae147ae14p-1, {     0x1.6485a22bc881ep-2,    0x1.7a47a4dabea7cp-59 }, 1 }, // acos(0.94) == 0.34816602127296103742
    {     0x1.eb851eb851eb8p-1, {     0x1.229aec47638dfp-2,   -0x1.742ef62956816p-57 }, 1 }, // acos(0.96) == 0.28379410920832797251
    {     0x1.f5c28f5c28f5cp-1, {     0x1.9a49276037887p-3,   -0x1.0e40dc73060b0p-60 }, 1 }, // acos(0.98) == 0.20033484232311968196
    {     0x1.0000000000000p+0, {                 0x0.0p+0,                 0x0.0p+0 }, 1 }, // acos(1.0) == 0.0
};

void Test_acos_approx(void)
{
    for (int i = 0; i < _countof(s_acos_approx_tests); i++)
    {
        double x = s_acos_approx_tests[i].x;
        double expected = s_acos_approx_tests[i].expected.rounded;
        double z = acos(x);
        int64_t error = abs(ulp_error_precise(&s_acos_approx_tests[i].expected, z));
        ok(error <= s_acos_approx_tests[i].max_error,
            "acos(%.17e) = %.17e, expected %.17e, error %I64d ULPs, max %u ULPs\n",
            x, z, expected, error, s_acos_approx_tests[i].max_error);
    }
}

#ifdef HAS_ACOSF

// These are expected to match exactly
static TESTENTRY_DBL s_acosf_exact_tests[] =
{
    { 0x00000000 /*  0.000000 */, 0x3fc90fdb /*  1.570796 */ },
    { 0x80000000 /* -0.000000 */, 0x3fc90fdb /*  1.570796 */ },
    { 0x7f800000 /*  1.#INF00 */, 0x3fc90fdb /*  1.570796 */ },
    { 0x7f800001 /*  1.#SNAN0 */, 0x3fc90fdb /*  1.570796 */ },
    { 0x7fBFffff /*  1.#SNAN0 */, 0x3fc90fdb /*  1.570796 */ },
    { 0x7fC00000 /*  1.#QNAN0 */, 0x3fc90fdb /*  1.570796 */ },
    { 0x7fC80001 /*  1.#QNAN0 */, 0x3fc90fdb /*  1.570796 */ },
    { 0x7fFfffff /*  1.#QNAN0 */, 0x3fc90fdb /*  1.570796 */ },
    { 0xff800000 /* -1.#INF00 */, 0x3fc90fdb /*  1.570796 */ },
    { 0xff800001 /* -1.#SNAN0 */, 0x3fc90fdb /*  1.570796 */ },
    { 0xffBfffff /* -1.#SNAN0 */, 0x3fc90fdb /*  1.570796 */ },
    { 0xffC00000 /* -1.#IND00 */, 0x3fc90fdb /*  1.570796 */ },
    { 0xfff80001 /* -1.#QNAN0 */, 0x3fc90fdb /*  1.570796 */ },
    { 0xffffffff /* -1.#QNAN0 */, 0x3fc90fdb /*  1.570796 */ },
};

void Test_acosf_exact(void)
{
    for (int i = 0; i < _countof(s_acosf_exact_tests); i++)
    {
        float x = u64_to_dbl(s_acosf_exact_tests[i].x);
        float z = acosf(x);
        ok_eq_flt_exact("acosf", s_acosf_exact_tests[i].x, z, s_acosf_exact_tests[i].result);
    }
}

#endif // HAS_ACOSF

#if defined(HAS_ACOSF) || defined(HAS_LIBM_SSE2)

static TESTENTRY_DBL_APPROX s_acosf_approx_tests[] =
{
//  {    x,                     {    y_rounded,               y_difference           } }
    {    -0x1.0000000000000p+0, {     0x1.921fb54442d18p+1,    0x1.1a62633145c07p-53 }, 1 }, // acosf(-1.0) == 3.1415926535897932385
    {    -0x1.f5c2900000000p-1, {     0x1.787b239c14496p+1,    0x1.797206dc626b2p-53 }, 1 }, // acosf(-0.9800000190734863) == 2.9412579071145714098
    {    -0x1.eb851e0000000p-1, {     0x1.6dcc5716c4181p+1,    0x1.8125a18bfd702p-55 }, 1 }, // acosf(-0.9599999785423279) == 2.8577984677469321779
    {    -0x1.e147ae0000000p-1, {     0x1.658f00efc7f78p+1,   -0x1.73d00e4a2c9bfp-55 }, 1 }, // acosf(-0.9399999976158142) == 2.7934266253286601108
    {    -0x1.d70a3e0000000p-1, {     0x1.5e93844b1fa46p+1,   -0x1.78b4409d06ac5p-57 }, 1 }, // acosf(-0.9200000166893005) == 2.7388768545927488671
    {    -0x1.cccccc0000000p-1, {     0x1.586475afa87a2p+1,   -0x1.99926d7af536cp-54 }, 1 }, // acosf(-0.8999999761581421) == 2.6905657870965606016
    {    -0x1.c28f5c0000000p-1, {     0x1.52c5b4cf8c34dp+1,    0x1.d4e9b6b09485fp-53 }, 1 }, // acosf(-0.8799999952316284) == 2.6466585172096645886
    {    -0x1.b851ec0000000p-1, {     0x1.4d93925340d85p+1,    0x1.be7920d9a13eap-55 }, 1 }, // acosf(-0.8600000143051147) == 2.6060660273084886236
    {    -0x1.ae147a0000000p-1, {     0x1.48b6d43eccaffp+1,   -0x1.eae7a61bed3e6p-55 }, 1 }, // acosf(-0.8399999737739563) == 2.5680795008314584749
    {    -0x1.a3d70a0000000p-1, {     0x1.441f5eb118eb7p+1,    0x1.0b46eaeba6394p-56 }, 1 }, // acosf(-0.8199999928474426) == 2.5322073330624692711
    {    -0x1.99999a0000000p-1, {     0x1.3fc176e25300bp+1,    0x1.feb4e380e8f98p-54 }, 1 }, // acosf(-0.800000011920929) == 2.49809156466472404
    {    -0x1.8f5c280000000p-1, {     0x1.3b944314e2505p+1,    0x1.f7c2333ecd7fcp-53 }, 1 }, // acosf(-0.7799999713897705) == 2.4654620983097881268
    {    -0x1.851eb80000000p-1, {     0x1.3790e5d0380bbp+1,   -0x1.3b923cc2f9ccep-53 }, 1 }, // acosf(-0.7599999904632568) == 2.4341094271368012033
    {    -0x1.7ae1480000000p-1, {     0x1.33b1e76cc05aep+1,    0x1.577c6eab559d1p-53 }, 1 }, // acosf(-0.7400000095367432) == 2.4038666993153220799
    {    -0x1.70a3d80000000p-1, {     0x1.2ff2d98acc17cp+1,    0x1.a80b4b1cd0306p-54 }, 1 }, // acosf(-0.7200000286102295) == 2.3745986869545828522
    {    -0x1.6666660000000p-1, {     0x1.2c501422f47f0p+1,   -0x1.818a88c5bed90p-53 }, 1 }, // acosf(-0.699999988079071) == 2.3461938067130104206
    {    -0x1.5c28f60000000p-1, {     0x1.28c68a5598d50p+1,   -0x1.6a5e114395f0dp-53 }, 1 }, // acosf(-0.6800000071525574) == 2.3185589712099171172
    {    -0x1.51eb860000000p-1, {     0x1.2553a4f33ccb3p+1,   -0x1.7771d4bd8c1cfp-53 }, 1 }, // acosf(-0.6600000262260437) == 2.2916151225741370793
    {    -0x1.47ae140000000p-1, {     0x1.21f52c2f25bccp+1,    0x1.fb7c1bd9abd94p-55 }, 1 }, // acosf(-0.6399999856948853) == 2.2652945738040895502
    {    -0x1.3d70a40000000p-1, {     0x1.1ea9371307330p+1,   -0x1.b4e5637fc1f66p-53 }, 1 }, // acosf(-0.6200000047683716) == 2.239539036074709865
    {    -0x1.3333340000000p-1, {     0x1.1b6e196ebbe45p+1,    0x1.6368d0e665a95p-54 }, 1 }, // acosf(-0.6000000238418579) == 2.2142974653905037268
    {    -0x1.28f5c20000000p-1, {     0x1.18425ae7e6c57p+1,    0x1.0339b842e02e2p-53 }, 1 }, // acosf(-0.5799999833106995) == 2.1895249969798374915
    {    -0x1.1eb8520000000p-1, {     0x1.1524b0226a846p+1,    0x1.113537ee1749ap-55 }, 1 }, // acosf(-0.5600000023841858) == 2.1651821296736981933
    {    -0x1.147ae20000000p-1, {     0x1.1213f0258720fp+1,    0x1.cea2ad5ca7270p-53 }, 1 }, // acosf(-0.5400000214576721) == 2.141233461689132623
    {    -0x1.0a3d700000000p-1, {     0x1.0f0f10b4b0aacp+1,    0x1.1fae62753160ap-53 }, 1 }, // acosf(-0.5199999809265137) == 2.1176472551608950394
    {    -0x1.0000000000000p-1, {     0x1.0c152382d7366p+1,   -0x1.ee6913347c2a6p-53 }, 1 }, // acosf(-0.5) == 2.0943951023931954923
    {    -0x1.eb851e0000000p-2, {     0x1.09254ea80cd76p+1,   -0x1.81cb80b39b377p-56 }, 1 }, // acosf(-0.47999998927116394) == 2.071451026969664412
    {    -0x1.d70a3e0000000p-2, {     0x1.063ecd0ef4599p+1,    0x1.1808cd3d748a4p-53 }, 1 }, // acosf(-0.46000000834465027) == 2.0487915347118358482
    {    -0x1.c28f5c0000000p-2, {     0x1.0360e94998d21p+1,   -0x1.bbcdbea0f6b75p-53 }, 1 }, // acosf(-0.4399999976158142) == 2.0263949975357180862
    {    -0x1.ae147a0000000p-2, {     0x1.008afd6440d3dp+1,    0x1.72931993dabaep-53 }, 1 }, // acosf(-0.41999998688697815) == 2.0042416324155555793
    {    -0x1.99999a0000000p-2, {     0x1.fb78e063ce4abp+0,   -0x1.c2783b05fed0bp-54 }, 1 }, // acosf(-0.4000000059604645) == 1.9823131793657845634
    {    -0x1.851eb80000000p-2, {     0x1.f5e965d7943a5p+0,   -0x1.c10e248614dd2p-57 }, 1 }, // acosf(-0.3799999952316284) == 1.9605926181140855713
    {    -0x1.70a3d80000000p-2, {     0x1.f066838497f95p+0,    0x1.7ebd0b2eb605ep-55 }, 1 }, // acosf(-0.36000001430511475) == 1.9390642355647050159
    {    -0x1.5c28f60000000p-2, {     0x1.eaef410de72a1p+0,    0x1.49ce219f3d925p-56 }, 1 }, // acosf(-0.3400000035762787) == 1.9177132281248889979
    {    -0x1.47ae140000000p-2, {     0x1.e582b71b1bfbap+0,   -0x1.724dc01c1c3e0p-56 }, 1 }, // acosf(-0.3199999928474426) == 1.8965258065399965636
    {    -0x1.3333340000000p-2, {     0x1.e0200bf242c1cp+0,   -0x1.35883b6d42879p-54 }, 1 }, // acosf(-0.30000001192092896) == 1.875488993306823215
    {    -0x1.1eb8520000000p-2, {     0x1.dac6705b710a5p+0,   -0x1.06e93d454d8cdp-54 }, 1 }, // acosf(-0.2800000011920929) == 1.8545904372449878979
    {    -0x1.0a3d700000000p-2, {     0x1.d575216974b6fp+0,    0x1.cb284ee29a9ffp-54 }, 1 }, // acosf(-0.25999999046325684) == 1.8338185198269590811
    {    -0x1.eb851e0000000p-3, {     0x1.d02b6568682a7p+0,    0x1.0f5b5c2ec05c9p-55 }, 1 }, // acosf(-0.23999999463558197) == 1.8131621723079350011
    {    -0x1.c28f5c0000000p-3, {     0x1.cae88a8793619p+0,   -0x1.059c9956958f6p-54 }, 1 }, // acosf(-0.2199999988079071) == 1.7926107960696581732
    {    -0x1.99999a0000000p-3, {     0x1.c5abe6a5e8f4bp+0,    0x1.888788ca356dfp-54 }, 1 }, // acosf(-0.20000000298023224) == 1.7721542506269142033
    {    -0x1.70a3d80000000p-3, {     0x1.c074d62c9d373p+0,    0x1.2b480084fe234p-54 }, 1 }, // acosf(-0.18000000715255737) == 1.7517827853127670528
    {    -0x1.47ae140000000p-3, {     0x1.bb42baffe6e20p+0,    0x1.2445ceb29419dp-55 }, 1 }, // acosf(-0.1599999964237213) == 1.7314869761238540808
    {    -0x1.1eb8520000000p-3, {     0x1.b614fcc5600cep+0,   -0x1.13423bf023078p-56 }, 1 }, // acosf(-0.14000000059604645) == 1.7112577421067274159
    {    -0x1.eb851e0000000p-4, {     0x1.b0eb068f951c1p+0,    0x1.29082826e907cp-54 }, 1 }, // acosf(-0.11999999731779099) == 1.6910862064879526678
    {    -0x1.99999a0000000p-4, {     0x1.abc447c0b4f17p+0,    0x1.dda57373a33e7p-56 }, 1 }, // acosf(-0.10000000149011612) == 1.6709637494540794648
    {    -0x1.47ae140000000p-4, {     0x1.a6a0324fae9c3p+0,    0x1.9f8f0f7b5c65cp-55 }, 1 }, // acosf(-0.07999999821186066) == 1.6508819050346666308
    {    -0x1.eb851e0000000p-5, {     0x1.a17e3b2a18053p+0,   -0x1.5ada1a98159d6p-54 }, 1 }, // acosf(-0.05999999865889549) == 1.6308323838966500088
    {    -0x1.47ae140000000p-5, {     0x1.9c5dd8fa425c6p+0,    0x1.076eb68353b17p-55 }, 1 }, // acosf(-0.03999999910593033) == 1.6108070002540997586
    {    -0x1.47ae140000000p-6, {     0x1.973e83f3ea2b6p+0,   -0x1.12ddd8f41ede4p-59 }, 1 }, // acosf(-0.019999999552965164) == 1.5907976599211628414
    {                 0x0.0p+0, {     0x1.921fb54442d18p+0,    0x1.1a62633145c07p-54 }, 1 }, // acosf(0.0) == 1.5707963267948966192
    {     0x1.47ae140000000p-6, {     0x1.8d00e6949b77bp+0,   -0x1.c2a44ad5d3883p-54 }, 1 }, // acosf(0.019999999552965164) == 1.5507949936686303971
    {     0x1.47ae140000000p-5, {     0x1.87e1918e4346ap+0,    0x1.b10d6b20e1a82p-54 }, 1 }, // acosf(0.03999999910593033) == 1.5307856533356934798
    {     0x1.eb851e0000000p-5, {     0x1.82c12f5e6d9dep+0,   -0x1.c1847c157b873p-56 }, 1 }, // acosf(0.05999999865889549) == 1.5107602696931432296
    {     0x1.47ae140000000p-4, {     0x1.7d9f3838d706dp+0,    0x1.64fd3ea4dd4e0p-54 }, 1 }, // acosf(0.07999999821186066) == 1.4907107485551266076
    {     0x1.99999a0000000p-4, {     0x1.787b22c7d0b19p+0,    0x1.bd5b6985a2b14p-54 }, 1 }, // acosf(0.10000000149011612) == 1.4706289041357137737
    {     0x1.eb851e0000000p-4, {     0x1.735463f8f086fp+0,    0x1.0bbc9e3ba2791p-54 }, 1 }, // acosf(0.11999999731779099) == 1.4505064471018405706
    {     0x1.1eb8520000000p-3, {     0x1.6e2a6dc325963p+0,   -0x1.866aaaa16bbd4p-54 }, 1 }, // acosf(0.14000000059604645) == 1.4303349114830658226
    {     0x1.47ae140000000p-3, {     0x1.68fcaf889ec10p+0,    0x1.a2a1df094173fp-54 }, 1 }, // acosf(0.1599999964237213) == 1.4101056774659391577
    {     0x1.70a3d80000000p-3, {     0x1.63ca945be86bdp+0,    0x1.097cc5dd8d5d9p-54 }, 1 }, // acosf(0.18000000715255737) == 1.3898098682770261856
    {     0x1.99999a0000000p-3, {     0x1.5e9383e29cae5p+0,    0x1.587a7b30ac25dp-55 }, 1 }, // acosf(0.20000000298023224) == 1.3694384029628790352
    {     0x1.c28f5c0000000p-3, {     0x1.5956e000f2418p+0,   -0x1.8b3d408dbddf9p-55 }, 1 }, // acosf(0.2199999988079071) == 1.3489818575201350652
    {     0x1.eb851e0000000p-3, {     0x1.541405201d789p+0,    0x1.ad17184b2b529p-54 }, 1 }, // acosf(0.23999999463558197) == 1.3284304812818582373
    {     0x1.0a3d700000000p-2, {     0x1.4eca491f10ec1p+0,    0x1.a671ddffc3839p-56 }, 1 }, // acosf(0.25999999046325684) == 1.3077741337628341574
    {     0x1.1eb8520000000p-2, {     0x1.4978fa2d1498cp+0,   -0x1.88a3f8b04de4ap-55 }, 1 }, // acosf(0.2800000011920929) == 1.2870022163448053406
    {     0x1.3333340000000p-2, {     0x1.441f5e9642e15p+0,   -0x1.2b65fc6063ef3p-55 }, 1 }, // acosf(0.30000001192092896) == 1.2661036602829700235
    {     0x1.47ae140000000p-2, {     0x1.3ebcb36d69a77p+0,   -0x1.6ea7c9966d6fap-54 }, 1 }, // acosf(0.3199999928474426) == 1.2450668470497966749
    {     0x1.5c28f60000000p-2, {     0x1.3950297a9e78fp+0,    0x1.e2513dfabc1c5p-54 }, 1 }, // acosf(0.3400000035762787) == 1.2238794254649042406
    {     0x1.70a3d80000000p-2, {     0x1.33d8e703eda9bp+0,    0x1.756640cb307dfp-54 }, 1 }, // acosf(0.36000001430511475) == 1.2025284180250882226
    {     0x1.851eb80000000p-2, {     0x1.2e5604b0f168cp+0,   -0x1.9319750cb1e38p-54 }, 1 }, // acosf(0.3799999952316284) == 1.1810000354757076671
    {     0x1.99999a0000000p-2, {     0x1.28c68a24b7586p+0,   -0x1.185fd2eeb5cf5p-59 }, 1 }, // acosf(0.4000000059604645) == 1.159279474224008675
    {     0x1.ae147a0000000p-2, {     0x1.23296fc003fb6p+0,   -0x1.60c2d98a53e9dp-55 }, 1 }, // acosf(0.41999998688697815) == 1.1373510211742376592
    {     0x1.c28f5c0000000p-2, {     0x1.1d7d97f553fefp+0,    0x1.ac6043a478ef8p-54 }, 1 }, // acosf(0.4399999976158142) == 1.1151976560540751523
    {     0x1.d70a3e0000000p-2, {     0x1.17c1d06a9cefep+0,    0x1.2ccaf9e89b1a9p-60 }, 1 }, // acosf(0.46000000834465027) == 1.0928011188779573902
    {     0x1.eb851e0000000p-2, {     0x1.11f4cd386bf45p+0,   -0x1.6ac859708db15p-54 }, 1 }, // acosf(0.47999998927116394) == 1.0701416266201288265
    {     0x1.0000000000000p-1, {     0x1.0c152382d7366p+0,   -0x1.ee6913347c2a6p-54 }, 1 }, // acosf(0.5) == 1.0471975511965977462
    {     0x1.0a3d700000000p-1, {     0x1.0621491f244d8p+0,   -0x1.52ffd0fae80e0p-59 }, 1 }, // acosf(0.5199999809265137) == 1.0239453984288981991
    {     0x1.147ae20000000p-1, {     0x1.00178a3d77612p+0,   -0x1.68809456c2cd1p-54 }, 1 }, // acosf(0.5400000214576721) == 1.0003591919006606154
    {     0x1.1eb8520000000p-1, {     0x1.f3ec148761349p-1,   -0x1.4f575652008fdp-56 }, 1 }, // acosf(0.5600000023841858) == 0.97641052391609504516
    {     0x1.28f5c20000000p-1, {     0x1.e775697170304p-1,    0x1.728aaee659250p-57 }, 1 }, // acosf(0.5799999833106995) == 0.95206765660995574701
    {     0x1.3333340000000p-1, {     0x1.dac66f561bb4cp-1,    0x1.a2b7eaf84baf1p-55 }, 1 }, // acosf(0.6000000238418579) == 0.92729518819928951167
    {     0x1.3d70a40000000p-1, {     0x1.cdd9f8c4ee7a3p-1,   -0x1.85c1ca77c249dp-56 }, 1 }, // acosf(0.6200000047683716) == 0.9020536175150833735
    {     0x1.47ae140000000p-1, {     0x1.c0aa245474531p-1,   -0x1.91f28f1494d79p-55 }, 1 }, // acosf(0.6399999856948853) == 0.87629807978570368826
    {     0x1.51eb860000000p-1, {     0x1.b330414418197p-1,   -0x1.b8af2044b88a9p-55 }, 1 }, // acosf(0.6600000262260437) == 0.84997753101565615915
    {     0x1.5c28f60000000p-1, {     0x1.a564abbaa7f23p-1,   -0x1.ecfe2e2c913b2p-55 }, 1 }, // acosf(0.6800000071525574) == 0.82303368237987612128
    {     0x1.6666660000000p-1, {     0x1.973e8485394a3p-1,   -0x1.904c5023ed9a5p-55 }, 1 }, // acosf(0.699999988079071) == 0.79539884687678281784
    {     0x1.70a3d80000000p-1, {     0x1.88b36ee5dae70p-1,    0x1.1972f68b76a0fp-55 }, 1 }, // acosf(0.7200000286102295) == 0.76699396663521038629
    {     0x1.7ae1480000000p-1, {     0x1.79b7375e09da8p-1,   -0x1.e8d05bd07ee52p-56 }, 1 }, // acosf(0.7400000095367432) == 0.7377259542744711586
    {     0x1.851eb80000000p-1, {     0x1.6a3b3dd02b176p-1,    0x1.57d27fd0fe352p-55 }, 1 }, // acosf(0.7599999904632568) == 0.70748322645299203512
    {     0x1.8f5c280000000p-1, {     0x1.5a2dc8bd8204bp-1,    0x1.15017f93c2054p-56 }, 1 }, // acosf(0.7799999713897705) == 0.67613055528000511166
    {     0x1.99999a0000000p-1, {     0x1.4978f987bf434p-1,    0x1.b07f170d143b1p-57 }, 1 }, // acosf(0.800000011920929) == 0.64350108892506919851
    {     0x1.a3d70a0000000p-1, {     0x1.38015a4ca7985p-1,   -0x1.c19e8b0bc1ae5p-59 }, 1 }, // acosf(0.8199999928474426) == 0.60938532052732396733
    {     0x1.ae147a0000000p-1, {     0x1.25a38415d8866p-1,   -0x1.ab8ecd1efbbffp-55 }, 1 }, // acosf(0.8399999737739563) == 0.57351315275833476353
    {     0x1.b851ec0000000p-1, {     0x1.12308bc407e4dp-1,   -0x1.54ef94148a3cep-55 }, 1 }, // acosf(0.8600000143051147) == 0.53552662628130461487
    {     0x1.c28f5c0000000p-1, {     0x1.fad003a5b4e57p-2,   -0x1.d43a9bfa762c3p-56 }, 1 }, // acosf(0.8799999952316284) == 0.4949341363801286499
    {     0x1.cccccc0000000p-1, {     0x1.cdd9fca4d2bb4p-2,   -0x1.8d466113fa433p-57 }, 1 }, // acosf(0.8999999761581421) == 0.4510268664932326369
    {     0x1.d70a3e0000000p-1, {     0x1.9c6187c919692p-2,    0x1.8f6d39d8b159ap-56 }, 1 }, // acosf(0.9200000166893005) == 0.40271579899704437134
    {     0x1.e147ae0000000p-1, {     0x1.6485a2a3d6d03p-2,   -0x1.15332785e3128p-58 }, 1 }, // acosf(0.9399999976158142) == 0.34816602826113312765
    {     0x1.eb851e0000000p-1, {     0x1.229af16bf5cb9p-2,    0x1.d0c7d67233233p-56 }, 1 }, // acosf(0.9599999785423279) == 0.28379418584286106053
    {     0x1.f5c2900000000p-1, {     0x1.9a491a82e881fp-3,   -0x1.f0fa3ab1caab3p-57 }, 1 }, // acosf(0.9800000190734863) == 0.20033474647522182862
    {     0x1.0000000000000p+0, {                 0x0.0p+0,                 0x0.0p+0 }, 1 }, // acosf(1.0) == 0.0
};

#endif // defined(HAS_ACOSF) || defined(HAS_LIBM_SSE2)

#if defined(HAS_ACOSF)

void Test_acosf_approx(void)
{
    for (int i = 0; i < _countof(s_acosf_approx_tests); i++)
    {
        float x = s_acosf_approx_tests[i].x;
        float expected = s_acosf_approx_tests[i].expected.rounded;
        float z = acosf(x);
        int64_t error = abs(ulp_error_flt(expected, z));
        ok(error <= s_acos_approx_tests[i].max_error,
            "acos(%.6e) = %.7e, expected %.7e, error %I64d ULPs, max %u ULPs\n",
            x, z, expected, error, s_acos_approx_tests[i].max_error);
    }
}

#endif // defined(HAS_ACOSF)

#if defined(HAS_LIBM_SSE2)

__ATTRIBUTE_SSE2__ __m128d __libm_sse2_acos(__m128d Xmm0);

__ATTRIBUTE_SSE2__
void Test_libm_sse2_acos(void)
{
    int i;
    for (i = 0; i < _countof(s_acos_approx_tests); i++)
    {
        double x = s_acos_approx_tests[i].x;
        double expected = s_acos_approx_tests[i].expected.rounded;
        __m128d xmm0 = _mm_set_sd(x);
        __m128d xmm1 = __libm_sse2_acos(xmm0);
        double z = _mm_cvtsd_f64(xmm1);
        int64_t error = ulp_error_precise(&s_acos_approx_tests[i].expected, z);
        ok(error <= s_acos_approx_tests[i].max_error,
            "__libm_sse2_acos(%.17e) = %.17e, expected %.17e, error %I64d ULPs, max %u ULPs\n",
            x, z, expected, error, s_acos_approx_tests[i].max_error);
    }
}

__ATTRIBUTE_SSE2__ __m128 __libm_sse2_acosf(__m128 Xmm0);

__ATTRIBUTE_SSE2__
void Test_libm_sse2_acosf(void)
{
    int i;
    for (i = 0; i < _countof(s_acosf_approx_tests); i++)
    {
        float x = s_acosf_approx_tests[i].x;
        float expected = s_acosf_approx_tests[i].expected.rounded;
        __m128 xmm0 = _mm_set_ps1(x);
        __m128 xmm1 = __libm_sse2_acosf(xmm0);
        float z = _mm_cvtss_f32(xmm1);
        int64_t error = ulp_error_flt(expected, z);
        ok(error <= s_acosf_approx_tests[i].max_error,
            "__libm_sse2_acosf(%.6e) = %.7e, expected %.7e, error %I64d ULPs, max %u ULPs\n",
            x, z, expected, error, s_acosf_approx_tests[i].max_error);
    }
}

#endif // defined(HAS_LIBM_SSE2)

START_TEST(acos)
{
    Test_acos_exact();
    Test_acos_approx();
#if defined(HAS_ACOSF)
    Test_acosf_exact();
    Test_acosf_approx();
#endif
#if defined(HAS_LIBM_SSE2)
    Test_libm_sse2_acos();
    Test_libm_sse2_acosf();
#endif
}
