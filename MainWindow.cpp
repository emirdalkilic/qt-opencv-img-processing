#include "MainWindow.h"

#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QMessageBox>
#include <QPixmap>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QWidget>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace
{
QImage matToQImage(const cv::Mat &image)
{
    if (image.empty()) {
        return {};
    }

    if (image.type() == CV_8UC1) {
        return QImage(
            image.data,
            image.cols,
            image.rows,
            static_cast<int>(image.step),
            QImage::Format_Grayscale8
        ).copy();
    }

    if (image.type() == CV_8UC3) {
        cv::Mat rgbImage;
        cv::cvtColor(image, rgbImage, cv::COLOR_BGR2RGB);

        return QImage(
            rgbImage.data,
            rgbImage.cols,
            rgbImage.rows,
            static_cast<int>(rgbImage.step),
            QImage::Format_RGB888
        ).copy();
    }

    return {};
}
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      infoLabel(nullptr),
      originalImageLabel(nullptr),
      processedImageLabel(nullptr),
      blurImageLabel(nullptr),
      pixelatedImageLabel(nullptr),
      edgeImageLabel(nullptr),
      invertedImageLabel(nullptr),
      openButton(nullptr)
{
    setupUi();
}

void MainWindow::setupUi()
{
    setWindowTitle("Image Processing Studio");
    resize(1250, 1050);

    auto *central = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(central);
    auto *imagesLayout = new QGridLayout();
    auto *heroLayout = new QHBoxLayout();
    auto *heroTextLayout = new QVBoxLayout();
    auto *logoCard = new QWidget(this);
    auto *logoCardLayout = new QHBoxLayout(logoCard);
    auto *logoLabel = new QLabel(logoCard);
    const QPixmap logoPixmap("/Users/emirdalkilic/Documents/New project/arvis.png");

    logoCard->setFixedSize(190, 116);
    logoCard->setStyleSheet(
        "QWidget {"
        "background-color: white;"
        "border-radius: 24px;"
        "}"
    );
    logoCardLayout->setContentsMargins(18, 18, 18, 18);
    logoCardLayout->addWidget(logoLabel);

    logoLabel->setFixedSize(154, 80);
    logoLabel->setAlignment(Qt::AlignCenter);
    logoLabel->setStyleSheet("background: transparent;");
    logoLabel->setPixmap(
        logoPixmap.scaled(154, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation)
    );

    auto *titleLabel = new QLabel("Image Processing Studio", this);
    titleLabel->setStyleSheet(
        "QLabel {"
        "font-size: 28px;"
        "font-weight: 800;"
        "color: #f3f4f6;"
        "}"
    );

    infoLabel = new QLabel(
        "Bu proje Qt ile arayuz kurmayi, OpenCV ile de bir resmi farkli filtrelerle "
        "islemeyi ogrenmek icin hazirlandi. Bir gorsel sectiginde ayni resmin "
        "orijinal, siyah-beyaz, bulanik, piksel, kenar tespiti ve ters renk "
        "versiyonlarini ayni ekranda goreceksin.",
        this
    );
    infoLabel->setWordWrap(true);
    infoLabel->setStyleSheet(
        "QLabel {"
        "font-size: 15px;"
        "line-height: 1.4;"
        "color: #d1d5db;"
        "}"
    );

    openButton = new QPushButton("Open Image", this);
    connect(openButton, &QPushButton::clicked, this, &MainWindow::openAndProcessImage);

    originalImageLabel = new QLabel("Original image burada gorunecek", this);
    processedImageLabel = new QLabel("Processed image burada gorunecek", this);
    blurImageLabel = new QLabel("Blur image burada gozukcek", this);
    pixelatedImageLabel = new QLabel("Pixelated image burada gozukcek", this);
    edgeImageLabel = new QLabel("Edge image burada gozukcek", this);
    invertedImageLabel = new QLabel("Inverted image burada gozukcek", this);


    openButton->setStyleSheet(
        "QPushButton {"
        "background-color: orange;"
        "color: white;"
        "font-size: 15px;"
        "font-weight: 700;"
        "border-radius: 8px;"
        "padding: 10px 18px;"
        "}"
        "QPushButton:hover {"
        "background-color: orange;"
        "}"
        "QPushButton:pressed {"
        "background-color: #cc8400;"
        "}"
    );

    auto *buttonShadow = new QGraphicsDropShadowEffect(this);
    buttonShadow->setBlurRadius(24);
    buttonShadow->setOffset(0, 0);
    buttonShadow->setColor(QColor(255, 215, 0, 180));
    openButton->setGraphicsEffect(buttonShadow);

    for (QLabel *label : {
                          originalImageLabel,
                          processedImageLabel,
                          blurImageLabel,
                          pixelatedImageLabel,
                          edgeImageLabel,
                          invertedImageLabel
                       }) {
        label->setMinimumSize(260, 260);
        label->setAlignment(Qt::AlignCenter);
        label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        label->setStyleSheet(
            "QLabel {"
            "border: 2px dashed #8a8a8a;"
            "background: #f8f8f8;"
            "color: #444;"
            "padding: 12px;"
            "}"
        );
    }

    auto createImageColumn = [this](const QString &title, QLabel *imageLabel) {
        auto *columnLayout = new QVBoxLayout();
        auto *titleLabel = new QLabel(title, this);

        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(
            "QLabel {"
            "font-size: 16px;"
            "font-weight: 700;"
            "color: #f3f4f6;"
            "padding: 4px;"
            "}"
        );

        columnLayout->addWidget(titleLabel);
        columnLayout->addWidget(imageLabel);
        columnLayout->setSpacing(10);

        return columnLayout;
    };

    heroTextLayout->addWidget(titleLabel);
    heroTextLayout->addWidget(infoLabel);
    heroLayout->addWidget(logoCard, 0, Qt::AlignTop);
    heroLayout->addLayout(heroTextLayout, 1);
    heroLayout->setSpacing(18);

    imagesLayout->addLayout(createImageColumn("Orijinal Resim", originalImageLabel), 0, 0);
    imagesLayout->addLayout(createImageColumn("Siyah-Beyaz", processedImageLabel), 0, 1);
    imagesLayout->addLayout(createImageColumn("Bulanik", blurImageLabel), 0, 2);
    imagesLayout->addLayout(createImageColumn("Piksel", pixelatedImageLabel), 1, 0);
    imagesLayout->addLayout(createImageColumn("Kenar Tespiti", edgeImageLabel), 1, 1);
    imagesLayout->addLayout(createImageColumn("Ters Renk", invertedImageLabel), 1, 2);
    imagesLayout->setHorizontalSpacing(20);
    imagesLayout->setVerticalSpacing(20);

    central->setStyleSheet("background-color: #111827;");

    mainLayout->addLayout(heroLayout);
    mainLayout->addWidget(openButton);
    mainLayout->addLayout(imagesLayout);
    mainLayout->setSpacing(18);

    setCentralWidget(central);
}

void MainWindow::openAndProcessImage()
{
    const QString filePath = QFileDialog::getOpenFileName(
        this,
        "Bir resim sec",
        QString(),
        "Images (*.png *.jpg *.jpeg *.bmp)"
    );

    if (filePath.isEmpty()) {
        return;
    }

    const cv::Mat original = cv::imread(filePath.toStdString());
    if (original.empty()) {
        QMessageBox::warning(this, "OpenCV", "Resim okunamadi.");
        return;
    }

    const cv::Mat gray = makeGrayImage(original);
    const cv::Mat blurred = makeBlurImage(original);
    const cv::Mat pixelated = makePixelatedImage(original);
    const cv::Mat edges = makeEdgeImage(original);
    const cv::Mat inverted = makeInvertedImage(original);

    showImageOnLabel(original, originalImageLabel);
    showImageOnLabel(gray, processedImageLabel);
    showImageOnLabel(blurred, blurImageLabel);
    showImageOnLabel(pixelated, pixelatedImageLabel);
    showImageOnLabel(edges, edgeImageLabel);
    showImageOnLabel(inverted, invertedImageLabel);
}

cv::Mat MainWindow::makeGrayImage(const cv::Mat &image)
{
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    return grayImage;
}

cv::Mat MainWindow::makeBlurImage(const cv::Mat &Image)
{
    cv::Mat blurredImage;
    cv::GaussianBlur(Image, blurredImage, cv::Size(15, 15), 0);
    return blurredImage;
}

cv::Mat MainWindow::makePixelatedImage(const cv::Mat &image)
{
    cv::Mat smallImage;
    cv::Mat pixelatedImage;

    cv::resize(image, smallImage, cv::Size(), 0.1, 0.1, cv::INTER_LINEAR);
    cv::resize(smallImage, pixelatedImage, image.size(), 0, 0, cv::INTER_NEAREST);

    return pixelatedImage;
}

cv::Mat MainWindow::makeEdgeImage(const cv::Mat &image)
{
    cv::Mat grayImage;
    cv::Mat edgeImage;

    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::Canny(grayImage, edgeImage, 80, 160);

    return edgeImage;
}

cv::Mat MainWindow::makeInvertedImage(const cv::Mat &image)
{
    cv::Mat invertedImage;
    cv::bitwise_not(image, invertedImage);
    return invertedImage;
}


void MainWindow::showImageOnLabel(const cv::Mat &image, QLabel *label)
{
    const QImage qtImage = matToQImage(image);
    if (qtImage.isNull()) {
        label->setText("Gorsel donusumu basarisiz oldu");
        return;
    }

    const QPixmap pixmap = QPixmap::fromImage(qtImage).scaled(
        label->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
    );

    label->setPixmap(pixmap);
}
