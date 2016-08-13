/*****************************************************************************
 * MediaLibrary.cpp: VLMC media library's ui
 *****************************************************************************
 * Copyright (C) 2008-2016 VideoLAN
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

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "MediaLibraryView.h"

#include "Library/MediaLibrary.h"
#include "Library/MediaLibraryModel.h"
#include "Main/Core.h"

#include <QBoxLayout>
#include <QListView>
#include <QtQuick/QQuickView>
#include <QQmlContext>
#include <QUrl>
#include <QDrag>
#include <QMimeData>

MediaLibraryView::MediaLibraryView( QWidget* parent )
    : QObject( parent )
{
    setObjectName( QStringLiteral( "medialibrary" ) );
    auto view = new QQuickView;
    m_container = QWidget::createWindowContainer( view, parent );
    m_container->setMinimumSize( 100, 1 );
    m_container->setObjectName( objectName() );

    auto ctx = view->rootContext();
    ctx->setContextProperty( QStringLiteral( "mlModel" ), Core::instance()->mediaLibrary()->model( MediaLibrary::MediaType::Video ) );
    ctx->setContextProperty( QStringLiteral( "view" ), this );

    view->setSource( QUrl( QStringLiteral( "qrc:/qml/MediaLibraryView.qml" ) ) );
    view->setResizeMode(QQuickView::SizeRootObjectToView);
}

MediaLibraryView::~MediaLibraryView()
{
}

QWidget*
MediaLibraryView::container()
{
    return m_container;
}

void
MediaLibraryView::startDrag( const QString& mediaPath, const QString& thumbnailPath )
{
    Q_UNUSED( mediaPath )

    QDrag* drag = new QDrag( this );
    QMimeData* mimeData = new QMimeData;

    drag->setMimeData( mimeData );
    drag->setPixmap( QPixmap( thumbnailPath.isEmpty() ? QStringLiteral( ":/images/vlmc" ) : thumbnailPath )
                     .scaled( 100, 100, Qt::KeepAspectRatio ) );

    drag->exec();
}
