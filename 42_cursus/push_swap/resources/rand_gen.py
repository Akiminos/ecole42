#!/usr/bin/env python3

import sys
import random
if (len(sys.argv) != 2 and len(sys.argv) != 4):
	sys.exit("Wrong number of inputs")
if (str(sys.argv[1]) == "-h" or str(sys.argv[1]) == "--help"):
	print("Usage : generator.sh MIN_VALUE MAX_VALUE NBR_OF_VALUES")
	sys.exit(0)
min_val = int(sys.argv[1])
max_val = int(sys.argv[2])
nbr_val = int(sys.argv[3])
f = open("run.sh", "a")
f.write("./push_swap ")
numbers = random.sample(range(max_val - min_val), nbr_val)
for index, number in enumerate(numbers):
	numbers[index] += min_val
	f.write(str(numbers[index]))
	f.write(" ")
f.write("\n")
f.close()
