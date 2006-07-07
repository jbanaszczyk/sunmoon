//. planets.cpp - 惑星位置計算
//	Copyright (C) 1997,1998,1999,2000 hkuno
//	mailto:hkuno.kuno@nifty.ne.jp

#include "planets.h"
#include <cmath>
#include "acoord.h"

using namespace std;
using namespace util;
using namespace astro;

namespace astro {
//------------------------------------------------------------------------
//.----- class PlanetData : 惑星位置計算用のデータ項目 -------------------
//------------------------------------------------------------------------
struct PlanetData {
    double a, b, c;             // 係数
    bool at;                    // a 項にTを掛けるなら true

    // １項目分の計算
    // @param T J2000.0[TDT]からのユリウス世紀
    double operator()(double T) const {
        double x = a * cos(dd2mod1(b * T + c) * DD2RAD);
        if (at) x *= T;
        return x;
    }
};//endclass PlanetData
};//endnamespace astro

//----- 太陽 SUN
const PlanetData
sunL[] = {                      // 平均黄経[°]
    {36000.7695,        0   ,     0   , true},
    {  280.4659,        0   ,     0   , },
    {    1.9147,    35999.05,   267.52, },
    {    0.0200,    71998.1 ,   265.1 , },
    {   -0.0048,    35999   ,   268   , true},
    {    0.0020,    32964   ,   158   , },
    {    0.0018,       19   ,   159   , },
    {    0.0018,   445267   ,   208   , },
    {    0.0015,    45038   ,   254   , },
    {    0.0013,    22519   ,   352   , },
    {    0.0007,    65929   ,    45   , },
    {    0.0007,     3035   ,   110   , },
    {    0.0007,     9038   ,    64   , },
    {    0.0006,    33718   ,   316   , },
    {    0.0005,      155   ,   118   , },
    {    0.0005,     2281   ,   221   , },
    {    0.0004,    29930   ,    48   , },
    {    0.0004,    31557   ,   161   , },
},
sunR[] = {                      // 地心距離[AU]
    {    1.000140,      0   ,     0   , },
    {    0.016706,  35999.05,   177.53, },
    {    0.000139,  71998   ,   175   , },
    {   -0.000042,  35999   ,   178   , true},
    {    0.000031, 445267   ,   298   , },
    {    0.000016,  32964   ,    68   , },
    {    0.000016,  45038   ,   164   , },
    {    0.000005,  22519   ,   233   , },
    {    0.000005,  33718   ,   226   , },
};

