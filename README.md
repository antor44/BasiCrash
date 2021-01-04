# BasiCrash


            ___            __              
           | o ) _   _ () / _| _  _   _ || 
           | o \/o\ (c'||( (_ /_|/o\ (c'| \
           |___/\_,]\_)L| \__|L| \_,]\_)Ln|


BasiCrash is a free MSX Basic game, a new old school arcade game developed with default Basic, no assembly, and in monochrome text mode (SCREEN 0). 


Game buttons: 
Up/DOWN - move, Enter - play or restart


Requirements:

-MSX 1/2/2+ Europe or USA BIOS


For MSX turbo R Europe or USA BIOS add this Basic line:

5 DEFUSR=39+PEEK(-2385)+PEEK(-2384)*256:IFUSR(0)THENLINE>0COPY0&H80F6OR384ALLYOURBASEAREBELONGTOUS!

.

basicra0.bas: basic version with VPOKE/VPEEK, less than 1 Kbyte

basicra1.bas: basic version with arrays, more compatible with other BASIC

basicra2.bas: basic version with VPOKE/VPEEK and arrays

basicra3.bas: enhanced version, more specialized MSX Basic instructions

basicra4.bas: enhanced version with lives and extra lives


basicras.bas: version 4 MSX Basic tokenized

basicr.cas: version 4 CAS file

basicras.rom: version 4 ROM file (MSX Basic)

