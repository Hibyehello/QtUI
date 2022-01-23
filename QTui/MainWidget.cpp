//
//  MainWidget.cpp
//  QTui
//
//  Created by Cox Family on 12/31/21.
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
    
    QWidget *sWidget = new QWidget;
    
    // Create Scroll layout
    QHBoxLayout *slayout = new QHBoxLayout;
    for(int i = 0; i < 20; i++){
        QPushButton* button = new QPushButton;
        button->setText("Game " + QString::number(i+1));
        button->setFixedSize(200, 250);
        slayout->addWidget(button); // Add the button to the layout
        button->setStyleSheet("QPushButton:focus {  background-color: red; };");
        buttons.push_back(button);
    }
    
    QScrollArea *scroll = new QScrollArea;
    scroll->setStyleSheet("QScrollBar {height:0px;}");
    scroll->setStyleSheet("QScrollBar {width:0px;}");
    scroll->setFrameShape(scroll->NoFrame);

    sWidget->setLayout(slayout);
    scroll->setWidget(sWidget);

    QScroller::grabGesture(scroll, QScroller::LeftMouseButtonGesture);

    // Add Widgets to layout
    layout->addWidget(scroll, 1, 1);
};


void MyWidget::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_A)
    {
//        if(MyWidget::HasFocus != 0){
//            HasFocus--;
//        } else {
//            HasFocus = 19;
//        }
//        buttons[HasFocus]->setFocus();
        QWidget::focusPreviousChild();
    }
    
    if(event->key() == Qt::Key_D)
    {
        QWidget::focusNextChild();
    }
}



