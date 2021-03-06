#!/bin/bash

echo "Patmos MessagePasser 022 experiment"
echo -e "PPC\tWCRT"

for i in {1..9} {10..45..5} {50..90..10} {100..450..50} {500..1000..100}
do
	make wcet PROJECT=messagepasser_single_mem FUNCTION=timed_task PROGS_PER_CORE=$i T_DELAY_CYCLES=21 -B >/dev/null 2>/dev/null
	WCRT=$(cat messagepasser_single_mem_wcet_report.txt | grep '^  cycles:' | egrep -o '[0-9]+') 
	echo -e "$i\t$WCRT"
done