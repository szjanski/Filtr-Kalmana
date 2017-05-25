Implementacja filtru Kalmana w C++ z użyciem bibliotek Eigen (http://eigen.tuxfamily.org/index.php?title=Main_Page).
W plikach polzenie.csv i predkosc.csv znajdują się dane wejsciowe dla programu. Dane wyjściowe zapisywane są w pliku wyjscie.txt.

Uruchomienie dla innych danych wejściowych możliwe po zmianie argumentu wywołania funkcji open znajdującej się w KF.cpp.

Kompilacja i uruchomienie w systemie Linux (w folderze z plikami z kodem):

```
cmake .
make
./Kalman
```

W przypadku kompilacji na Windowsie należy dodać ścieżkę do biblioteki Eigen w pliku KF.h:

```
#include <<sciezka_do_tego_folderu>\eigen3\Eigen\Dense>
```
