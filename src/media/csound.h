/********************************************************************
    Copyright (c) 2013-2015 - Mogara

    This file is part of Cardirector.

    This game engine is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 3.0
    of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    See the LICENSE file for more details.

    Mogara
*********************************************************************/

#ifndef CSOUND_H
#define CSOUND_H

#include "cglobal.h"

#include <QObject>

MCD_BEGIN_NAMESPACE

class CSoundPrivate;
class MCD_EXPORT CSound : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(int loops READ loops WRITE setLoops NOTIFY loopsChanged)
    Q_PROPERTY(int loopsRemaining READ loopsRemaining NOTIFY loopsRemainingChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying NOTIFY isPlayingChanged)
    Q_PROPERTY(qreal volume READ volume WRITE setVolume NOTIFY volumeChanged)

public:
    CSound(QObject *parent = Q_NULLPTR);
    CSound(const QString &fileName, QObject *parent = Q_NULLPTR);
    ~CSound();

    QString fileName() const;
    void setFileName(const QString &fileName);

    int loops() const;
    int loopsRemaining() const;
    void setLoops(int number);

    bool isPlaying() const;

    qreal volume() const;
    void setVolume(qreal volume);

    Q_INVOKABLE void play();
    Q_INVOKABLE void stop();

    Q_INVOKABLE static void Play(const QString &fileName);

signals:
    void started();
    void stopped();

    void fileNameChanged();
    void loopsChanged();
    void loopsRemainingChanged();
    void isPlayingChanged();
    void volumeChanged();

private:
    C_DISABLE_COPY(CSound)
    C_DECLARE_PRIVATE(CSound)
    CSoundPrivate *p_ptr;
};

MCD_END_NAMESPACE

#endif // CSOUND_H