//----- 月 MOON
const PlanetData
moonL[] = {                     // 視黄経[°]
        { 481267.8809,      0    ,     0    , true},
        {    218.3162,      0    ,     0    , },
        {      6.2888, 477198.868,    44.963, },
        {      1.2740, 413335.35 ,    10.74 , },
        {      0.6583, 890534.22 ,   145.7  , },
        {      0.2136, 954397.74 ,   179.93 , },
        {      0.1851,  35999.05 ,    87.53 , },
        {      0.1144, 966404    ,   276.5  , },
        {      0.0588,  63863.5  ,   124.2  , },
        {      0.0571, 377336.3  ,    13.2  , },
        {      0.0533,1367733.1  ,   280.7  , },
        {      0.0458, 854535.2  ,   148.2  , },
        {      0.0409, 441199.8  ,    47.4  , },
        {      0.0347, 445267.1  ,    27.9  , },
        {      0.0304, 513197.9  ,   222.5  , },
        {      0.0154,  75870    ,    41    , },
        {      0.0125, 1443603   ,    52    , },
        {      0.0110,  489205   ,   142    , },
        {      0.0107, 1303870   ,   246    , },
        {      0.0100, 1431597   ,   315    , },
        {      0.0085,  826671   ,   111    , },
        {      0.0079,  449334   ,   188    , },
        {      0.0068,  926533   ,   323    , },
        {      0.0052,   31932   ,   107    , },
        {      0.0050,  481266   ,   205    , },
        {      0.0040, 1331734   ,   283    , },
        {      0.0040, 1844932   ,    56    , },
        {      0.0040,     133   ,    29    , },
        {      0.0038, 1781068   ,    21    , },
        {      0.0037,  541062   ,   259    , },
        {      0.0028,    1934   ,   145    , },
        {      0.0027,  918399   ,   182    , },
        {      0.0026, 1379739   ,    17    , },
        {      0.0024,   99863   ,   122    , },
        {      0.0023,  922466   ,   163    , },
        {      0.0022,  818536   ,   151    , },
        {      0.0021,  990397   ,   357    , },
        {      0.0021,   71998   ,    85    , },
        {      0.0021,  341337   ,    16    , },
        {      0.0018,  401329   ,   274    , },
        {      0.0016, 1856938   ,   152    , },
        {      0.0012, 1267871   ,   249    , },
        {      0.0011, 1920802   ,   186    , },
        {      0.0009,  858602   ,   129    , },
        {      0.0008, 1403732   ,    98    , },
        {      0.0007,  790672   ,   114    , },
        {      0.0007,  405201   ,    50    , },
        {      0.0007,  485333   ,   186    , },
        {      0.0007,   27864   ,   127    , },
        {      0.0006,  111869   ,    38    , },
        {      0.0006, 2258267   ,   156    , },
        {      0.0005, 1908795   ,    90    , },
        {      0.0005, 1745069   ,    24    , },
        {      0.0005,  509131   ,   242    , },
        {      0.0004,   39871   ,   223    , },
        {      0.0004,   12006   ,   187    , },
        {      0.0003,  958465   ,   340    , },
        {      0.0003,  381404   ,   354    , },
        {      0.0003,  349472   ,   337    , },
        {      0.0003, 1808933   ,    58    , },
        {      0.0003,  549197   ,   220    , },
        {      0.0003,    4067   ,    70    , },
        {      0.0003, 2322131   ,   191    , },
},
moonB[] = {                     // 視黄緯[°]
        {      5.1281, 483202.019,     3.273, },
        {      0.2806, 960400.89 ,   138.24 , },
        {      0.2777,   6003.15 ,    48.31 , },
        {      0.1733, 407332.2  ,    52.43 , },
        {      0.0554, 896537.4  ,   104    , },
        {      0.0463,  69866.7  ,    82.5  , },
        {      0.0326,1373736.2  ,   239    , },
        {      0.0172,1437599.8  ,   273.2  , },
        {      0.0093, 884531    ,   187    , },
        {      0.0088, 471196    ,    87    , },
        {      0.0082, 371333    ,    55    , },
        {      0.0043, 547066    ,   217    , },
        {      0.0042,1850935    ,    14    , },
        {      0.0034, 443331    ,   230    , },
        {      0.0025, 860538    ,   106    , },
        {      0.0022, 481268    ,   308    , },
        {      0.0022,1337737    ,   241    , },
        {      0.0021, 105866    ,    80    , },
        {      0.0019, 924402    ,   141    , },
        {      0.0018, 820668    ,   153    , },
        {      0.0018, 519201    ,   181    , },
        {      0.0018,1449606    ,    10    , },
        {      0.0015,  42002    ,    46    , },
        {      0.0015, 928469    ,   121    , },
        {      0.0015, 996400    ,   316    , },
        {      0.0014,  29996    ,   129    , },
        {      0.0013, 447203    ,     6    , },
        {      0.0013,  37935    ,    65    , },
        {      0.0011,1914799    ,    48    , },
        {      0.0010,1297866    ,   288    , },
        {      0.0009,1787072    ,   340    , },
        {      0.0008, 972407    ,   235    , },
        {      0.0007,1309873    ,   205    , },
        {      0.0006, 559072    ,   134    , },
        {      0.0006,1361730    ,   322    , },
        {      0.0005, 848352    ,   190    , },
        {      0.0005, 419339    ,   149    , },
        {      0.0005, 948395    ,   222    , },
        {      0.0004,2328134    ,   149    , },
        {      0.0004,1024264    ,   352    , },
        {      0.0003, 932536    ,   282    , },
        {      0.0003,1409735    ,    57    , },
        {      0.0003,2264270    ,   115    , },
        {      0.0003,1814936    ,    16    , },
        {      0.0003, 335334    ,    57    , },
},
moonP[] = {                     // 地平視差
        {    0.950725,      0    ,     0    , },
        {    0.051820, 477198.868,   134.963, },
        {    0.009530, 413335.35 ,   100.74 , },
        {    0.007842, 890534.22 ,   235.7  , },
        {    0.002824, 954397.74 ,   269.93 , },
        {    0.000858,1367733.1  ,    10.7  , },
        {    0.000531, 854535.2  ,   238.2  , },
        {    0.000400, 377336.3  ,   103.2  , },
        {    0.000319, 441199.8  ,   137.4  , },
        {    0.000271, 445267    ,   118    , },
        {    0.000263, 513198    ,   312    , },
        {    0.000197, 489205    ,   232    , },
        {    0.000173,1431597    ,    45    , },
        {    0.000167,1303870    ,   336    , },
        {    0.000111,  35999    ,   178    , },
        {    0.000103, 826671    ,   201    , },
        {    0.000084,  63864    ,   214    , },
        {    0.000083, 926533    ,    53    , },
        {    0.000078,1844932    ,   146    , },
        {    0.000073,1781068    ,   111    , },
        {    0.000064,1331734    ,    13    , },
        {    0.000063, 449334    ,   278    , },
        {    0.000041, 481266    ,   295    , },
        {    0.000034, 918399    ,   272    , },
        {    0.000033, 541062    ,   349    , },
        {    0.000031, 922466    ,   253    , },
        {    0.000030,  75870    ,   131    , },
        {    0.000029, 990397    ,    87    , },
        {    0.000026, 818536    ,   241    , },
        {    0.000023, 553069    ,   266    , },
        {    0.000019,1267871    ,   339    , },
        {    0.000013,1403732    ,   188    , },
        {    0.000013, 341337    ,   106    , },
        {    0.000013, 401329    ,     4    , },
        {    0.000012,2258267    ,   246    , },
        {    0.000011,1908795    ,   180    , },
        {    0.000011, 858602    ,   219    , },
        {    0.000010,1745069    ,   114    , },
        {    0.000009, 790672    ,   204    , },
        {    0.000007,2322131    ,   281    , },
        {    0.000007,1808933    ,   148    , },
        {    0.000006, 485333    ,   276    , },
        {    0.000006,  99863    ,   212    , },
        {    0.000005, 405201    ,   140    , },
};

