import io
import random

filename=input("Please enter file name[matrix]:")
if len(filename) == 0:
    filename="matrix"

file=io.open(filename+".c","w")
header=io.open(filename+".h","w")
file.write("""#include "matrix.h"\n""")
file.write("long long matrixA[SIZE][SIZE]={")
for i in range(0,4096):
    file.write("\n{")
    for j in range(0,4096):
        file.write("{},".format(random.randint(1,200)))
    file.write("},")
file.write("\n};")

file.write("\nlong long matrixB[SIZE][SIZE]={")
for i in range(0,4096):
    file.write("\n{")
    for j in range(0,4096):
        file.write("{},".format(random.randint(1,200)))
    file.write("},")
file.write("\n};")

macro=filename.upper()+"_H_"+str(random.randint(333,666))
header.write\
("""#ifndef {0}
#define {0}

#define SIZE 4096

long long matrixA[SIZE][SIZE];
long long matrixB[SIZE][SIZE];
 
#endif //{0}""".format(macro))

print("Done!")
