./build/encoder < data/matrix.in | sort -k 1n -k 2n | ./build/decoder > matrix.out
./build/encoder < matrix.out | sort -k 1n -k 2n | ./build/decoder > matrix.orig
diff data/matrix.in matrix.orig
rm matrix.out matrix.orig
