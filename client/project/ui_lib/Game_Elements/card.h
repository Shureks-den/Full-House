#pragma once
#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>


class Card : public QLabel {
public:
    Card() = delete;
    explicit Card(size_t value, size_t suit, bool upsided = false);
    ~Card();
    void Flip();
    size_t GetValue();
    size_t GetSuit();
    bool GetSide();

    void Resize(QSize WinSize);

private:
    bool LowRes;
    QSize normal;
    QSize min;
    bool mUpSided;
    size_t mUpSideTextureId;
    size_t mDownSideTextureId = 0;
    size_t mValue;
    size_t mSuit;
    QImage* mUpTexture;
    QImage* mDownTexture;

    QImage card;
};

#endif // CARD_H
