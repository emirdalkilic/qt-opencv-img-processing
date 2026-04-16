# Image Processing Studio

`Image Processing Studio`, Qt ve OpenCV kullanarak temel goruntu isleme mantigini ogrenmek icin hazirlanmis bir macOS masaustu uygulamasidir. Kullanici bir resim secer ve uygulama ayni gorselin farkli islenmis versiyonlarini tek ekranda gosterir.

## Proje Amaci

Bu proje ozellikle su konulari birlikte ogrenmek icin tasarlandi:

- `Qt Widgets` ile masaustu arayuzu kurmak
- `OpenCV` ile resim okumak ve islemek
- Islenmis goruntuleri `QLabel` uzerinde gostermek
- `CMake` ile Qt ve OpenCV baglantisini kurmak

## Uygulamada Neler Var?

Uygulamada bir resmi sectikten sonra su goruntuler uretilir:

- `Orijinal Resim`
- `Siyah-Beyaz`
- `Bulanik`
- `Piksel`
- `Kenar Tespiti`
- `Ters Renk`

Ayrica uygulamanin ust kismina proje logosu, baslik ve aciklayici bir tanitim metni eklenmistir.

## Kullanilan Teknolojiler

- `C++`
- `Qt 6`
- `Qt Widgets`
- `OpenCV`
- `CMake`

## Ogrenilen Temel Kavramlar

Bu proje uzerinden su yapilar pratik edilebilir:

- `QMainWindow`
- `QLabel`
- `QPushButton`
- `QGridLayout`
- `QVBoxLayout`
- `cv::Mat`
- `cv::imread`
- `cv::cvtColor`
- `cv::GaussianBlur`
- `cv::resize`
- `cv::Canny`
- `cv::bitwise_not`

## Ekran Akisi

1. Uygulama acilir
2. Kullanici `Open Image` butonuna basar
3. Bilgisayardan bir gorsel secer
4. OpenCV secilen resmi farkli filtrelerden gecirir
5. Sonuclar tek ekranda karsilastirmali olarak gosterilir

## Kurulum

Ilk olarak gerekli araclari kur:

```bash
brew install cmake opencv pkg-config
```

Qt tarafinda `Qt 6 for macOS` ve `Qt Creator` kurulu olmalidir.

## Derleme ve Calistirma

Proje klasorunde:

```bash
cd "/Users/emirdalkilic/Documents/New project"
cmake -S . -B build -DCMAKE_PREFIX_PATH="$HOME/Qt/6.11.0/macos"
cmake --build build
./build/QtOpenCVStarter
```

Eger OpenCV yolu bulunamazsa su parametreyi de ekleyebilirsin:

```bash
-DOpenCV_DIR=/opt/homebrew/opt/opencv/lib/cmake/opencv4
```

Tam komut:

```bash
cmake -S . -B build \
  -DCMAKE_PREFIX_PATH="$HOME/Qt/6.11.0/macos" \
  -DOpenCV_DIR=/opt/homebrew/opt/opencv/lib/cmake/opencv4
```

## Qt Creator Ile Calistirma

1. `CMakeLists.txt` dosyasini `Open File or Project` ile ac
2. `Qt 6 for macOS` veya `Desktop` kit sec
3. `Build`
4. `Run`

Not: `iOS` kit secilirse proje masaustu yerine mobil hedefe build edilmeye calisilir ve hata verebilir.

## Proje Dosyalari

- `main.cpp`: uygulamayi baslatir
- `MainWindow.h`: pencere sinifinin tanimlari
- `MainWindow.cpp`: arayuz ve goruntu isleme akisi
- `arvis.png`: uygulama logosu
- `CMakeLists.txt`: build yapilandirmasi

## Gelecekte Eklenebilecek Ozellikler

- `Sepya` filtresi
- `Threshold` filtresi
- Kameradan canli goruntu alma
- Filtre secimi icin `ComboBox`
- Kaydetme ozelligi
- Daha profesyonel arayuz tasarimi

## Kisa Not

Bu proje, staj surecinde `Qt`, `C++` ve `OpenCV` ogrenmeye baslayan biri icin guzel bir baslangic uygulamasidir. Hem temel goruntu isleme mantigini hem de masaustu uygulama gelistirme akislarini pratik ettirir.
