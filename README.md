# Qt OpenCV Image Processing
<img width="900" height="750" alt="image" src="https://github.com/user-attachments/assets/bf8dab18-a5be-4059-a934-7e22b1306060" />

Bu proje, Qt ile arayüz geliştirmeyi ve OpenCV ile temel görüntü işleme mantığını öğrenmek için hazırlanmış bir C++ çalışmasıdır.

Uygulamada kullanıcı bir görsel seçer ve seçilen görsel aynı pencere içinde farklı işlemlerden geçirilmiş halleriyle birlikte gösterilir. Amaç hem Qt tarafında arayüz kurmayı öğrenmek hem de OpenCV ile temel görüntü işleme fonksiyonlarını uygulamalı şekilde görmekti.

## Projede Neler Var?

Uygulama içinde şu işlemler bulunuyor:

- Orijinal görselin gösterilmesi
- Siyah-beyaz dönüşüm
- Blur (bulanıklaştırma)
- Pixelated efekt
- Edge detection (kenar tespiti)
- Invert / negative görüntü

Böylece tek bir görsel üzerinden farklı görüntü işleme sonuçları aynı anda karşılaştırılabiliyor.

## Kullanılan Teknolojiler

- C++
- Qt6
- OpenCV
- CMake

## Projenin Amacı

Bu projeyi yaparken hedefim:

- Qt ile masaüstü arayüz mantığını öğrenmek
- OpenCV ile temel görüntü işleme işlemlerini uygulamak
- C++ tarafında daha rahat pratik yapmak
- Bir görselin farklı işlemlerden nasıl geçtiğini mantığıyla birlikte görmekti

Bu çalışma daha çok öğrenme ve deneme amaçlı geliştirildi. Yani büyük ölçekli bir ürün değil, ama hem Qt hem OpenCV tarafında iyi bir başlangıç projesi oldu.

## Uygulama Nasıl Çalışıyor?

1. Kullanıcı uygulamadaki **Open Image** butonuna tıklar
2. Bilgisayardan bir görsel seçilir
3. OpenCV ile görsel okunur
4. Aynı görsel farklı işlemlerden geçirilir
5. Sonuçlar Qt arayüzünde ayrı alanlarda gösterilir

## Uygulanan İşlemler Kısaca

### 1. Gray Scale
Renkli görsel gri tonlamaya çevrilir.

### 2. Blur
Gaussian Blur kullanılarak görüntü yumuşatılır.

### 3. Pixelated Effect
Görsel önce küçültülüp sonra tekrar büyütülerek pikselli bir görünüm elde edilir.

### 4. Edge Detection
Canny algoritması ile görseldeki kenarlar tespit edilir.

### 5. Invert / Negative
Görselin renkleri ters çevrilir.

## Proje Yapısı

- `main.cpp`  
  Uygulamanın başlangıç noktasıdır.

- `MainWindow.h`  
  Ana pencerenin tanımları ve fonksiyon bildirimleri burada bulunur.

- `MainWindow.cpp`  
  Arayüz kurulumu, görsel yükleme işlemi ve OpenCV filtreleri burada yer alır.

- `CMakeLists.txt`  
  Qt ve OpenCV bağlantıları ile proje yapılandırması burada yapılır.
