#include "mysyntaxhighlighter.h"
#include <QTextCharFormat>
#include <QFont>
#include <QString>
#include <QRegularExpression>

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{

}

MySyntaxHighlighter::~MySyntaxHighlighter()
{

}

void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat my_format;
    my_format.setFont(QFont("微软雅黑"));
    my_format.setFontWeight(QFont::Bold);
    my_format.setForeground(Qt::green);

    QString pattern = "\\bchar\\b";

    static QRegularExpression expression(pattern);
    QRegularExpressionMatchIterator matchIterator = expression.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), my_format);
    }
}
