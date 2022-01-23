//
//  MainWidget.hpp
//  QTui
//
//  Created by Hibyehello on 12/31/21.
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
    int GameFocus = 0;
    int RowFocus = 0;
    int SettingFocus = 0;
    std::vector<QPushButton*> gButtons;
    std::vector<QPushButton*> sButtons;
    MyWidget(QWidget *parent = 0, const char *name=0);
    void changeFocus();
    virtual ~MyWidget() {};
    
    protected:
    void keyPressEvent(QKeyEvent *event) override;
    bool focusNextChild();
    bool focusPreviousChild();
};
