EESchema Schematic File Version 4
LIBS:mswi-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3050 4800 0    60   Input ~ 0
GND_IN
Text HLabel 7300 3950 2    60   Output ~ 0
+5V_OUT
$Comp
L Device:C_Small C601
U 1 1 5A008895
P 4900 4400
AR Path="/5AACFFEF/5A008895" Ref="C601"  Part="1" 
AR Path="/5DDD6AD9/5A008895" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5A008895" Ref="C?"  Part="1" 
F 0 "C601" H 4910 4470 50  0000 L CNN
F 1 "1uF" H 4910 4320 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4900 4400 50  0001 C CNN
F 3 "" H 4900 4400 50  0001 C CNN
	1    4900 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C602
U 1 1 5A00899A
P 5200 4400
AR Path="/5AACFFEF/5A00899A" Ref="C602"  Part="1" 
AR Path="/5DDD6AD9/5A00899A" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5A00899A" Ref="C?"  Part="1" 
F 0 "C602" H 5210 4470 50  0000 L CNN
F 1 "100nF" H 5210 4320 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5200 4400 50  0001 C CNN
F 3 "" H 5200 4400 50  0001 C CNN
	1    5200 4400
	1    0    0    -1  
$EndComp
Text HLabel 3050 3950 0    60   Input ~ 0
+18V_IN
$Comp
L Device:C_Small C605
U 1 1 5A00B18A
P 6650 4400
AR Path="/5AACFFEF/5A00B18A" Ref="C605"  Part="1" 
AR Path="/5DDD6AD9/5A00B18A" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5A00B18A" Ref="C?"  Part="1" 
F 0 "C605" H 6660 4470 50  0000 L CNN
F 1 "100nF" H 6660 4320 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6650 4400 50  0001 C CNN
F 3 "" H 6650 4400 50  0001 C CNN
	1    6650 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C606
U 1 1 5AAD0D5C
P 7000 4400
AR Path="/5AACFFEF/5AAD0D5C" Ref="C606"  Part="1" 
AR Path="/5DDD6AD9/5AAD0D5C" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5AAD0D5C" Ref="C?"  Part="1" 
F 0 "C606" H 7010 4470 50  0000 L CNN
F 1 "10uF" H 7010 4320 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-6032-20_AVX-F_Pad2.25x2.35mm_HandSolder" H 7000 4400 50  0001 C CNN
F 3 "" H 7000 4400 50  0001 C CNN
	1    7000 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:Fuse_Small F601
U 1 1 5AB12173
P 3350 3950
AR Path="/5AACFFEF/5AB12173" Ref="F601"  Part="1" 
AR Path="/5DDD6AD9/5AB12173" Ref="F?"  Part="1" 
AR Path="/5DDDDD89/5AB12173" Ref="F?"  Part="1" 
F 0 "F601" H 3350 3890 50  0000 C CNN
F 1 "500mA" H 3350 4010 50  0000 C CNN
F 2 "Fuse:Fuse_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3350 3950 50  0001 C CNN
F 3 "https://www.mouser.com/datasheet/2/643/0ZCJ_Nov2016-1132002.pdf" H 3350 3950 50  0001 C CNN
F 4 "https://br.mouser.com/ProductDetail/Bel-Fuse/0ZCJ0050AF2E?qs=%2Fha2pyFadugaoNql5zaJPtCzxaRCuZne0%252BGltuyizoH09DOBIA3TDQ%3D%3D" H 3350 3950 50  0001 C CNN "Mouser"
F 5 "0ZCJ0050AF2E" H 3350 3950 50  0001 C CNN "Model"
	1    3350 3950
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
	3450 3950 3600 3950
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
$Comp
L power:PWR_FLAG #FLG0601
U 1 1 5BE75359
P 5200 3850
AR Path="/5AACFFEF/5BE75359" Ref="#FLG0601"  Part="1" 
AR Path="/5DDD6AD9/5BE75359" Ref="#FLG?"  Part="1" 
AR Path="/5DDDDD89/5BE75359" Ref="#FLG?"  Part="1" 
F 0 "#FLG0601" H 5200 3925 50  0001 C CNN
F 1 "PWR_FLAG" H 5200 4050 50  0000 C CNN
F 2 "" H 5200 3850 50  0001 C CNN
F 3 "~" H 5200 3850 50  0001 C CNN
	1    5200 3850
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0602
U 1 1 5BE753AF
P 5200 4900
AR Path="/5AACFFEF/5BE753AF" Ref="#FLG0602"  Part="1" 
AR Path="/5DDD6AD9/5BE753AF" Ref="#FLG?"  Part="1" 
AR Path="/5DDDDD89/5BE753AF" Ref="#FLG?"  Part="1" 
F 0 "#FLG0602" H 5200 4975 50  0001 C CNN
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
	3050 3950 3250 3950
Wire Wire Line
	4050 4800 4100 4800
