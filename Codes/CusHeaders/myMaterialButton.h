#ifndef MYMATERIALBUTTON_H
#define MYMATERIALBUTTON_H

#include "qtmaterialraisedbutton.h"

class myMaterialButton : public QtMaterialRaisedButton
{
public:
    explicit myMaterialButton(QWidget *parent = nullptr) :
        QtMaterialRaisedButton(parent)
    {
        MyInit();
    }
    explicit myMaterialButton(const QString &text,QWidget * parent = nullptr) :
        QtMaterialRaisedButton(parent)
    {
        setText(text);
        MyInit();
    }
    ~myMaterialButton(){

    }
private:
    void MyInit()
    {
        setRole(Material::Role::Primary);
    }
};

#endif // MYMATERIALBUTTON_H
