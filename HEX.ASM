;BCD to HEX Conversion
.model small
;**************************DATA********************************

.data
        ans1 dw 0
        h   dw 10000
        ans dw 0
      

        divisor dw 10

        menu db 10,13,09,'***********MENU***********',10,13,'$'
        m1   db 10,13,09,'1.BCD to HEX Conversion',10,13,'$'
        m2   db 10,13,09,'2.HEX to BCD Conversion',10,13,'$'
        m3   db 10,13,09,'3.Exit ',10,13,'$'

        m0  db 10,13,'               Enter Your Chioce  $'
        op  db ?

        msg db 10,13,'Enter the 5 digit BCD no.( <=65535 ) $',10,13
        mg1 db 10,13,'Enter the 4 digit HEX no. $',10,13
        new_line db 10,13,'$'        ;For new line
        mg2 db 10,13,'the Equivalent HEX no. is = $'
        mg3 db 10,13,'Invalid BCD number Enter again$',10,13
        mg4 db 10,13,'Invalid HEX number Enter again$',10,13
        default db 10,13,'Pls enter the valid choise$'
        mg5 db 10,13,'the Equivalent BCD no. is = $'



;**************************MACRO******************************

mess macro m1
        push ax
        push dx        

        lea dx,m1
        mov ah,09h
        int 21h

        pop dx
        pop ax
endm

;*************************CODE***********************************

.code 

main :  mov ax,@data
        mov ds,ax

up:     mess new_line
        mess menu
        mess m1
        mess m2
        mess m3
        mess new_line
        mess m0
        
        mov ah,01h
        int 21h
        mov op,al

case_1: cmp op,'1'
        jne case_2
                mess new_line
                mess msg
                call value_bcd
                call disply

        jmp up
case_2: cmp op,'2'
        jne case_3
                mess new_line
                mess mg1
                call value_hex
                call disply1
        jmp up
case_3: cmp op,'3'
        je end1
        mess default
        jmp up
end1:   mov ah,4ch
        int 21h
;*******************************************************************
disply proc

        mess new_line
        mess mg2

        mov ch,04h
        mov cl,04h

up4  :  rol ans1,CL
        mov BX,ans1
        and BX,000Fh
        mov DL,BL
        call hex_asc
        mov AH,02h
        int 21h
        dec CH
        jnz up4
        ret
disply endp
;**************************************************************************
 disply1 PROC
        mess new_line
        mess mg5
         mov cl,05
         mov BX,10000
up6:     mov AX,ans
         mov DX,0000h
         div BX
         mov ans,DX
         mov DL,AL

         call hex_asc
         mov ah,2
         int 21h
         mov AX,BX
         mov DX,0000h
         div divisor
         mov BX,AX
         dec CL
         jnz up6

         ret
disply1 endp
;**************************************************************************
 value_hex  proc
        mov cl,04
        mov ch,04

      
        jmp up5
below1: mess mg4    ;Call to Macro

up5:    mov ah,01h  ;input no.
        int 21h

        cmp AL,'0'
        jb d1

        cmp AL,'9'
        jbe next

        cmp AL,'A'
        jb d1

        cmp AL,'F'
        jbe here

        cmp AL,'a'
        jb d1

        cmp AL,'f'
        ja d1

        sub AL,57h
        jmp d2

here  : sub AL,37h
        jmp d2

next  : sub AL,30h
        jmp d2

d1    : jmp below1

d2    : rol ans,CL
        mov AH,00
        add ans,AX
        dec CH
        jnz up5
        ret
value_hex endp
;**************************************************************************
hex_asc proc
         cmp DL,09
         jbe next1
         add DL,37h
         jmp down1

next1:   add DL,30h

down1:   ret

hex_asc endp
;*************************PROCEDURE************************************
value_bcd proc
        mov ans1,0
        mov h,10000
        mov ch,05h
        jmp up3

        mess new_line

below:  mess mg3    ;Call to Macro
        
up3:    
        mov ah,01h  ;input no.
        int 21h
        cmp al,'0'  ;compare it with 0
        jb below
        cmp al,'9'
        ja below
        sub al,30h  ;ASSCI to hex conversion

store:  mov ah,00h
        mul h
        add ans1,ax

down:   mov ax,h
        mov dx,0
        div divisor
        mov h,ax

        dec ch
        jnz up3

        ret
value_bcd  ENDP
;*******************************Precedure End*******************

end main