//----- 水星 MERCURY
const PlanetData
mercuryL[] = {                  // 日心平均黄経[°]
        { 149474.0714,     0     ,     0     , true},
        {    252.2502,     0     ,     0     , },
        {     23.4405,149472.5153,    84.7947, },
        {      2.9818,298945.031 ,   259.589 , },
        {      0.5258,448417.55  ,    74.38  , },
        {      0.1796,298945.77  ,   137.84  , },
        {      0.1061,597890.1   ,   249.2   , },
        {      0.0850,149473.3   ,   143     , },
        {      0.0760,448418.3   ,   312.6   , },
        {      0.0256,597890.8   ,   127.4   , },
        {      0.0230,747362.6   ,    64     , },
        {      0.0081,747363     ,   302     , },
        {      0.0069,     1     ,   148     , },
        {      0.0052,896835     ,   239     , },
        {      0.0023,149473     ,    85     , true},
        {      0.0023,896836     ,   117     , },
        {      0.0019,  6356     ,    85     , },
        {      0.0011,1046308    ,    54     , },
        {      0.0010,  32437    ,   234     , },
        {      0.0009, 143403    ,   171     , },
        {      0.0006, 298945    ,   260     , true},
        {      0.0006, 155828    ,   268     , },
        {      0.0005,1046308    ,   292     , },
        {      0.0004, 143117    ,    84     , },
        {      0.0003, 181909    ,    63     , },
        {      0.0003, 123392    ,   288     , },
        {      0.0003, 448419    ,    11     , },
},
mercuryB[] = {                  // 日心平均黄緯[°]
        {      6.7057,149472.886 ,   113.919 , },
        {      1.4396,     0.37  ,   119.12  , },
        {      1.3643,298945.4   ,   288.71  , },
        {      0.3123,448417.92  ,   103.51  , },
        {      0.0753,597890.4   ,   278.3   , },
        {      0.0367,149472.1   ,    55.7   , },
        {      0.0187,747362.9   ,    93.1   , },
        {      0.0050,298945     ,   230     , },
        {      0.0047,896835     ,   268     , },
        {      0.0028,448419     ,   342     , },
        {      0.0023,298946     ,   347     , },
        {      0.0020,597891     ,   157     , },
        {      0.0017,149473     ,   114     , true},
        {      0.0012,1046308    ,    83     , },
        {      0.0009,747364     ,   331     , },
        {      0.0009,448417     ,    45     , },
        {      0.0005,298945     ,   289     , true},
        {      0.0005,     0     ,   119     , true},
        {      0.0005,149474     ,   352     , },
        {      0.0003,896836     ,   146     , },
},
mercuryR[] = {                  // 動径[AU]
        {    0.395283,      0    ,     0     , },
        {    0.078341, 149472.515,   354.795 , },
        {    0.007955, 298945.03 ,   169.59  , },
        {    0.001214,448417.55  ,   344.38  , },
        {    0.000218,597890.1   ,   159.2   , },
        {    0.000042,747363     ,   334     , },
        {    0.000008,149473     ,   355     , true},
        {    0.000006,896835     ,   149     , },
        {    0.000002,     0     ,     0     , true},
        {    0.000002,298945     ,   170     , true},
};

