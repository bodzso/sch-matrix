Schönherz Mátrix
================

Programok, amelyek szükségesek egy Mátrix esemény lebonyolításához,
plusz dokumentáció.

**FIGYELEM**: Az itt található AnimEditor nem teljesen kompatibilis a 2012-essel,
amíg az van hivatalosan használatban, abból kell exportálni az animációt beadáshoz!

## Release update

**Ez a branch a régi AnimEditor hálózattól teljesen függetlenített változatát adja.**

Az mnp4 library static lett ki lett belőle törölve minden, ami nem kellett. Más alkalmazások amik függtek az  mnp4-től és a hálózattól nem fognak működni. Itt ezzel nem foglalkozunk.

Qt Creatorral is ugyanúgy fog menni minden mint parancssorból.

A magyar fordításhoz szükséges az apps/animeditor/ mappában futtatni az `lupdate`, `lrelease` parancsot. Ezt a Qt-s környezeti változókkal rendelkező parancssorból vagy Qt Creatoron belül a Tools/External/Linguist menü alatt tehetjük meg.

A régi FMOD Ex-et belehet innen szerezni: https://zdoom.org/files/fmod/

Egyéb jelenlegi mátrix rendezők által ismert helyen is megtalálható lesz.

Ami kell
--------

* Qt 5.11.1 vagy valami kompatibilis
* FMOD Ex 4 (régebben könnyebb volt beszerezni, most kicsit kutatni kell utána)
* ~~Lua 5.3.5~~ (beépítve)

A Luát update-eltem 5.3.5-re a 2012-es állapothoz képest, ez a bit32 libraryt megszünteti, ami eltörhet egyes régi animációkat. A Q4X formátum ezért verziót lépett 2-re.

Ez egy lehetséges workaround régi animációkhoz, ha berakod a .qp4 elejére:

```
local bit32 = bit32 or load([[return {
    band = function(a, b) return a & b end,
    bor = function(a, b) return a | b end,
    bxor = function(a, b) return a ~ b end,
    bnot = function(a) return ~a end,
    rshift = function(a, n) return a >> n end,
    lshift = function(a, n) return a << n end,
}]])()
```

Fordítás Windowson
------------------

* Telepítsd fel a Qt-t, legutóbb 5.11.1-en volt a kód tesztelve VS2017 15.8.4-gyel.
* Az ext_libs/lua mappában van egy .vcxproj, fordítsd le (Release|x64-et akarsz valószínűleg)
* Indíts egy terminált, amiben Qt és Visual Studio environment is van
* A főmappában `qmake -tp vc -r`
* A létrejött matrix.sln fájlt töltsd be a Visual Studioba és fordíthatod

Ha nem statikusan fordítottad le, akkor az alábbi fájlokat valószínűleg a kimeneti mappába kell másolni (debug esetén valami.dll helyett értelemszerűen valamid.dll):

Qt5Core.dll, Qt5Gui.dll, Qt5Network.dll, Qt5Svg.dll, Qt5Widgets.dll, fmodex64.dll

Fordítás Linuxon
----------------

Egy "base" Debian 9-en fel kell telepíteni még ezeket:
* qt5-default (most ez 5.7.1)
* libqt5svg5-dev
* make
* g++
* zlib1g-dev
* libreadline-dev
* ncurses-dev

Az ext_libs/lua mappában le kell fordítani a Luát:
* `make linux` (-j ízlés szerint)

Visszamehetsz a főmappába:
* `chmod +x linux_init.sh`
* `./linux_init.sh`
* `qmake`
* `make` (-j ízlés szerint)

Futtatáshoz valószínűleg kelleni fog `LD_LIBRARY_PATH=.`