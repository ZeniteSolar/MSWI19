EESchema Schematic File Version 4
LIBS:mswi-cache
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
Text HLabel 5500 3800 0    60   BiDi ~ 0
CAN_H
Text HLabel 5500 3900 0    60   BiDi ~ 0
CAN_L
Text HLabel 5500 3700 0    60   Output ~ 0
CAN_18V
Text HLabel 5500 4000 0    60   BiDi ~ 0
CAN_GND
Text Label 5600 3700 0    60   ~ 0
CAN_18V
Wire Wire Line
	5500 3700 5600 3700
Text Label 5600 3900 0    60   ~ 0
CAN_L
Text Label 5600 3800 0    60   ~ 0
CAN_H
Wire Wire Line
	5500 3800 5600 3800
Wire Wire Line
	5600 3900 5500 3900
Wire Wire Line
	5500 4000 5600 4000
Text Label 5600 4000 0    60   ~ 0
CAN_GND
$Comp
L Connector:Conn_01x04_Male J501
U 1 1 5DD7554D
P 6950 3900
F 0 "J501" H 7100 4100 50  0000 C CNN
F 1 "Conn_01x04_Male" H 7100 4100 50  0001 C CNN
F 2 "" H 6950 3900 50  0001 C CNN
F 3 "~" H 6950 3900 50  0001 C CNN
	1    6950 3900
	-1   0    0    1   
$EndComp
Text Label 6750 3700 2    60   ~ 0
CAN_18V
Text Label 6750 4000 2    60   ~ 0
CAN_GND
Text Label 6750 3800 2    60   ~ 0
CAN_L
Text Label 6750 3900 2    60   ~ 0
CAN_H
$EndSCHEMATC
