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
    layout = new QGridLayout;
    this->setLayout(layout);
    layout->setRowStretch(0, 0);
    layout->setRowStretch(3, 0);
    
    gWidget = new QWidget;
    sWidget = new QWidget;
    
    // Create Scroll layout
    glayout = new QHBoxLayout;
    slayout = new QHBoxLayout;
    for(int i = 0; i < 20; i++){
        QPushButton* button = new QPushButton;
        button->setText("Game " + QString::number(i+1));
        button->setFixedSize(375, 500);
        glayout->addWidget(button); // Add the button to the layout
        button->setStyleSheet("QPushButton:focus { border-width: 10px; border-style: solid; border-color : rgb(24, 108, 204); border-radius: 10px; } QPushButton{ background-image: url(../game_art.jpg); background-repeat: no-repeat; border-radius: 10px;}");
        glayout->setAlignment(button, Qt::AlignTop);
        gButtons.push_back(button);
    }

    for(int i = 0; i < 5; i++){
        QPushButton* button = new QPushButton;
        button->setText("Setting " + QString::number(i+1));
        button->setFixedSize(100, 100);
        slayout->addWidget(button); // Add the button to the layout
        button->setStyleSheet("QPushButton:focus {  border-width: 5px; border-style: solid; border-color : rgb(24, 108, 204); border-radius: 10px; } QPushButton{ background: gray; }");
        slayout->setAlignment(button, Qt::AlignTop);
        sButtons.push_back(button);
    }

    sButtons[SettingFocus]->setFocus();
    
    scroll = new QScrollArea;
    scroll->setStyleSheet("QScrollBar {height:0px;}");
    scroll->setStyleSheet("QScrollBar {width:0px;}");
    scroll->setFrameShape(scroll->NoFrame);

    gWidget->setLayout(glayout);
    scroll->setWidget(gWidget);

    sWidget->setLayout(slayout);

    QScroller::grabGesture(scroll, QScroller::LeftMouseButtonGesture);

    // Add Widgets to layout
    layout->addWidget(sWidget, 0, 0);
    layout->addWidget(scroll, 1, 0, 3, 3);
};


void MyWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        QApplication::quit();
    }
    if(event->key() == Qt::Key_W) {
        if(RowFocus != 0) {
            RowFocus--;
            sButtons[SettingFocus]->setFocusPolicy(Qt::StrongFocus);
            sButtons[SettingFocus]->setFocus(Qt::TabFocusReason);
        }
    }
    if(event->key() == Qt::Key_S) {
        if(RowFocus != 1) {
            RowFocus++;
            gButtons[SettingFocus]->setFocusPolicy(Qt::StrongFocus);
            gButtons[GameFocus]->setFocus(Qt::TabFocusReason);
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
            gButtons[SettingFocus]->setFocusPolicy(Qt::StrongFocus);
            gButtons[GameFocus]->setFocus(Qt::TabFocusReason);
            scroll->ensureWidgetVisible(gButtons[GameFocus]);
        } else if(RowFocus == 0) {
            if(SettingFocus > 0) {
                SettingFocus--;
            }
            sButtons[SettingFocus]->setFocusPolicy(Qt::StrongFocus);
            sButtons[SettingFocus]->setFocus(Qt::TabFocusReason);
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
            gButtons[SettingFocus]->setFocusPolicy(Qt::StrongFocus);
            gButtons[GameFocus]->setFocus(Qt::TabFocusReason);
            scroll->ensureWidgetVisible(gButtons[GameFocus]);
        } else if(RowFocus == 0) {
            if(SettingFocus < 4) {
                SettingFocus++;
            }
            sButtons[SettingFocus]->setFocusPolicy(Qt::StrongFocus);
            sButtons[SettingFocus]->setFocus(Qt::TabFocusReason);
        }
    }
}



