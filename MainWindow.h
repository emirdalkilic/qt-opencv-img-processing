#pragma once

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

#include <opencv2/core.hpp>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void openAndProcessImage();

private:
    QLabel *infoLabel;
    QLabel *originalImageLabel;
    QLabel *processedImageLabel;
    QLabel *blurImageLabel;
    QLabel *pixelatedImageLabel;
    QLabel *edgeImageLabel;
    QLabel *invertedImageLabel;

    QPushButton *openButton;

    void setupUi();
    void showImageOnLabel(const cv::Mat &image, QLabel *label);
    cv::Mat makeGrayImage(const cv::Mat &image);
    cv::Mat makeBlurImage(const cv::Mat &image);
    cv::Mat makePixelatedImage(const cv::Mat &image);
    cv::Mat makeEdgeImage(const cv::Mat &image);
    cv::Mat makeInvertedImage(const cv::Mat &image);
};
