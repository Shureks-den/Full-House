#include "playerinfolabel.h"

PlayerInfoLabel::PlayerInfoLabel(std::string nickname, size_t money) {
    mNickname = new QLabel;
    mTotalMoney = new QLabel;
    mBet = new QLabel;

    QString name = QString::fromStdString(nickname);
    mNickname->setText(name);
    QString total = "Bank 💰: " + QString::number(money);
    mTotalMoney->setText(total);

    mNickname->setParent(this);
    mNickname->setGeometry(0, 50, 400, 30);
    mNickname->setStyleSheet("background:rgba(33,33,33,0.5);font-size:24px;color:rgb(242, 224, 22)");

    mTotalMoney->setParent(this);
    mTotalMoney->setGeometry(0, 80, 400, 30);
    mTotalMoney->setStyleSheet("background:rgba(33,33,33,0.5);font-size:24px;color:rgb(242, 224, 22)");

    mBet->setParent(this);
    mBet->setGeometry(0, 110, 400, 30);
    mBet->setStyleSheet("background:rgba(33,33,33,0.5);font-size:24px;color:rgb(242, 224, 22)");
    qDebug("All added");
}

void PlayerInfoLabel::setTotal(size_t total) {
    QString totalm = "Bank 💰: " + QString::number(total);
    mTotalMoney->setText(totalm);
}

void PlayerInfoLabel::setBet(size_t bet) {
    QString total = "Bet 🌝: " + QString::number(bet);
    mBet->setText(total);
}

PlayerInfoLabel::~PlayerInfoLabel() {
    delete mNickname;
    delete mTotalMoney;
    delete mBet;
}
