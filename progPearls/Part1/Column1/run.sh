./build/uniqueRandInt 10000000 10000000 > input
echo "qsortints"
time ./build/qsortints < input > output1
echo "sortingints"
time ./build/sortingints < input > output2
echo "bitsort"
time ./build/bitsort < input > output3
echo "twoPhaseBitSort"
time ./build/twoPhaseBitSort input > output4
echo "multiBitSort"
time ./build/multiBitSort < input > output5
diff output1 output2
diff output2 output3
diff output3 output4
diff output4 output5
rm input output*
