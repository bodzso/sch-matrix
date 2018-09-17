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

#ifndef MATRIXSTACK_H
#define	MATRIXSTACK_H

#include "global.h"

/**
 * Transzform�ci�s m�trixok stackje, a la glPushMatrix/glPopMatrix.
 */
class MatrixStack : public QTransform
{
    QStack<QTransform> stack_;
public:
    void push(){stack_.push(*this);}
    void pop(){*this=stack_.pop();}
    QTransform& operator=(const QTransform& o){return QTransform::operator=(o);}
};

#endif
