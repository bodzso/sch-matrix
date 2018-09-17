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

#include "libmnp4/core/mcconfig.h"

MCConfig* MCConfig::instance_=NULL;

MCConfig::MCConfig()
{
}

/**
 * Le�ll�tja az oszt�lyt. Sz�ks�ges, ha �j
 * konfigur�ci� providert akarsz haszn�lni.
 */
void MCConfig::shutdown()
{
    delete instance_;
}

/**
 * Inicializ�lja az oszt�lyt
 *
 * \param cfg Innen fog j�nni a konfigur�ci�.
 */
void MCConfig::init(QVariant(*cfg)(QString))
{
    Q_ASSERT(!instance_);
    instance_=new MCConfig;
    instance_->cfg_=cfg;
}

/**
 * \return Az oszt�ly egyetlen objektuma.
 */
MCConfig* MCConfig::instance()
{
    Q_ASSERT(instance_);
    return instance_;
}

/**
 * Konfigur�ci�s �rt�kek lek�r�s�t v�gzi.
 *
 * \param A k�v�nt konfigur�ci�s �rt�k el�r�si �tja
 * \return Az �rt�k, QVariant-ba csomagolva.
 */
QVariant MCConfig::query(QString name)
{
    return (*instance()->cfg_)(name);
}