//----- 金星 VENUS
const PlanetData
venusL[] = {                    // 日心平均黄経[°]
        { 58519.2125,      0     ,     0     , true},
        {   181.9793,      0     ,     0     , },
        {     0.7761,  58517.81  ,   320.41  , },
        {     0.0503, 117036.6   ,   300.6   , },
        {    -0.0054,  58518     ,   320     , true},
        {     0.0033, 117036     ,    11     , },
        {     0.0032,  45038     ,   254     , },
        {     0.0020,  67556     ,   159     , },
        {     0.0014,  22519     ,   172     , },
        {     0.0010,   9038     ,   244     , },
        {     0.0008,  55483     ,   239     , },
        {     0.0008,    155     ,   303     , },
        {     0.0007,  58519     ,    70     , },
        {     0.0007, 175554     ,   351     , },
        {     0.0005,   3035     ,   110     , },
        {     0.0004,  54076     ,    34     , },
},
venusB[] = {                    // 日心平均黄緯[°]
        {     3.3939,  58518.312 ,    15.299 , },
        {     0.0230,      0.5   ,   144.9   , },
        {     0.0230, 117036.1   ,    65.7   , },
        {     0.0010,  58518     ,    15     , true},
        {     0.0005, 175555     ,    46     , },
},
venusR[] = {                    // 動径[AU]
        {     0.723348,     0    ,     0     , },
        {     0.004899, 58517.81 ,   230.41  , },
        {    -0.000034, 58518    ,   230     , true},
        {     0.000017,117036    ,   281     , },
        {     0.000016, 45038    ,   164     , },
        {     0.000014, 67556    ,    69     , },
        {     0.000004, 55483    ,   121     , },
};

//----- 火星 MARS
const PlanetData
marsL[] = {                     // 日心平均黄経[°]
        { 19141.6999,      0     ,     0     , true},
        {   355.4472,      0     ,     0     , },
        {    10.6919,  19139.859 ,   289.388 , },
        {     0.6227,  38279.71  ,   308.78  , },
        {     0.0504,  57419.6   ,   328.2   , },
        {     0.0147,     19     ,   336     , },
        {     0.0144,  38282     ,   342     , },
        {     0.0140,      0     ,   180     , },
        {     0.0105,  19140     ,   289     , true},
        {     0.0070,  16105     ,    48     , },
        {     0.0060,  13071     ,   168     , },
        {     0.0047,  76559     ,   348     , },
        {     0.0045,  32211     ,   191     , },
        {     0.0038,   2281     ,    21     , },
        {     0.0037,      0     ,   180     , true},
        {     0.0028,  57422     ,     1     , },
        {     0.0028,  19142     ,   142     , },
        {     0.0023,  16859     ,    13     , },
        {     0.0019,  14579     ,    95     , },
        {     0.0018,   1098     ,    50     , },
        {     0.0013,   4561     ,   290     , },
        {     0.0012,  38280     ,   309     , true},
        {     0.0010,   3035     ,    39     , },
        {     0.0009,  35245     ,    67     , },
        {     0.0009,  10036     ,   167     , },
        {     0.0007,  29176     ,   208     , },
        {     0.0007,  12298     ,   166     , },
        {     0.0006,  51350     ,   205     , },
        {     0.0005,  16696     ,   137     , },
        {     0.0005,  21421     ,    53     , },
        {     0.0004,    895     ,   229     , },
        {     0.0004,   6069     ,   220     , },
        {     0.0004,  17918     ,    28     , },
        {     0.0003,  10017     ,   256     , },
        {     0.0003,  76562     ,    21     , },
        {     0.0003,  48316     ,   179     , },
        {     0.0003,   6842     ,   214     , },
},
marsB[] = {                     // 日心平均黄緯[°]
        {     1.8334,  19140.925 ,   215.876 , },
        {     0.1727,      1.07  ,    16.5   , },
        {     0.1709,  38280.79  ,   235.28  , },
        {     0.0179,  57420.6   ,   254.7   , },
        {     0.0021,  19139     ,     3     , },
        {     0.0020,  76561     ,   274     , },
        {    -0.0007,  19141     ,   216     , true},
},
marsR[] = {                     // 動径[AU]
        {     1.530339,     0    ,     0     , },
        {     0.141850, 19139.859,   199.388 , },
        {     0.006606, 38279.72 ,   218.78  , },
        {     0.000455, 57419.6  ,   238.2   , },
        {     0.000139, 19139.9  ,   199.4   , true},
        {     0.000080, 16105    ,   317     , },
        {     0.000072, 32211    ,   103     , },
        {     0.000055, 13071    ,    77     , },
        {     0.000035, 76559    ,   258     , },
        {     0.000024, 16859    ,   284     , },
        {     0.000023, 14579    ,     3     , },
        {     0.000013,     0    ,     0     , true},
        {     0.000013, 38280    ,   219     , true},
        {     0.000013, 29176    ,   118     , },
        {     0.000010, 35245    ,   338     , },
        {     0.000009, 48316    ,    89     , },
        {     0.000008,  2281    ,   311     , },
};

