10 REM *** BasiCrash v. 4.04 ***
20 SCREEN 0,,0
30 DEFINT A-Z:DIM ST%(1),SB%(1)
40 RE=0:K=3:L=1:S=1:Q=0:J=0:Z=500
50 KEY OFF::GOSUB 2100:GOSUB 5000:GOSUB 6000
60 T$=INKEY$
70 IF T$<>CHR$(13) THEN 60
80 KEY 1,"SCORE":KEY3,"HIGH"
90 GOSUB 3500:KEY ON
100 CLS:KEY 2,STR$(RE+P):KEY 4,STR$(Z):GOSUB 2000:F=0:N=0
110 IF S<>1 OR J=1 GOTO 280
120 ERASE ST
130 DIM ST%(39,22)
160 FOR X=1 TO L*5
170 A=INT(RND(1)*38)+1:B=INT(RND(1)*22)+1
180 IF ST%(A,B)<>0 OR (ST%(A+1,B)=4 AND (ST%(A-1,B)=4 OR ST%(A,B-1)=4 OR ST%(A+1,B-1)=4)) GOTO 170 ELSE ST%(A,B)=6
190 A=INT(RND(1)*37)+2:B=INT(RND(1)*22)+1
200 IF ST%(A,B)<>0 OR (ST%(A-1,B)=6 AND (ST%(A-2,B)=4 OR ST%(A-1,B-1)=4 OR ST%(A,B-1)=4)) GOTO 190 ELSE ST%(A,B)=4
210 NEXT X
280 IF J=1 GOTO 340
290 ERASE SB
300 DIM SB%(39,22)
310 P=0
340 FOR Y=1 TO 22
350 FOR X=0 TO 39
360 VPOKE X+Y*40,ST%(X,Y)-SB%(X,Y)
370 NEXT X,Y
380 IF Q=1 THEN ON INTERVAL=45 GOSUB 3000:INTERVAL ON
400 IF S<>2 THEN VPOKE F,0
410 F=N:VPOKE N,190
420 FOR X=1 TO 110-L*10:NEXT X
430 T$=INKEY$
440 IF T$="" GOTO 470
450 IF T$=CHR$(31) AND N<880 THEN N=N+40
460 IF T$=CHR$(30) AND N>39 THEN N=N-40
470 N=N+1
480 IF N>919 THEN N=880
490 IF VPEEK(N)=6 THEN DEFUSR=&H90:A=USR(0):PLAY "l4o2t255A","l4o4t255G":P=P+1+Q*9:SB%(N-INT(N/40)*40,INT(N/40))=6 ELSE 530
500 IF RE+P>Z THEN Z=RE+P:KEY 4,STR$(Z)
510 IF (RE+P)/500=INT((RE+P)/500) THEN K=K+1:GOSUB 3500:PLAY "t255o5GAGA","t255o4BEBE"
520 KEY 2,STR$(RE+P):IF P=L*5 AND Q=0 THEN RE=RE+P:S=S+1:P=0:J=0:GOTO 100
530 IF VPEEK(N)<>4 GOTO 400
540 IF Q=1 THEN RE=RE+P:P=0:Q=0:S=S+1:INTERVAL OFF:GOSUB 1000:GOTO 100 ELSE GOSUB 1000:K=K-1:J=1
550 IF K>0 THEN GOSUB 3500:GOTO 100
560 RE=0:K=3:P=0:L=1:S=1:J=0
570 LOCATE 5,7,0:FOR X=1 TO 26:PRINT CHR$(200);:NEXT X
580 LOCATE 5,8,0:PRINT CHR$(200);"                        ";CHR$(200)
590 LOCATE 5,9,0:PRINT CHR$(200);"        GAME OVER       ";CHR$(200)
600 LOCATE 5,10,0:PRINT CHR$(200);"                        ";CHR$(200)
610 LOCATE 5,11,0:PRINT CHR$(200);" Press ENTER to restart ";CHR$(200)
620 LOCATE 5,12,0:PRINT CHR$(200);"                        ";CHR$(200)
630 LOCATE 5,13,0:FOR X=1 TO 26:PRINT CHR$(200);:NEXT X
640 DEFUSR=&H90:A=USR(0):PLAY "t255o3CDEABCo4c","t255o3EFGEFGo1g"
650 ON INTERVAL=10800 GOSUB 6000:INTERVAL ON
660 T$=INKEY$
670 IF T$=CHR$(13) THEN INTERVAL OFF:GOSUB 3500:GOTO 100 ELSE 660
1000 VPOKE F,15:SOUND 7,&B10110111:SOUND 8,16:SOUND 6,31:SOUND 12,25:SOUND 13,6
1010 FOR X=1 TO 10
1020 IF F-X*41>=0 THEN VPOKE F-X*39,29:VPOKE F-X*41,30:VPOKE F-X*40,22
1030 IF F-X>=0 THEN VPOKE F-X,23
1040 IF F+X*41<920 THEN VPOKE F+X*39,29:VPOKE F+X*41,30:VPOKE F+X*40,22
1050 IF F+X<920 THEN VPOKE F+X,23
1060 NEXT X
1070 FOR X=1 TO 300:NEXT:SOUND 13,1:FOR X=1 TO 300:NEXT
1080 RETURN
2000 IF S>2 AND L/2=INT(L/2) AND S=3 THEN Q=1
2010 IF S>2 AND Q=0 THEN L=L+1:S=1:J=0
2020 LOCATE 5,8,0:FOR X=1 TO 26:PRINT CHR$(200);:NEXT X
2030 LOCATE 5,9,0:PRINT CHR$(200);"                        ";CHR$(200)
2040 DEFUSR=&H90:A=USR(0):IF Q=0 THEN LOCATE 5,10,0:PRINT CHR$(200);"  LEVEL      STAGE      ";CHR$(200):PLAY "t120o5CDE","t120o5EFG" ELSE LOCATE 5,10,0:PRINT CHR$(200);"      BONUS  STAGE      ";CHR$(200):PLAY "t255o5EDCEDCEE","t255o5GFEGFEGG"
2050 LOCATE 5,11,0:PRINT CHR$(200);"                        ";CHR$(200)
2060 LOCATE 5,12,0:FOR X=1 TO 26:PRINT CHR$(200);:NEXT X
2070 IF Q=0 THEN LOCATE 13,10,0:PRINT L: LOCATE 24,10,0:PRINT S
2080 RETURN
2100 FOR X=0 TO 2:READ R%(X):NEXT X
2110 FOR Y=0 TO 2
2130 FOR X=0 TO 7:READ R$:VPOKE 2048+R%(Y)*8+X,VAL("&B"+R$):NEXT X
2140 NEXT Y
2150 DATA 4,190,6
2300 DATA 10000100
2310 DATA 01001000
2320 DATA 00110000
2330 DATA 11001100
2340 DATA 00110000
2350 DATA 01001000
2360 DATA 10000100
2370 DATA 00000000
2380 DATA 10000000
2390 DATA 01100000
2400 DATA 00111000
2410 DATA 00111100
2420 DATA 00111100
2430 DATA 00111000
2440 DATA 01100000
2450 DATA 10000000
2460 DATA 00000000
2470 DATA 00000000
2480 DATA 00110000
2490 DATA 01111000
2500 DATA 01111000
2510 DATA 00110000
2520 DATA 00000000
2530 DATA 00000000
2540 RETURN
3000 VPOKE INT(RND(1)*920),6
3010 V=INT(RND(1)*920):IF ABS(V-N)>5 THEN VPOKE V,4
3020 RETURN
3500 R$="":IF K=1 GOTO 3540
3510 FOR X=2 TO K
3520 R$=R$+CHR$(190)
3530 NEXT X
3540 KEY5,R$
3550 RETURN
5000 FOR X=0 TO 7:READ R%(X):NEXT X
5010 FOR Y=0 TO 7
5020 FOR X=0 TO 7:READ R$:VPOKE 2048+R%(Y)*8+X,VAL("&B"+R$):NEXT X
5030 NEXT Y
5040 DATA 224,225,226,227,228,229,230,231
5050 RETURN
5300 DATA 00000000
5310 DATA 00000000
5320 DATA 00000000
5330 DATA 01100100
5340 DATA 01100100
5350 DATA 01100100
5360 DATA 01100100
5370 DATA 01111100
5380 DATA 00000000
5390 DATA 00000000
5400 DATA 00000000
5410 DATA 11111000
5420 DATA 11111000
5430 DATA 10000000
5440 DATA 10000000
5450 DATA 11111000
5460 DATA 01111100
5470 DATA 00000100
5480 DATA 00000100
5490 DATA 01111100
5500 DATA 01111100
5510 DATA 00000000
5520 DATA 00000000
5530 DATA 00000000
5540 DATA 11111000
5550 DATA 10011000
5560 DATA 10011000
5570 DATA 10011000
5580 DATA 10011000
5590 DATA 00000000
5600 DATA 00000000
5610 DATA 00000000
5620 DATA 00000000
5630 DATA 00011100
5640 DATA 00111100
5650 DATA 01110000
5660 DATA 01100000
5670 DATA 11000000
5680 DATA 11000000
5690 DATA 11000100
5700 DATA 00000000
5710 DATA 11100000
5720 DATA 11110000
5730 DATA 00111000
5740 DATA 00111000
5750 DATA 01111100
5760 DATA 11101100
5770 DATA 11001100
5780 DATA 11001100
5790 DATA 11011100
5800 DATA 11111000
5810 DATA 01110000
5820 DATA 01110000
5830 DATA 00111100
5840 DATA 00011100
5850 DATA 00000000
5860 DATA 10001100
5870 DATA 00001100
5880 DATA 00001100
5890 DATA 00011000
5900 DATA 00111000
5910 DATA 11110000
5920 DATA 11100000
5930 DATA 00000000
6000 CLS
6010 DEFUSR=&H90:A=USR(0):PLAY "t255o5EDCEDCEEo2t255At120o5CDEt255o3CDEABCo4C","t255o5GFEGFEGGo4t255Gt120o5EFGt255o3EFGEFGo1G"
6020 LOCATE 12,7,0:PRINT "@antor44"
6030 LOCATE 12,9,0:PRINT "PRESENTS"
6040 LOCATE 28,8,0:PRINT " \__/"
6050 LOCATE 28,9,0:PRINT " /oo\"
6060 LOCATE 28,10,0:PRINT "| ";CHR$(224);CHR$(225);" |"
6070 LOCATE 28,11,0:PRINT "| ";CHR$(226);CHR$(227);" |"
6080 LOCATE 28,12,0:PRINT " \oo/"
6090 VPOKE 404,6:VPOKE 454,6:VPOKE 460,6:VPOKE 463,6
6100 VPOKE 493,6:VPOKE 501,6:VPOKE 310,6:VPOKE 345,6
6110 VPOKE 340,6:VPOKE 545,6:VPOKE 386,6:VPOKE 416,6
6120 VPOKE 583,6:VPOKE 698,6:VPOKE 307,6:VPOKE 707,6
6130 IF PLAY(1) THEN 6130
7000 FOR F=400 TO 465
7010 FOR X=1 TO 50:NEXT X
7020 VPOKE F-1,0:VPOKE F,190
7030 IF F=410 THEN VPOKE F,0:F=F+40
7040 IF F>459 THEN VPOKE 931-F,0:VPOKE 930-F,4
7050 NEXT F
7060 GOSUB 1000
8000 LOCATE 0,13,0
8010 PRINT "   ___            __ "
8020 PRINT "  | o ) _   _ () / _| _  _   _ ||"
8030 LOCATE 0,15,0:PRINT "  | o \/o\ (c'||( (_ /_|/o\ (c'| \"
8040 LOCATE 0,16,0:PRINT "  |___/\_,]\_)L| \__|L| \_,]\_)Ln|"
8050 LOCATE 5,19,0:PRINT "Press ENTER to   'em all"
8060 LOCATE 20,18,0:PRINT CHR$(228);CHR$(229)
8070 LOCATE 20,19,0:PRINT CHR$(230);CHR$(231)
8080 RETURN

