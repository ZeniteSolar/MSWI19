EESchema Schematic File Version 4
LIBS:main-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3100 3500 0    60   BiDi ~ 0
CAN_H
Text HLabel 3100 3600 0    60   BiDi ~ 0
CAN_L
Text HLabel 3100 3400 0    60   Output ~ 0
CAN_18V
Text HLabel 3100 3700 0    60   BiDi ~ 0
CAN_GND
Wire Wire Line
	5950 3950 5950 3900
Wire Wire Line
	5000 3600 5550 3600
Wire Wire Line
	5550 3700 5000 3700
Wire Wire Line
	5000 3400 5450 3400
Text Label 5000 3400 0    60   ~ 0
CAN_18V
Text Label 5000 3500 0    60   ~ 0
CAN_GND
Text Label 5000 3600 0    60   ~ 0
CAN_L
Text Label 5000 3700 0    60   ~ 0
CAN_H
$Comp
L Connector:RJ45_Shielded J501
U 1 1 5BE6C2F7
P 5950 3400
AR Path="/5AAD16DD/5BE6C2F7" Ref="J501"  Part="1" 
AR Path="/5DDDDD74/5BE6C2F7" Ref="J?"  Part="1" 
F 0 "J501" H 6150 3950 50  0000 C CNN
F 1 "RJ45" H 5800 3950 50  0000 C CNN
F 2 "KicadZeniteSolarLibrary18:RJ45_YH59_01" H 5950 3400 50  0001 C CNN
F 3 "" H 5950 3400 50  0001 C CNN
	1    5950 3400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5550 3000 5450 3000
Wire Wire Line
	4950 3000 4950 3500
Wire Wire Line
	4950 3950 5950 3950
Wire Wire Line
	5550 3100 5450 3100
Wire Wire Line
	5450 3100 5450 3000
Connection ~ 5450 3000
Wire Wire Line
	5450 3000 4950 3000
Wire Wire Line
	5550 3200 5450 3200
Wire Wire Line
	5550 3300 5450 3300
Wire Wire Line
	5450 3300 5450 3400
Connection ~ 5450 3400
Wire Wire Line
	5450 3400 5550 3400
Wire Wire Line
	4950 3500 5550 3500
Connection ~ 4950 3500
Wire Wire Line
	4950 3500 4950 3950
Text Label 3200 3400 0    60   ~ 0
CAN_18V
Wire Wire Line
	3100 3400 3200 3400
Text Label 3200 3600 0    60   ~ 0
CAN_L
Text Label 3200 3500 0    60   ~ 0
CAN_H
Wire Wire Line
	3100 3500 3200 3500
Wire Wire Line
	3200 3600 3100 3600
Wire Wire Line
	3100 3700 3200 3700
Wire Wire Line
	5450 3200 5450 3100
Connection ~ 5450 3100
Text Label 3200 3700 0    60   ~ 0
CAN_GND
$EndSCHEMATC
