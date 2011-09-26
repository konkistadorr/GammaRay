/*
  textdocumentmodel.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2011 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_TEXTDOCUMENTMODEL_H
#define GAMMARAY_TEXTDOCUMENTMODEL_H

#include <QStandardItemModel>
#include <qtextobject.h>

class QTextTable;
class QTextBlock;
class QTextFrame;
class QTextDocument;

namespace GammaRay {

class TextDocumentModel : public QStandardItemModel
{
  Q_OBJECT
  public:
    explicit TextDocumentModel(QObject *parent = 0);

    enum Roles {
      FormatRole = Qt::UserRole
    };

    void setDocument(QTextDocument *doc);

  private:
    void fillModel();
    void fillFrame(QTextFrame *frame, QStandardItem *parent);
    void fillFrameIterator(const QTextFrame::iterator &it, QStandardItem *parent);
    void fillTable(QTextTable *table, QStandardItem *parent);
    void fillBlock(const QTextBlock &block, QStandardItem *parent);
    QStandardItem *formatItem(const QTextFormat &format);
    void appendRow(QStandardItem *parent, QStandardItem *item, const QTextFormat &format);

  private slots:
    void documentChanged();

  private:
    QTextDocument *m_document;
};

}

#endif
