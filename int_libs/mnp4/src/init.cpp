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

#include <stdio.h>

#include "libmnp4/init.h"
#include "libmnp4/core/mctime.h"
#include "libmnp4/core/mcconfig.h"

/**
 * Inicializálja a libraryt. Meg kell hívni, mielőtt bármi mást csinálnál.
 * \param cfg Függvény, ami konfigurációs értékeket szállít a libnek. Lásd #MCConfig
 */
void MNP4_EXPORT libmnp_init(QVariant(*cfg)(QString))
{
    MCConfig::init(cfg);
}

/**
 * Leállítja a libraryt. Kilépés előtt érdemes meghívni.
 */
void MNP4_EXPORT libmnp_shutdown()
{
    //common
    MCTime::shutdown();
    //core
    //config
    MCConfig::shutdown();
}
