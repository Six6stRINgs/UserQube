#ifndef DATETIMEDELEGATE_H
#define DATETIMEDELEGATE_H
#include <QStyledItemDelegate>
#include <QDateTime>

class DateTimeDelegate : public QStyledItemDelegate
{
public:
    explicit DateTimeDelegate(const QString &timeDisplayFormat, QObject *parent = nullptr)
        : QStyledItemDelegate(parent)
        , m_timeDisplayFormat(timeDisplayFormat)
    {
    }

    QString displayText(const QVariant &value, const QLocale &locale) const override
    {
        if (value.canConvert<QDateTime>()) {
            return value.toDateTime().toString(m_timeDisplayFormat);
        } else {
            return QStyledItemDelegate::displayText(value, locale);
        }
    }

private:
    QString m_timeDisplayFormat;
};

#endif // DATETIMEDELEGATE_H

