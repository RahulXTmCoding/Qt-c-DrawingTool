#include "ellipsecomponent.h"

EllipseComponent::EllipseComponent()
{
    pen=NULL;
    brush=NULL;
}

QBrush *EllipseComponent::getBrush() const
{
    return brush;
}

void EllipseComponent::setBrush(QBrush *value)
{
    brush = value;
}

float EllipseComponent::getX() const
{
    return x;
}

void EllipseComponent::setX(float value)
{
    x = value;
}

float EllipseComponent::getY() const
{
    return y;
}

void EllipseComponent::setY(float value)
{
    y = value;
}

float EllipseComponent::getWidth() const
{
    return width;
}

void EllipseComponent::setWidth(float value)
{
    width = value;
}

float EllipseComponent::getHeight() const
{
    return height;
}

void EllipseComponent::setHeight(float value)
{
    height = value;
}

QPen *EllipseComponent::getPen() const
{
    return pen;
}

void EllipseComponent::setPen(QPen *value)
{
    pen = value;
}
void EllipseComponent::draw(QPainter *painter)
{

    if(pen==NULL)
    {
        qDebug()<<"set hua pen";

        pen=new QPen();
        pen->setWidth(painter->pen().width());
        pen->setColor(painter->pen().color());
    }
   painter->setPen(*pen);
    //painter->setPen(*(this->getPen()));
    //painter->setBrush(*(this->getBrush()));
    painter->drawEllipse(this->getX(),this->getY(),this->getWidth(),this->getHeight());

}

bool EllipseComponent::isClicked(QPoint *point)
{
  if(sqrt((point->x()-this->getX())*(this->getX()+this->getWidth()-point->x()))*sqrt((point->y()-this->getY())*(this->getY()+this->getHeight()-point->y()))>=0)
  {
      return true;
  }
return false;
}

QString EllipseComponent::componentName()
{
return "Ellipse";
}

void EllipseComponent::select(QPainter *p)
{
    p->drawRect(x+(width/2)-5,y-5,10,10);
    p->drawRect(x+width-5,y+(height/2)-5,10,10);
    p->drawRect(x-5,y+(height/2)-5,10,10);
    p->drawRect(x+(width/2)-5,y+height-5,10,10);
}

void EllipseComponent::update(int x, int y)
{
    this->setX(this->getX()+x);
    this->setY(this->getY()+y);
}