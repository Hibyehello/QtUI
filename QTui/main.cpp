//
//  main.cpp
//  QTui
//
//  Created by Hibyehello on 12/30/21.
//  Copyright © 2021 Hibyehello. All rights reserved.
//

#include <iostream>

#include "MainWidget.hpp"

//Qt Includes
#include <QApplication>


int main(int argc, char * argv[]) {
    QApplication app(argc, argv);
    
    MyWidget m;
    
    m.showFullScreen();
    m.buttons[1]->setFocus(Qt::TabFocusReason);
    
    return app.exec();
}
