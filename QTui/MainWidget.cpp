//
//  MainWidget.cpp
//  QTui
//
//  Created by Hibyehello on 12/31/21.
//  Copyright © 2021 Hibyehello. All rights reserved.
//

#include "MainWidget.hpp"

MyWidget::MyWidget( QWidget *parent, const char *name )
{
    
    setWindowTitle("Main");
    
    // Create Layout
    QGridLayout* layout = new QGridLayout;
    this->setLayout(layout);
    layout->setRowStretch(0, 1);
    layout->setRowStretch(3, 1);
    
    QWidget *gWidget = new QWidget;
    QWidget *sWidget = new QWidget;
    
    // Create Scroll layout
    QHBoxLayout *glayout = new QHBoxLayout;
    QHBoxLayout *slayout = new QHBoxLayout;
    for(int i = 0; i < 20; i++){
        QPushButton* button = new QPushButton;
        button->setText("Game " + QString::number(i+1));
        button->setFixedSize(200, 250);
        glayout->addWidget(button); // Add the button to the layout
        button->setStyleSheet("QPushButton:focus {  background-color: red; }");
        gButtons.push_back(button);
    }

    for(int i = 0; i < 5; i++){
        QPushButton* button = new QPushButton;
        button->setText("Setting " + QString::number(i+1));
        button->setFixedSize(100, 50);
        slayout->addWidget(button); // Add the button to the layout
        button->setStyleSheet("QPushButton:focus {  background-color: red; }");
        sButtons.push_back(button);
    }

    sButtons[SettingFocus]->setFocus();
    
    QScrollArea *scroll = new QScrollArea;
    scroll->setStyleSheet("QScrollBar {height:0px;}");
    scroll->setStyleSheet("QScrollBar {width:0px;}");
    scroll->setFrameShape(scroll->NoFrame);

    gWidget->setLayout(glayout);
    scroll->setWidget(gWidget);

    sWidget->setLayout(slayout);

    QScroller::grabGesture(scroll, QScroller::LeftMouseButtonGesture);

    // Add Widgets to layout
    layout->addWidget(sWidget, 0, 0);
    layout->addWidget(scroll, 1, 0, 1, 3);
};


void MyWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        QApplication::quit();
    }
    if(event->key() == Qt::Key_W) {
        if(RowFocus != 0) {
            RowFocus--;
            sButtons[SettingFocus]->setFocus();
        }
    }
    if(event->key() == Qt::Key_S) {
        if(RowFocus != 1) {
            RowFocus++;
            gButtons[GameFocus]->setFocus();
        }
    }

    if(event->key() == Qt::Key_A)
    {
        if(RowFocus == 1) {
            if(GameFocus <= 0) {
                GameFocus = 19;
            } else{
                GameFocus--;
            }

            gButtons[GameFocus]->setFocus();
        } else if(RowFocus == 0) {
            if(SettingFocus > 0) {
                SettingFocus--;
            }

            sButtons[SettingFocus]->setFocus();
        }
    }
    
    if(event->key() == Qt::Key_D)
    {
        if(RowFocus == 1){
            if(GameFocus >= 19) {
            GameFocus = 0;
            } else {
            GameFocus++;
            }

            gButtons[GameFocus]->setFocus();
        } else if(RowFocus == 0) {
            if(SettingFocus < 4) {
                SettingFocus++;
            }

            sButtons[SettingFocus]->setFocus();
        }
    }
}



