///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/sasfit_ff/sasfit_ff_DoubleShell_withSD.c
*
* Copyright (c) 2008-2009, Paul Scherrer Institute (PSI)
*
* This file is part of SASfit.
*
* SASfit is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* SASfit is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with SASfit.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*   Ingo Bressler (ingo@cs.tu-berlin.de)
*/
/*
double DoubleShell_withSD(Tcl_Interp *interp,
double q,
double R,
double s,
double c1,
double c2,
double c3,
double cm,
double d1,
double d2,
bool  *error)
*/
double Iq( double q,
	double R,
	double s,
	double c1,
	double c2,
	double c3,
	double cm,
	double d1,
	double d2)
{
double t2;
double t3;
double t4;
double t5;
double t6;
double t8;
double t10;
double t11;
double t12;
double t14;
double t15;
double t16;
double t17;
double t18;
double t19;
double t20;
double t21;
double t22;
double t23;
double t24;
double t25;
double t28;
double t29;
double t30;
double t31;
double t32;
double t35;
double t36;
double t40;
double t41;
double t42;
double t43;
double t44;
double t45;
double t46;
double t47;
double t48;
double t49;
double t50;
double t51;
double t53;
double t54;
double t55;
double t56;
double t57;
double t60;
double t61;
double t62;
double t67;
double t68;
double t69;
double t70;
double t72;
double t73;
double t74;
double t75;
double t76;
double t77;
double t82;
double t83;
double t84;
double t85;
double t86;
double t87;
double t88;
double t89;
double t90;
double t93;
double t94;
double t95;
double t100;
double t101;
double t102;
double t103;
double t104;
double t107;
double t108;
double t109;
double t112;
double t113;
double t116;
double t119;
double t121;
double t123;
double t124;
double t126;
double t127;
double t128;
double t132;
double t134;
double t141;
double t142;
double t143;
double t144;
double t145;
double t146;
double t147;
double t150;
double t151;
double t153;
double t155;
double t156;
double t157;
double t159;
double t161;
double t163;
double t164;
double t165;
double t166;
double t167;
double t170;
double t172;
double t173;
double t177;
double t178;
double t180;
double t183;
double t184;
double t185;
double t186;
double t187;
double t189;
double t192;
double t193;
double t194;
double t195;
double t197;
double t198;
double t201;
double t202;
double t203;
double t204;
double t205;
double t206;
double t209;
double t210;
double t211;
double t212;
double t213;
double t214;
double t215;
double t218;
double t219;
double t221;
double t222;
double t223;
double t226;
double t227;
double t228;
double t229;
double t230;
double t233;
double t234;
double t235;
double t238;
double t239;
double t240;
double t243;
double t244;
double t249;
double t250;
double t252;
double t255;
double t256;
double t258;
double t261;
double t262;
double t263;
double t264;
double t267;
double t268;
double t272;
double t273;
double t275;
double t276;
double t277;
double t279;
double t282;
double t283;
double t284;
double t287;
double t288;
double t293;
double t294;
double t295;
double t301;
double t302;
double t303;
double t304;
double t305;
double t308;
double t311;
double t312;
double t313;
double t314;
double t317;
double t318;
double t320;
double t321;
double t322;
double t323;
double t327;
double t328;
double t330;
double t331;
double t336;
double t339;
double t341;
double t342;
double t343;
double t344;
double t350;
double t351;
double t352;
double t355;
double t357;
double t358;
double t361;
double t362;
double t366;
double t367;
double t373;
double t374;
double t376;
double t377;
double t380;
double t381;
double t384;
double t385;
double t386;
double t389;
double t394;
double t397;
double t398;
double t399;
double t400;
double t407;
double t412;
double t413;
double t414;
double t419;
double t422;
double t424;
double t427;
double t430;
double t431;
double t432;
double t433;
double t437;
double t442;
double t445;
double t446;
double t447;
double t448;
double t451;
double t452;
double t453;
double t456;
double t457;
double t458;
double t461;
double t462;
double t463;
double t466;
double t471;
double t472;
double t475;
double t480;
double t483;
double t485;
double t486;
double t487;
double t490;
double t493;
double t503;
double t506;
double t511;
double t515;
double t516;
double t519;
double t521;
double t522;
double t523;
double t525;
double t528;
double t529;
double t530;
double t533;
double t534;
double t535;
double t538;
double t540;
double t543;
double t544;
double t545;
double t546;
double t547;
double t550;
double t551;
double t552;
double t555;
double t556;
double t559;
double t560;
double t561;
double t564;
double t565;
double t566;
double t573;
double t576;
double t577;
double t582;
double t584;
double t587;
double t588;
double t591;
double t594;
double t597;
double t598;
double t601;
double t603;
double t605;
double t610;
double t611;
double t612;
double t615;
double t616;
double t620;
double t621;
double t623;
double t626;
double t627;
double t628;
double t631;
double t639;
double t643;
double t647;
double t650;
double t651;
double t654;
double t655;
double t659;
double t660;
double t663;
double t665;
double t668;
double t673;
double t678;
double t681;
double t682;
double t683;
double t684;
double t687;
double t689;
double t695;
double t700;
double t705;
double t708;
double t709;
double t710;
double t713;
double t714;
double t715;
double t720;
double t722;
double t728;
double t730;
double t735;
double t737;
double t740;
double t744;
double t745;
double t746;
double t749;
double t751;
double t752;
double t753;
double t756;
double t759;
double t764;
double t767;
double t769;
double t774;
double t780;
double t786;
double t788;
double t791;
double t792;
double t795;
double t796;
double t800;
double t803;
double t806;
double t807;
double t810;
double t812;
double t815;
double t818;
double t819;
double t825;
double t826;
double t827;
double t830;
double t836;
double t837;
double t842;
double t847;
double t848;
double t851;
double t859;
double t865;
double t866;
double t867;
double t870;
double t871;
double t874;
double t877;
double t880;
double t884;
double t887;
double t888;
double t894;
double t900;
double t902;
double t908;
double t909;
double t910;
double t914;
double t917;
double t919;
double t923;
double t927;
double t928;
double t929;
double t930;
double t933;
double t935;
double t938;
double t941;
double t942;
double t947;
double t952;
double t953;
double t962;
double t967;
double t970;
double t974;
double t978;
double t988;
double t989;
double t994;
double t996;
double t1000;
double t1003;
double t1006;
double t1007;
double t1014;
double t1015;
double t1016;
double t1019;
double t1020;
double t1023;
double t1028;
double t1029;
double t1031;
double t1043;
double t1049;
double t1054;
double t1057;
double t1058;
double t1061;
double t1064;
double t1072;
double t1083;
double t1084;
double t1087;
double t1090;
double t1091;
double t1092;
double t1099;
double t1102;
double t1106;
double t1110;
double t1113;
double t1114;
double t1117;
double t1118;
double t1123;
double t1126;
double t1129;
double t1131;
double t1139;
double t1142;
double t1148;
double t1149;
double t1158;
double t1159;
double t1160;
double t1163;
double t1165;
double t1168;
double t1169;
double t1174;
double t1178;
double t1186;
double t1201;
double t1212;
double t1214;
double t1227;
double t1230;
double t1235;
double t1238;
double t1240;
double t1241;
double t1244;
double t1249;
double t1251;
double t1255;
double t1258;
double t1274;
double t1277;
double t1282;
double t1289;
double t1292;
double t1293;
double t1297;
double t1302;
double t1303;
double t1304;
double t1311;
double t1312;
double t1315;
double t1316;
double t1321;
double t1326;
double t1331;
double t1333;
double t1338;
double t1343;
double t1345;
double t1346;
double t1347;
double t1348;
double t1357;
double t1364;
double t1371;
double t1374;
double t1375;
double t1377;
double t1380;
double t1386;
double t1389;
double t1394;
double t1396;
double t1401;
double t1404;
double t1405;
double t1410;
double t1415;
double t1416;
double t1419;
double t1422;
double t1427;
double t1428;
double t1429;
double t1432;
double t1433;
double t1436;
double t1447;
double t1450;
double t1457;
double t1465;
double t1472;
double t1477;
double t1480;
double t1481;
double t1484;
double t1487;
double t1490;
double t1495;
double t1500;
double t1501;
double t1506;
double t1513;
double t1520;
double t1527;
double t1528;
double t1538;
double t1544;
double t1545;
double t1550;
double t1554;
double t1561;
double t1567;
double t1575;
double t1581;
double t1585;
double t1586;
double t1587;
double t1590;
double t1593;
double t1602;
double t1614;
double t1615;
double t1620;
double t1630;
double t1633;
double t1636;
double t1637;
double t1642;
double t1643;
double t1648;
double t1657;
double t1660;
double t1679;
double t1685;
double t1688;
double t1690;
double t1694;
double t1701;
double t1702;
double t1716;
double t1722;
double t1733;
double t1734;
double t1737;
double t1738;
double t1755;
double t1762;
double t1763;
double t1766;
double t1769;
double t1774;
double t1784;
double t1789;
double t1798;
double t1799;
double t1808;
double t1823;
double t1826;
double t1831;
double t1844;
double t1853;
double t1856;
double t1857;
double t1858;
double t1867;
double t1871;
double t1882;
double t1890;
double t1899;
double t1908;
double t1914;
double t1921;
double t1929;
double t1932;
double t1934;
double t1937;
double t1954;
double t1959;
double t1970;
double t1974;
double t1979;
double t1980;
double t1986;
double t1989;
double t1999;
double t2003;
double t2005;
double t2024;
double t2029;
double t2043;
double t2046;
double t2051;
double t2052;
double t2057;
double t2071;
double t2080;
double t2122;
double t2123;
double t2128;
double t2133;
double t2139;
double t2142;
double t2151;
double t2160;
double t2161;
double t2162;
double t2173;
double t2179;
double t2197;
double t2204;
double t2215;
double t2218;
double t2221;
double t2222;
double t2225;
double t2243;
double t2251;
double t2268;
double t2294;
double t2298;
double t2312;
double t2328;
double t2332;
double t2339;
double t2342;
double t2354;
double t2357;
double t2361;
double t2364;
double t2368;
double t2371;
double t2389;
double t2407;
double t2424;
double t2431;
double t2434;
double t2451;
double t2475;
double t2478;
double t2489;
double t2494;
double t2510;
double t2539;
double t2553;
double t2569;
double t2587;
double t2592;
double t2593;
double t2602;
double t2614;
double t2625;
double t2637;
double t2640;
double t2642;
double t2670;
double t2682;
double t2717;
double t2724;
double t2743;
double t2755;
double t2758;
double t2768;
double t2808;
double t2811;
double t2838;
double t2841;
double t2844;
double t2850;
double t2854;
double t2857;
double t2858;
double t2859;
double t2903;
double t2918;
double t2941;
double t2946;
double t2987;
double t3007;
double t3026;
double t3030;
double t3035;
double t3075;
double t3116;
double t3160;
double t3204;
double t3205;
double t3215;
double t3249;
double t3292;
double t3333;
double t3374;
double t3415;
double t3455;
double t3495;
double t3535;
double t3575;
double t3592;
t2 =  ( R *  R);
t3 =  q *  q;
t4 =  (s * s);
t5 =  t4 *  t4;
t6 =  (t3 * t5);
t8 = t2 + 4 * t6;
t10 = t8 / t2;
t11 = t2 + t4;
t12 = 1 / t4;
t14 =  (t11 * t12) / 0.2e1;
t15 = pow( t10, -t14);
t16 = cm * cm;
t17 = t15 * t16;
t18 = t3 *  q;
t19 = t17 * t18;
t20 = pow( t10, t14);
t21 = t5 * t20;
t22 = d1 *  q;
t23 = sin(t22);
t24 = d1 * t23;
t25 = t21 * t24;
t28 = c2 * c2;
t29 = t15 * t28;
t30 = t2 * t2;
t31 =  t30 * t20;
t32 = t31 * t3;
t35 = sqrt( t10);
t36 = q * t4;
t40 = atan( (2 * t36 / R));
t41 =  t2 * t40;
t42 = t41 *  t12;
t43 = sin(t42);
t44 = t35 * t43;
t45 = t17 * t44;
t46 = d1 * d1;
t47 =  t2 * t46;
t48 = 0.2e1 * t22;
t49 = sin(t48);
t50 = t3 * t49;
t51 = t47 * t50;
t53 = t15 * cm;
t54 = c3 * t35;
t55 = t53 * t54;
t56 = cos(t42);
t57 = t56 *  t2;
t60 = (0.2e1 * d1 + d2) *  q;
t61 = cos(t60);
t62 = t61 * t46;
t67 = t15 * c2;
t68 = cm * t18;
t69 = t67 * t68;
t70 = t5 *  R;
t72 =  t11 * t40 *  t12;
t73 = cos(t72);
t74 = t22 / 0.2e1;
t75 = sin(t74);
t76 = t75 * t75;
t77 = t73 * t76;
t82 = c2 * cm;
t83 = t2 * t12;
t84 =  t83 / 0.2e1;
t85 = pow( t10, -t84);
t86 = t85 * t43;
t87 = t82 * t86;
t88 =  q * t61;
t89 = d1 *  t2;
t90 = t88 * t89;
t93 = t3 * t3;
t94 = cm * t93;
t95 = t67 * t94;
t100 = c3 * t93;
t101 = t53 * t100;
t102 =  t36 * d1;
t103 =  t36 * d2;
t104 = t40 *  t4;
t107 = cos((t102 + t103 + t41 + t104) *  t12);
t108 = t107 * d1;
t109 = t70 * t108;
t112 =  pow( R,  t83);
t113 = t3 *  t112;
t116 = t2 + 2 * t4;
t119 = pow( t8, - (t116 * t12) / 0.2e1);
t121 = d2 *  q;
t123 = sin(t121 / 0.2e1);
t124 = t30 * t2;
t126 = 0.3e1 * t102;
t127 = 0.2e1 * t41;
t128 = 0.4e1 * t104;
t132 = cos((t126 + t103 + t127 + t128) *  t12 / 0.2e1);
t134 = t119 * t75 * t123 *  t124 * t132;
t141 = c2 * c3;
t142 = t18 *  R;
t143 = t141 * t142;
t144 = sin(t72);
t145 = t15 * t144;
t146 = t61 * t5;
t147 = t145 * t146;
t150 = t35 * t56;
t151 = t150 *  t2;
t153 = t93 * t3;
t155 = t153 *  t112 * t119;
t156 = t82 * t155;
t157 = t75 * t123;
t159 = pow( t10, t84);
t161 = (d1 + d2) *  q;
t163 = cos(t161 / 0.2e1);
t164 = t159 * t163;
t165 = t5 * t5;
t166 = t164 * t165;
t167 = t157 *  t2 * t166;
t170 = t15 * c1;
t172 = t170 * c2 * t35;
t173 = t3 *  t2;
t177 = sin((t102 + t127 + t128) *  t12 / 0.2e1);
t178 = t75 * t177;
t180 = t173 * t178 *  t4;
t183 = cm * c3;
t184 = t183 *  q;
t185 = t2 * R;
t186 =  t185 * t15;
t187 = cos(t22);
t189 = t186 * t144 * t187;
t192 = t85 * t159;
t193 = t82 * t192;
t194 = cos(t121);
t195 = t194 * d1;
t197 = t93 * d2 * t5;
t198 = t195 * t197;
t201 = c3 * c3;
t202 = t15 * t201;
t203 =  t2 * t20;
t204 = t202 * t203;
t205 = t3 * d2;
t206 = t195 * t205;
t209 = t93 *  R;
t210 = t183 * t209;
t211 = t15 * t73;
t212 = cos(t161);
t213 = t212 * d2;
t214 = t213 * t5;
t215 = t211 * t214;
t218 = 0.8e1 * t19 * t25 - 0.2e1 * t29 * t32 + t45 * t51 - 0.4e1 * t55
* t57 * t62 * t3 + 0.64e2 * t69 * t70 * t77 * t23 - 0.4e1 * t87 * t90
- 0.32e2 * t95 * t70 * t77 * d1 + 0.8e1 * t101 * t109 - 0.8e1 * t82
* t113 * t134 - 0.4e1 * t55 * t57 * t22 * t49 + 0.16e2 * t143 * t147
+ t29 * t151 + 0.128e3 * t156 * t167 + 0.4e1 * t172 * t180 - 0.4e1
* t184 * t189 + 0.8e1 * t193 * t198 + 0.2e1 * t204 * t206 - 0.8e1 * t210 * t215;
t219 = t35 *  t2;
t221 = (t102 + t41) *  t12;
t222 = cos(t221);
t223 = t219 * t222;
t226 = t17 * t20;
t227 = t18 * t5;
t228 = sin(t161);
t229 = t228 * d1;
t230 = t227 * t229;
t233 = t93 * t5;
t234 = t212 *  t2;
t235 = t233 * t234;
t238 = t212 * d1;
t239 = t238 * t5;
t240 = t211 * t239;
t243 = t16 * t85;
t244 = t243 * t43;
t249 = cm * t35;
t250 = t170 * t249;
t252 = t57 * t22 * t23;
t255 = c3 * t20;
t256 = t170 * t255;
t258 = t233 * t238 *  R;
t261 = sin(t60);
t262 = t261 * d1;
t263 = t262 * d2;
t264 = t173 * t263;
t267 = t76 * t144;
t268 = t70 * t267;
t272 = t67 * t249 * t3;
t273 =  t2 * t187;
t275 =  t116 * t40 *  t12;
t276 = cos(t275);
t277 = t276 * t76;
t279 = t273 * t277 *  t4;
t282 = t183 * t85;
t283 = t56 * t212;
t284 = t283 *  t6;
t287 = t43 *  t2;
t288 = t46 * t3;
t293 = 0.2e1 * t161;
t294 = cos(t293);
t295 =  q * t294;
t301 = t53 * t54 * t56;
t302 =  t2 * t61;
t303 = d1 * t3;
t304 = t303 * d2;
t305 = t302 * t304;
t308 = t233 * t263;
t311 = t2 * q;
t312 = cos(t48);
t313 = d1 * t312;
t314 =  t311 * t313;
t317 = t202 * t93;
t318 = 0.2e1 * t102;
t320 = (t318 + t103 + t41 + t104) *  t12;
t321 = cos(t320);
t322 = t321 * d2;
t323 = t70 * t322;
t327 = t93 *  t112 * t119;
t328 = t82 * t327;
t330 = t164 * t5;
t331 = t157 *  t30 * t330;
t336 = t233 * t212 *  R * d2;
t339 = -0.4e1 * t17 * t223 - 0.8e1 * t226 * t230 - 0.8e1 * t226 * t235
- 0.8e1 * t210 * t240 - 0.8e1 * t244 * t23 * t3 * t5 - 0.2e1 * t250
* t252 - 0.8e1 * t256 * t258 - 0.2e1 * t45 * t264 + 0.16e2 * t19 * t268
- 0.8e1 * t272 * t279 + 0.8e1 * t282 * t284 - 0.2e1 * t55 * t287
* t288 * t49 - 0.4e1 * t55 * t287 * t295 * d2 - 0.4e1 * t301 * t305 -
0.8e1 * t45 * t308 + 0.2e1 * t45 * t314 + 0.8e1 * t317 * t323 + 0.64e2
* t328 * t331 - 0.8e1 * t256 * t336;
t341 = t85 * t56;
t342 = t183 * t341;
t343 = t61 * d1;
t344 = t343 * t197;
t350 = t170 * cm * t20;
t351 =  t185 * t212;
t352 = t351 * t303;
t355 = t5 *  t4;
t357 = t164 *  t2;
t358 = t157 * t355 * t357;
t361 = t202 * t20;
t362 =  t185 * t194;
t366 = t67 * t249;
t367 = t3 *  t30;
t373 = t113 * t119;
t374 = t82 * t373;
t376 = t164 *  t30;
t377 = t157 *  t4 * t376;
t380 = d2 * t228;
t381 =  t311 * t380;
t384 = t82 * t341;
t385 = t312 * t46;
t386 = t385 * t173;
t389 = t141 * t341;
t394 = t183 * t373;
t397 = t141 * t209;
t398 = d1 * t49;
t399 = t398 * t5;
t400 = t145 * t399;
t407 = t227 * t380;
t412 = sin(t293);
t413 = t3 * t412;
t414 = d2 * d2;
t419 = t183 * t327;
t422 = 0.8e1 * t342 * t344 + 0.2e1 * t342 * t305 + 0.2e1 * t350 * t352
+ 0.64e2 * t328 * t358 + 0.2e1 * t361 * t362 * t205 - 0.8e1 * t366
* t367 * t187 * t276 * t76 + 0.8e1 * t374 * t377 - 0.2e1 * t226 * t381
- 0.2e1 * t384 * t386 - 0.8e1 * t389 * t344 - 0.2e1 * t389 * t305
+ 0.8e1 * t394 * t377 - 0.16e2 * t397 * t400 - 0.4e1 * t55 * t287 * t22
* t312 - 0.8e1 * t256 * t407 - 0.8e1 * t256 * t230 - 0.2e1 * t55
* t287 * t413 * t414 + 0.64e2 * t419 * t331;
t424 = t195 * t205 *  t2;
t427 = t351 * t205;
t430 = t16 * t3;
t431 = t430 *  t185;
t432 = t261 * d2;
t433 = t145 * t432;
t437 = t43 * t261 *  t6;
t442 =  t311 * t229;
t445 = t3 *  t185;
t446 = t141 * t445;
t447 = t61 * d2;
t448 = t211 * t447;
t451 = t202 * t44;
t452 = t412 * t414;
t453 = t233 * t452;
t456 = t170 * cm;
t457 = t107 * d2;
t458 = t445 * t457;
t461 = t53 * c3;
t462 = t187 * t3;
t463 = t31 * t462;
t466 = t385 * t233;
t471 = t261 * t5;
t472 = t211 * t471;
t475 =  q * t412;
t480 = t89 * t205;
t483 = t16 * t93;
t485 = t15 * t20;
t486 = d1 * t5;
t487 = t485 * t486;
t490 = t202 * t35;
t493 =  q * t261;
t503 = 0.2e1 * t193 * t424 - 0.2e1 * t256 * t427 + 0.2e1 * t431 * t433
+ 0.8e1 * t282 * t437 + 0.2e1 * t350 * t427 - 0.2e1 * t226 * t442
- 0.2e1 * t446 * t448 + 0.4e1 * t451 * t453 + 0.2e1 * t456 * t458
- 0.2e1 * t461 * t463 - 0.8e1 * t384 * t466 + 0.64e2 * t419 * t358
+ 0.16e2 * t143 * t472 - 0.4e1 * t55 * t57 * t475 * d1 - 0.2e1 * t361
* t480 - 0.8e1 * t483 *  R * t487 + 0.8e1 * t490 * t437 + 0.4e1
* t55 * t57 * t493 * d2 + 0.2e1 * t55 * t57 * t294 * t3 * t414;
t506 = t294 * t46;
t511 = c3 *  t2;
t515 = t17 * t35;
t516 = t367 * t178;
t519 = cos(t74);
t521 = t76 * t75;
t522 = sin(t275);
t523 = t521 * t522;
t525 =  t2 * t519 * t523 *  t4;
t528 = t67 * cm;
t529 = t20 * t46;
t530 = t233 * t529;
t533 = t170 * c3;
t534 = t35 * t3;
t535 = 0.2e1 * t104;
t538 = cos((t102 + t103 + t41 + t535) *  t12);
t540 = t534 *  t30 * t538;
t543 = cm *  t2;
t544 = t67 * t543;
t545 = t20 * d1;
t546 =  q * t23;
t547 = t545 * t546;
t550 = t20 * t187;
t551 = t3 *  t4;
t552 = t550 * t551;
t555 = t43 * t228;
t556 = t555 *  t2;
t559 = t56 * t3;
t560 = t5 * t312;
t561 = t559 * t560;
t564 = t412 * d2;
t565 = t564 * d1;
t566 = t233 * t565;
t573 = t183 * t155;
t576 = t183 * t445;
t577 = t211 * t343;
t582 = cos((t318 + t103 + t41 + t535) *  t12);
t584 = t173 * t582 *  t4;
t587 = t202 * t150;
t588 = t227 * t432;
t591 = t141 *  q;
t594 = t211 * t213;
t597 = 0.2e1 * t55 * t57 * t506 * t3 + 0.4e1 * t53 * t511 * t20 +
+ 0.4e1 * t515 * t516 + 0.16e2 * t272 * t525 + 0.8e1 * t528 * t530
- 0.2e1 * t533 * t540 - 0.2e1 * t544 * t547 - 0.2e1 * t544 * t552
- 0.2e1 * t282 * t556 + 0.4e1 * t490 * t561 + 0.8e1 * t451 * t566
- 0.4e1 * t55 * t287 * t295 * d1 + 0.128e3 * t573 * t167 + 0.4e1 * t576
* t577 + 0.2e1 * t515 * t584 - 0.8e1 * t587 * t588 + 0.4e1 * t591
* t189 - 0.2e1 * t576 * t594;
t598 = 0.2e1 * t103;
t601 = cos((t318 + t598 + t41 + t535) *  t12);
t603 = t173 * t601 *  t4;
t605 = t555 *  t6;
t610 = cos((t102 + t41 + t104) *  t12);
t611 = d1 * t610;
t612 = t445 * t611;
t615 =  t2 * t294;
t616 = t615 * t304;
t620 = (t102 + t103 + t41) *  t12;
t621 = cos(t620);
t623 = t534 * t5 * t621;
t626 = t82 * t85;
t627 = t159 * t46;
t628 = t627 * t233;
t631 = t145 * t229;
t639 = t627 * t173;
t643 = t485 * t195 * t5;
t647 = t550 * t3;
t650 =  t2 * t194;
t651 = t650 * t288;
t654 = d1 * t187;
t655 = t654 * t5;
t659 = t343 * t5;
t660 = t211 * t659;
t663 = sin(t221);
t665 = t227 * d1 * t663;
t668 = t243 * t56;
t673 = t56 * t93;
t678 =  t6 * t20;
t681 = t29 *  t185;
t682 = t3 * t73;
t683 = t76 * d1;
t684 = t682 * t683;
t687 = -t515 * t603 - 0.8e1 * t282 * t605 + 0.2e1 * t528 * t612
+ 0.4e1 * t301 * t616 + 0.8e1 * t533 * t623 - 0.8e1 * t626 * t628
- 0.2e1 * t446 * t631 + 0.16e2 * t366 * t367 * t519 * t521 * t522
- 0.2e1 * t626 * t639 - 0.16e2 * t397 * t643 + 0.2e1 * t17
* t30 * t647 + 0.2e1 * t361 * t651 - 0.8e1 * t397 * t485 * t655 - 0.16e2
* t397 * t660 + 0.8e1 * t250 * t665 - 0.8e1 * t668 * t312 * t3 * t5
+ 0.8e1 * t55 * t673 * t560 * t46 - 0.8e1 * t202 * t678 + 0.4e1 * t681 * t684;
t689 = t53 * t511;
t695 = t233 * t261 * t46;
t700 = t157 * t355 *  t2 * t132;
t705 = t157 *  t4 *  t30 * t132;
t708 = t170 * c2;
t709 = t93 * t355;
t710 = t709 * t550;
t713 = sin(t620);
t714 = t713 * d1;
t715 = t227 * t714;
t720 = cos((t102 + t41 + t535) *  t12);
t722 = t534 *  t30 * t720;
t728 = cos((t126 + t127) *  t12 / 0.2e1);
t730 = t75 * d1;
t735 = t20 * t93;
t737 = t735 * t355 * t212;
t740 = q * t185;
t744 = cos((t102 + t127 + t535) *  t12 / 0.2e1);
t745 = t744 * t75;
t746 =  t740 * t745;
t749 = t202 * t18;
t751 = (t318 + t598 + t41 + t104) *  t12;
t752 = sin(t751);
t753 = t70 * t752;
t756 =  t740 * t752;
t759 = t287 * t49;
t764 = t186 * t73 * t23;
t767 = t53 * t255;
t769 = t233 * t194 * t46;
t774 = t157 *  t30 * t132 * t5;
t780 = -0.2e1 * t689 * t547 - 0.2e1 * t689 * t552 - 0.8e1 * t451
* t695 - 0.32e2 * t419 * t700 - 0.8e1 * t394 * t705 - 0.8e1 * t708
* t710 - 0.8e1 * t250 * t715 - 0.2e1 * t456 * t722 - 0.8e1 * t366
* t2 * t728 * t730 *  q + 0.8e1 * t461 * t737 - 0.8e1
* t528 * t746 + 0.8e1 * t749 * t753 + 0.2e1 * t17 * t756 - t490 * t759
- 0.8e1 * t87 * t695 - 0.4e1 * t184 * t764 - 0.16e2 * t767 * t769
- 0.32e2 * t419 * t774 + 0.4e1 * t361 * t362 * t303;
t786 = t17 *  t185;
t788 =  q * t76 * t144;
t791 = t713 * d2;
t792 = t227 * t791;
t795 = t159 * t187;
t796 = t795 *  t6;
t800 = t145 * t229 * t5;
t803 = t62 * t173;
t806 = t49 * t5;
t807 = t211 * t806;
t810 = sin(t121);
t812 = t227 * d2 * t810;
t815 = t145 * t380;
t818 = t5 * t294;
t819 = t559 * t818;
t825 = cos((t318 + t103 + t127 + t535) *  t12 / 0.2e1);
t826 = t825 * t123;
t827 =  t740 * t826;
t830 = t227 * t447;
t836 = t76 * t23;
t837 =  q * t73 * t836;
t842 =  t6 * t550;
t847 = t412 * d1;
t848 = t227 * t847;
t851 = -0.8e1 * t183 * t113 * t134 + 0.16e2 * t461 * t530 + 0.4e1
* t786 * t788 - 0.8e1 * t250 * t792 + 0.8e1 * t282 * t796 - 0.8e1 * t397
* t800 + 0.2e1 * t384 * t803 - 0.16e2 * t143 * t807 + 0.8e1 * t226
* t812 - 0.2e1 * t446 * t815 + 0.4e1 * t490 * t819 - 0.8e1 * t456 * t827
- 0.8e1 * t45 * t830 - 0.4e1 * t451 * t90 - 0.8e1 * t681 * t837
- 0.8e1 * t528 * t710 - 0.8e1 * t528 * t842 - 0.2e1 * t461 * t722
+ 0.8e1 * t587 * t848;
t859 = cos((t318 + t41) *  t12);
t865 = t5 * t194;
t866 = d1 * d2;
t867 = t865 * t866;
t870 = t29 * t93;
t871 = t21 * t46;
t874 = t29 *  t2;
t877 = t203 * t212;
t880 = t62 * t233;
t884 =  t30 * t194 * t3;
t887 = t35 * t18;
t888 = t17 * t887;
t894 = t534 * t5 * t222;
t900 = t82 *  q;
t902 = t186 * t73 * t49;
t908 = t183 * t86;
t909 = t46 * t93;
t910 = t909 * t806;
t914 = t89 *  q * t49;
t917 = t43 * t3;
t919 = d2 *  t2;
t923 = t243 * t159;
t927 = t17 * t3;
t928 = cos(t751);
t929 =  t185 * t928;
t930 = t929 * d1;
t933 = -0.8e1 * t451 * t830 - 0.8e1 * t528 * t534 * t5 * t859 + 0.8e1
* t17 * t735 * t867 - 0.4e1 * t870 * t871 + 0.2e1 * t874 * t552
+ 0.2e1 * t461 * t877 + 0.8e1 * t384 * t880 + 0.2e1 * t361 * t884
+ 0.8e1 * t888 * t5 * t43 * t654 + 0.16e2 * t528 * t894 - 0.2e1 * t431
* t485 * d1 + 0.4e1 * t900 * t902 + 0.8e1 * t244 * t50 * t5 + 0.8e1
* t908 * t910 + 0.2e1 * t587 * t914 + 0.2e1 * t243 * t917 * t262 * t919
+ 0.2e1 * t923 * t288 *  t2 - 0.2e1 * t927 * t930;
t935 = t919 *  q * t810;
t938 = t650 * t551;
t941 = t412 * t46;
t942 = t233 * t941;
t947 = t928 * d1;
t952 = (t318 + t41 + t104) *  t12;
t953 = sin(t952);
t962 = t485 * t213;
t967 =  t311 * t791;
t970 =  t311 * t714;
t974 = t89 *  q * t663;
t978 = t16 *  q *  t185;
t988 = t56 * t61;
t989 = t988 *  t6;
t994 = 0.2e1 * t361 * t935 + 0.2e1 * t361 * t938 + 0.4e1 * t451 * t942
- 0.2e1 * t193 * t381 + 0.4e1 * t461 * t445 * t947 - 0.16e2 * t461
* t142 * t5 * t953 - 0.8e1 * t226 * t407 - 0.8e1 * t515 * t665 + 0.2e1
* t446 * t962 + 0.4e1 * t451 * t910 + 0.2e1 * t515 * t967 + 0.2e1 * t515
* t970 - 0.2e1 * t515 * t974 - 0.4e1 * t978 * t211 * t228 - 0.2e1
* t923 * t651 + 0.8e1 * t342 * t230 + 0.4e1 * t786 * t684 - 0.8e1 * t282
* t989 + 0.2e1 * t342 * t442;
t996 = t170 * t94;
t1000 = t186 * t545;
t1003 = t17 * t150;
t1006 = cos(t952);
t1007 = d1 * t1006;
t1014 = t82 * t209;
t1015 = t447 * t5;
t1016 = t211 * t1015;
t1019 = t18 * d1;
t1020 = t1019 * t560;
t1023 =  t311 * t847;
t1028 = c1 * c1;
t1029 = t15 * t1028;
t1031 = t17 * t534;
t1043 = t173 * t565;
t1049 = t22 * t23 *  t2;
t1054 = t22 * t273;
t1057 = 0.8e1 * t996 * t109 + 0.4e1 * t141 * t3 * t1000 + 0.8e1
* t1003 * t344 + 0.4e1 * t461 * t445 * t1007 + 0.8e1 * t923 * t909 * t5
+ 0.8e1 * t1014 * t1016 + 0.16e2 * t87 * t1020 + 0.2e1 * t587 * t1023
+ 0.8e1 * t515 * t715 - t1029 * t32 + 0.4e1 * t1031 *  t2
* t75 * t177 *  t4 - 0.8e1 * t668 * t407 - 0.2e1 * t668 * t381
- 0.4e1 * t250 * t180 + 0.2e1 * t451 * t1043 + 0.8e1 * t767 * t235
- 0.2e1 * t384 * t1049 - 0.12e2 * t17 * t678 - 0.2e1 * t87 * t1054;
t1058 = t70 * t745;
t1061 = t227 * t262;
t1064 = t70 * t611;
t1072 = t43 * t49 *  t6;
t1083 = t43 * t23;
t1084 = t1083 *  t2;
t1087 = t227 * t564;
t1090 = t20 * t3;
t1091 = t5 * t212;
t1092 = t1090 * t1091;
t1099 = t5 * t728 * t730;
t1102 = t203 * t187;
t1106 = t173 * t538 *  t4;
t1110 = t173 * t720 *  t4;
t1113 = t23 * t5;
t1114 = t1019 * t1113;
t1117 = t43 * t93;
t1118 = t5 * t412;
t1123 =  t311 * t564;
t1126 = -0.32e2 * t69 * t1058 - 0.16e2 * t1003 * t1061 + 0.8e1 * t95
* t1064 + 0.8e1 * t668 * t61 * t3 * t5 - 0.8e1 * t282 * t1072 + 0.8e1
* t456 * t737 - 0.8e1 * t256 * t235 - 0.16e2 * t55 * t673 * t146 * t46
+ 0.2e1 * t282 * t1084 + 0.8e1 * t1003 * t1087 + 0.8e1 * t456 * t1092
+ 0.32e2 * t19 * t1058 + 0.16e2 * t29 * t887 * t1099 + 0.2e1 * t17
* t1102 - 0.2e1 * t515 * t1106 + 0.2e1 * t515 * t1110 - 0.8e1 * t384
* t1114 - 0.8e1 * t55 * t1117 * t1118 * t414 + 0.2e1 * t587 * t1123;
t1129 = t294 * d1;
t1131 = t233 * t1129 * d2;
t1139 = t186 * t73 * t228;
t1142 = t56 * t18;
t1148 = t29 * t35;
t1149 =  t6 * t222;
t1158 = t82 * t445;
t1159 = t194 * d2;
t1160 = t485 * t1159;
t1163 = t56 * d1;
t1165 = t227 * t1163 * t23;
t1168 = d1 *  R;
t1169 = t21 * t1168;
t1174 = t917 * t1118;
t1178 = t1090 *  t4;
t1186 = -0.8e1 * t1003 * t1131 + 0.8e1 * t515 * t792 + 0.2e1 * t923
* t381 + 0.4e1 * t184 * t1139 - 0.16e2 * t55 * t1142 * t399 - 0.8e1
* t923 * t769 - 0.8e1 * t1148 * t1149 + 0.8e1 * t533 * t842 - 0.8e1
* t786 * t837 - 0.8e1 * t193 * t230 + 0.2e1 * t1158 * t1160 - 0.8e1
* t250 * t1165 - 0.16e2 * t317 * t1169 + 0.4e1 * t45 * t942 + 0.8e1
* t55 * t1174 - t1029 *  t2 * t1178 + 0.8e1 * t767 * t230 + 0.8e1 * t244 * t228 * t3 * t5;
t1201 = t709 * t194;
t1212 = t82 * t142;
t1214 = t211 * t228 * t5;
t1227 = t211 * t1113;
t1230 = t57 * t187;
t1235 = t141 * t192;
t1238 = 0.2e1 * t1003 * t803 + 0.8e1 * t461 * t735 * t5 * t414 + 0.8e1
* t342 * t407 + 0.2e1 * t342 * t381 - 0.8e1 * t55 * t1117 * t1118
* t46 + 0.8e1 * t226 * t1201 - 0.4e1 * t900 * t764 - 0.8e1 * t193 * t407
- 0.2e1 * t461 * t150 *  t2 * t312 + 0.16e2 * t1212 * t1214
- 0.4e1 * t591 * t1139 + 0.4e1 * t184 * t902 - 0.4e1 * t366 * t180
- 0.2e1 * t342 * t386 + 0.8e1 * t361 * t769 + 0.16e2 * t143 * t1227
+ 0.2e1 * t515 * t1230 - 0.2e1 * t202 * t32 - 0.8e1 * t1235 * t198;
t1240 = t56 * t187;
t1241 = t1240 *  t6;
t1244 = sin(t320);
t1249 = t1029 * t3;
t1251 =  t30 * t35 * t276;
t1255 = t211 * t655;
t1258 = t211 * t654;
t1274 = t550 * t303;
t1277 = t145 * t24;
t1282 = t493 * t89;
t1289 = t233 * t650;
t1292 = t159 * t194;
t1293 = t1292 *  t2;
t1297 = t233 * t294 * t414;
t1302 = -0.8e1 * t626 * t1241 + 0.32e2 * t461 * t142 * t5 * t1244
- t1249 * t1251 - 0.2e1 * t342 * t1049 - 0.8e1 * t397 * t1255 - 0.2e1
* t446 * t1258 - 0.8e1 * t366 * t1165 - 0.16e2 * t461 * t142 * t5 * t752
- 0.16e2 * t342 * t1061 - 0.16e2 * t461 * t1090 * t865 + 0.2e1 * t170
* c3 *  t185 * t1274 - 0.2e1 * t1158 * t1277 - 0.16e2 * t1212
* t472 - 0.4e1 * t342 * t1282 - 0.16e2 * t461 * t735 * t355 * t194
+ 0.8e1 * t226 * t1289 - 0.2e1 * t243 * t1293 - 0.4e1 * t1003 * t1297
+ 0.8e1 * t45 * t566;
t1303 = t187 * t5;
t1304 = t1019 * t1303;
t1311 = t18 * t212;
t1312 = t1311 * t486;
t1315 =  q * t212;
t1316 = t1315 * t89;
t1321 = cos((t318 + t41 + t535) *  t12);
t1326 = t234 * t551;
t1331 = t173 * t452;
t1333 = t1315 * t919;
t1338 = t367 * t1321;
t1343 = t67 * cm *  t185;
t1345 = t144 * d1;
t1346 = 0.3e1 / 0.2e1 * t22;
t1347 = cos(t1346);
t1348 = t1345 * t1347;
t1357 = t186 * t144 * t61;
t1364 = -0.8e1 * t87 * t1304 - 0.16e2 * t143 * t1214 + 0.2e1 * t767
* t442 - 0.8e1 * t244 * t1312 - 0.2e1 * t244 * t1316 + 0.2e1 * t461
* t534 *  t30 * t1321 + 0.2e1 * t767 * t1326 - 0.2e1 * t515
* t1084 + t45 * t1331 - 0.2e1 * t244 * t1333 - 0.8e1 * t533 * t737
- t490 * t1338 + 0.2e1 * t576 * t1258 - 0.8e1 * t1343 * t3 * t75 * t1348
+ 0.2e1 * t533 * t463 - 0.8e1 * t389 * t230 - 0.4e1 * t900 * t1357
+ 0.8e1 * t533 * t710 - 0.8e1 * t923 * t1114;
t1371 = t170 * t511;
t1374 = t29 * t445;
t1375 = t75 * t144;
t1377 = t1375 * d1 * t1347;
t1380 =  t6 * t1083;
t1386 = t287 * t22 * t187;
t1389 = t141 * t86;
t1394 = t43 * d1;
t1396 = t227 * t1394 * t187;
t1401 = t17 * t93;
t1404 = t321 * d1;
t1405 = t70 * t1404;
t1410 = sin(t1346);
t1415 = t928 * d2;
t1416 = t70 * t1415;
t1419 = t70 * t947;
t1422 = t70 * t1007;
t1427 = -0.2e1 * t923 * t1049 + 0.2e1 * t1371 * t552 + 0.4e1 * t1374
* t1377 - 0.8e1 * t172 * t1380 + 0.8e1 * t172 * t1241 - 0.2e1 * t250
* t1386 - 0.2e1 * t1389 * t51 - 0.4e1 * t900 * t189 - 0.8e1 * t250
* t1396 - 0.16e2 * t1389 * t1020 + 0.8e1 * t1401 * t323 + 0.16e2 * t1401
* t1405 - 0.4e1 * t515 * t1072 + 0.32e2 * t69 * t70 * t1375 * t1410
- 0.8e1 * t1401 * t1416 - 0.8e1 * t1401 * t1419 - 0.8e1 * t1401 * t1422
- 0.2e1 * t389 * t381;
t1428 = d2 * t5;
t1429 = t1311 * t1428;
t1432 = t3 * t261;
t1433 = t1432 * t47;
t1436 = t141 * t155;
t1447 = t31 * t212 * t3;
t1450 = t17 *  q;
t1457 = t445 * t108;
t1465 = t186 * t73 * t261;
t1472 = t170 * t100;
t1477 =  t311 * t447;
t1480 = c3 * t18;
t1481 = t170 * t1480;
t1484 = -0.8e1 * t244 * t1429 + 0.2e1 * t1389 * t1433 - 0.128e3
* t1436 * t167 - 0.8e1 * t708 * t150 *  t6 + 0.2e1 * t1158
* t815 - 0.8e1 * t1389 * t910 - 0.2e1 * t533 * t1447 + 0.8e1 * t1450
* t185 * t744 * t75 - 0.8e1 * t101 * t1064 + 0.2e1 * t456
* t1457 + 0.4e1 * t515 * t819 + 0.4e1 * t767 * t480 + 0.4e1 * t591
* t1465 - 0.4e1 * t184 * t1465 + 0.2e1 * t193 * t651 + 0.8e1 * t1472
* t1064 - 0.8e1 * t515 * t989 - 0.2e1 * t451 * t1477 + 0.8e1 * t1481 * t25;
t1487 = t21 * t654 *  R;
t1490 = t70 * t1244;
t1495 = t283 *  t2;
t1500 = t17 * t445;
t1501 = t77 * t654;
t1506 = t728 * t75;
t1513 = t145 * t1303;
t1520 = t57 * t312;
t1527 = t483 *  R * t15;
t1528 = t73 * t61;
t1538 = 0.8e1 * t1472 * t1487 - 0.16e2 * t749 * t1490 + 0.8e1 * t193
* t769 + 0.2e1 * t282 * t1495 + 0.2e1 * t243 * t556 + 0.8e1 * t1500
* t1501 - 0.2e1 * t908 * t1433 - 0.32e2 * t366 * t227 * t1506 * d1
+ 0.4e1 * t515 * t561 - 0.16e2 * t1212 * t1513 - 0.16e2 * t210 * t643
- 0.2e1 * t87 * t1477 + t515 * t1520 + 0.8e1 * t1003 * t880 + 0.4e1
* t591 * t764 - 0.8e1 * t1527 * t1528 * t1428 + 0.2e1 * t431 * t1277
- 0.4e1 * t515 * t1174 + 0.2e1 * t533 * t612;
t1544 = t144 * t1410;
t1545 =  q * t75 * t1544;
t1550 = t144 * t261;
t1554 =  t6 * t194;
t1561 = t227 * t343;
t1567 = t170 * c2 * t93;
t1575 =  t30 * t187 * t277;
t1581 = t173 * t1321 *  t4;
t1585 = t202 * t3;
t1586 =  t185 * t321;
t1587 = t1586 * d2;
t1590 = t183 * t142;
t1593 = 0.8e1 * t282 * t1380 - 0.16e2 * t19 * t1490 - 0.4e1 * t681
* t1545 - 0.2e1 * t461 * t612 + 0.8e1 * t1527 * t1550 * t1428 + 0.8e1
* t361 * t1554 - 0.2e1 * t1235 * t1049 - 0.8e1 * t908 * t695 - 0.16e2
* t45 * t1561 + 0.8e1 * t1343 * t1545 - 0.8e1 * t1567 * t1487 + 0.2e1
* t193 * t1049 - 0.8e1 * t533 * t894 + 0.4e1 * t1031 * t1575 + 0.2e1
* t1003 * t914 - t490 * t1581 + 0.8e1 * t226 * t1554 + 0.2e1 * t1585
* t1587 - 0.16e2 * t1590 * t1513;
t1602 = t21 * t273;
t1614 = t159 * t212;
t1615 = t1614 *  t6;
t1620 = t988 *  t2;
t1630 = t1019 * t806;
t1633 = t740 * t1244;
t1636 = R * d2;
t1637 = t233 * t1636;
t1642 = 0.2e1 * t668 * t386 - 0.32e2 * t69 * t268 - 0.8e1 * t69 * t25
- 0.8e1 * t1567 * t1602 + 0.4e1 * t1031 * t279 - 0.8e1 * t95 * t1602
- 0.2e1 * t431 * t1258 + 0.8e1 * t141 * t113 * t134 - 0.8e1 * t626
* t1615 + 0.4e1 * t384 * t914 - 0.2e1 * t282 * t1620 - 0.2e1 * t446
* t485 * t654 + 0.2e1 * t767 * t381 - 0.2e1 * t366 * t1386 + 0.16e2
* t384 * t1630 + 0.8e1 * t461 * t1633 - 0.8e1 * t226 * t1637 + 0.2e1 * t172 * t252;
t1643 = t145 * t1091;
t1648 = t145 * t560;
t1657 = t740 * t144;
t1660 = t740 * t953;
t1679 = t43 * t18;
t1685 = t559 * t5;
t1688 = t615 * t288;
t1690 = 0.16e2 * t1590 * t1643 + 0.8e1 * t668 * t466 + 0.16e2 * t1590
* t1648 - 0.2e1 * t908 * t264 - 0.8e1 * t397 * t1016 + 0.8e1 * t19
* t753 - 0.4e1 * t456 * t1657 + 0.2e1 * t202 * t1660 + 0.16e2 * t101
* t1422 + 0.16e2 * t101 * t1419 + 0.2e1 * t1003 * t1023 + 0.2e1 * t172
* t1386 + 0.4e1 * t244 * t90 + 0.16e2 * t908 * t1020 - 0.4e1 * t244
* t314 - 0.8e1 * t908 * t308 - 0.16e2 * t55 * t1679 * t818 * d2 + 0.4e1
* t1029 * t35 * t1685 - t1003 * t1688;
t1694 = t493 * t919;
t1701 = t3 * t414;
t1702 = t615 * t1701;
t1716 = t141 * t85;
t1722 = t16 * t18 *  R;
t1733 = t53 * t1480;
t1734 = t70 * t826;
t1737 = 0.2e1 * t668 * t1049 - 0.2e1 * t342 * t1694 + 0.8e1 * t908
* t1312 + 0.4e1 * t1148 * t1685 - t1003 * t1702 + 0.4e1 * t87 * t314
+ 0.16e2 * t767 * t1637 + 0.2e1 * t908 * t1316 - 0.8e1 * t342 * t588
- 0.8e1 * t456 * t623 + 0.16e2 * t210 * t660 + 0.8e1 * t1716 * t1241
- 0.2e1 * t1716 * t1520 + 0.16e2 * t1722 * t472 - 0.16e2 * t87 * t1561
+ 0.2e1 * t1716 * t1230 + 0.4e1 * t389 * t1282 - 0.8e1 * t389 * t407
- 0.32e2 * t1733 * t1734;
t1738 = t70 * t457;
t1755 = t211 * t238;
t1762 = t313 * t5;
t1763 = t211 * t1762;
t1766 = t211 * t313;
t1769 = t203 * t551;
t1774 = c2 *  t2;
t1784 = 0.8e1 * t101 * t1738 - 0.16e2 * t1590 * t472 + 0.16e2 * t1590
* t1214 + 0.16e2 * t1590 * t807 + 0.8e1 * t1716 * t1072 + 0.16e2
* t389 * t1061 + 0.2e1 * t384 * t305 - 0.2e1 * t55 * t967 + 0.2e1 * t446
* t1755 + 0.2e1 * t389 * t1694 + 0.8e1 * t515 * t1241 + 0.16e2 * t397
* t1763 + 0.4e1 * t446 * t1766 + 0.2e1 * t708 * t1769 + 0.8e1 * t384
* t344 + 0.2e1 * t170 * t1774 * t20 + 0.8e1 * t397 * t240 - 0.2e1 * t87
* t264 - 0.8e1 * t1389 * t1312;
t1789 = t145 * t380 * t5;
t1798 = t294 * d2;
t1799 = t227 * t1798;
t1808 = t183 * t192;
t1823 = t227 * t1129;
t1826 = t367 * t601;
t1831 = -0.8e1 * t397 * t1789 - 0.2e1 * t1389 * t1316 + 0.8e1 * t389
* t588 - 0.2e1 * t490 * t1620 + 0.8e1 * t451 * t1799 - 0.4e1 * t184
* t1357 + 0.8e1 * t226 * t769 - 0.4e1 * t490 * t1072 + 0.2e1 * t1808
* t651 - 0.4e1 * t461 * t1660 + 0.4e1 * t908 * t314 - 0.2e1 * t1389
* t1333 - 0.16e2 * t1212 * t147 - 0.8e1 * t317 * t1422 - 0.16e2 * t244
* t1020 + 0.8e1 * t451 * t1823 - t490 * t1826 + 0.4e1 * t978 * t145 * t187;
t1844 = t485 * t1159 * t5;
t1853 = t145 * t262;
t1856 = t29 * t233;
t1857 =  R * t75;
t1858 = t1857 * t1348;
t1867 = t471 * d1;
t1871 = t445 * d2;
t1882 = 0.16e2 * t1722 * t1513 - 0.4e1 * t978 * t145 * t312 - 0.4e1
* t250 * t516 + 0.2e1 * t446 * t1277 + 0.2e1 * t908 * t51 - 0.8e1 * t397
* t1844 - 0.8e1 * t244 * t910 - 0.8e1 * t87 * t308 - 0.16e2 * t1590
* t147 + 0.4e1 * t446 * t1853 + 0.16e2 * t1856 * t1858 + 0.2e1 * t202
* t756 + 0.8e1 * t45 * t1020 - 0.2e1 * t244 * t51 + 0.32e2 * t55 * t1142
* t1867 - 0.2e1 * t361 * t1871 + 0.16e2 * t1014 * t400 + 0.8e1 * t996
* t1738 - 0.2e1 * t226 *  t30 * t212 * t3;
t1890 =  t6 * t212;
t1899 = t287 * t261;
t1908 = t145 * t1867;
t1914 = t219 * t859;
t1921 = t219 * t621;
t1929 = t145 * t24 * t5;
t1932 = -0.8e1 * t1733 * t25 + 0.4e1 * t1500 * t1377 - 0.2e1 * t576
* t1277 - 0.8e1 * t226 * t1890 - 0.4e1 * t461 * t44 *  t2 * t261
+ 0.8e1 * t515 * t437 + 0.2e1 * t515 * t1899 + 0.4e1 * t342 * t914
+ 0.16e2 * t143 * t1513 + 0.2e1 * t1158 * t631 + 0.16e2 * t397 * t1908
+ 0.8e1 * t1527 * t1345 * t1113 + t17 * t1914 - 0.8e1 * t226 * t709
* t212 + 0.2e1 * t384 * t442 - 0.2e1 * t461 * t1921 + 0.8e1 * t55 * t665
+ 0.8e1 * t461 * t894 - 0.8e1 * t210 * t1929;
t1934 = t70 * t144;
t1937 = t170 * t68;
t1954 = t709 * t20;
t1959 = t145 * t398;
t1970 =  t311 * t1129;
t1974 = t186 * t144 * t312;
t1979 = t29 * t227;
t1980 = t1857 * t1544;
t1986 = 0.8e1 * t1029 * t18 * t1934 - 0.32e2 * t1937 * t1734 + 0.8e1
* t384 * t230 + 0.2e1 * t461 * t44 *  t2 * t49 - 0.8e1 * t515
* t1380 + 0.8e1 * t55 * t287 * t88 * d1 - 0.8e1 * t317 * t1419 - 0.8e1
* t29 * t1954 - 0.2e1 * t461 * t1102 + 0.4e1 * t576 * t1959 - 0.2e1
* t45 * t1433 + 0.2e1 * t55 * t57 * t385 * t3 + 0.8e1 * t668 * t1114
+ 0.2e1 * t45 * t1970 - 0.4e1 * t591 * t1974 + 0.16e2 * t342 * t1630
- 0.16e2 * t1979 * t1980 - 0.8e1 * t1003 * t588 + t490 * t1520;
t1989 = t529 * t3;
t1999 = t173 * t941;
t2003 = t17 * t203;
t2005 = t1292 *  t6;
t2024 = t233 * t866;
t2029 = -t874 * t1989 - 0.2e1 * t243 * t1899 + 0.8e1 * t1716 * t989
+ 0.8e1 * t451 * t1020 - 0.2e1 * t451 * t1433 + t45 * t1999 + 0.8e1
* t767 * t407 - 0.3e1 * t2003 + 0.8e1 * t282 * t2005 - 0.8e1 * t1235
* t1114 + 0.16e2 * t210 * t400 + 0.2e1 * t461 * t44 *  t2 * t412
- 0.8e1 * t29 * t678 - 0.8e1 * t1567 * t1064 - 0.2e1 * t55 * t1110
+ 0.4e1 * t900 * t1974 - 0.8e1 * t361 * t2024 - 0.8e1 * t55 * t819;
t2043 = t233 * t203;
t2046 = t17 *  t2;
t2051 = t16 * t153;
t2052 =  t112 * t119;
t2057 = t157 * t165 *  t4 * t159 * t163;
t2071 =  t2 * t859 * t288;
t2080 = -0.16e2 * t55 * t1679 * t1762 - 0.12e2 * t1401 * t871 - 0.2e1
* t528 * t1914 - 0.8e1 * t587 * t1131 + 0.2e1 * t461 * t540 + 0.2e1
* t528 * t1769 + 0.8e1 * t528 * t2043 + 0.2e1 * t2046 * t552 + 0.2e1
* t244 * t1054 - 0.128e3 * t2051 * t2052 * t2057 - 0.16e2 * t143 * t1643
- 0.2e1 * t668 * t803 - 0.16e2 * t515 * t1149 + 0.2e1 * t626 * t1495
+ 0.8e1 * t1014 * t800 - t515 * t2071 + 0.8e1 * t456 * t894 + 0.32e2
* t55 * t1679 * t659 - 0.8e1 * t374 * t705;
t2122 = -0.2e1 * t1235 * t651 + 0.2e1 * t515 * t367 * t720 + 0.16e2
* t1212 * t1648 + 0.16e2 * t55 * t989 + 0.2e1 * t2046 * t547 - 0.4e1
* t431 * t1959 - 0.16e2 * t1527 * t1345 * t806 - 0.8e1 * t55 * t715
- 0.2e1 * t431 * t631 - 0.8e1 * t461 * t623 + 0.2e1 * t576 * t448
+ 0.8e1 * t1235 * t407 - 0.16e2 * t1722 * t1648 + 0.8e1 * t1003 * t848
- 0.4e1 * t202 * t1633 + 0.2e1 * t1808 * t1049 + 0.8e1 * t244 * t1304
+ 0.2e1 * t55 * t1106 - 0.32e2 * t328 * t700;
t2123 = t219 * t1240;
t2128 = t929 * d2;
t2133 = t2052 * t75;
t2139 = t219 * t1083;
t2142 = t485 * t214;
t2151 = t170 * t54;
t2160 =  R * t73;
t2161 = t683 * t187;
t2162 = t2160 * t2161;
t2173 = -0.2e1 * t528 * t2123 + 0.2e1 * t244 * t1433 - 0.2e1 * t927
* t2128 + 0.2e1 * t1716 * t1620 - 0.128e3 * t2051 * t2133 * t123
* t2 * t166 - 0.2e1 * t708 * t2139 - 0.8e1 * t1014 * t2142
+ 0.2e1 * t243 * t1230 + 0.8e1 * t1808 * t1114 - 0.2e1 * t576 * t1160
+ 0.2e1 * t2151 * t1110 - 0.8e1 * t668 * t880 + 0.8e1 * t1808 * t769
+ 0.2e1 * t908 * t1333 + 0.32e2 * t1856 * t2162 + 0.2e1 * t1235 * t442
+ 0.2e1 * t708 * t32 - 0.16e2 * t767 * t198 - 0.2e1 * t2151 * t974;
t2179 = t144 * t228;
t2197 = t1586 * d1;
t2204 = t485 * t239;
t2215 = t485 * t238;
t2218 = t462 * t5;
t2221 = -0.8e1 * t1527 * t2179 * t486 - 0.2e1 * t2151 * t1106 + 0.8e1
* t1235 * t230 + 0.2e1 * t1158 * t1258 - 0.2e1 * t17 * t877 + 0.8e1
* t1716 * t1615 + 0.16e2 * t244 * t1561 + 0.8e1 * t210 * t1016 + 0.4e1
* t927 * t2197 - 0.16e2 * t143 * t1648 - 0.8e1 * t210 * t1844 - 0.8e1
* t1014 * t2204 - 0.32e2 * t328 * t774 + 0.2e1 * t1158 * t448 - 0.2e1
* t1808 * t381 + 0.4e1 * t184 * t1974 + 0.2e1 * t446 * t2215 + 0.8e1 * t668 * t2218;
t2222 = t243 * t1292;
t2225 = t1614 *  t2;
t2243 = t159 * t3 * t5;
t2251 = t430 * t2052;
t2268 = -0.8e1 * t2222 * t2024 - 0.2e1 * t626 * t2225 + 0.8e1 * t389
* t466 + 0.4e1 * t55 * t287 * t1432 * t46 + 0.16e2 * t1014 * t643
+ 0.2e1 * t1716 * t556 - 0.8e1 * t1716 * t561 + 0.128e3 * t573 * t2057
+ 0.8e1 * t243 * t2243 - t515 * t1581 + 0.2e1 * t927 * t1587 + 0.2e1
* t446 * t594 + 0.8e1 * t2251 * t157 *  t124 * t132 + 0.16e2
* t397 * t487 + 0.2e1 * t366 * t2071 - 0.2e1 * t389 * t803 + 0.2e1 * t55
* t603 + 0.8e1 * t1716 * t2243 + 0.8e1 * t361 * t812;
t2294 = t202 * t735;
t2298 = t186 * t144 * t212;
t2312 = 0.8e1 * t45 * t1799 + 0.8e1 * t55 * t1072 - 0.2e1 * t431
* t815 + 0.2e1 * t55 * t974 - 0.8e1 * t1808 * t407 + 0.2e1 * t431
* t1755 - 0.2e1 * t2222 * t480 + 0.8e1 * t244 * t695 + 0.8e1 * t923
* t1890 - 0.8e1 * t389 * t880 - 0.8e1 * t1235 * t769 + 0.8e1 * t397
* t215 + 0.8e1 * t2294 * t867 + 0.4e1 * t184 * t2298 - 0.4e1 * t461
* t534 * t30 * t582 - 0.8e1 * t317 * t1416 - 0.8e1 * t1527
* t2179 * t1428 + 0.4e1 * t461 * t1769;
t2328 = t485 * t195;
t2332 = t67 * t94 * t5;
t2339 = t192 *  t2;
t2342 = t170 * t1774;
t2354 = t21 *  t2;
t2357 = t70 * t953;
t2361 = t170 * c2 * t18;
t2364 = -0.2e1 * t282 * t639 + 0.4e1 * t431 * t1853 + 0.4e1 * t45
* t910 - 0.2e1 * t256 * t442 - 0.2e1 * t256 * t1326 - 0.8e1 * t870
* t1169 + 0.16e2 * t2294 * t865 * t1168 - 0.4e1 * t446 * t2328 - 0.64e2
* t2332 * t2162 + 0.8e1 * t243 * t1117 * t262 * t1428 - 0.2e1 * t183
* t2339 - 0.2e1 * t2342 * t552 - 0.2e1 * t874 * t1178 - 0.8e1 * t244
* t1432 * t5 - 0.2e1 * t708 * t151 - 0.4e1 * t461 * t756 - 0.8e1 * t870
* t2354 + 0.8e1 * t19 * t2357 + 0.32e2 * t2361 * t1058;
t2368 =  t185 * d1 * t1006;
t2371 = t795 *  t2;
t2389 = t73 * t212;
t2407 = -0.2e1 * t1585 * t2368 + 0.2e1 * t282 * t2371 + 0.8e1 * t172
* t1165 + 0.8e1 * t172 * t1396 - t515 * t759 - 0.2e1 * t256 * t381
- 0.2e1 * t1716 * t1495 - 0.4e1 * t384 * t1282 + 0.8e1 * t587 * t344
- 0.2e1 * t708 * t612 + 0.8e1 * t1527 * t2389 * t486 - 0.4e1 * t446
* t577 + 0.8e1 * t2251 * t705 + 0.2e1 * t431 * t594 - 0.8e1 * t282
* t628 + 0.2e1 * t1808 * t424 - 0.2e1 * t256 * t352 + 0.8e1 * t361 * t1201;
t2424 = t141 * t373;
t2431 = t483 * t2052;
t2434 = t141 * t327;
t2451 = 0.2e1 * t626 * t1520 + 0.8e1 * t708 * t2043 + 0.8e1 * t55
* t673 * t818 * t46 - 0.8e1 * t626 * t605 + 0.8e1 * t350 * t235 + 0.8e1
* t908 * t1429 - 0.4e1 * t591 * t902 - 0.8e1 * t2424 * t377 - 0.4e1
* t908 * t90 - 0.2e1 * t243 * t2371 + 0.32e2 * t2431 * t700 + 0.32e2
* t2434 * t774 + 0.16e2 * t461 * t2043 - 0.16e2 * t908 * t1561 + 0.8e1
* t708 * t746 + 0.8e1 * t626 * t284 - 0.4e1 * t576 * t1766 + 0.8e1
* t1014 * t1255 - 0.2e1 * t1716 * t1293;
t2475 = t203 * t194;
t2478 = t203 * t288;
t2489 = t233 * t414;
t2494 = -0.8e1 * t1716 * t2005 - t515 * t1338 - 0.2e1 * t2342 * t547
- 0.8e1 * t708 * t842 - 0.2e1 * t282 * t1230 - 0.16e2 * t767 * t1289
- 0.16e2 * t767 * t812 + 0.4e1 * t461 * t32 + 0.32e2 * t2434 * t700
+ 0.8e1 * t1527 * t2389 * t1428 + 0.2e1 * t461 * t1457 - 0.4e1 * t461
* t2475 + 0.4e1 * t461 * t2478 + 0.2e1 * t350 * t1326 + 0.8e1 * t350
* t336 - 0.8e1 * t626 * t2243 - 0.8e1 * t342 * t1114 - 0.4e1 * t361
* t2489 + 0.4e1 * t1585 * t2197;
t2510 = t57 * t294;
t2539 = -0.2e1 * t533 * t877 + 0.8e1 * t749 * t2357 + 0.8e1 * t587
* t1630 + 0.2e1 * t244 * t1477 - 0.4e1 * t978 * t211 * t49 - 0.4e1
* t1029 * t678 + 0.2e1 * t490 * t584 + t490 * t2510 - 0.2e1 * t626
* t1620 - 0.8e1 * t626 * t989 - 0.32e2 * t2332 * t1858 + 0.2e1 * t384
* t381 - 0.4e1 * t55 * t584 + 0.4e1 * t461 * t150 * t302 + 0.2e1 * t626
* t1084 + 0.2e1 * t17 * t2475 - 0.16e2 * t55 * t1142 * t1118 * d2
- 0.4e1 * t55 * t57 * t475 * d2 + 0.8e1 * t282 * t561;
t2553 = t73 * d1;
t2569 =  t6 * t859;
t2587 = 0.8e1 * t626 * t1380 - 0.2e1 * t29 * t203 - 0.2e1 * t204
+ 0.16e2 * t767 * t2024 + 0.2e1 * t1808 * t935 - t1029 * t203 - 0.8e1
* t1527 * t2553 * t1303 + 0.2e1 * t243 * t159 *  t2 - 0.2e1
* t1003 * t616 - 0.4e1 * t1029 * t93 * t2354 - 0.2e1 * t29 * t223
+ 0.8e1 * t1014 * t1844 + 0.4e1 * t515 * t2569 - 0.8e1 * t626 * t1072
- 0.8e1 * t923 * t812 + 0.8e1 * t55 * t673 * t818 * t414 - 0.8e1 * t55
* t1117 * t5 * t46 * t49 + 0.8e1 * t528 * t678;
t2592 = t17 * t233;
t2593 = t2160 * t683;
t2602 = t21 * t187;
t2614 =  t185 * t107;
t2625 = t219 * t276 *  t4;
t2637 = t157 *  t124 * t159 * t163;
t2640 = -0.4e1 * t1029 * t1954 - 0.16e2 * t1212 * t1227 + 0.16e2
* t2592 * t2593 - 0.16e2 * t384 * t1061 + 0.8e1 * t2424 * t705 + 0.2e1
* t528 * t2478 + 0.8e1 * t927 * t2602 - 0.2e1 * t1158 * t962 + 0.2e1
* t243 * t2225 - 0.8e1 * t55 * t561 + t29 * t1914 + 0.2e1 * t29 * t1102
- 0.2e1 * t927 * t2614 * d1 + 0.2e1 * t456 * t367 * t35 * t276 + 0.2e1
* t170 * cm * t3 * t2625 + 0.4e1 * t528 * t223 - 0.16e2 * t1343 * t682
* t2161 - 0.2e1 * t533 * t223 + 0.8e1 * t394 * t2637;
t2642 = t367 * t582;
t2670 = t1090 * d1;
t2682 = 0.2e1 * t515 * t2642 - 0.4e1 * t576 * t1853 + t1029 * t151
+ 0.8e1 * t384 * t407 + 0.8e1 * t461 * t1092 + 0.2e1 * t389 * t1049
- 0.2e1 * t243 * t1084 - 0.8e1 * t202 * t1954 - 0.2e1 * t533 * t1457
- 0.2e1 * t528 * t1102 - 0.8e1 * t1343 * t684 - 0.2e1 * t1158 * t594
- 0.2e1 * t1585 * t930 + 0.8e1 * t244 * t830 - 0.2e1 * t681 * t2670
+ 0.8e1 * t1808 * t812 - 0.2e1 * t1808 * t442 - 0.2e1 * t927 * t2614
* d2 + 0.2e1 * t250 * t974;
t2717 = t202 *  t2;
t2724 = 0.2e1 * t29 *  t30 * t647 + 0.2e1 * t533 * t1102
+ 0.8e1 * t1014 * t1789 + 0.8e1 * t397 * t1929 - 0.4e1 * t431 * t577
+ 0.4e1 * t978 * t211 * t261 - 0.4e1 * t767 * t938 - 0.4e1 * t1003
* t466 + 0.8e1 * t626 * t437 - 0.8e1 * t282 * t1241 - 0.2e1 * t626
* t759 - 0.2e1 * t1003 * t1694 - 0.16e2 * t210 * t1908 - 0.8e1 * t1808
* t230 + 0.2e1 * t587 * t305 + 0.4e1 * t431 * t1766 - 0.2e1 * t2717
* t1178 - 0.4e1 * t1158 * t1853 - 0.8e1 * t384 * t588;
t2743 = t483 * t2133;
t2755 = t355 * t20 * t187;
t2758 = t173 * t414;
t2768 = 0.32e2 * t1481 * t1734 - 0.2e1 * t384 * t1694 - 0.4e1 * t767
* t935 - 0.4e1 * t767 * t424 - 0.16e2 * t1014 * t1908 - 0.2e1 * t1158
* t433 - 0.4e1 * t587 * t1282 + 0.2e1 * t87 * t1316 - 0.64e2 * t2743
* t123 * t355 * t357 - 0.2e1 * t1716 * t2371 - 0.8e1 * t1716 * t796
+ 0.4e1 * t681 * t788 + 0.8e1 * t1401 * t2755 - t361 * t2758 + 0.2e1
* t17 * t1921 - 0.4e1 * t1158 * t1766 + 0.2e1 * t576 * t631 + 0.4e1 * t591 * t1357;
t2808 = t233 * t859 * t46;
t2811 = 0.2e1 * t451 * t314 + t451 * t51 + 0.8e1 * t210 * t1255 +
+ 0.8e1 * t1450 *  t185 * t825 * t123 - 0.2e1 * t82 * t2339 -
- 0.4e1 * t767 * t651 - t927 * t1251 - 0.8e1 * t1014 * t215 + 0.2e1
* t451 * t1970 + 0.32e2 * t2592 * t2162 + 0.8e1 * t1401 * t1602 + 0.8e1
* t1716 * t605 - 0.4e1 * t668 * t914 - 0.64e2 * t2434 * t358 - 0.4e1
* t461 * t31 * t194 * t3 + 0.16e2 * t1856 * t2593 - 0.4e1 * t446 * t1959
+ 0.2e1 * t626 * t2371 + 0.8e1 * t366 * t2808;
t2838 = t53 * t54 * t43;
t2841 =  t311 * t1798;
t2844 = t287 * t412;
t2850 = t29 * t534;
t2854 = t233 * t506;
t2857 = -0.2e1 * t282 * t2225 + 0.16e2 * t55 * t1117 * t471 * t46
+ 0.2e1 * t490 * t2642 + 0.2e1 * t1029 * t1657 - 0.2e1 * t576 * t433
+ 0.8e1 * t389 * t1114 + 0.8e1 * t626 * t796 + 0.8e1 * t1374 * t1501
- 0.8e1 * t282 * t1615 + 0.16e2 * t668 * t1061 - 0.8e1 * t490 * t989
+ 0.4e1 * t2838 * t264 + 0.2e1 * t451 * t2841 - t490 * t2844 + 0.2e1
* t446 * t433 - 0.8e1 * t1401 * t109 + 0.4e1 * t2850 * t279 - t927
* t2625 - 0.4e1 * t1003 * t2854;
t2858 = t432 * t5;
t2859 = t145 * t2858;
t2903 = 0.8e1 * t397 * t2859 + 0.2e1 * t681 * t1274 + 0.16e2 * t1527
* t2553 * t560 - 0.8e1 * t87 * t830 - 0.8e1 * t210 * t2859 - 0.16e2
* t1014 * t1763 - 0.2e1 * t533 * t458 - 0.8e1 * t1389 * t1429 + 0.8e1
* t55 * t57 * t493 * d1 - 0.2e1 * t1716 * t1899 + 0.8e1 * t888 * t5
* t56 * t24 - 0.2e1 * t250 * t970 + 0.4e1 * t1158 * t577 - 0.16e2 * t210
* t1763 - 0.8e1 * t317 * t2354 + 0.8e1 * t923 * t407 - 0.8e1 * t1401
* t1738 + 0.16e2 * t1389 * t1561 + 0.4e1 * t1389 * t90;
t2918 = t29 * t18;
t2941 = t243 * t988;
t2946 = 0.2e1 * t1389 * t1477 + 0.2e1 * t461 * t223 + 0.4e1 * t1158
* t2328 - 0.2e1 * t250 * t1110 + 0.8e1 * t870 * t1602 + 0.8e1 * t2918
* t25 - 0.8e1 * t668 * t1890 + 0.16e2 * t1527 * t1550 * t486 - t515
* t2844 - 0.2e1 * t1158 * t1755 + 0.2e1 * t1003 * t1123 - 0.8e1 * t226
* t2024 + 0.8e1 * t587 * t1087 + 0.8e1 * t708 * t1954 - 0.16e2 * t668
* t1630 + 0.2e1 * t141 * t2339 - 0.2e1 * t2941 * t480 - 0.2e1 * t1158 * t2215;
t2987 = 0.4e1 * t978 * t211 * t23 + 0.8e1 * t29 * t3 * t2602 + 0.8e1
* t361 * t1289 - t587 * t1688 - 0.8e1 * t2251 * t2637 - 0.2e1 * t908
* t1477 + 0.4e1 * t183 * t3 * t1000 + 0.8e1 * t350 * t230 + 0.2e1 * t923
* t442 + 0.8e1 * t923 * t230 + 0.8e1 * t533 * t827 - 0.8e1 * t908
* t830 - 0.12e2 * t1401 * t2354 - 0.2e1 * t226 * t1326 + 0.16e2 * t461
* t1954 + 0.16e2 * t461 * t678 + 0.32e2 * t19 * t1734 + 0.2e1 * t250
* t1106 + 0.8e1 * t870 * t2755;
t3007 = t17 * t219;
t3026 =  t30 * t519 * t523;
t3030 = t1506 * t22;
t3035 = 0.16e2 * t2838 * t308 + 0.2e1 * t461 * t458 + 0.4e1 * t45
* t453 - 0.3e1 * t2046 * t1178 - 0.2e1 * t626 * t1230 - 0.2e1 * t908
* t1054 - 0.8e1 * t45 * t695 + 0.16e2 * t1014 * t660 - 0.2e1 * t1585
* t2128 + 0.2e1 * t3007 * t1163 * t546 + 0.8e1 * t1856 * t550 * t1168
- t587 * t1702 + 0.2e1 * t389 * t386 - 0.2e1 * t515 * t1620 - 0.8e1
* t908 * t1304 - 0.64e2 * t2743 * t123 *  t30 * t330 - 0.8e1
* t2850 * t3026 + 0.4e1 * t29 * t219 * t3030 + 0.2e1 * t456 * t1447;
t3075 = -0.2e1 * t587 * t616 - 0.2e1 * t626 * t556 - 0.8e1 * t250
* t1241 + 0.2e1 * t626 * t1899 + 0.16e2 * t210 * t487 + 0.8e1 * t708
* t678 - 0.4e1 * t226 * t2489 - 0.8e1 * t282 * t2243 + 0.2e1 * t668
* t1694 - 0.8e1 * t1014 * t240 - 0.2e1 * t515 * t367 * t538 + 0.8e1
* t1389 * t830 + 0.16e2 * t1212 * t807 - 0.4e1 * t786 * t1545 + 0.4e1
* t1148 * t2569 - 0.2e1 * t250 * t967 - 0.8e1 * t366 * t1241 - 0.8e1
* t461 * t842 - 0.4e1 * t515 * t2808;
t3116 = 0.8e1 * t2151 * t715 + 0.2e1 * t3007 * t1394 *  q
* t187 + 0.2e1 * t226 * t884 - 0.2e1 * t461 * t150 * t615 - 0.2e1
* t1235 * t935 - 0.2e1 * t927 * t2368 + 0.8e1 * t2151 * t792 + 0.2e1
* t2151 * t970 - 0.2e1 * t226 * t1871 + 0.8e1 * t350 * t258 - 0.16e2
* t587 * t1061 + 0.2e1 * t2151 * t967 - 0.8e1 * t461 * t710 - 0.8e1
* t2151 * t665 - 0.8e1 * t1235 * t812 + 0.8e1 * t87 * t1312 - 0.4e1
* t490 * t1174 + t451 * t1331;
t3160 = -0.12e2 * t17 * t1954 + 0.8e1 * t210 * t800 + 0.16e2 * t888
* t1099 + 0.4e1 * t2850 * t1575 + 0.2e1 * t67 * t543 * t20 - 0.2e1 * t55
* t287 * t413 * t46 - 0.4e1 * t978 * t145 * t212 - 0.2e1 * t2717
* t1989 + 0.2e1 * t461 * t534 *  t30 * t601 + 0.2e1 * t243
* t1620 + 0.2e1 * t626 * t1293 + 0.8e1 * t626 * t2005 - 0.2e1 * t923
* t935 + 0.8e1 * t87 * t1429 + 0.2e1 * t87 * t1333 + 0.16e2 * t101
* t1416 + 0.2e1 * t55 * t1581 + 0.8e1 * t350 * t407 - t1003 * t386;
t3204 = 0.2e1 * t1389 * t1054 + 0.2e1 * t45 * t1043 + 0.16e2 * t55
* t1679 * t1015 + 0.4e1 * t172 * t516 - 0.2e1 * t226 * t480 - 0.8e1
* t430 * t2133 * t123 *  t4 * t376 + 0.2e1 * t226 * t938 + 0.8e1
* t1389 * t1304 + 0.2e1 * t576 * t815 + 0.8e1 * t2294 * t865 * t1636
- t226 * t2758 - 0.4e1 * t1389 * t314 + 0.2e1 * t461 * t1447 + 0.16e2
* t2592 * t1858 + 0.8e1 * t528 * t1954 - 0.2e1 * t587 * t1694 - 0.2e1
* t668 * t442 + 0.8e1 * t193 * t1114 + 0.8e1 * t668 * t588;
t3205 = t17 * t227;
t3215 = t2160 * t836;
t3249 = -0.16e2 * t3205 * t1980 - 0.4e1 * t202 *  t185 * t2670
- 0.4e1 * t2838 * t1043 - 0.8e1 * t1472 * t109 - 0.32e2 * t3205
* t3215 + 0.2e1 * t1716 * t759 - 0.4e1 * t45 * t90 + 0.8e1 * t210
* t1789 + 0.16e2 * t2918 * t268 - 0.2e1 * t45 * t1477 - 0.8e1 * t1014
* t2859 - 0.8e1 * t55 * t792 + 0.2e1 * t490 * t1899 + 0.8e1 * t19
* t1934 - 0.16e2 * t456 * t227 *  R * t144 - 0.8e1 * t461 * t445
* t1404 + 0.8e1 * t626 * t561 + 0.2e1 * t193 * t935 - 0.8e1 * t2941 * t2024;
t3292 = -0.2e1 * t1716 * t1084 + 0.16e2 * t317 * t1405 + 0.2e1 * t17
* t1660 - 0.2e1 * t708 * t1102 + 0.2e1 * t533 * t1921 + 0.4e1 * t55
* t287 * t88 * d2 + 0.2e1 * t202 * t2475 - 0.2e1 * t389 * t442 + 0.4e1
* t900 * t1139 - 0.8e1 * t461 * t827 + 0.8e1 * t250 * t1380 - 0.16e2
* t1722 * t1643 - 0.4e1 * t900 * t1465 + 0.8e1 * t193 * t812 - 0.8e1
* t1716 * t1380 + 0.2e1 * t874 * t547 + 0.8e1 * t515 *  t6
* t621 - 0.16e2 * t2838 * t566;
t3333 = -t1249 * t2625 + 0.2e1 * t226 * t651 + 0.2e1 * t17 * t1657
- 0.2e1 * t170 * c2 *  t185 * t1274 - 0.2e1 * t576 * t1755
- 0.2e1 * t193 * t442 + 0.2e1 * t708 * t2123 - 0.32e2 * t1979 * t3215
- 0.8e1 * t1716 * t437 - 0.2e1 * t456 * t1921 - 0.3e1 * t17 * t32
+ 0.8e1 * t1389 * t695 + t451 * t1999 + 0.2e1 * t87 * t51 - 0.2e1 * t451
* t264 - 0.4e1 * t587 * t1297 + 0.8e1 * t374 * t2637 + 0.2e1 * t461
* t203 * t1701 + 0.16e2 * t55 * t1142 * t2858;
t3374 = -0.2e1 * t243 * t1495 - 0.16e2 * t55 * t437 + 0.2e1 * t456
* t223 - t515 * t1826 + 0.8e1 * t587 * t880 + 0.2e1 * t1003 * t305
+ 0.8e1 * t45 * t1823 - 0.2e1 * t708 * t463 - 0.16e2 * t55 * t1679
* t818 * d1 - 0.8e1 * t923 * t1554 + 0.2e1 * t587 * t803 - 0.8e1 * t533
* t1092 + 0.2e1 * t282 * t1293 + 0.2e1 * t1389 * t264 + 0.4e1 * t978
* t145 * t61 + 0.8e1 * t1808 * t198 - 0.16e2 * t451 * t1561 + t515
* t2510 - 0.32e2 * t101 * t1405;
t3415 = -0.16e2 * t101 * t323 + 0.2e1 * t1716 * t2225 - 0.4e1 * t587
* t466 + 0.128e3 * t156 * t2057 - 0.8e1 * t668 * t230 + 0.16e2 * t301
* t1131 - 0.8e1 * t1031 * t3026 + 0.2e1 * t1716 * t639 + 0.8e1 * t397
* t2142 - 0.2e1 * t456 * t2123 - 0.8e1 * t1014 * t1929 + 0.4e1 * t1158
* t1959 + 0.8e1 * t87 * t910 - 0.16e2 * t55 * t1142 * t1118 * d1 + 0.4e1
* t668 * t1282 + 0.32e2 * t2431 * t774 + 0.2e1 * t2003 * t206 - 0.8e1
* t317 * t871 - 0.4e1 * t389 * t914;
t3455 = -0.16e2 * t389 * t1630 - 0.8e1 * t923 * t2218 + 0.2e1 * t282
* t1899 - 0.2e1 * t528 * t463 + 0.8e1 * t397 * t2204 - 0.8e1 * t342
* t466 + 0.2e1 * t1371 * t547 + 0.2e1 * t226 * t935 - 0.8e1 * t451
* t308 - 0.4e1 * t587 * t2854 - 0.2e1 * t446 * t1160 + 0.8e1 * t1716
* t628 + 0.2e1 * t456 * t540 - 0.4e1 * t1003 * t1282 - 0.16e2 * t1527
* t1528 * t486 - 0.8e1 * t1472 * t1738 + 0.8e1 * t1389 * t308 - 0.8e1 * t1031 * t525;
t3495 = -t587 * t386 - 0.2e1 * t243 * t1520 + 0.2e1 * t456 * t877
+ 0.16e2 * t1722 * t147 + 0.16e2 * t1722 * t1227 - 0.8e1 * t2361 * t25
- 0.8e1 * t361 * t1637 - 0.2e1 * t1235 * t424 - 0.2e1 * t431 * t448
+ 0.4e1 * t461 * t20 *  t185 * t205 - 0.16e2 * t1722 * t807
+ 0.8e1 * t1472 * t1602 + 0.2e1 * t1235 * t381 + 0.2e1 * t282 * t1520
+ 0.2e1 * t243 * t759 + 0.4e1 * t461 * t445 * t1415 - t1148 * t2071
- 0.8e1 * t101 * t1602 - 0.2e1 * t87 * t1433;
t3535 = 0.8e1 * t1003 * t1630 + 0.16e2 * t1343 * t837 + 0.2e1 * t528
* t32 - t490 * t603 - 0.128e3 * t1436 * t2057 + 0.2e1 * t350 * t442
+ 0.2e1 * t456 * t2139 - 0.16e2 * t301 * t344 - 0.32e2 * t1937 * t1058
+ 0.4e1 * t3007 * t3030 - 0.8e1 * t366 * t1396 - 0.3e1 * t2046 * t1989
- 0.2e1 * t282 * t759 + 0.2e1 * t342 * t803 - 0.4e1 * t17 * t1633
- 0.8e1 * t1716 * t284 - 0.8e1 * t528 *  t740 * t267 + 0.2e1
* t350 * t381 - 0.8e1 * t2850 * t525;
t3575 = -0.4e1 * t1148 * t2808 - 0.16e2 * t1590 * t1227 - 0.4e1 * t576
* t2328 + 0.8e1 * t366 * t1380 - 0.8e1 * t456 * t746 - 0.16e2 * t1722
* t1214 - 0.8e1 * t2424 * t2637 - 0.64e2 * t2434 * t331 + 0.4e1 * t900
* t2298 + 0.2e1 * t528 * t2139 + 0.8e1 * t342 * t880 - 0.4e1 * t591
* t2298 - 0.4e1 * t366 * t516 - 0.2e1 * t366 * t252 - 0.4e1 * t461
* t445 * t322 + 0.2e1 * t45 * t2841 + 0.16e2 * t1212 * t1643 - 0.2e1
* t55 * t970 + 0.2e1 * t533 * t722;
t3592 = -0.6e1 * 0.3141592654e1 *  R * (t2987 + t2494 + t2221
+ t1737 + t1784 + t422 + t2682 + t3415 + t687 + t3075 + t1538 + t1690
+ t339 + t851 + t3249 + t1427 + t2724 + t2587 + t3455 + t1484 + t2768
+ t2407 + t1831 + t3495 + t597 + t2029 + t3035 + t2451 + t2811 + t994
+ t218 + t2080 + t1642 + t3116 + t1186 + t3160 + t3374 + t933 + t2857
+ t1882 + t3333 + t1364 + t1986 + t1593 + t503 + t2173 + t2312 + t3575
+ t3204 + t1238 + t1302 + t2539 + t2903 + t2268 + t2364 + t3535
+ t2640 + t780 + t1126 + t1057 + t3292 + t1932 + t2122 + t2946)
/ t153 / t11 /  t116 /  t8;
return 4./3.*M_PI*(R*R+s*s)*(R*R+2.*s*s)/R* t3592;
// The analytical formular for ??
}
double Iqxy( double qx, double qy,
	double R,
	double s,
	double c1,
	double c2,
	double c3,
	double cm,
	double d1,
	double d2)
{
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, R, s, c1, c2, c3, cm, d1, d2);
}
