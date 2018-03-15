.name "karima"
.comment "no comment"

start:
sti r1, %:l1, %1
start2:
ldi %:l1, %1, r1
sti r1, %:l2, %1
l1: live %93
fork %:l1
l2: live %93
st r2, -34
st r2, -36
