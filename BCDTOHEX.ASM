.model small
;**************************DATA********************************

.data
        ans1 dw 0
        h   dw 10000
	divisor dw 10       
        msg db 10,13,'Enter the 5 digit BCD no.( <=65535 ) $',10,13
        new_line db 10,13,'$'        ;For new line
        mg2 db 10,13,'The Equivalent HEX no. is = $'
        mg3 db 10,13,'Invalid BCD number Enter again$',10,13
        

;**************************MACRO******************************

mess macro m
        push ax
        push dx        

        lea dx,m
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
        mess msg
	call value_bcd
        call disply

        ;jmp up
	mov ah,4ch
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
;*******************************Precedure End***************
end