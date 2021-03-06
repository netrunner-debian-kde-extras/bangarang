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

#ifndef SAVEDLISTSMANAGER_H
#define SAVEDLISTSMANAGER_H

#include <QObject>
#include <QItemSelection>
#include <QStringList>
#include <KUrl>

namespace Ui
{
    class MainWindowClass;
}
class MainWindow;
class MediaItem;
class MediaItemModel;
class BangarangApplication;

/*
 * This class provides a user interface for saving and removing media lists
 * FIXME: Need interface to rename (or configure?) media lists
 */
class SavedListsManager : public QObject
{
    Q_OBJECT
    
    public:
        SavedListsManager(MainWindow * parent);
        ~SavedListsManager();
        void saveMediaList(QList<MediaItem> mediaList, const QString &name, const QString &type, bool append = false);
        void saveView(const QString &name, const QString &type);
        QStringList savedListNames(const QString &type);
        QString savedListLriName(const QString &lri);
        
    signals:
        void savedListsChanged();
        
    public slots:
        void showAudioListSave();
        void showVideoListSave();
        void returnToAudioList();
        void returnToVideoList();
        void saveAudioList();
        void saveVideoList();
        void removeSelected();
        void saveAudioListSettings();
        void saveVideoListSettings();
        void savePlaylist();
        void loadPlaylist();
        void showAudioSavedListSettings();
        void showVideoSavedListSettings();
        void toggleAmpacheDataAdd(bool);
        
    private:
        BangarangApplication * m_application;
        MainWindow *m_parent; 
        Ui::MainWindowClass *ui;
        int m_startRow;
        QList<int> m_savedAudioListRows;
        QList<int> m_savedVideoListRows;
        QStringList m_savedAudioLists;
        QStringList m_savedVideoLists;
        void updateSavedListsIndex();
        bool m_nepomukInited;
        bool m_ampachePasswordEdited;
        void exportPlaylist(KUrl &saveFrom);
        void saveAmpacheData(const QString type, const QString oldName, const QString newName, const QString server, const QString userName, const QString password);
        void removeAmpacheData(const QString type, const QString name);

    private slots:
        void enableValidSave(QString newText = QString());
        void selectionChanged (const QItemSelection & selected, const QItemSelection & deselected);
        void audioListsSelectionChanged(const QItemSelection & selected, const QItemSelection & deselected);
        void videoListsSelectionChanged(const QItemSelection & selected, const QItemSelection & deselected);
        void mediaListChanged();
        void infoBoxSelectionChanged(QList<MediaItem> selectedItems);
        void removeAudioList();
        void removeVideoList();
        void exportAudioList();
        void exportVideoList();
        void loadSavedListsIndex();
        void ampachePasswordEdited(QString text);

};
#endif //SAVEDLISTSMANAGER_H
