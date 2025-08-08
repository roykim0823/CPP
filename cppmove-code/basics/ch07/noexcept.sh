clang++ -std=c++20 -DNOEXCEPT=""  movenoexcept.cpp -o ignore
clang++ -std=c++20 -DNOEXCEPT=noexcept  movenoexcept.cpp -o noexcept
clang++ -std=c++20 -DNOEXCEPT=""  movenoexcept.cpp -O3 -o ignore_o3
clang++ -std=c++20 -DNOEXCEPT=noexcept  movenoexcept.cpp -O3 -o noexcept_o3