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

#ifndef NEWCLIPDIALOG_H
#define	NEWCLIPDIALOG_H

#include "global.h"
#include "scenetree.h"

/**
 * �j klip k�sz�t�s�re szolg�l� p�rbesz�dablak.
 */
class NewClipDialog : public QDialog
{
    Q_OBJECT
    QGridLayout* layout_;
    QFormLayout* formLayout_;
    QLineEdit* nameEdit_;
    QSpinBox* widthEdit_;
    QSpinBox* heightEdit_;
    QPushButton* ok_;
public:
    NewClipDialog(SceneTree*,QWidget* _=NULL);
    ~NewClipDialog();
    QString name();
    int width();
    int height();
};

#endif