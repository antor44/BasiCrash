# BasiCrash

.    ___            __              
.   | o ) _   _ () / _| _  _   _ || 
.   | o \/o\ (c'||( (_ /_|/o\ (c'| \
.   |___/\_,]\_)L| \__|L| \_,]\_)Ln|


BasiCrash MSX Basic game, only text mode (SCREEN 0)


Game buttons: 
Up/DOWN - move, Enter - play or restart


Requirements:

-MSX 1/2/2+ Europe or USA BIOS


For MSX turbo R Europe or USA BIOS add this Basic line:

5 DEFUSR=39+PEEK(-2385)+PEEK(-2384)*256:IFUSR(0)THENLINE>0COPY0&H80F6OR384ALLYOURBASEAREBELONGTOUS!

.

basicrash0.bas: basic version with VPOKE/VPEEK, less than 1 Kbyte

basicrash1.bas: basic version with arrays, more compatible with other BASIC

basicrash2.bas: basic version with VPOKE/VPEEK and arrays

basicrash3.bas: enhanced version, more specialized MSX Basic instructions

basicrash4.bas: enhanced version with lives and extra lives


basicras.bas: version 4 MSX Basic tokenized

BasiCrash: version 4 CAS file

BasiCrash.rom: version 4 Basic ROM file

