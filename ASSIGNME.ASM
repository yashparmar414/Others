
;ASSIGNMENT NO. 1: ADDTION OF N NUMBERS USING ARRAY

;Addition of two digit nos

ASSUME CS:CODE,DS:DATA

DATA SEGMENT
M1 DB 10,13, "ENTER TWO DIGIT NO: $"
M2 DB 10,13, "ADDITION IS: $"
ARR DB 05 DUP(?)
DATA ENDS

CODE SEGMENT
        START:
                MOV AX,DATA
                MOV DS,AX

                DISP MACRO M
                LEA DX,M

                MOV AH,09H
                INT 21H

                ENDM

                MOV SI,OFFSET ARR
                MOV CH,05H
                MOV BH,00H
                MOV CL,04H

             L1:DISP M1

                MOV AH,01H
                INT 21H
                CALL ATOH
                ROL AL,CL
                MOV BL,AL

                MOV  AH,01H
                INT 21H
                CALL ATOH
                ADD BL,AL
                ADD BH,BL
                MOV [SI],BH
                INC SI
                DEC CH
                JNZ L1

                DEC SI
                MOV BL,[SI]
                DISP M2
                MOV CL,04H

                AND BL,0F0H
                ROR BL,CL
                MOV DL,BL
                CALL HTOA
                MOV AH,02H
                INT 21H

                MOV BL,[SI]
                AND BL,0FH
                MOV DL,BL
                CALL HTOA
                MOV AH,02H
                INT 21H

                MOV AH,4CH
                INT 21H
                
                ATOH PROC NEAR
                CMP AL,39H
                JLE L2
                SUB AL,07H
                L2:SUB AL,30H
                RET
                ENDP

                HTOA PROC NEAR
                CMP DL,09H
                JLE L3
                ADD DL,07H
                L3:ADD DL,30H
                RET
                ENDP

                Code ends
                end START



.........................OUTPUT...........................
C:\Tasm>tasm assignment1.asm
Turbo Assembler  Version 2.0  Copyright (c) 1988,

Assembling file:   assignment1.asm
Error messages:    None
Warning messages:  None
Passes:            1
Remaining memory:  474k

C:\Tasm>tlink assignment1
Turbo Link  Version 3.0 Copyright (c) 1987, 1990 Borland International
Warning: No stack

C:\Tasm>assignment1.exe

ENTER TWO DIGIT NO: 10
ENTER TWO DIGIT NO: 11
ENTER TWO DIGIT NO: 13
ENTER TWO DIGIT NO: 12
ENTER TWO DIGIT NO: 14
ADDITION IS:60
C:\Tasm>
