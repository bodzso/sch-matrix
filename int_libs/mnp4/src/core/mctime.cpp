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

#include "libmnp4/core/mctime.h"

#include <algorithm>

/*
 * Az időszinkronizációról.
 *
 * A szinkronizációs folyamat méréseket végez, melyekkel megpróbálja
 * megállapítani a szerver és kliens órájának eltolódását, valamint a köztük
 * levő késleltetést.
 *
 * Egy mérés 3 fázisból áll:
 *
 * Első fázis: A kliens elküldi óraállását a szervernek.
 * Második fázis: A szerver elküldi a kapott óraállást és a saját óraállását
 * a kliensnek.
 * Harmadik fázis: A kliens régi óraállásának ismeretében kiszámítja az RTT-t
 * és az órák eltolódását, majd ezt visszaküldi a szervernek.
 *
 * A szerver a kapott mérési eredményeket aggregálja. Tizenegy beérkezett mérési
 * eredmény esetén a leggyorsabb (legalacsonyabb RTT-jű) három értéket
 * átlagolja, majd a kapott értékkel eltolja a saját óráját.
 *
 * Az ok, amiért a szerver állítgatja az óráját: Ha a kép csúszik el pár msec-kel,
 * azt észre sem lehet venni (nem fog bevillanni korábbi frame, így lett megírva
 * az MCAnimPlayer), viszont ha a hangot ugráltatnánk, azt hallani lehetne.
 */

DEFINE_MNP_INITIALIZABLE_STRICT(MCTime);


MCTime::MCTime()
    :lock_(QReadWriteLock::Recursive),sync_tick_(NULL)
{
    moveToThread(this);
    delta_=-getTimeMsCore(); // 0-ról indítjuk a timert
    start();
}

MCTime::~MCTime()
{
    quit();
    wait();
    //delete sync_tick_; ~QObject() megoldja
}

/**
 * Elindítja az event loop-ot.
 */
void MCTime::run()
{
    exec();
}

/**
 * Visszaadja az óra értékét. Ez egy 1000 Hz-es számláló, mely 0-tól indul,
 * viszont a szerver átállíthatja a saját óráját a klienséhez. Ekkor akár
 * csökkenhet is az értéke két hívás között.
 */
qint64 MCTime::getTimeMs()
{
    Q_ASSERT(instance_);
    QReadLocker locker(&instance_->lock_);
    return instance_->getTimeMsCore()+instance_->delta_;
}
