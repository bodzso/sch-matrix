/*
 *  This file is part of SCH Matrix.
 *
 *  SCH Matrix is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SCH Matrix is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SCH Matrix. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ABOUTWINDOW_H
#define	ABOUTWINDOW_H

#include "global.h"

class AboutWindow : public QDialog
{
Q_OBJECT

    QGridLayout* layout_;
    QLabel* mainText_;
    QPushButton* aboutQt_;
    QPushButton* aboutLua_;
    QPushButton* ok_;
    QLabel m_gif;
    QMovie m_gifPlayer{":/matrix.gif"};
public:
    AboutWindow(QWidget* parent=NULL);
public slots:
    void aboutLua();
    void linkClicked(const QString&);
};

#endif