//----- 木星 JUPITER
const PlanetData
jupiterL[] = {                  // 日心平均黄経[°]
        {  3036.08406,     0     ,     0     , true},
        {    34.39356,     0     ,     0     , },
        {     5.54603,  3034.5334,   289.6842, },
        {     0.17575,  6083.2578,   309.5012, },
        {     0.05532,  3624.312 ,   237.453 , },
        {     0.04370,  6071.843 ,   218.916 , true},
        {     0.03557,   596.267 ,   191.685 , },
        {     0.02274,  2405.806 ,   135.412 , },
        {     0.02120,  1822.117 ,    73.665 , },
        {     0.00757,  9107.13  ,   327.94  , },
        {     0.00699,  2920.69  ,   198.68  , },
        {     0.00607,  4759.11  ,    88.37  , },
        {     0.00501,  5449.93  ,   206.94  , },
        {     0.00482,  4730.71  ,   273.36  , },
        {     0.00397,  4206.81  ,   294.77  , },
        {     0.00343,  6666.05  ,   259.11  , },
        {     0.00335,  1284.47  ,   244.1   , },
        {     0.00224,  1466.26  ,    54.64  , },
        {     0.00094,  7251.8   ,   221.3   , },
        {     0.00039, 12131.7   ,   345.5   , },
        {     0.00035,  8473.4   ,   241.5   , },
        {     0.00029,  9704.4   ,   270.6   , },
        {     0.00028,  9087.8   ,   197.2   , true},
        {     0.00012,  7779.9   ,   258.5   , },
        {     0.00010, 10902.8   ,   174     , },
        {     0.00009, 10324     ,   251     , },
        {     0.00003, 12691     ,   195     , },
},
jupiterB[] = {                  // 日心平均黄緯[°]
        {     1.30086, 3034.1263 ,   203.9187, },
        {     0.06299,    0      ,     0     , },
        {     0.06295, 6068.687  ,   223.544 , },
        {     0.02141, 3034.269  ,   309.356 , true},
        {     0.00347, 9134.65   ,   243.22  , },
        {     0.00185, 9115.63   ,   152.84  , true},
        {     0.00106, 6049.97   ,   339.44  , true},
        {     0.00072, 2424.7    ,   113.1   , },
        {     0.00063, 6654.4    ,   171.6   , },
        {     0.00051,    0      ,   180     , true},
        {     0.00045, 3627.8    ,   122.2   , },
        {     0.00038, 1225.1    ,   214.6   , },
        {     0.00033, 4850.1    ,     0.8   , },
        {     0.00031,  562.9    ,   266.8   , },
        {     0.00028, 5432.9    ,    75.7   , },
        {     0.00020,12136.2    ,   262.6   , },
        {     0.00011, 4231.5    ,   267.9   , },
        {     0.00007, 9699      ,   191     , },
        {     0.00006, 8494      ,   132     , },
        {     0.00006,  799      ,   181     , },
},
jupiterR[] = {                  // 動径[AU]
        {    5.209105,      0    ,     0     , },
        {    0.251681,   3034.534,   199.614 , },
        {    0.006134,   6066.1  ,   219     , },
        {    0.002802,   3624.5  ,   147.7   , },
        {    0.000880,   2406    ,    46     , },
        {    0.000635,   1818    ,   344     , },
        {    0.000612,   2968    ,    19     , true},
        {    0.000309,   6090    ,   312     , true},
        {    0.000306,    601    ,    97     , },
        {    0.000299,   5444    ,   124     , },
        {    0.000224,   4215    ,   205     , },
        {    0.000212,   9113    ,   233     , },
        {    0.000129,   6671    ,   171     , },
        {    0.000069,   7258    ,   125     , },
        {    0.000061,   1190    ,   169     , },
        {    0.000061,   4840    ,   334     , },
        {    0.000057,   9479    ,   276     , true},
        {    0.000030,      0    ,   180     , true},
        {    0.000017,   1517    ,   288     , },
        {    0.000016,   8482    ,   167     , },
        {    0.000012,   7830    ,   175     , },
        {    0.000009,  12122    ,   249     , },
        {    0.000009,  10896    ,    84     , },
        {    0.000005,  10256    ,   164     , },
        {    0.000005,   9560    ,   138     , },
};

