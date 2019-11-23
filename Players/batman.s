.name       "Batman"
.comment    "This city needs"

loop:
        sti r1, %:live, %1w
live:
        live %0
        ld %0, r2
        zjmp %:loop
