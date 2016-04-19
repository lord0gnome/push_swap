echo running push swap with params \(2 1 3 5 8 6\)
#./push_swap 2 1 3 5 8 6

MIN=0
MAX=12345
rnd= $(( $RANDOM % ($MAX + 1 - $MIN) + $MIN ))
echo $(rnd);