//----- 土星 SATURN
const PlanetData
saturnL[] = {                   // 日心平均黄経[°]
        {  1224.04687,     0     ,     0     , true},
        {    49.97937,     0     ,     0     , },
        {     6.19608,  1178.3909,   227.5245, },
        {     4.81254,  1200.7657,   317.4395, true},
        {     0.44141,  2380.375 ,   279.0711, true},
        {     0.19720,  2310.5997,   187.9907, },
        {     0.11441,   597.506 ,     9.0137, },
        {     0.03220,  3731.729 ,     8.114 , true},
        {     0.01138,  3816.622 ,   105.909 , },
        {     0.00857,  1884.95  ,   334.19  , },
        {     0.00215,  3151.76  ,    22.82  , },
        {     0.00184,  5435.18  ,    44.09  , },
        {     0.00094,  4198.7   ,    97.3   , },
        {     0.00056,  4729.7   ,   316.6   , },
        {     0.00054,  7243     ,    29.7   , },
        {     0.00040,  4516.9   ,   147.7   , },
        {     0.00029,  6009.6   ,    94.9   , },
        {     0.00018,  9058     ,    13.7   , },
        {     0.00011,  7825.9   ,    74.1   , },
        {     0.00010,  6055     ,    92     , },
        {     0.00009,  6619     ,    69     , },
        {     0.00007, 10868     ,   354     , },
        {     0.00005,  9616     ,    68     , },
        {     0.00004,  8461     ,    79     , },
},
saturnB[] = {                   // 日心平均黄緯[°]
        {     2.47972, 1224.5698 ,   206.3386, },
        {     0.13425, 2445.2128 ,   163.7721, },
        {     0.05938, 1223.005  ,   113.635 , true},
        {     0.04858,    0      ,     0     , },
        {     0.00978,  514.08   ,    27.67  , true},
        {     0.00812, 3673.28   ,   121.34  , },
        {     0.00305,  437.68   ,   296.69  , },
        {     0.00277, 1812.03   ,   303.12  , },
        {     0.00230, 2450.45   ,   251.99  , true},
        {     0.00064, 3629      ,    28.8   , true},
        {     0.00055, 3035.3    ,   321     , },
        {     0.00039, 4861.3    ,    64     , },
        {     0.00017, 4953      ,    79.5   , },
},
saturnR[] = {                   // 動径[AU]
        {    9.554001,      0    ,     0     , },
        {    0.515185,   1188.045,   137.576 , },
        {    0.314172,   1205.098,   227.317 , true},
        {    0.014780,   2442.07 ,    92.09  , },
        {    0.008245,   1814.6  ,   341.2   , },
        {    0.005400,    586.3  ,   277.3   , },
        {    0.001556,   3612.4  ,   347.2   , },
        {    0.001238,   2600    ,   225.3   , true},
        {    0.000555,      0    ,   180     , true},
        {    0.000314,   5440    ,   313     , },
        {    0.000215,   3941    ,    32     , },
        {    0.000166,   3228    ,   160     , },
        {    0.000136,   4900    ,   358     , },
        {    0.000119,   4379    ,    22     , },
        {    0.000096,   7245    ,   298     , },
        {    0.000055,   6017    ,    15     , },
        {    0.000032,   9051    ,   281     , },
        {    0.000027,   7826    ,     1     , },
        {    0.000014,   6628    ,    20     , },
        {    0.000012,  10878    ,   263     , },
        {    0.000009,   9610    ,   343     , },
        {    0.000007,   8336    ,    15     , },
        {    0.000004,  12669    ,   244     , },
};

//----- 天王星 URANUS
const PlanetData
uranusL[] = {                   // 日心平均黄経[°]
        {   428.72880,     0     ,     0     , true},
        {   313.33676,     0     ,     0     , },
        {     5.35857,   460.6198,    48.8503, },
        {     3.20671,   705.1553,   114.0274, true},
        {     2.69325,   597.7738,   317.7651, true},
        {     0.58964,   919.0429,   188.3245, },
        {     0.12397,  1065.1192,   354.5935, },
        {     0.01475,  2608.702 ,   351.028 , },
        {     0.00090,  1968.3   ,   247.7   , },
        {     0.00036,  5647.4   ,    10.4   , },
        {     0.00017,  2356.6   ,   183.6   , },
        {     0.00017,  2873.2   ,   321.9   , },
        {     0.00015,  3798.6   ,   313.4   , true},
        {     0.00014,  3157.9   ,   308.1   , },
},
uranusB[] = {                   // 日心平均黄緯[°]
        {     1.78488,  507.5228 ,   188.3239, true},
        {     1.15483,  419.9173 ,   128.1530, },
        {     0.67756,  652.9504 ,   273.6644, },
        {     0.56518,  892.2869 ,   354.9571, true},
        {     0.13490,  998.0302 ,    83.3517, },
        {     0.02997,    0      ,   180.    , },
        {     0.00036,  1526.5   ,   263     , true},
        {     0.00025,  3030.9   ,   194.2   , },
},
uranusR[] = {                   // 動径[AU]
        {   19.203034,      0    ,     0     , },
        {    0.905790,    408.729,   320.313 , },
        {    0.361949,    440.702,    19.879 , true},
        {    0.166685,    702.024,   307.419 , true},
        {    0.062710,    799.95 ,    67.99  , },
        {    0.042617,      0    ,     0     , true},
        {    0.004897,   2613.7  ,    80.4   , },
        {    0.000656,   1527    ,   202     , },
        {    0.000223,   2120    ,   321     , },
        {    0.000205,   3104    ,    37     , },
        {    0.000120,   5652    ,   100     , },
};

