j main
x: push %ebp
mov %esp,%ebp
lw $s0, 0($sp)
addi $sp, $sp,4
lw $s1, 0($sp)
addi $sp, $sp,4
add $s2,$s1,$s0
addi $sp, $sp,-4
sw $s2,0($sp)
ret
mov %ebp, %esp
pop %ebp
ret
main: push %ebp
mov %esp,%ebp
movl $8, %eax
push %eax
lw $s0, 0($sp)
sw $s0, 0($108)
movl $1, %eax
push %eax
lw $s0, 0($sp)
addi $sp, $sp,4
lw $s1, 0($sp)
addi $sp, $sp,4
add $s2,$s1,$s0
addi $sp, $sp,-4
sw $s2,0($sp)
lw $s0, 0($sp)
sw $s0, 0($108)
movl $1, %eax
push %eax
lw $s0, 0($sp)
addi $sp, $sp,4
li $1,-1
mul $s2,$s1,$s0
addi $sp, $sp,-4
sw $s2,0($sp)
lw $t0, 0(123)
movl $t0,$a0
lw $t0, 0(-1)
movl $t0,$a1
jal x
push res
lw $s0, 0($sp)
sw $s0, 0($108)
movl $2, %eax
push %eax
lw $s0, 0($sp)
addi $sp, $sp,4
lw $s1, 0($sp)
addi $sp, $sp,4
mul $s2,$s1,$s0
addi $sp, $sp,-4
sw $s2,0($sp)
ret
mov %ebp, %esp
pop %ebp
ret

