# Qt + OpenCV Starter

Bu proje, sifirdan baslayan biri icin en temel akisi gosterir:

- Qt pencereyi ve butonu olusturur.
- OpenCV resmi diskten okur.
- OpenCV resmi gray'e cevirir.
- Qt sonucu ekranda gosterir.

## Ne ogreneceksin?

- `QMainWindow`: ana pencere
- `QPushButton`: tiklanan buton
- `QLabel`: metin ya da gorsel gostermek
- `cv::Mat`: OpenCV'nin temel image veri tipi
- `cv::imread(...)`: resmi dosyadan okumak
- `cv::cvtColor(...)`: renk uzayi donusumu yapmak

## Build

Ilk once eksik araclari kur:

```bash
brew install cmake opencv pkg-config
```

Sonra Qt'nin kurulu oldugu yolu kendi makinene gore ver:

```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH="$HOME/Qt/6.11.0/macos"
cmake --build build
./build/QtOpenCVStarter
```

Eger CMake `OpenCV` bulamazsa su ek yardimci parametreyi dene:

```bash
-DOpenCV_DIR=/opt/homebrew/opt/opencv/lib/cmake/opencv4
```

Tam komut:

```bash
cmake -S . -B build \
  -DCMAKE_PREFIX_PATH="$HOME/Qt/6.11.0/macos" \
  -DOpenCV_DIR=/opt/homebrew/opt/opencv/lib/cmake/opencv4
```

## Ilk odev fikri

Bu uygulamayi sirayla sunlara cevir:

1. Gray yerine blur ekle
2. Sonra edge detection ekle
3. Sonra iki buton yap: `Gray` ve `Blur`
