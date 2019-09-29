.name       "Batman"
.comment    "This city needs me"

lo*op:
        sti r1, %:live, %1
live:
        live %0
        ld %0, r2
        zjmp %:loop