$Comp
L Device:Q_NMOS_GSD Q601
U 1 1 5D9E3E7E
P 3850 4700
AR Path="/5AACFFEF/5D9E3E7E" Ref="Q601"  Part="1" 
AR Path="/5DDD6AD9/5D9E3E7E" Ref="Q?"  Part="1" 
AR Path="/5DDDDD89/5D9E3E7E" Ref="Q?"  Part="1" 
F 0 "Q601" V 4100 4700 50  0000 C CNN
F 1 "si2308cds" V 4200 4700 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4050 4800 50  0001 C CNN
F 3 "~" H 3850 4700 50  0001 C CNN
	1    3850 4700
	0    1    1    0   
$EndComp
Connection ~ 4100 4800
Wire Wire Line
	4100 4800 4900 4800
$Comp
L Device:R_Small R601
U 1 1 5D9E9D52
P 4100 4150
AR Path="/5AACFFEF/5D9E9D52" Ref="R601"  Part="1" 
AR Path="/5DDD6AD9/5D9E9D52" Ref="R?"  Part="1" 
AR Path="/5DDDDD89/5D9E9D52" Ref="R?"  Part="1" 
F 0 "R601" H 4200 4200 50  0000 L CNN
F 1 "1M" H 4200 4100 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4100 4150 50  0001 C CNN
F 3 "~" H 4100 4150 50  0001 C CNN
	1    4100 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener_Small D601
U 1 1 5D9EA99D
P 4100 4600
AR Path="/5AACFFEF/5D9EA99D" Ref="D601"  Part="1" 
AR Path="/5DDD6AD9/5D9EA99D" Ref="D?"  Part="1" 
AR Path="/5DDDDD89/5D9EA99D" Ref="D?"  Part="1" 
F 0 "D601" V 4000 4700 50  0000 L CNN
F 1 "MMSZ5240BT1" V 4100 4700 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" V 4100 4600 50  0001 C CNN
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
	4100 4700 4100 4800
Wire Wire Line
	3850 4500 3850 4400
Wire Wire Line
	3850 4400 4100 4400
Connection ~ 4100 4400
Wire Wire Line
	4100 4400 4100 4500
Wire Wire Line
	3050 4800 3600 4800
$Comp
L Device:C_Small C603
U 1 1 5D9EFA18
P 5500 4400
AR Path="/5AACFFEF/5D9EFA18" Ref="C603"  Part="1" 
AR Path="/5DDD6AD9/5D9EFA18" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5D9EFA18" Ref="C?"  Part="1" 
F 0 "C603" H 5510 4470 50  0000 L CNN
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
L Device:C_Small C604
U 1 1 5D9F17B7
P 6300 4400
AR Path="/5AACFFEF/5D9F17B7" Ref="C604"  Part="1" 
AR Path="/5DDD6AD9/5D9F17B7" Ref="C?"  Part="1" 
AR Path="/5DDDDD89/5D9F17B7" Ref="C?"  Part="1" 
F 0 "C604" H 6310 4470 50  0000 L CNN
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
Wire Wire Line
	5200 3850 5200 3950
Wire Wire Line
	4100 3950 4900 3950
Text Label 4400 3950 0    50   ~ 0
+18V
$Comp
L Device:D_TVS D602
U 1 1 5DD19DD4
P 3600 4400
F 0 "D602" V 3550 4600 50  0000 R CNN
F 1 "400W 24VDC" V 3650 4950 50  0000 R CNN
F 2 "Diode_SMD:D_SMA" H 3600 4400 50  0001 C CNN
F 3 "https://www.mouser.com/datasheet/2/445/824501241-952945.pdf" H 3600 4400 50  0001 C CNN
F 4 "https://br.mouser.com/ProductDetail/Wurth-Elektronik/824501241?qs=%2Fha2pyFadujZKBgF5S1ldkLPpipTn8KXCRHX4IsQDUlguH4XSGuxlw%3D%3D" V 3600 4400 50  0001 C CNN "Mouser"
	1    3600 4400
	0    -1   1    0   
$EndComp
Wire Wire Line
	3600 4250 3600 3950
Connection ~ 3600 3950
Wire Wire Line
	3600 3950 4100 3950
Wire Wire Line
	3600 4550 3600 4800
Connection ~ 3600 4800
Wire Wire Line
	3600 4800 3650 4800
Text Notes 3400 5350 0    39   ~ 0
TVS:\nhttps://m.littelfuse.com/~~/media/electronics/application_notes/littelfuse_tvs_diode_overview_application_note.pdf.pdf
$Comp
L Regulator_Linear:LM1117-5.0 U601
U 1 1 5DA67007
P 5900 3950
F 0 "U601" H 5900 4250 50  0000 C CNN
F 1 "LM1117-5.0" H 5900 4150 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 5900 3950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 5900 3950 50  0001 C CNN
	1    5900 3950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
