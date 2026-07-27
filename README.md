# Flight-controller
A custom Flight controller to control a rocket with TVC! It uses a STM32 and other peripherals like power management, battery charging etc. to make it a fully functional controller, with LiPo support.
This is my schematic<img width="1141" height="802" alt="{1A992728-89DA-410E-9264-2D571C69BAF3}" src="https://github.com/user-attachments/assets/ee1ede57-6263-442d-87c6-f4aafa6e4ed2" />
This is how my PCB looks:<img width="1318" height="811" alt="{BEE2E16C-D04B-4341-9590-978375379D45}" src="https://github.com/user-attachments/assets/7cf78789-8697-4d41-a311-7beb763c49dd" />
This how my Assembled PCB is supposed to look like:<img width="1036" height="694" alt="{85D26635-DA95-49A9-963A-9BCFD05A4956}" src="https://github.com/user-attachments/assets/94ed3190-c967-41f2-9ed7-63dc1e4416d7" />
<img width="1326" height="722" alt="{B8652330-A4F8-4AD3-A79F-0697AFAC499F}" src="https://github.com/user-attachments/assets/4ee12aba-9fc1-4613-915f-72458a3b8e2b" />
This is my BoM (also in a .csv file in the repo): 
| Designator | Footprint | Value | LCSC Part # | Generic Name | Qty | Source | Unit Price ($) | Product Link | Total ($) |
|------------|-----------|-------|-------------|--------------|-----|--------|----------------|--------------|-----------|
| C1 | 0402 | 47 nF | C82219 | Capacitors | 20 | JLCPCB | 0.068 | https://jlcpcb.com/partdetail/83376-0402B473K500NT/C82219 | 1.36 |
| C2, C3 | 0402 | 22 uF | C15525 | Capacitors | 20 | JLCPCB | 0.394 | https://jlcpcb.com/partdetail/16204-CL05A106MQ5NUNC/C15525 | 7.88 |
| C4 | 0805 | 10 uF | C124129 | Capacitors | 5 | JLCPCB | 1.0915 | https://jlcpcb.com/partdetail/125403-GRM21BR61A476ME15L/C124129 | 5.46 |
| C10, C11, C16, C17, C9 | 0805 | 100 nF | C45783 | Capacitors | 18 | JLCPCB | 2.1114 | https://jlcpcb.com/partdetail/46786-CL21A226MAQNNNE/C45783 | 38.00 |
| C12, C13, C14, C5, C8 | 0805 | 10 uF | C440198 | Capacitors | 10 | JLCPCB | 0.912 | https://jlcpcb.com/partdetail/439567-GRM21BR61H106KE43L/C440198 | 9.12 |
| C15, C18–C21, C26, C28–C32, C7 | 0402 | 20 pF | C1525 | Capacitors | 34 | JLCPCB | 0.204 | https://jlcpcb.com/partdetail/1877-CL05B104KO5NNNC/C1525 | 6.94 |
| C22, C23 | 0402 | 6.8 pF | C1554 | Capacitors | 20 | JLCPCB | 0.066 | https://jlcpcb.com/partdetail/1906-0402CG200J500NT/C1554 | 1.32 |
| C24, C25 | 0402 | 2.2 uF | C1576 | Capacitors | 20 | JLCPCB | 0.048 | https://jlcpcb.com/partdetail/1928-0402CG6R8C500NT/C1576 | 0.96 |
| C27 | 0402 | 1 uF | C12530 | Capacitors | 20 | JLCPCB | 0.154 | https://jlcpcb.com/partdetail/13164-CL05A225MQ5NSNC/C12530 | 3.08 |
| C33–C36, C6 | 0402 | 44 uF | C52923 | Capacitors | 20 | JLCPCB | 0.282 | https://jlcpcb.com/partdetail/53938-CL05A105KA5NQNC/C52923 | 5.64 |
| CARD1 | SMD | TF‑01A | C91145 | SD Card Slot | 2 | JLCPCB | 0.3802 | https://jlcpcb.com/partdetail/Korean_HropartsElec-TF01A/C91145 | 0.76 |
| D1 | 0805 | LED | C2293 | LED | 20 | JLCPCB | 0.244 | https://jlcpcb.com/partdetail/Hubei_KENTOElec-KT0805B/C2293 | 4.88 |
| J1 | 插件,P=2.54mm | Screw_Terminal_01x02 | C557685 | Screw Terminal | 2 | JLCPCB | 0.48 | https://jlcpcb.com/partdetail/Ningbo_Xinlaiya_Elec-XY308_2_542P/C557685 | 0.96 |
| L1 | 1210 | 1 uH | C99412 | Inductor | 6 | JLCPCB | 0.696 | https://jlcpcb.com/partdetail/100626-CMI322513U1R0KT/C99412 | 4.18 |
| L2 | 1008 | 1.5 uH | C5289259 | Inductor | 6 | JLCPCB | 0.2256 | https://jlcpcb.com/partdetail/XR-XRNR252010_1_5uHN/C5289259 | 1.35 |
| L3 | 1210 | 5.6 uH | C87563 | Inductor | 6 | JLCPCB | 0.2748 | https://jlcpcb.com/partdetail/TDK-NLV32T_5R6JPF/C87563 | 1.65 |
| L4 | 0603 | FCM1608KF‑601T03 | C141723 | Ferrite Bead | 20 | JLCPCB | 0.202 | https://jlcpcb.com/partdetail/TAITECH-FCM1608KF601T03/C141723 | 4.04 |
| R1, R2 | 0402 | 5.1K | C25905 | Resistors | 20 | JLCPCB | 0.018 | https://jlcpcb.com/partdetail/26648-0402WGF5101TCE/C25905 | 0.36 |
| R9 | 0201 | 30.1K | C320818 | Resistors | 20 | JLCPCB | 0.012 | https://jlcpcb.com/partdetail/301723-RC01W3012FT/C320818 | 0.24 |
| R10 | 0201 | 383 | C423551 | Resistors | 20 | JLCPCB | 0.012 | https://jlcpcb.com/partdetail/416501-0201WMF3830TEE/C423551 | 0.24 |
| R11 | 0201 | 5.23K | C332546 | Resistors | 20 | JLCPCB | 0.022 | https://jlcpcb.com/partdetail/RALEC-RTT015231FTH/C332546 | 0.44 |
| R12–R22 | 0201 | 10K | C7467266 | Resistors | 40 | JLCPCB | 0.032 | https://jlcpcb.com/partdetail/FOJAN-FRC0201J103TS/C7467266 | 1.28 |
| R14 | 0805 | 100K | C149504 | Resistors | 20 | JLCPCB | 0.064 | https://jlcpcb.com/partdetail/160838-0805W8F1003T5E/C149504 | 1.28 |
| R15 | 0201 | 22.1K | C384418 | Resistors | 20 | JLCPCB | 0.02 | https://jlcpcb.com/partdetail/Walsin_TechCorp-WR02X2212FAL/C384418 | 0.40 |
| SW1, SW2 | SMD, 4x3mm | TS‑1088‑AR02016 | C720477 | Switches | 8 | JLCPCB | 0.4408 | https://jlcpcb.com/partdetail/XUNPU-TS_1088AR02016/C720477 | 3.53 |
| U1 | VQFN‑24‑EP(4x4) | BQ25883RGER | C544362 | Battery Management | 2 | JLCPCB | 8.189 | https://jlcpcb.com/partdetail/TexasInstruments-BQ25883RGER/C544362 | 16.38 |
| U2 | VQFN‑15‑HR(2.5x3) | TPS63070RNMR | C109322 | Buck Converter (5V) | 2 | JLCPCB | 2.6384 | https://jlcpcb.com/partdetail/TexasInstruments-TPS63070RNMR/C109322 | 5.28 |
| U3 | SOT‑23‑6‑THIN | LMR51430 | C5219261 | Buck Converter | 2 | JLCPCB | 1.73 | https://jlcpcb.com/partdetail/TexasInstruments-LMR51430YFDDCR/C5219261 | 3.46 |
| U4 | LGA‑10(2x2) | BMP580 | C22391138 | Barometer | 2 | JLCPCB | 2.6674 | https://jlcpcb.com/partdetail/BoschSensortec-BMP580/C22391138 | 5.33 |
| U5 | LGA‑14(3x2.5) |
| **Grand Total** |  |  |  |  |  |  |  |  | **206.47** |

[bom.csv](https://github.com/user-attachments/files/29258043/bom.csv)

