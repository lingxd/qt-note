#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QObject>

class QTextDocument;

class MySyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit MySyntaxHighlighter(QTextDocument *parent = 0);
    ~MySyntaxHighlighter();

protected:
    virtual void highlightBlock(const QString &text);

private:
    MySyntaxHighlighter(const MySyntaxHighlighter &) = delete;
    MySyntaxHighlighter &operator=(const MySyntaxHighlighter &) = delete;
};

#endif // MYSYNTAXHIGHLIGHTER_H
