#ifndef BOOST_PREPROCESSOR_REPEAT_2ND_HPP
#define BOOST_PREPROCESSOR_REPEAT_2ND_HPP

/* Copyright (C) 2001
 * Housemarque Oy
 * http://www.housemarque.com
 *
 * Permission to copy, use, modify, sell and distribute this software is
 * granted provided this copyright notice appears in all copies. This
 * software is provided "as is" without express or implied warranty, and
 * with no claim as to its suitability for any purpose.
 *
 * See http://www.boost.org for most recent version.
 */

/** <p>Same as BOOST_PP_REPEAT(), but implemented independently.</p>

<h3>Test</h3>
<ul>
  <li><a href="../../test/repeat_2nd_test.cpp">repeat_2nd_test.cpp</a></li>
</ul>
*/
#define BOOST_PP_REPEAT_2ND(N,M,P) BOOST_PP_REPEAT_2ND_DELAY(N,M,P)

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define BOOST_PP_REPEAT_2ND_DELAY(N,M,P) BOOST_PP_REPEAT_2ND##N(M,P)
#define BOOST_PP_REPEAT_2ND0(M,P)
#define BOOST_PP_REPEAT_2ND1(M,P) M(0,P)
#define BOOST_PP_REPEAT_2ND2(M,P) M(0,P) M(1,P)
#define BOOST_PP_REPEAT_2ND3(M,P) M(0,P) M(1,P) M(2,P)
#define BOOST_PP_REPEAT_2ND4(M,P) M(0,P) M(1,P) M(2,P) M(3,P)
#define BOOST_PP_REPEAT_2ND5(M,P) BOOST_PP_REPEAT_2ND4(M,P) M(4,P)
#define BOOST_PP_REPEAT_2ND6(M,P) BOOST_PP_REPEAT_2ND5(M,P) M(5,P)
#define BOOST_PP_REPEAT_2ND7(M,P) BOOST_PP_REPEAT_2ND6(M,P) M(6,P)
#define BOOST_PP_REPEAT_2ND8(M,P) BOOST_PP_REPEAT_2ND7(M,P) M(7,P)
#define BOOST_PP_REPEAT_2ND9(M,P) BOOST_PP_REPEAT_2ND8(M,P) M(8,P)
#define BOOST_PP_REPEAT_2ND10(M,P) BOOST_PP_REPEAT_2ND9(M,P) M(9,P)
#define BOOST_PP_REPEAT_2ND11(M,P) BOOST_PP_REPEAT_2ND10(M,P) M(10,P)
#define BOOST_PP_REPEAT_2ND12(M,P) BOOST_PP_REPEAT_2ND11(M,P) M(11,P)
#define BOOST_PP_REPEAT_2ND13(M,P) BOOST_PP_REPEAT_2ND12(M,P) M(12,P)
#define BOOST_PP_REPEAT_2ND14(M,P) BOOST_PP_REPEAT_2ND13(M,P) M(13,P)
#define BOOST_PP_REPEAT_2ND15(M,P) BOOST_PP_REPEAT_2ND14(M,P) M(14,P)
#define BOOST_PP_REPEAT_2ND16(M,P) BOOST_PP_REPEAT_2ND15(M,P) M(15,P)
#define BOOST_PP_REPEAT_2ND17(M,P) BOOST_PP_REPEAT_2ND16(M,P) M(16,P)
#define BOOST_PP_REPEAT_2ND18(M,P) BOOST_PP_REPEAT_2ND17(M,P) M(17,P)
#define BOOST_PP_REPEAT_2ND19(M,P) BOOST_PP_REPEAT_2ND18(M,P) M(18,P)
#define BOOST_PP_REPEAT_2ND20(M,P) BOOST_PP_REPEAT_2ND19(M,P) M(19,P)
#define BOOST_PP_REPEAT_2ND21(M,P) BOOST_PP_REPEAT_2ND20(M,P) M(20,P)
#define BOOST_PP_REPEAT_2ND22(M,P) BOOST_PP_REPEAT_2ND21(M,P) M(21,P)
#define BOOST_PP_REPEAT_2ND23(M,P) BOOST_PP_REPEAT_2ND22(M,P) M(22,P)
#define BOOST_PP_REPEAT_2ND24(M,P) BOOST_PP_REPEAT_2ND23(M,P) M(23,P)
#define BOOST_PP_REPEAT_2ND25(M,P) BOOST_PP_REPEAT_2ND24(M,P) M(24,P)
#define BOOST_PP_REPEAT_2ND26(M,P) BOOST_PP_REPEAT_2ND25(M,P) M(25,P)
#define BOOST_PP_REPEAT_2ND27(M,P) BOOST_PP_REPEAT_2ND26(M,P) M(26,P)
#define BOOST_PP_REPEAT_2ND28(M,P) BOOST_PP_REPEAT_2ND27(M,P) M(27,P)
#define BOOST_PP_REPEAT_2ND29(M,P) BOOST_PP_REPEAT_2ND28(M,P) M(28,P)
#define BOOST_PP_REPEAT_2ND30(M,P) BOOST_PP_REPEAT_2ND29(M,P) M(29,P)
#define BOOST_PP_REPEAT_2ND31(M,P) BOOST_PP_REPEAT_2ND30(M,P) M(30,P)
#define BOOST_PP_REPEAT_2ND32(M,P) BOOST_PP_REPEAT_2ND31(M,P) M(31,P)
#define BOOST_PP_REPEAT_2ND33(M,P) BOOST_PP_REPEAT_2ND32(M,P) M(32,P)
#define BOOST_PP_REPEAT_2ND34(M,P) BOOST_PP_REPEAT_2ND33(M,P) M(33,P)
#define BOOST_PP_REPEAT_2ND35(M,P) BOOST_PP_REPEAT_2ND34(M,P) M(34,P)
#define BOOST_PP_REPEAT_2ND36(M,P) BOOST_PP_REPEAT_2ND35(M,P) M(35,P)
#define BOOST_PP_REPEAT_2ND37(M,P) BOOST_PP_REPEAT_2ND36(M,P) M(36,P)
#define BOOST_PP_REPEAT_2ND38(M,P) BOOST_PP_REPEAT_2ND37(M,P) M(37,P)
#define BOOST_PP_REPEAT_2ND39(M,P) BOOST_PP_REPEAT_2ND38(M,P) M(38,P)
#define BOOST_PP_REPEAT_2ND40(M,P) BOOST_PP_REPEAT_2ND39(M,P) M(39,P)
#define BOOST_PP_REPEAT_2ND41(M,P) BOOST_PP_REPEAT_2ND40(M,P) M(40,P)
#define BOOST_PP_REPEAT_2ND42(M,P) BOOST_PP_REPEAT_2ND41(M,P) M(41,P)
#define BOOST_PP_REPEAT_2ND43(M,P) BOOST_PP_REPEAT_2ND42(M,P) M(42,P)
#define BOOST_PP_REPEAT_2ND44(M,P) BOOST_PP_REPEAT_2ND43(M,P) M(43,P)
#define BOOST_PP_REPEAT_2ND45(M,P) BOOST_PP_REPEAT_2ND44(M,P) M(44,P)
#define BOOST_PP_REPEAT_2ND46(M,P) BOOST_PP_REPEAT_2ND45(M,P) M(45,P)
#define BOOST_PP_REPEAT_2ND47(M,P) BOOST_PP_REPEAT_2ND46(M,P) M(46,P)
#define BOOST_PP_REPEAT_2ND48(M,P) BOOST_PP_REPEAT_2ND47(M,P) M(47,P)
#define BOOST_PP_REPEAT_2ND49(M,P) BOOST_PP_REPEAT_2ND48(M,P) M(48,P)
#define BOOST_PP_REPEAT_2ND50(M,P) BOOST_PP_REPEAT_2ND49(M,P) M(49,P)
#define BOOST_PP_REPEAT_2ND51(M,P) BOOST_PP_REPEAT_2ND50(M,P) M(50,P)
#define BOOST_PP_REPEAT_2ND52(M,P) BOOST_PP_REPEAT_2ND51(M,P) M(51,P)
#define BOOST_PP_REPEAT_2ND53(M,P) BOOST_PP_REPEAT_2ND52(M,P) M(52,P)
#define BOOST_PP_REPEAT_2ND54(M,P) BOOST_PP_REPEAT_2ND53(M,P) M(53,P)
#define BOOST_PP_REPEAT_2ND55(M,P) BOOST_PP_REPEAT_2ND54(M,P) M(54,P)
#define BOOST_PP_REPEAT_2ND56(M,P) BOOST_PP_REPEAT_2ND55(M,P) M(55,P)
#define BOOST_PP_REPEAT_2ND57(M,P) BOOST_PP_REPEAT_2ND56(M,P) M(56,P)
#define BOOST_PP_REPEAT_2ND58(M,P) BOOST_PP_REPEAT_2ND57(M,P) M(57,P)
#define BOOST_PP_REPEAT_2ND59(M,P) BOOST_PP_REPEAT_2ND58(M,P) M(58,P)
#define BOOST_PP_REPEAT_2ND60(M,P) BOOST_PP_REPEAT_2ND59(M,P) M(59,P)
#define BOOST_PP_REPEAT_2ND61(M,P) BOOST_PP_REPEAT_2ND60(M,P) M(60,P)
#define BOOST_PP_REPEAT_2ND62(M,P) BOOST_PP_REPEAT_2ND61(M,P) M(61,P)
#define BOOST_PP_REPEAT_2ND63(M,P) BOOST_PP_REPEAT_2ND62(M,P) M(62,P)
#define BOOST_PP_REPEAT_2ND64(M,P) BOOST_PP_REPEAT_2ND63(M,P) M(63,P)
#define BOOST_PP_REPEAT_2ND65(M,P) BOOST_PP_REPEAT_2ND64(M,P) M(64,P)
#define BOOST_PP_REPEAT_2ND66(M,P) BOOST_PP_REPEAT_2ND65(M,P) M(65,P)
#define BOOST_PP_REPEAT_2ND67(M,P) BOOST_PP_REPEAT_2ND66(M,P) M(66,P)
#define BOOST_PP_REPEAT_2ND68(M,P) BOOST_PP_REPEAT_2ND67(M,P) M(67,P)
#define BOOST_PP_REPEAT_2ND69(M,P) BOOST_PP_REPEAT_2ND68(M,P) M(68,P)
#define BOOST_PP_REPEAT_2ND70(M,P) BOOST_PP_REPEAT_2ND69(M,P) M(69,P)
#define BOOST_PP_REPEAT_2ND71(M,P) BOOST_PP_REPEAT_2ND70(M,P) M(70,P)
#define BOOST_PP_REPEAT_2ND72(M,P) BOOST_PP_REPEAT_2ND71(M,P) M(71,P)
#define BOOST_PP_REPEAT_2ND73(M,P) BOOST_PP_REPEAT_2ND72(M,P) M(72,P)
#define BOOST_PP_REPEAT_2ND74(M,P) BOOST_PP_REPEAT_2ND73(M,P) M(73,P)
#define BOOST_PP_REPEAT_2ND75(M,P) BOOST_PP_REPEAT_2ND74(M,P) M(74,P)
#define BOOST_PP_REPEAT_2ND76(M,P) BOOST_PP_REPEAT_2ND75(M,P) M(75,P)
#define BOOST_PP_REPEAT_2ND77(M,P) BOOST_PP_REPEAT_2ND76(M,P) M(76,P)
#define BOOST_PP_REPEAT_2ND78(M,P) BOOST_PP_REPEAT_2ND77(M,P) M(77,P)
#define BOOST_PP_REPEAT_2ND79(M,P) BOOST_PP_REPEAT_2ND78(M,P) M(78,P)
#define BOOST_PP_REPEAT_2ND80(M,P) BOOST_PP_REPEAT_2ND79(M,P) M(79,P)
#define BOOST_PP_REPEAT_2ND81(M,P) BOOST_PP_REPEAT_2ND80(M,P) M(80,P)
#define BOOST_PP_REPEAT_2ND82(M,P) BOOST_PP_REPEAT_2ND81(M,P) M(81,P)
#define BOOST_PP_REPEAT_2ND83(M,P) BOOST_PP_REPEAT_2ND82(M,P) M(82,P)
#define BOOST_PP_REPEAT_2ND84(M,P) BOOST_PP_REPEAT_2ND83(M,P) M(83,P)
#define BOOST_PP_REPEAT_2ND85(M,P) BOOST_PP_REPEAT_2ND84(M,P) M(84,P)
#define BOOST_PP_REPEAT_2ND86(M,P) BOOST_PP_REPEAT_2ND85(M,P) M(85,P)
#define BOOST_PP_REPEAT_2ND87(M,P) BOOST_PP_REPEAT_2ND86(M,P) M(86,P)
#define BOOST_PP_REPEAT_2ND88(M,P) BOOST_PP_REPEAT_2ND87(M,P) M(87,P)
#define BOOST_PP_REPEAT_2ND89(M,P) BOOST_PP_REPEAT_2ND88(M,P) M(88,P)
#define BOOST_PP_REPEAT_2ND90(M,P) BOOST_PP_REPEAT_2ND89(M,P) M(89,P)
#define BOOST_PP_REPEAT_2ND91(M,P) BOOST_PP_REPEAT_2ND90(M,P) M(90,P)
#define BOOST_PP_REPEAT_2ND92(M,P) BOOST_PP_REPEAT_2ND91(M,P) M(91,P)
#define BOOST_PP_REPEAT_2ND93(M,P) BOOST_PP_REPEAT_2ND92(M,P) M(92,P)
#define BOOST_PP_REPEAT_2ND94(M,P) BOOST_PP_REPEAT_2ND93(M,P) M(93,P)
#define BOOST_PP_REPEAT_2ND95(M,P) BOOST_PP_REPEAT_2ND94(M,P) M(94,P)
#define BOOST_PP_REPEAT_2ND96(M,P) BOOST_PP_REPEAT_2ND95(M,P) M(95,P)
#define BOOST_PP_REPEAT_2ND97(M,P) BOOST_PP_REPEAT_2ND96(M,P) M(96,P)
#define BOOST_PP_REPEAT_2ND98(M,P) BOOST_PP_REPEAT_2ND97(M,P) M(97,P)
#define BOOST_PP_REPEAT_2ND99(M,P) BOOST_PP_REPEAT_2ND98(M,P) M(98,P)
#define BOOST_PP_REPEAT_2ND100(M,P) BOOST_PP_REPEAT_2ND99(M,P) M(99,P)
#define BOOST_PP_REPEAT_2ND101(M,P) BOOST_PP_REPEAT_2ND100(M,P) M(100,P)
#define BOOST_PP_REPEAT_2ND102(M,P) BOOST_PP_REPEAT_2ND101(M,P) M(101,P)
#define BOOST_PP_REPEAT_2ND103(M,P) BOOST_PP_REPEAT_2ND102(M,P) M(102,P)
#define BOOST_PP_REPEAT_2ND104(M,P) BOOST_PP_REPEAT_2ND103(M,P) M(103,P)
#define BOOST_PP_REPEAT_2ND105(M,P) BOOST_PP_REPEAT_2ND104(M,P) M(104,P)
#define BOOST_PP_REPEAT_2ND106(M,P) BOOST_PP_REPEAT_2ND105(M,P) M(105,P)
#define BOOST_PP_REPEAT_2ND107(M,P) BOOST_PP_REPEAT_2ND106(M,P) M(106,P)
#define BOOST_PP_REPEAT_2ND108(M,P) BOOST_PP_REPEAT_2ND107(M,P) M(107,P)
#define BOOST_PP_REPEAT_2ND109(M,P) BOOST_PP_REPEAT_2ND108(M,P) M(108,P)
#define BOOST_PP_REPEAT_2ND110(M,P) BOOST_PP_REPEAT_2ND109(M,P) M(109,P)
#define BOOST_PP_REPEAT_2ND111(M,P) BOOST_PP_REPEAT_2ND110(M,P) M(110,P)
#define BOOST_PP_REPEAT_2ND112(M,P) BOOST_PP_REPEAT_2ND111(M,P) M(111,P)
#define BOOST_PP_REPEAT_2ND113(M,P) BOOST_PP_REPEAT_2ND112(M,P) M(112,P)
#define BOOST_PP_REPEAT_2ND114(M,P) BOOST_PP_REPEAT_2ND113(M,P) M(113,P)
#define BOOST_PP_REPEAT_2ND115(M,P) BOOST_PP_REPEAT_2ND114(M,P) M(114,P)
#define BOOST_PP_REPEAT_2ND116(M,P) BOOST_PP_REPEAT_2ND115(M,P) M(115,P)
#define BOOST_PP_REPEAT_2ND117(M,P) BOOST_PP_REPEAT_2ND116(M,P) M(116,P)
#define BOOST_PP_REPEAT_2ND118(M,P) BOOST_PP_REPEAT_2ND117(M,P) M(117,P)
#define BOOST_PP_REPEAT_2ND119(M,P) BOOST_PP_REPEAT_2ND118(M,P) M(118,P)
#define BOOST_PP_REPEAT_2ND120(M,P) BOOST_PP_REPEAT_2ND119(M,P) M(119,P)
#define BOOST_PP_REPEAT_2ND121(M,P) BOOST_PP_REPEAT_2ND120(M,P) M(120,P)
#define BOOST_PP_REPEAT_2ND122(M,P) BOOST_PP_REPEAT_2ND121(M,P) M(121,P)
#define BOOST_PP_REPEAT_2ND123(M,P) BOOST_PP_REPEAT_2ND122(M,P) M(122,P)
#define BOOST_PP_REPEAT_2ND124(M,P) BOOST_PP_REPEAT_2ND123(M,P) M(123,P)
#define BOOST_PP_REPEAT_2ND125(M,P) BOOST_PP_REPEAT_2ND124(M,P) M(124,P)
#define BOOST_PP_REPEAT_2ND126(M,P) BOOST_PP_REPEAT_2ND125(M,P) M(125,P)
#define BOOST_PP_REPEAT_2ND127(M,P) BOOST_PP_REPEAT_2ND126(M,P) M(126,P)
#define BOOST_PP_REPEAT_2ND128(M,P) BOOST_PP_REPEAT_2ND127(M,P) M(127,P)
#endif

/** <p>Obsolete. Use BOOST_PP_REPEAT_2ND().</p> */
#define BOOST_PREPROCESSOR_REPEAT_2ND(N,M,P) BOOST_PP_REPEAT_2ND(N,M,P)
#endif
