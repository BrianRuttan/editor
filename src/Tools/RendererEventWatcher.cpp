/*****************************************************************************
 * RendererEventWatcher.cpp: Watches events from a ISourceRenderer and convert them to SIGNAL
 *****************************************************************************
 * Copyright (C) 2008-2014 VideoLAN
 *
 * Authors: Hugo Beauzée-Luyssen <hugo@beauzee.fr>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "RendererEventWatcher.h"

RendererEventWatcher::RendererEventWatcher(QObject *parent) :
    QObject(parent)
{
}

void
RendererEventWatcher::onTimeChanged(int64_t time )
{
    emit timeChanged( time );
}

void
RendererEventWatcher::onPlaying()
{
    emit playing();
}

void
RendererEventWatcher::onPaused()
{
    emit paused();
}

void
RendererEventWatcher::onStopped()
{
    emit stopped();
}

void
RendererEventWatcher::onEndReached()
{
    emit endReached();
}

void
RendererEventWatcher::onVolumeChanged()
{
    emit volumeChanged();
}

void
RendererEventWatcher::onPositionChanged( float pos )
{
    emit positionChanged( pos );
}

void
RendererEventWatcher::onLengthChanged(int64_t length )
{
    emit lengthChanged( length );
}

void
RendererEventWatcher::onErrorEncountered()
{
    emit errorEncountered();
}