//----- 海王星 NEPTUNE
const PlanetData
neptuneL[] = {                  // 日心平均黄経[°]
        {   219.93503,     0     ,     0     , true},
        {    55.13323,     0     ,   180     , },
        {     0.97450,   221.3904,   167.7269, },
        {     0.04403,   684.128 ,   332.797 , true},
        {     0.02928,   904.371 ,   342.114 , true},
        {     0.01344,   986.281 ,    50.826 , },
        {     0.00945,  2815.89  ,     0.09  , },
        {     0.00235,  2266.5   ,   309.35  , },
        {     0.00225,  2279.43  ,   127.61  , },
        {     0.00023,  5851.6   ,    19.2   , },
},
neptuneB[] = {                  // 日心平均黄緯[°]
        {     1.76958,  218.8790 ,    83.1101, },
        {     0.01725,    0      ,     0     , },
        {     0.01366,  447.128  ,   338.864 , },
        {     0.00015, 1107.1    ,   224.7   , },
        {     0.00015, 2596.7    ,   187.5   , },
        {     0.00012, 3035      ,   243.9   , },
},
neptuneR[] = {                  // 動径[AU]
        {   30.073033,      0    ,     0     , },
        {    0.260457,    222.371,    79.994 , },
        {    0.009784,    515.2  ,   195.7   , true},
        {    0.004944,   2815.4  ,    90.1   , },
        {    0.003364,    524    ,   308.1   , },
        {    0.002579,   1025.1  ,   104     , },
        {    0.000120,   5845    ,   111     , },
};

//----- 冥王星 PLUTO
const PlanetData
plutoL[] = {                    // 日心平均黄経[°]
        {   241.82574,     0     ,     0     , },
        {   179.09519,     0     ,     0     , true},
        {    15.81087,   246.5564,   298.3480, },
        {     1.18379,   551.3471,   351.6767, },
        {     0.07886,   941.622 ,    41.989 , },
        {     0.00861,  2836.46  ,    60.35  , },
        {     0.00590,  1306.75  ,   112.91  , },
        {     0.00145,  2488.14  ,    19.01  , },
        {     0.00022,  5861.8   ,    77.9   , },
        {     0.00013,  3288.8   ,   293     , },
},
plutoB[] = {                    // 日心平均黄緯[°]
        {    17.04550,  172.5543 ,    42.5749, },
        {     2.45310,  415.6063 ,    66.1535, },
        {     2.30285,    0      ,   180     , },
        {     0.26775,  713.1227 ,   105.084 , },
        {     0.01855, 1089.202  ,   146.66  , },
        {     0.00119, 2658.22   ,   293.06  , },
        {     0.00098, 3055.6    ,    18.8   , },
        {     0.00090, 1532.6    ,   213.7   , },
        {     0.00042, 2342.3    ,   254.2   , },
},
plutoR[] = {                    // 動径[AU]
        {   38.662489,      0     ,     0     , },
        {    8.670489,    181.3383,   198.4973, },
        {    0.333884,    475.963 ,   228.717 , },
        {    0.008426,    909.8   ,   252.9   , },
        {    0.007619,   1425.9   ,    31     , true},
        {    0.004902,   2831.6   ,   149.4   , },
        {    0.002543,   2196.1   ,   199.5   , true},
        {    0.001188,   1748     ,   114.1   , },
        {    0.000390,   3188     ,    15     , },
        {    0.000116,   5860     ,   169     , },
};

//------------------------------------------------------------------------
//.----- class Planets : 惑星位置計算 ------------------------------------
//------------------------------------------------------------------------

// 計算集計
// @param T J2000.0[TDT]からのユリウス世紀
// @param data データ項目
// @param n    データ項目数
// @return 動径[AU]
static double sumR(double T, const PlanetData* data, size_t n) {
    double x = 0;
    while (n--)
        x += (*data++)(T);
    return x;
}

// 計算集計
// @param T J2000.0[TDT]からのユリウス世紀
// @param data データ項目
// @param n    データ項目数
// @return 角度
static Degree sumDeg(double T, const PlanetData* data, size_t n) {
    double x = 0;
    while (n--)
        x += dd2mod2((*data++)(T));
    return Degree(x * 3600);
}

//------------------------------------------------------------------------
// 日心幾何学黄道座標を、惑星光行差付きの地心黄道座標に変換する
// @param r 動径[AU]
// @param b 日心黄緯
// @param l 日心黄経
// @param c 光行差定数
Vec3
Planets::conv(double r, Degree b, Degree l, Degree c) const
{
#ifdef TEST
    printf("conv: l=%10.8f b=%10.8f r=%10.8f\n",
        dd2mod1(l.degree()), dd2mod2(b.degree()), r);
#endif
    // 地心幾何学黄道座標を得る
    Vec3 v;
    v.setLtLg(r, b, l);
    v += sunVc;
    Degree bb, ll;
    v.getLtLg(bb, ll);

    // 黄経に惑星光行差を加える
    ll -= Degree(0.00569 * 3600) * cos(ll - L) / R
                            + c * cos(ll - l) / r;

    // 結果を単位ベクトルとして設定する
    v.setLtLg(1, bb, ll);

    return v;
}

