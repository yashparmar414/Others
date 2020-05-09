.model small
;**************************DATA********************************

.data
        ans1 dw 0
        h   dw 10000
        ans dw 0
      

        divisor dw 10

        mg1 db 10,13,'Enter the 4 digit HEX no. $',10,13
        new_line db 10,13,'$'        ;For new line
        mg4 db 10,13,'Invalid HEX number Enter again$',10,13
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

	mov ax,@data
        mov ds,ax

up:     
       
        mess new_line
        mess mg1
        call value_hex
        call disply1
        ;jmp up
	
	mov ah,4ch
        int 21h

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

END