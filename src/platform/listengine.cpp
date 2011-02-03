/* BANGARANG MEDIA PLAYER
* Copyright (C) 2009 Andrew Lake (jamboarder@yahoo.com)
* <http://gitorious.org/bangarang>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "listengine.h"

ListEngine::ListEngine(ListEngineFactory * parent) : QThread(parent)
{
}

ListEngine::~ListEngine()
{
}

void ListEngine::setModel(MediaItemModel * mediaItemModel)
{
    m_mediaItemModel = mediaItemModel;
    connect(this, 
            SIGNAL(results(QString, QList<MediaItem>, MediaListProperties, bool, QString)),
            m_mediaItemModel,
            SLOT(addResults(QString, QList<MediaItem>, MediaListProperties, bool, QString)));
    connect(this, 
            SIGNAL(updateMediaItems(QList<MediaItem>)),
            m_mediaItemModel,
            SLOT(updateMediaItems(QList<MediaItem>)));

}

MediaItemModel * ListEngine::model()
{
    return m_mediaItemModel;
}

void ListEngine::setMediaListProperties(const MediaListProperties& mediaListProperties)
{
    m_mediaListProperties = mediaListProperties;
}

const MediaListProperties& ListEngine::mediaListProperties() const
{
    return m_mediaListProperties;
}

void ListEngine::setRequestSignature(const QString& requestSignature)
{
    m_requestSignature = requestSignature;
}

const QString& ListEngine::requestSignature() const {
	return m_requestSignature;
}

void ListEngine::setSubRequestSignature(const QString& subRequestSignature)
{
    m_subRequestSignature = subRequestSignature;
}

const QString& ListEngine::subRequestSignature() const {
	return m_subRequestSignature;
}
