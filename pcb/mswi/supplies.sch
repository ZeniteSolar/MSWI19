EESchema Schematic File Version 4
LIBS:main-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Regulator_Linear:LM7805_TO220 U501
U 1 1 5A007B62
P 5900 3950
AR Path="/5AACFFEF/5A007B62" Ref="U501"  Part="1" 
AR Path="/5DDD6AD9/5A007B62" Ref="U?"  Part="1" 
AR Path="/5DDDDD89/5A007B62" Ref="U?"  Part="1" 
F 0 "U?" H 5750 4075 50  0000 C CNN
F 1 "LM7805" H 5900 4100 50  0000 L CNN
F 2 "KicadZeniteSolarLibrary18:TO-220-3_Horizontal_TabDown_SMD" H 5900 4175 50  0001 C CIN
F 3 "https://www.sparkfun.com/datasheets/Components/LM7805.pdf" H 5900 3900 50  0001 C CNN
	1    5900 3950
	1    0    0    -1  
$EndComp
Text HLabel 3400 4800 0    60   Input ~ 0
GND_IN
Text HLabel 7300 3950 2    60   Output ~ 0
+5V_OUT
$Comp
L Device:CP1_Small C501
U 1 1 5A008895
P 4900 4400
AR Path="/5AACFFEF/5A008895" Ref="C501"  Part="1" 
AR Path="/5DDD6AD9/5A008895" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5A008895" Ref="C?"  Part="1" 
F 0 "C?" H 4910 4470 50  0000 L CNN
F 1 "1uF" H 4910 4320 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-6032-20_AVX-F_Pad2.25x2.35mm_HandSolder" H 4900 4400 50  0001 C CNN
F 3 "" H 4900 4400 50  0001 C CNN
	1    4900 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C502
U 1 1 5A00899A
P 5200 4400
AR Path="/5AACFFEF/5A00899A" Ref="C502"  Part="1" 
AR Path="/5DDD6AD9/5A00899A" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5A00899A" Ref="C?"  Part="1" 
F 0 "C?" H 5210 4470 50  0000 L CNN
F 1 "100nF" H 5210 4320 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5200 4400 50  0001 C CNN
F 3 "" H 5200 4400 50  0001 C CNN
	1    5200 4400
	1    0    0    -1  
$EndComp
Text HLabel 3400 3950 0    60   Input ~ 0
+18V_IN
$Comp
L Device:C_Small C503
U 1 1 5A00B18A
P 6650 4400
AR Path="/5AACFFEF/5A00B18A" Ref="C503"  Part="1" 
AR Path="/5DDD6AD9/5A00B18A" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5A00B18A" Ref="C?"  Part="1" 
F 0 "C?" H 6660 4470 50  0000 L CNN
F 1 "100nF" H 6660 4320 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6650 4400 50  0001 C CNN
F 3 "" H 6650 4400 50  0001 C CNN
	1    6650 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C504
U 1 1 5AAD0D5C
P 7000 4400
AR Path="/5AACFFEF/5AAD0D5C" Ref="C504"  Part="1" 
AR Path="/5DDD6AD9/5AAD0D5C" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5AAD0D5C" Ref="C?"  Part="1" 
F 0 "C?" H 7010 4470 50  0000 L CNN
F 1 "10uF" H 7010 4320 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-6032-20_AVX-F_Pad2.25x2.35mm_HandSolder" H 7000 4400 50  0001 C CNN
F 3 "" H 7000 4400 50  0001 C CNN
	1    7000 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:Fuse_Small F501
U 1 1 5AB12173
P 3700 3950
AR Path="/5AACFFEF/5AB12173" Ref="F501"  Part="1" 
AR Path="/5DDD6AD9/5AB12173" Ref="F?"  Part="1" 
AR Path="/5DDDDD89/5AB12173" Ref="F?"  Part="1" 
F 0 "F?" H 3700 3890 50  0000 C CNN
F 1 "500mA" H 3700 4010 50  0000 C CNN
F 2 "Fuse:Fuse_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3700 3950 50  0001 C CNN
F 3 "https://www.mouser.com/datasheet/2/643/0ZCJ_Nov2016-1132002.pdf" H 3700 3950 50  0001 C CNN
	1    3700 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4800 4900 4500
