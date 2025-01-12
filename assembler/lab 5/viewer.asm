.model tiny

.code 
org 100h


;----------------------------------------------------------------------
  


start: 
call reading_cmd
call Interface 
call clear_file
call open_file_write
fl: 
call clear_str
call record_string
jmp fl
call close_file




 
exit:
call open_file_read
read_loop:
    call read_file
    cmp ax, 0
    je done
    cmp buffer, 0Dh
jne read_loop
    inc count_string
jmp read_loop 



done: 
call close_file
call clear_str
mov ah,09h
mov dx,offset end_string
int 21h
  
  cmp count_string,10
  JAE foo 
  
    mov dx,word ptr count_string
    add dx,'0'
    mov ah, 2
    int 21h 
 cf:
int 20h     

foo:   
call conversion 
jmp cf 


close_error:
mov ah,09h
mov dx, offset error_close
int 21h
jmp cf 


open_error:
mov ah,09h
mov dx, offset error_open
int 21h
jmp cf 


write_error:
mov ah,09h
mov dx, offset error_write
int 21h
jmp cf


read_error:
mov ah,09h
mov dx, offset error_read
int 21h
jmp cf 
;----------------------------------------------------------------------   
    
open_file_write proc
mov ax,3D01h
mov dx,offset filename
int 21h
jc open_error
mov word ptr f_id,ax   
ret
open_file_write endp


close_file proc  
mov ah,3Eh
mov bx, word ptr f_id
int 21h
jc close_error    
ret 
close_file endp


record_string proc 
mov word ptr count_symbols,0
call input_string 
cmp al,1Bh
JE exit 
mov ah,40h
mov bx,word ptr f_id    
mov cx,word ptr count_symbols
mov dx, offset string
int 21h    
jc write_error
ret
record_string endp


input_string proc 
mov ah,09h
mov dx,offset input
int 21h   
lea di,string 
inp:
mov ah,01h
int 21h  
mov [di],al
inc di
inc count_symbols
cmp al,1Bh
JE exit_input  
cmp al,0Dh
JNE inp   
mov al, byte ptr endl
mov [di], al    
ret    


exit_input:
mov word ptr count_symbols,0
ret
input_string endp
 
 
 
clear_file proc
mov ah, 3Ch 
lea dx, filename 
int 21h 

mov ah, 3Eh 
mov bx, ax 
int 21h     
ret
clear_file endp 
 
clear_str proc 
mov ax,0600h
mov bh,07
mov cx,0
mov dx,050h    
int 10h    
ret   
clear_str endp

read_file proc
    mov ah, 3Fh
    mov bx, word ptr f_id
    lea dx, buffer
    mov cx, 1
    int 21h
    ret
read_file endp
    
    
    
open_file_read proc
mov ax,3D00h
mov dx,offset filename
int 21h
jc read_error
mov word ptr f_id,ax   
ret
open_file_read endp 

  
clear_console proc
mov ax,0600h
mov bh,07
mov cx,0
mov dx,184FH 
int 10h  
ret             
clear_console endp


interface proc
mov ah,02h
mov bh,0
mov dh,9
mov dl,27
int 10h  

mov ah,09h
mov dx,offset menu
int 21h  
 
mov ah,02h
mov bh,0
mov dh,0
mov dl,0
int 10h  
 
mov ah,01h
int 16h  
mov ah, 00h    
int 16h 

call clear_console
ret 
interface endp 

conversion proc
 xor cx,cx
 xor dx,dx
 mov ax,word ptr count_string
 cd:
 div num
 push dx
 inc cx
 cmp al,10
 JA cd
 push ax
 inc cx
 output:
 pop dx
 add dl,'0' 
 mov ah,02h
 int 21h 
 dec cx
 cmp cx,0
 JNE output     
 ret  
conversion endp  


reading_cmd proc
lea si,[0082h]
mov di,offset filename
read_cmd:
mov al,[si]
cmp al,0Dh
JNE continue_r
JE end_read_cmd
continue_r:
mov [di],al
inc di
inc si
jmp read_cmd 

end_read_cmd:
mov [di],0
mov [di+1],'$'
xor ax,ax
mov ah,09h
mov dx, offset filename
int 21h
ret
reading_cmd endp 
;------------------------------------------------------------------------

menu db '$',0dh,0ah
count_string dw 0
count_symbols dw 0
string db 100 DUP(?)
filename db 30 DUP(?)
f_id dw ? 
endl db 0Dh
buffer db ? 
end_string db 'Number of lines in file: $'
input db 'Add a line to the file: $'
num dw 10 
error_close db 'File closing error!$'
error_open db 'File opening error!$'
error_write db 'Write error!$'
error_read db 'Read error!$' 
end start   