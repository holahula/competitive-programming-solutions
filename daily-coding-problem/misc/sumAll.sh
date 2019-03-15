# Sum the command line args 

#!/bin/bash
j=0

for i in "$@"
do
    j=$((j+i))
done

echo $j