Connection ~ 4900 3950
Wire Wire Line
	5200 4500 5200 4800
Connection ~ 4900 4800
Connection ~ 5200 3950
Wire Wire Line
	6200 3950 6300 3950
Connection ~ 5200 4800
Wire Wire Line
	5900 4800 5900 4250
Wire Wire Line
	6650 4800 6650 4500
Connection ~ 5900 4800
Connection ~ 6650 3950
Wire Wire Line
	7000 3950 7000 4300
Wire Wire Line
	7000 4800 7000 4500
Connection ~ 6650 4800
Wire Wire Line
	4900 3950 4900 4300
Wire Wire Line
	3800 3950 4100 3950
Wire Wire Line
	4900 3950 5200 3950
Wire Wire Line
	4900 4800 5200 4800
Wire Wire Line
	5200 3950 5200 4300
Wire Wire Line
	5200 3950 5500 3950
Wire Wire Line
	5200 4800 5200 4900
Wire Wire Line
	5200 4800 5500 4800
Wire Wire Line
	5900 4800 6300 4800
Wire Wire Line
	6650 3950 7000 3950
Wire Wire Line
	6650 3950 6650 4300
Text HLabel 6650 3550 2    60   Input ~ 0
+18V_OUT
Wire Wire Line
	5200 3550 5200 3950
Wire Wire Line
	5200 3550 6650 3550
Connection ~ 5200 3550
Wire Wire Line
	5200 3450 5200 3550
$Comp
L power:PWR_FLAG #FLG0501
U 1 1 5BE75359
P 5200 3450
AR Path="/5AACFFEF/5BE75359" Ref="#FLG0501"  Part="1" 
AR Path="/5DDD6AD9/5BE75359" Ref="#FLG?"  Part="1" 
AR Path="/5DDDDD89/5BE75359" Ref="#FLG?"  Part="1" 
F 0 "#FLG?" H 5200 3525 50  0001 C CNN
F 1 "PWR_FLAG" H 5200 3650 50  0000 C CNN
F 2 "" H 5200 3450 50  0001 C CNN
F 3 "~" H 5200 3450 50  0001 C CNN
	1    5200 3450
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0502
U 1 1 5BE753AF
P 5200 4900
AR Path="/5AACFFEF/5BE753AF" Ref="#FLG0502"  Part="1" 
AR Path="/5DDD6AD9/5BE753AF" Ref="#FLG?"  Part="1" 
AR Path="/5DDDDD89/5BE753AF" Ref="#FLG?"  Part="1" 
F 0 "#FLG?" H 5200 4975 50  0001 C CNN
F 1 "PWR_FLAG" H 5200 5100 50  0000 C CNN
F 2 "" H 5200 4900 50  0001 C CNN
F 3 "~" H 5200 4900 50  0001 C CNN
	1    5200 4900
	-1   0    0    1   
$EndComp
Text HLabel 7300 4800 2    60   Output ~ 0
GND_OUT
Wire Wire Line
	7000 3950 7300 3950
Connection ~ 7000 3950
Wire Wire Line
	6650 4800 7000 4800
Connection ~ 7000 4800
Wire Wire Line
	7000 4800 7300 4800
Wire Wire Line
	3400 3950 3600 3950
Wire Wire Line
	4050 4800 4100 4800
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5D9E3E7E
P 3850 4700
AR Path="/5AACFFEF/5D9E3E7E" Ref="Q?"  Part="1" 
AR Path="/5DDD6AD9/5D9E3E7E" Ref="Q?"  Part="1" 
AR Path="/5DDDDD89/5D9E3E7E" Ref="Q?"  Part="1" 
F 0 "Q?" V 3400 4600 50  0000 C CNN
F 1 "Q_NMOS_GSD" V 3750 4450 50  0000 C CNN
F 2 "" H 4050 4800 50  0001 C CNN
F 3 "~" H 3850 4700 50  0001 C CNN
	1    3850 4700
	0    1    1    0   
