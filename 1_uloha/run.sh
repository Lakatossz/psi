cd build
make
cd ..

for ((i = 50; i >= 1; i--))
do
  echo "$i. time"
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZABCDEFGHIJKLMNOPQRSTUVWXZ
  ./build/client/client 8080 ABCD
  ./build/client/client 8080 ABCDE
  ./build/client/client 8080 ABCDEF
  ./build/client/client 8080 ABCDEFG
  ./build/client/client 8080 ABCDEFGH
  ./build/client/client 8080 ABCDEFGHI
  ./build/client/client 8080 ABCDEFGHIJ
  ./build/client/client 8080 ABCDEFGHIJK
  ./build/client/client 8080 ABCDEFGHIJKL
  ./build/client/client 8080 ABCDEFGHIJKLM
  ./build/client/client 8080 ABCDEFGHIJKLMN
  ./build/client/client 8080 ABCDEFGHIJKLMNO
  ./build/client/client 8080 ABCDEFGHIJKLMNOP
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQ
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQR
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQRS
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQRST
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQRSTU
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQRSTUV
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQRSTUVW
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQRSTUVWX
  ./build/client/client 8080 ABCDEFGHIJKLMNOPQRSTUVWXZ
done