//------------------------------------------------------------------------
// 月・惑星の位置を計算する
void
Planets::calc(const AstroCoordinate& acoord)
{
    #define SUMR(array)         sumR(T, array, ELEMENTS_OF(array))
    #define DEG(array)          sumDeg(T, array, ELEMENTS_OF(array))
    #define CONV(name, c)       conv(SUMR(name##R), DEG(name##B), DEG(name##L), Degree(c * 3600))

    // T = J2000.0からのユリウス世紀[TDT]
    const double T = acoord.getTime().j2000() / 36525;

    // 太陽の黄道座標を得る
    L = DEG(sunL);
    R = SUMR(sunR);
    sunVc.setLtLg(R, Degree(0), L);
    vc[SUN].setLtLg(1, Degree(0), L - Degree(0.0057 * 3600)); // 惑星光行差を加える

    // 月の黄道座標を得る（これだけは視位置である）
    Lm = DEG(moonL);
    Bm = DEG(moonB);
    Pm = SUMR(moonP);
    vc[MOON].setLtLg(1, Bm, Lm);

#ifdef TEST
    printf("SUN:  L=%10.8f R=%10.8f\n", dd2mod1(L.degree()), R);
    printf("MOON: L=%10.8f B=%10.8f P=%10.8f\n",
        dd2mod1(Lm.degree()), dd2mod2(Bm.degree()), Pm);
#endif

    // 各惑星の地心平均黄道座標を求める(惑星光行差付き)
    vc[MERCURY] = CONV(mercury, 0.00347);
    vc[VENUS]   = CONV(venus,   0.00484);
    vc[MARS]    = CONV(mars,    0.00700);
    vc[JUPITER] = CONV(jupiter, 0.01298);
    vc[SATURN]  = CONV(saturn,  0.01756);
    vc[URANUS]  = CONV(uranus,  0.02490);
    vc[NEPTUNE] = CONV(neptune, 0.03121);
    vc[PLUTO]   = CONV(pluto,   0.03461);

    // 赤道座標を求める
    for (int i = SUN; i <= PLUTO; ++i) {
        Vec3 v(vc[i]);
        // 瞬時の平均赤道座標を求める
        if (i == MOON) {
            // 視黄道座標を平均赤道座標に補正する
            acoord.conv_tc2tq(v);
            acoord.conv_tq2q(v);

            // 地心座標を測心座標に変換する
            double r = 6378140 / (Pm * DD2RAD); // 地球赤道半径 / 地平視差 == 月までの距離[m]
            v *= r;
            v -= acoord.getQLocation();

            // 単位ベクトル化する
            v.setDirectionCosines();
        }
        else
            acoord.conv_c2q(v);
        vq[i] = v;
        // J2000.0の赤道座標を求める
        acoord.conv_q2j(v);
        vj[i] = v;
    }
}
//------------------------------------------------------------------------
// 太陽の位置(平均黄経、地心距離)を計算する
// @param T J2000.0からのユリウス世紀[TDT]
// @param l 瞬時の平均春分点による黄経(光行差補正なし)
//			 ※光行差補正には -0.00569度 加算すれば良い
// @param r 地心距離[AU]
void
Planets::calc_sun(double T, Degree& l, double& r)
{
	l = DEG(sunL);
	r = SUMR(sunR);
}

//------------------------------------------------------------------------
#ifdef TEST
int main()
{
    Planets pl;
    Jday dd(0);
    char buf[256];
    int y, m=1, d=0;
    fputs("input y.m.d [TDT 0h]\n",stderr);
    while (gets(buf)) {
        if (sscanf(buf, "%d.%d.%d.%d", &y, &m, &d) < 3)
            continue;
        dd.setGdate(y, m, d);
        AstroTime atime(dd, -31-32.184);
        pl.calc(atime);
    }
    return EXIT_SUCCESS;
}
/*
1991.5.24
SUN:  L=62.35109377 R=1.01256784
MOON: L=191.20472784 B=-5.06906236 P=0.93588661
conv: l=321.23875670 b=-6.99444806 r=0.40761082
conv: l=184.61075748 b=3.22869300 r=0.72038002
conv: l=148.90626257 b=1.82425842 r=1.66473231
conv: l=137.74552429 b=0.79180431 r=5.32806686
conv: l=301.54231414 b=-0.34483677 r=9.97172726
conv: l=281.34882372 b=-0.35490606 r=19.47043026
conv: l=285.10627005 b=0.79262538 r=30.19843774
conv: l=229.09017978 b=15.10813030 r=29.66418493
*/
#endif
//. planets.cpp - ends.
