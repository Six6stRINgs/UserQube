#ifndef BOOLDELEGATE_H
#define BOOLDELEGATE_H

#include <QStyledItemDelegate>

class BoolDelegate : public QStyledItemDelegate
{
public:
    explicit BoolDelegate(QObject *parent = nullptr) :
        QStyledItemDelegate(parent)
    {}

    QString displayText(const QVariant &value, const QLocale &locale) const override
    {
        if (value.type() == QVariant::Int) {
            return value.toInt() ? tr("是") : tr("否");
        }
        return QStyledItemDelegate::displayText(value, locale);
    }
};

#endif // BOOLDELEGATE_H