$EndComp
Connection ~ 4100 4800
Wire Wire Line
	4100 4800 4900 4800
$Comp
L Device:R_Small R?
U 1 1 5D9E9D52
P 4100 4150
AR Path="/5AACFFEF/5D9E9D52" Ref="R?"  Part="1" 
AR Path="/5DDD6AD9/5D9E9D52" Ref="R?"  Part="1" 
AR Path="/5DDDDD89/5D9E9D52" Ref="R?"  Part="1" 
F 0 "R?" H 4200 4200 50  0000 L CNN
F 1 "1M" H 4200 4150 50  0000 L CNN
F 2 "" H 4100 4150 50  0001 C CNN
F 3 "~" H 4100 4150 50  0001 C CNN
	1    4100 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener_Small D?
U 1 1 5D9EA99D
P 4100 4600
AR Path="/5AACFFEF/5D9EA99D" Ref="D?"  Part="1" 
AR Path="/5DDD6AD9/5D9EA99D" Ref="D?"  Part="1" 
AR Path="/5DDDDD89/5D9EA99D" Ref="D?"  Part="1" 
F 0 "D?" V 4000 4700 50  0000 L CNN
F 1 "MMSZ5240BT1" V 4100 4700 50  0000 L CNN
F 2 "" V 4100 4600 50  0001 C CNN
F 3 "~" V 4100 4600 50  0001 C CNN
F 4 "10V" V 4200 4700 50  0000 L CNN "Voltage"
	1    4100 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 4250 4100 4400
Wire Wire Line
	4100 4050 4100 3950
Connection ~ 4100 3950
Wire Wire Line
	4100 3950 4900 3950
Wire Wire Line
	4100 4700 4100 4800
Wire Wire Line
	3850 4500 3850 4400
Wire Wire Line
	3850 4400 4100 4400
Connection ~ 4100 4400
Wire Wire Line
	4100 4400 4100 4500
Wire Wire Line
	3400 4800 3650 4800
$Comp
L Device:C_Small C?
U 1 1 5D9EFA18
P 5500 4400
AR Path="/5AACFFEF/5D9EFA18" Ref="C?"  Part="1" 
AR Path="/5DDD6AD9/5D9EFA18" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5D9EFA18" Ref="C?"  Part="1" 
F 0 "C?" H 5510 4470 50  0000 L CNN
F 1 "100nF" H 5510 4320 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5500 4400 50  0001 C CNN
F 3 "" H 5500 4400 50  0001 C CNN
	1    5500 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4500 5500 4800
Wire Wire Line
	5500 3950 5500 4300
Connection ~ 5500 3950
Wire Wire Line
	5500 3950 5600 3950
Connection ~ 5500 4800
Wire Wire Line
	5500 4800 5900 4800
$Comp
L Device:C_Small C?
U 1 1 5D9F17B7
P 6300 4400
AR Path="/5AACFFEF/5D9F17B7" Ref="C?"  Part="1" 
AR Path="/5DDD6AD9/5D9F17B7" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5D9F17B7" Ref="C?"  Part="1" 
F 0 "C?" H 6310 4470 50  0000 L CNN
F 1 "100nF" H 6310 4320 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6300 4400 50  0001 C CNN
F 3 "" H 6300 4400 50  0001 C CNN
	1    6300 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 4800 6300 4500
Wire Wire Line
	6300 3950 6300 4300
Connection ~ 6300 3950
Wire Wire Line
	6300 3950 6650 3950
Connection ~ 6300 4800
Wire Wire Line
	6300 4800 6650 4800
$EndSCHEMATC
