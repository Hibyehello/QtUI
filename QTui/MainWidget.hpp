//
//  MainWidget.hpp
//  QTui
//
//  Created by Cox Family on 12/31/21.
//  Copyright © 2021 Hibyehello. All rights reserved.
//

#ifndef MainWidget_hpp
#define MainWidget_hpp

#include <iostream>
#include <vector>

#include <QWidget>
#include <QApplication>
#include <QObject>
#include <QPushButton>
#include <QFont>
#include <QGridLayout>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include <QScroller>
#include <QListWidget>
#include <QButtonGroup>
#include <QKeyEvent>

#endif /* MainWidget_hpp */


class MyWidget: public QWidget {
    public:
    int HasFocus = 0;
    std::vector<QPushButton*> buttons;
    MyWidget(QWidget *parent = 0, const char *name=0);
    void changeFocus();
    
    protected:
    void keyPressEvent(QKeyEvent *event) override;
    bool focusNextChild();
    bool focusPreviousChild();
};
